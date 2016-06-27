//��Ŀ����
//
//����һ�����������һ���㷨����Ԫ�ذ���֮�����δ�ӡ�������������
//����һ����������mat���Լ�����ά��nxm���뷵��һ�����飬����Ԫ������Ϊ��ӡ�����֡�
//����������
//[[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]], 4, 3
//���أ�[1, 2, 3, 6, 5, 4, 7, 8, 9, 12, 11, 10]


//����һ����־λ���߷���ż�����ɡ�
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



//��Ŀ����
//
//��һ��NxN�����������дһ���㷨��������˳ʱ����ת90�ȡ�
//����һ��NxN�ľ��󣬺;���Ľ���N, �뷵����ת���NxN����, ��֤NС�ڵ���300��
//����������
//[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 3
//���أ�[[7, 4, 1], [8, 5, 2], [9, 6, 3]]

#include <iostream>
using namespace std;
#include <vector>
//����һ���б任->�ζԽ��߱任  ����  �ζԽ��߱任->�б任
//��������һ��һ��ȡ��Ȼ���ٵ��ŷ�
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



//��Ŀ����
//
//����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�ء�
//����int����mat, �Լ�����ά��nxm���뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�������
//����������
//[[1, 2], [3, 4]], 2, 2
//���أ�[1, 2, 4, 3]


class Printer {
	vector<int> vc;
public:
	void printCircle(vector<vector<int> > mat,int x1, int y1,int x2,int y2)  //����һ����ӡһȦ�ĺ���
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
			return;   //������������Ȼ���ܼ���ִ������ĺ������ض����ݡ�
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


	//������
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
				//for (int j = 0; j < endY-startX;j++) //����
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
			//���Ƴ���һ�����һ��Ԫ�ص����е�һ��Ԫ��
			for (; j<endY; j++)
				vc.push_back(mat[i][j]);
			//���Ƴ���һcolumn���һ��Ԫ�ص����е�һcolumnԪ��
			for (; i<endX; i++)
				vc.push_back(mat[i][j]);
			//���Ƴ�lastһ�����һ��Ԫ�ص�����Ԫ��
			for (; j>startX; j--)
				vc.push_back(mat[i][j]);
			//���Ƴ���һlie���һ��Ԫ�ص�����Ԫ��
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