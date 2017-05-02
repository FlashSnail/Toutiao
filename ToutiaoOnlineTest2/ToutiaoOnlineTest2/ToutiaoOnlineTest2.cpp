// ToutiaoOnlineTest2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
using namespace std;
/*给定一个段落，由 N 个句子组成。第 i 个句子的长度为 L[i]，包含的单词个数为 W[i]。
句子不包含任何除字母和空格( ) 外的符号。
每个句子内部，含有若干个单词，由空格( ) 分隔。句子不会包含连续的空格。
 
随后给定 M 个查询，每个查询包含一个句子，需要在段落中寻找相同单词数量最多的句子。重复的单词只计一次，且不区分大小写。
输入数据将保证结果是存在且唯一的。
输入
第一行是两个整数 N 和 M。
接下来的 N+M 行，每行包含一个句子。
前 N 行代表段落中的句子，后 M 行表示查询。
输出
输出 M 行，每行代表查询的结果。

样例输入
6 3
An algorithm is an effective method that can be expressed within a finite amount of space and time
Starting from an initial state and initial input the instructions describe a computation
That when executed proceeds through a finite number of successive states
Eventually producing output and terminating at a final ending state
The transition from one state to the next is not necessarily deterministic
Some algorithms known as randomized algorithms incorporate random input
Next to the transition
Wormhole infinite time and space
The transition from one state to the next is not necessarily deterministic

样例输出
The transition from one state to the next is not necessarily deterministic
An algorithm is an effective method that can be expressed within a finite amount of space and time
The transition from one state to the next is not necessarily deterministic

Hint
数据规模
0 < L[i] < 512
0 < W[i] < 32
对于 30% 的数据，0 < N < 30，0 < M < 30。
对于 100% 的数据，0 < N <= 600，0 < M <= 800。
*/

int _tmain(int argc, _TCHAR* argv[])
{
	int n, m;
	char L[512];
	vector<string> La;
	char M[512];
	vector<string> Ma;
	while (cin >> n)
	{
		cin >> m;
		cin.get();
		vector<vector<string>> W(n);
		vector<vector<string>> A(m);
		vector<set<string>> S(n);
		vector<int> ans(n);
		set<string>::iterator iter;
		vector<int>::iterator biggest;
		for (int i = 0; i < n; i++)
		{
			cin.getline(L, 512);
			La.push_back(L);
			transform(La.back().begin(), La.back().end(), La.back().begin(), ::tolower);
		}
		for (int i = 0; i < m; i++)
		{
			cin.getline(M, 512);
			Ma.push_back(M);
			transform(Ma.back().begin(), Ma.back().end(), Ma.back().begin(), ::tolower);
		}
		int w_num = 0;
		int first;
		for (int i = 0; i < n; i++)		//分割L句子的单词，存入W
		{
			first = 0;
			for (int j = 0; j < La[i].length(); j++)
			{
				if (La[i][j] == ' ')
				{
					W[i].push_back(La[i].substr(first, j - first));
					first = j + 1;
				}
			}
			W[i].push_back(La[i].substr(first, La[i].length() - 1));
		}

		for (int i = 0; i < m; i++)		//分割M句子的单词，存入A
		{
			first = 0;
			for (int j = 0; j < Ma[i].length(); j++)
			{
				if (Ma[i][j] == ' ')
				{
					A[i].push_back(Ma[i].substr(first, j - first));
					first = j + 1;
				}
			}
			A[i].push_back(Ma[i].substr(first, Ma[i].length() - 1));
		}

		for (int i = 0; i < n; i++)		//句子L的单词集
		{
			for (int j = 0; j < W[i].size(); j++)
			{
				S[i].insert(W[i][j]);
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int z = 0; z < A[i].size(); z++)
				{
					iter = S[j].find(A[i][z]);
					if (iter!=S[j].end())
					{
						ans[j]++;
					}
				}				
			}
			biggest = std::max_element(std::begin(ans), std::end(ans));
			int index = std::distance(std::begin(ans), biggest);
			cout << La[index] << endl;
			ans.clear();
			ans.resize(n);
		}

		La.clear();
		Ma.clear();
		W.clear();
		A.clear();
		S.clear();
		ans.clear();
	}
	
	system("pause");
	return 0;
}
