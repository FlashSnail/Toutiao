// TouTIaoSecond3.cpp : 定义控制台应用程序的入口点。
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

/*我们有如下形式化的数字
*    ***   ***   * *   ***   ***   ***   ***   ***   ***
*      *     *   * *   *     *       *   * *   * *   * *
*    ***   ***   ***   ***   ***     *   ***   ***   * *
*    *       *     *     *   * *     *   * *     *   * *
*    ***   ***     *   ***   ***     *   ***   ***   ***
（* 下附图片供参考）

分别表示 1 2 3 4 5 6 7 8 9 0
有如下形式化的符号：
*        * *    *   ****
***  ***   *    *
*        * *  *     ****   **
**
​（* 下附图片供参考）

分别表示 + -*／ = 小数点
输入
现在 将输入一个算式
输出
你要将该算式计算之后按照上述形式化的方式输出
各个数字和符号之间空两格
无法整除则保留两位小数

样例输入
10 + 31
样例输出
*  ***       ***  *        * *  *
*  * *   *     *  *  ****  * *  *
*  * *  ***  ***  *        ***  *
*  * *   *     *  *  ****    *  *
*  ***       ***  *          *  *
​（* 下附图片供参考）


Hint
样例输入2：
2 ／ 5
样例输出2：
***       ***        ***      * *
*    *  *    ****  * *      * *
***   *   ***        * *      ***
*    *      *  ****  * *  **    *
***       ***        ***  **    *
​（* 下附图片供参考）

数据范围：
20 % 的数据 输入的数字和运算结果都是个位数
100 % 的数据保证 输入数字和答案都小于10000
100 % 的数据保证 输入数字不会出现小数
80 % 的数据保证 运算结果不会出现小数*/

int _tmain(int argc, _TCHAR* argv[])
{
	map<char, vector<string>> m;
	vector<string> num0;
	vector<string> num1;
	vector<string> num2;
	vector<string> num3;
	vector<string> num4;
	vector<string> num5;
	vector<string> num6;
	vector<string> num7;
	vector<string> num8;
	vector<string> num9;
	vector<string> plus;
	vector<string> sub;
	vector<string> mul;
	vector<string> div;
	vector<string> eco;
	vector<string> point;

	for (int i = 0; i < 5; i++)
	{
		num1.push_back("*  ");
	}

	num2.push_back("***");
	num2.push_back("  *");
	num2.push_back("***");
	num2.push_back("*  ");
	num2.push_back("***");

	num3.push_back("***");
	num3.push_back("  *");
	num3.push_back("***");
	num3.push_back("  *");
	num3.push_back("***");

	num4.push_back("* *");
	num4.push_back("* *");
	num4.push_back("***");
	num4.push_back("  *");
	num4.push_back("  *");

	num5.push_back("***");
	num5.push_back("*  ");
	num5.push_back("***");
	num5.push_back("  *");
	num5.push_back("***");

	num6.push_back("***");
	num6.push_back("*  ");
	num6.push_back("***");
	num6.push_back("* *");
	num6.push_back("***");

	num7.push_back("***");
	num7.push_back("  *");
	num7.push_back("  *");
	num7.push_back("  *");
	num7.push_back("  *");

	num8.push_back("***");
	num8.push_back("* *");
	num8.push_back("***");
	num8.push_back("* *");
	num8.push_back("***");

	num9.push_back("***");
	num9.push_back("* *");
	num9.push_back("***");
	num9.push_back("  *");
	num9.push_back("***");

	num0.push_back("***");
	num0.push_back("* *");
	num0.push_back("* *");
	num0.push_back("* *");
	num0.push_back("***");

	plus.push_back("   ");
	plus.push_back(" * ");
	plus.push_back("***");
	plus.push_back(" * ");	
	plus.push_back("   ");

	sub.push_back("   ");
	sub.push_back("   ");
	sub.push_back("***");
	sub.push_back("   ");
	sub.push_back("   ");

	mul.push_back("   ");
	mul.push_back("* *");
	mul.push_back(" * ");
	mul.push_back("* *");
	mul.push_back("   ");

	div.push_back("   ");
	div.push_back("  *");
	div.push_back(" * ");
	div.push_back("*  ");
	div.push_back("   ");

	eco.push_back("   ");
	eco.push_back("***");
	eco.push_back("   ");
	eco.push_back("***");
	eco.push_back("   ");

	point.push_back("   ");
	point.push_back("   ");
	point.push_back("   ");
	point.push_back(" **");
	point.push_back(" **");

	m['1'] = num1;
	m['2'] = num2;
	m['3'] = num3;
	m['4'] = num4;
	m['5'] = num5;
	m['6'] = num6;
	m['7'] = num7;
	m['8'] = num8;
	m['9'] = num9;
	m['0'] = num0;
	m['+'] = plus;
	m['-'] = sub;
	m['*'] = mul;
	m['/'] = div;
	m['='] = eco;
	while (1)
	{
		const int len = 40;
		char temp[len];
		cin.getline(temp, len);
		vector<char> ans;
		int i = 0;
		while (temp[i] != '\0')
		{
			if (temp[i] != ' ')
			{
				ans.push_back(temp[i]);
			}			
			i++;
		}
		for (int n = 0; n < 5; n++)
		{
			for (auto x : ans)
			{
				map<char, vector<string>>::iterator it;
				it = m.find(x);		
				cout << it->second[n] << "  ";
			}
			cout << endl;
		}

	}

	system("pause");
	return 0;
}

