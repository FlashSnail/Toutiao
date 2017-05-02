// ToutiaoOnlineTest1.cpp : 定义控制台应用程序的入口点。
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

/*按数组的形式给出函数f(x)的取值，即数组A的A[0]元素为f(0)的取值，数组的取值都为整数，
函数在每个点都是严格单调递增或者严格递减（即A[i-1] != A[i] != A[i+1]），
要求找出最宽的先上升后下降的区间（这个区间内函数的值必须先上升到一个点然后下降，区间的上升段和下降段长度必须都大于0）。
1. 如果找到符合条件的最大区间输出数组对应的左右下标（有多个最大区间时，输出最左边的那个”）
2. 找不到那么输出-1 -1
输入
n
n长度的整数数组
输出
区间的范围

样例输入
10
1 3 1 2 5 4 3 1 9 10
样例输出
2 7

Hint
数据规模
对于 100% 的数据，1 <=n <=10, 000, 000*/

int _tmain(int argc, _TCHAR* argv[])
{
	long long n;
	vector<int> array;			//存放数字数组
	vector<int>::iterator iter;
	int num;
	vector<int> len;			//存放满足题意的所有长度
	vector<int> top;			//记录波峰的索引
	vector<int> low;			//记录波谷的索引
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
			while ((index < size - 1) && (array[index] < array[index + 1]))		//单调增的情况
			{
				len.back()++;
				index++;				
			}
			top.back() = index;			//单调增结束，记录其位置：波峰
			while ((index < size - 1) && (array[index] > array[index + 1]))		//单调减的情况
			{
				len.back()++;
				index++;
			}
			low.back() = index;			//单调减结束，记录其位置：波谷
			len.push_back(0);			//初始化这三个数组，推入新的值，准备存放下一个波峰波谷和长度
			top.push_back(0);
			low.push_back(0);
		}
		iter = std::max_element(begin(len), end(len));	//找到长度中最长的
		int pos = std::distance(begin(len), iter);		//找到他的索引，对应的去找该索引的波峰波谷位置
		if (top[0] == size-1 || (top[0]==0&&low[0]==size-1))	//这是个临界条件，即只单调增和只单调减的情况
		{
			cout << "-1 -1" << endl;
		}
		else if (pos == 0)				//这也是临界条件，如果第一个长度就是最长的，那么就不存在上一个波谷，手动输出索引0
		{
			cout << "0" << " " << low[pos] << endl;
		}
		else                         //长度就是两个波谷的距离，那索引自然是这个波谷和上个波谷的索引
		{
			cout << low[pos - 1] << " " << low[pos] << endl;
		}		
		len.clear();		//这个序列找完了，清空，为下个序列做准备
		top.clear();
		low.clear();
		array.clear();
	}
	
	system("pause");
	return 0;
}

