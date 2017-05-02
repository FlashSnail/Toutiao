// TouTiaoSecond4.cpp : 定义控制台应用程序的入口点。
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

/*我们有一批任务在 mesos 当中。这批任务要么不依赖其它任务，要么一定恰好依赖于两个任务，并且整个依赖关系会构成一个三角模型：
 
Job(1, 1)
Job(2, 1)    Job(2, 2)
Job(3, 1)    Job(3, 2)    Job(3, 3)
……
Job(n, 1)    Job(n, 2)        ……        Job(n, n)
 
如上图，Job(1, 1) 依赖于 Job(2, 1) 和 Job(2, 2)；Job(2, 2) 依赖于 Job(3, 2) 和 Job(3, 3)；
对于任意 1 <= i < n, 1 <= j <= n，Job(i, j) 依赖于 Job(i + 1, j) 和 Job(i + 1, j + 1)。最后一行的任务没有任务依赖。
这批任务有一个特点，每个任务都需要配合它所依赖的任务来执行。也就是说，一个任务某次运行是有效的，当且仅当至少满足下列一个条件：
1. 该任务不依赖其它任务；
2. 该任务依赖的两个任务都是有效的。
每个任务都预先设定了一个权重 weight(i, j)。现在由于资源上的限制，我们只能挑选其中的 k 个任务来运行。
我们希望所有被运行的任务都是有效的，并使得所有运行过的任务的权重之和最大。
输入
第一行是两个整数 n 和 k。
接下来 n 行，其中第 i 行 (1 <= i <= n) 包含 i 个整数，给出各个任务的权重。这个三角形也同时描述了任务的依赖关系。
输出
输出仅包含一个整数，即所求的最大权重和。

样例输入
3 4
1
2 3
1 1 1
样例输出
6

Hint
对于 30% 的数据，1 <= n, k <= 50；
对于 100% 的数据，1 <= n <= 100，1 <= m <= C(n + 1, 2)，1 <= weight(i, j) <= 1000。*/

bool job(int i, int j, int n)
{
	if (i == n-1)
	{
		return true;
	}
	return job(i + 1, j, n) && job(i + 1, j, n);
}

int _tmain(int argc, _TCHAR* argv[])
{

	system("pause");
	return 0;
}

