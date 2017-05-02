// ToutiaoOnlineTest4.cpp : 定义控制台应用程序的入口点。
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

/*给定两个长度为 n 的整数数列 A 和 B。再给定 q 组查询，每次查询给出两个整数 x 和 y，求满足 Ai >= x 且 Bi >= y 这样的 i 的数量。
输入
第一行给定两个整数 n 和 q。
第二行给定数列 A，包含 n 个整数。
第三行给定数列 B，包含 n 个整数。
接下来 q 行，每行两个整数 x 和 y，意义如上所述。
输出
对于每组查询，输出所求的下标数量。

样例输入
3 2
3 2 4
6 5 8
1 1
4 8
样例输出
3
1

Hint
数据规模
对于 30% 的数据，1 <= n, q <= 100。
对于 100% 的数据，1 <= n, q, Ai, Bi <= 10^5。
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

