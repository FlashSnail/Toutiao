// ToutiaoOnlineTest2.cpp : �������̨Ӧ�ó������ڵ㡣
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
/*����һ�����䣬�� N ��������ɡ��� i �����ӵĳ���Ϊ L[i]�������ĵ��ʸ���Ϊ W[i]��
���Ӳ������κγ���ĸ�Ϳո�( ) ��ķ��š�
ÿ�������ڲ����������ɸ����ʣ��ɿո�( ) �ָ������Ӳ�����������Ŀո�
 
������ M ����ѯ��ÿ����ѯ����һ�����ӣ���Ҫ�ڶ�����Ѱ����ͬ�����������ľ��ӡ��ظ��ĵ���ֻ��һ�Σ��Ҳ����ִ�Сд��
�������ݽ���֤����Ǵ�����Ψһ�ġ�
����
��һ������������ N �� M��
�������� N+M �У�ÿ�а���һ�����ӡ�
ǰ N �д�������еľ��ӣ��� M �б�ʾ��ѯ��
���
��� M �У�ÿ�д����ѯ�Ľ����

��������
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

�������
The transition from one state to the next is not necessarily deterministic
An algorithm is an effective method that can be expressed within a finite amount of space and time
The transition from one state to the next is not necessarily deterministic

Hint
���ݹ�ģ
0 < L[i] < 512
0 < W[i] < 32
���� 30% �����ݣ�0 < N < 30��0 < M < 30��
���� 100% �����ݣ�0 < N <= 600��0 < M <= 800��
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
		for (int i = 0; i < n; i++)		//�ָ�L���ӵĵ��ʣ�����W
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

		for (int i = 0; i < m; i++)		//�ָ�M���ӵĵ��ʣ�����A
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

		for (int i = 0; i < n; i++)		//����L�ĵ��ʼ�
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
