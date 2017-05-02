// TouTiaoSecond1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

/*题目描述：
给两个整数(int)数组，输出相同的元素。
输入
给定两个整型数组[a1, a2, ...., am]，[b1, b2, ..., bn]
输入格式如下，第一行给定第一个数组的大小m，接下来的m行为其数组元素a1 -- am，每行一个元素；第m+1行为第二个数组的大小n，
接下来的n行为其数组元素b1 -- bn，也是每行一个元素。示例如下：
m
a1
a2
…
am
n
b1
b2
…
bn
​
输出
两个数组中相同的元素，以空格分隔在一行中显示，显示顺序为其在第二个数组中出现的顺序。

样例输入
5
11
15
9
12
3
4
11
3
9
7

样例输出
11 3 9*/

int _tmain(int argc, _TCHAR* argv[])
{
	int m, n;
	vector<int> a;
	vector<int> b;
	int temp;
	vector<int> ans;
	while (cin>>m)
	{
		int hash[100000] = { 0 };
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			a.push_back(temp);
			if (hash[temp] == 0)
			{
				hash[temp]++;
			}			
		}
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (hash[temp] >= 1)
			{
				ans.push_back(temp);
			}
			b.push_back(temp);			
		}
		if (!ans.empty())
		{
			for (int i = 0; i < ans.size() - 1; i++)
			{
				cout << ans[i] << " ";
			}
			cout << ans.back() << endl;
			a.clear();
			b.clear();
			ans.clear();
		}		
	}
	system("pause");
	return 0;
}

