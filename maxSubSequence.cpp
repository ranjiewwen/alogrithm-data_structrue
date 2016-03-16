//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
////常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
////并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？
//
//// 当我们加上一个正数时，和会增加；当我们加上一个负数时，和会减少。如果当前得到的和是个负数，
////那么这个和在接下来的累加中应该抛弃并重新清零，不然的话这个负数将会减少接下来的和
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.size() == 0) return 0;
//		int sum1 = array[0];
//		int temp = array[0];
//		for (int i = 1; i<array.size(); i++){
//			//temp为当前数组的和，当求和小于0时，重新选择求和起点
//			//只要有负数，temp就会减少，此时sum1>temp;当减少为负数时，temp重新赋值；直到遇到正数时，又开始求和
//			temp = (temp<0 ? array[i] : array[i] + temp);
//			sum1 = max(sum1, temp);//sum1暂时求得的和，如果后面有比sum1大的求和值，则取而代之
//		}
//		return sum1;
//	}
//};

//C实现

//输入：
//输入有多组数据, 每组测试数据包括两行。
//第一行为一个整数n(0 <= n <= 100000), 当n = 0时, 输入结束。接下去的一行包含n个整数(我们保证所有整数属于[-1000, 1000])。
//输出：
//对应每个测试案例, 需要输出3个整数单独一行, 分别表示连续子向量的最大和、该子向量的第一个元素的下标和最后一个元素的下标。
//若是存在多个子向量, 则输出起始元素下标最小的那个。
//
//#include<stdio.h>
//#include<stdlib.h>
//void main()
//{
//	int curSum, maxSum, start, end,n;
//	int index=0;
//	int *pData;
//	scanf("%d",&n);
//	while (n)
//	{
//		pData = (int*)malloc(sizeof(int)*n);
//		for (size_t i = 0; i < n; i++)
//		{
//			scanf("%d", &pData[i]);
//		}
//		curSum = maxSum = pData[0];
//		start = end = 0;
//		for (size_t i = 1; i < n; i++)
//		{
//			if (curSum<0)
//			{
//				curSum = 0;
//				index=i;//记录此时重新开始的位置
//			}
//			curSum += pData[i];
//			if (curSum>maxSum)
//			{
//				maxSum = curSum;
//				end = i;//结束的位子
//				start = index;//开始的位置
//			}
//		}
//		printf("%d,%d,%d\n",maxSum,start,end);
//		free(pData);
//		scanf("%d",&n);//开始重新循环
//	}
//}

//C++
#include<iostream>
using namespace std;
void main()
{
	int curSum, maxSum, start, end, n;
	int index=0;
	cin >> n;
	while (n)
	{
		int *pData = new int[n];//不确定大小时，有内存溢出的现象
		for (size_t i = 0; i < n; i++)
		{
			cin >> pData[i];
		}
		curSum = maxSum = pData[0];
		start = end = 0;
		for (size_t i = 1; i < n; i++)
		{
			if (curSum<0)
			{
				curSum = 0;
				index = i;//记录此时重新开始的位置
			}
			curSum += pData[i];
			if (curSum>maxSum)
			{
				maxSum = curSum;
				end = i;//结束的位子
				start = index;//开始的位置，当没有经过curSum<0时，index要初始化
			}
		}
		cout << maxSum << "  " << start << "  " << end << endl;
		delete[] pData;
		cin>>n;//开始重新循环
	}
}