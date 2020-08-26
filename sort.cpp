/*************************************************************************
	> File Name: sort.cpp
	> Author: zhangning
	> Mail: amoscykl@163.com 
	> Created Time: 2020年08月26日 星期三 14时31分30秒
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 用于便利vector
 * 
 * @param list 输入的动态数组
 */
void print(vector<int> &list)
{
	for (auto a : list)
	{
		cout << a << ",";
	}
	cout << endl;
}

/**
 * @brief 进行交换操作
 * 
 * @param a 输入的数a
 * @param b 输入的数b
 */
void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
/**
 * @brief  用于冒泡排序的升序操作
 * 
 * @param first 
 * @param second 
 * @return true 表示没有进行交换操作
 * @return false 表示有进行交换操作
 */
bool up_type(int &first, int &second)
{
	if (first <= second)
	{
		//ok
		return true;
	}
	else
	{
		swap(first, second);
		return false;
	}
}
/**
 * @brief 用于冒泡排序的降序操作
 * 
 * @param first 
 * @param second 
 * @return true 表示没有进行交换操作
 * @return false 表示有进行交换操作
 */
bool down_type(int &first, int &second)
{
	if (first >= second)
	{
		//ok
		return true;
	}
	else
	{
		swap(first, second);
		return false;
	}
}

/**
 * @brief 冒泡排序
 * 
 * @param list  输入的数组
 * @param flag 　flag = 0　表示升序　flag=1 表示降序 默认值 0
 * @return vector<int> 返回一个排好序的数组
 */
vector<int> bubble_sort(vector<int> &list, int flag = 0)
{
	vector<int> result;
	result.clear();

	if (list.size() == 0)
	{
		return result;
	}

	result = list;

	for (int i = 0; i < result.size() - 1; i++)
	{
		bool flag_tmp = true;
		for (int j = 0; j < result.size() - 1 - i; j++)
		{
			if (flag == 0)
			{
				flag_tmp = up_type(result[j], result[j + 1]);
			}
			else if (flag == 1)
			{
				flag_tmp = down_type(result[j], result[j + 1]);
			}
			else
			{
				cout << "line " << __LINE__ << ":flag value not right\n";
				exit(1);
			}
		}
		if (flag_tmp)
			break;
		cout<<"排序次数:"<<i<<endl;
		print(result);
	}
}

int main()
{

	vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8};

	auto new_list = bubble_sort(list);
	auto new_list_1 = bubble_sort(list,1);
	auto new_list_2 = bubble_sort(list, 2);
}
