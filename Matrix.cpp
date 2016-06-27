//题目描述
//
//对于一个矩阵，请设计一个算法，将元素按“之”字形打印。具体见样例。
//给定一个整数矩阵mat，以及他的维数nxm，请返回一个数组，其中元素依次为打印的数字。
//测试样例：
//[[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]], 4, 3
//返回：[1, 2, 3, 6, 5, 4, 7, 8, 9, 12, 11, 10]


//设置一个标志位或者分奇偶数即可。
#include <iostream>
using namespace std;
#include <vector>

class Printer {
public:
	vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> vc;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < m; j++)
				{
					vc.push_back(mat[i][j]);
				}
			}
			else
			{
				for (int j = m - 1; j >= 0; j--)
				{
					vc.push_back(mat[i][j]);
				}
			}
		}
		return vc;
	}
};



//题目描述
//
//有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。
//给定一个NxN的矩阵，和矩阵的阶数N, 请返回旋转后的NxN矩阵, 保证N小于等于300。
//测试样例：
//[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 3
//返回：[[7, 4, 1], [8, 5, 2], [9, 6, 3]]

#include <iostream>
using namespace std;
#include <vector>
//方法一：列变换->次对角线变换  或者  次对角线变换->列变换
//方法二：一列一列取，然后再倒着放
class Rotate {
public:
	vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
		// write code here
		vector<vector<int> > res;
		for (int i = 0; i < n;i++)
		{
			vector<int> vc;
			for (int j = n - 1; j >= 0;j--)
			{
				vc.push_back(mat[j][i]);
			}
			res.push_back(vc);
			vc.clear();
		}
		return res;
	}

	vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
		// write code here
		vector<vector<int> > a(n, vector<int>(n));
		int i, j;
		for (i = 0; i < n; i++)
		for (j = n - 1; j >= 0; j--)
		{
			a[i][n - j - 1] = mat[j][i];
		}
		return a;
	}
};



//题目描述
//
//对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。
//给定int矩阵mat, 以及它的维数nxm，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。
//测试样例：
//[[1, 2], [3, 4]], 2, 2
//返回：[1, 2, 4, 3]


class Printer {
	vector<int> vc;
public:
	void printCircle(vector<vector<int> > mat,int x1, int y1,int x2,int y2)  //定义一个打印一圈的函数
	{
		if (x1==x2&&y1==y2)
		{
			vc.push_back(mat[x1][y1]);
			return;
		}
		else if (x1==x2&&y1!=y2)
		{
			for (int y = y1; y <= y2;y++)
			{
				vc.push_back(mat[x1][y]);
			}
			return;   //跳出函数，不然可能继续执行下面的函数，重读数据。
		}
		else if (y1==y2&&x1!=x2)
		{
			for (int x = x1; x <= x2;x++)
			{
				vc.push_back(mat[x][y1]);
			}
			return;
		}
		for (int y = y1; y < y2;y++)
		{
			vc.push_back(mat[x1][y]);
		}
		for (int x = x1; x < x2;x++)
		{
			vc.push_back(mat[x][y2]);
		}
		for (int y= y2; y>y1;y--)
		{
			vc.push_back(mat[x2][y]);
		}
		for (int x = x2; x > x1;x--)
		{
			vc.push_back(mat[x][y1]);
		}
	}
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		int startX = 0, startY = 0;
		int endX = n - 1, endY = m - 1;
		while (startX <= endX&&startY <= endY)
		{
			printCircle(mat, startX, startY, endX, endY);
			startX++;
			startY++;
			endX--;
			endY--;
		}
		return vc;
	}


	//方法二
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> vc;
		int startX = 0, startY = 0;
		int endX = n - 1, endY = m - 1;
		int i = 0, j = 0;
		while (startX<=endX&&startY<=endY)
		{
			if (startX==endX)
			{
				//for (int j = 0; j < endY-startX;j++) //错误
				for (; j <= endY; j++)
				{
					vc.push_back(mat[startX][j]);
				}
				return vc;
			}
			if (startY==endY)
			{
				for (; i <= endX ;i++)
				{
					vc.push_back(mat[i][startY]);
				}
				return vc;
			}
			//复制除第一行最后一个元素的所有第一行元素
			for (; j<endY; j++)
				vc.push_back(mat[i][j]);
			//复制除第一column最后一个元素的所有第一column元素
			for (; i<endX; i++)
				vc.push_back(mat[i][j]);
			//复制除last一行最后一个元素的所有元素
			for (; j>startX; j--)
				vc.push_back(mat[i][j]);
			//复制除第一lie最后一个元素的所有元素
			for (; i>startY; i--)
				vc.push_back(mat[i][j]);

			startX++;
			startY++;
			endX--;
			endY--;
			i++;
			j++;
		}
		return vc;
	}
};