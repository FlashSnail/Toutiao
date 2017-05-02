// ToutiaoOnlineTest4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

/*������������Ϊ n ���������� A �� B���ٸ��� q ���ѯ��ÿ�β�ѯ������������ x �� y�������� Ai >= x �� Bi >= y ������ i ��������
����
��һ�и����������� n �� q��
�ڶ��и������� A������ n ��������
�����и������� B������ n ��������
������ q �У�ÿ���������� x �� y����������������
���
����ÿ���ѯ�����������±�������

��������
3 2
3 2 4
6 5 8
1 1
4 8
�������
3
1

Hint
���ݹ�ģ
���� 30% �����ݣ�1 <= n, q <= 100��
���� 100% �����ݣ�1 <= n, q, Ai, Bi <= 10^5��
*/

int _tmain(int argc, _TCHAR* argv[])
{
	int n, q;
	vector<long long> A;
	vector<long long> B;
	long long num_a;
	long long num_b;
	vector<int> x;
	vector<int> y;
	int s;
	int ans = 0;
	while (cin>>n>>q)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> num_a;
			A.push_back(num_a);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> num_b;
			B.push_back(num_b);
		}
		for (int i = 0; i < q; i++)
		{
			cin >> s;
			x.push_back(s);
		}
		for (int i = 0; i < q; i++)
		{
			cin >> s;
			y.push_back(s);
		}
		for (int i = 0; i < q; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (A[j] >= x[q] && B[j] >= y[q])
				{
					ans++;
				}
			}	
			cout << ans << endl;
		}	
		
	}
	return 0;
}

