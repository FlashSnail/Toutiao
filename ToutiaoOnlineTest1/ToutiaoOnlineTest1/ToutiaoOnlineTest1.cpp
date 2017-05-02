// ToutiaoOnlineTest1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

/*���������ʽ��������f(x)��ȡֵ��������A��A[0]Ԫ��Ϊf(0)��ȡֵ�������ȡֵ��Ϊ������
������ÿ���㶼���ϸ񵥵����������ϸ�ݼ�����A[i-1] != A[i] != A[i+1]����
Ҫ���ҳ��������������½������䣨��������ں�����ֵ������������һ����Ȼ���½�������������κ��½��γ��ȱ��붼����0����
1. ����ҵ��������������������������Ӧ�������±꣨�ж���������ʱ���������ߵ��Ǹ�����
2. �Ҳ�����ô���-1 -1
����
n
n���ȵ���������
���
����ķ�Χ

��������
10
1 3 1 2 5 4 3 1 9 10
�������
2 7

Hint
���ݹ�ģ
���� 100% �����ݣ�1 <=n <=10, 000, 000*/

int _tmain(int argc, _TCHAR* argv[])
{
	long long n;
	vector<int> array;			//�����������
	vector<int>::iterator iter;
	int num;
	vector<int> len;			//���������������г���
	vector<int> top;			//��¼���������
	vector<int> low;			//��¼���ȵ�����
	int index;
	while (cin>>n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			array.push_back(num);		
		}
		int size = array.size();		
		len.push_back(0);
		index = 0;		
		top.push_back(0);		
		low.push_back(0);
		while (index<size-1)
		{
			while ((index < size - 1) && (array[index] < array[index + 1]))		//�����������
			{
				len.back()++;
				index++;				
			}
			top.back() = index;			//��������������¼��λ�ã�����
			while ((index < size - 1) && (array[index] > array[index + 1]))		//�����������
			{
				len.back()++;
				index++;
			}
			low.back() = index;			//��������������¼��λ�ã�����
			len.push_back(0);			//��ʼ�����������飬�����µ�ֵ��׼�������һ�����岨�Ⱥͳ���
			top.push_back(0);
			low.push_back(0);
		}
		iter = std::max_element(begin(len), end(len));	//�ҵ����������
		int pos = std::distance(begin(len), iter);		//�ҵ�������������Ӧ��ȥ�Ҹ������Ĳ��岨��λ��
		if (top[0] == size-1 || (top[0]==0&&low[0]==size-1))	//���Ǹ��ٽ���������ֻ��������ֻ�����������
		{
			cout << "-1 -1" << endl;
		}
		else if (pos == 0)				//��Ҳ���ٽ������������һ�����Ⱦ�����ģ���ô�Ͳ�������һ�����ȣ��ֶ��������0
		{
			cout << "0" << " " << low[pos] << endl;
		}
		else                         //���Ⱦ����������ȵľ��룬��������Ȼ��������Ⱥ��ϸ����ȵ�����
		{
			cout << low[pos - 1] << " " << low[pos] << endl;
		}		
		len.clear();		//������������ˣ���գ�Ϊ�¸�������׼��
		top.clear();
		low.clear();
		array.clear();
	}
	
	system("pause");
	return 0;
}

