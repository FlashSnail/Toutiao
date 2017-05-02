// TouTiaoSecond2.cpp : �������̨Ӧ�ó������ڵ㡣
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

/*�ջ�Ծ�û��� (DAU) �Ǻ���һ����Ʒ���ֵ���Ҫָ�ꡣ
��Ҫ��д���򣬸��ݸ�����ĳһ��� N �����ʼ�¼���Ե�����û����� M ����ͳ�ơ�
ÿ���û����ܷ��ʶ�Ρ�
Ϊ�˷��㣬���������� (uid) Ψһ��ʶÿ���û���
����
ÿһ�а���һ�� uid������ 0 ʱ��Ϊ���������
���빲���� N+1 �У�����Ϊ������ġ�
���
һ�����֣�ȥ�غ� uid ������ M��

��������
12933
111111
59220
69433
59220
111111
0
�������
4

Hint
���ݷ�Χ
0 < uid < 2^63
���� 30% �����ݣ�0 < N < 100,000, 0 < M < 100,000
���� 100% �����ݣ�0 < N < 1,000,000, 0 < M < 800,000*/

int _tmain(int argc, _TCHAR* argv[])
{
	long long uid;
	set<long long> user;
	while (cin>>uid)
	{
		if (uid != 0)
		{
			user.insert(uid);
		}
		else
		{
			cout << user.size() << endl;
			user.clear();
		}		
	}
	system("pause");
	return 0;
}

