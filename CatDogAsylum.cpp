/*****************************************************
* \file CatDogAsylum.cpp
* \date 2016/05/09 15:19

* \问题描述：
题目描述

有家动物收容所只收留猫和狗，但有特殊的收养规则，收养人有两种收养方式，第一种为直接收养所有动物中最早进入收容所的，
第二种为选择收养的动物类型（猫或狗），并收养该种动物中最早进入收容所的。
给定一个操作序列int[][2] ope(C++中为vector<vector<int>>)代表所有事件。若第一个元素为1，则代表有动物进入收容所，
第二个元素为动物的编号，正数代表狗，负数代表猫；若第一个元素为2，则代表有人收养动物，第二个元素若为0，则采取第一种收养方式，
若为1，则指定收养狗，若为-1则指定收养猫。请按顺序返回收养的序列。若出现不合法的操作，即没有可以符合领养要求的动物，则将这次领养操作忽略。
测试样例：
[[1,1],[1,-1],[2,0],[2,-1]]
返回：[1,-1]

* \问题分析：
思路：定义两个vector<int>对象A和B，分别用于存放收容所里的动物和被收养的动物
操作如下：
对ope数组从按行从i = 0 ~ ope.size() -1遍历
1、指令为1（ope[i][0] = 1）时，即有动物进来，则将动物序号压入A--执行A.push_back(ope[i][1]);
2、指令为2（ope[i][0] = 2）时，即有动物被收养，此时首先判断A是否为空，即是否有动物
1）如果A为空，则continue
2）如果A不为空
1.如果操作为ope[i][1] = 0，即收养最先进来的动物，则将A[0]压入B，执行B.push_back(A[0])，然后在A中删除对应元素，即执行A.erase(A.begin())；
2.如果操作为ope[i][1] = 1，即收养最先进来的狗，此时遍历A找到第一个狗，然后将找到的元素压入B，再在A中删除对应元素；
3.如果操作为ope[i][1] = -1，即收养最先进来的猫，此时遍历A找到第一个猫，然后将找到的元素压入B，再在A中删除对应的元素。
遍历完成之后，返回B。


*****************************************************/
#include <iostream>
using namespace std;
#include <vector>
class CatDogAsylum {
public:
	vector<int> asylum(vector<vector<int> > ope) {
		// write code here
		int len = ope.size();
		vector<int> ans, in;
		if (len==0)
		{
			return ans;
		}
		for (int i = 0; i < len;i++)
		{
			if (ope[i][0]==1)  //有动物来收容所
			{
				in.push_back(ope[i][1]);
			}
			else if (ope[i][0]==2)  //	有人收养
			{
				if (in.empty())
				{
					continue;
				}
				if (ope[i][1]==0)  //第一种收养方式，取第一个
				{
					ans.push_back(in[0]);
					in.erase(in.begin());
				}
				else if (ope[i][1]==1)  //指定养狗
				{
					for (int i = 0; i < in.size();i++)
					{
						if (in[i]>0)
						{
							ans.push_back(in[i]);
							in.erase(in.begin()+i);
							break;
						}
					}
				}else if (ope[i][1]==-1) //指定养猫
				{
					for (int i = 0; i < in.size();i++)
					{
						if (in[i]<0)
						{
							ans.push_back(in[i]);
							in.erase(in.begin()+i);
							break;
						}
					}
				}
			}
		}
		return ans;
	}
};


//////////////////////////////////////////////////////////////////////////
//题目分析：
//根据先进先出的原则，自然想到了用队列实现，如果只维护一个队列，那么第一种方法实现起来比较简单，只需要取出队头的动物则可以，
//但是第二种方法就比较复杂，需要访问整个队列来找出第一个被访问的猫或者狗。

//因此我们可以选择维护两个队列来实现，一个队列存放放入的狗，一个队列存放放入的猫，对于第二种方法实现起来相当容易，
//我们只需要根据要选择的猫或者狗从相应的队列中取出便可以，但是第一种方法需要判断那个两个队列头部的是猫先进入收容所，还是狗先进入，
//这个时候需要一个标志，所以我们每次把动物放入队列的时候，同时将一个递增的序号放入队列，这个序号就是一个时间序列，根据这个序号便可以轻松实现第一种方法。
//《程序员面试金典》--题目详解：
//http ://blog.csdn.net/zdplife/article/category/5799903
//////////////////////////////////////////////////////////////////////
#include <queue>
class CatDogAsylum {
public:
	vector<int> asylum(vector<vector<int> > ope) {
		// write code here
		queue<int> cat;
		queue<int> dog;
		vector<int> vec;
		int index = 0;
		int size1 = ope.size();
		for (int i = 0; i < size1; i++)
		{
			int kind = ope[i][0];
			if (kind == 1)  //有动物来收容所
			{
				if (ope[i][1] >= 0) //狗队列
				{
					dog.push(index++);  //标记谁是自一个进入
					dog.push(ope[i][1]);
				}
				else
				{
					cat.push(index++);  //猫队列 
					cat.push(ope[i][1]);
				}
			}
			else    //有人收养
			{
				if (ope[i][1] == 0)  //收养最先进来的动物
				{
					int min = 0;
					if (cat.empty() && !dog.empty())  //dog不为空
						min = 1;
					if (!cat.empty() && dog.empty())
						min = -1;
					if (!cat.empty() && !dog.empty())
						min = dog.front() > cat.front() ? -1 : 1;
					if (min == -1)  //收养猫
					{
						cat.pop();
						vec.push_back(cat.front());
						cat.pop();
					}
					if (min == 1)  //收养狗
					{
						dog.pop();
						vec.push_back(dog.front());
						dog.pop();
					}
				}
				else
				{
					if (ope[i][1] == 1 && !dog.empty())  //收养狗
					{
						dog.pop();
						vec.push_back(dog.front());
						dog.pop();
					}
					if (ope[i][1] == -1 && !cat.empty()) //收养猫
					{
						cat.pop();
						vec.push_back(cat.front());
						cat.pop();
					}
				}

			}
		}
		return vec;
	}
};