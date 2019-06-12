// Testconvex.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

#define DIM 2

template <class T>
#define T int
class CBox
{
public:
	int m_pmin[DIM], m_pmax[DIM];

public:
	CBox()
	{
		m_pmin[0] = 0;
		m_pmax[0] = -1;
	}
	bool IsNull()
	{
		return m_pmin[0] > m_pmax[0];
	}
	void AddPoint(T pt[DIM])
	{
		int i;
		if (IsNull())
		{
			for (i = 0; i < DIM; i++)
			{
				m_pmin[i] = m_pmax[i] = pt[i];
			}
			return;
		}
		for (i = 0; i < DIM; i++)
		{
			if (pt[i] < m_pmin[i])
				m_pmin[i];
			else if (pt[i] > m_pmax[i])
				m_pmax[i] = pt[i];
		}
	}
	void AddBox(CBox bx)
	{
		AddPoint(bx.m_pmin);
		AddPoint(bx.m_pmax);
	}
	int InSide(T pt[DIM])
	{
		int i;
		for (i = 0; i < DIM; i++)
		{
			if (pt[i] < m_pmin[i] || pt[i] > m_pmax[i])
				return 0;
		}
		return 1;
	}
	void Output()
	{
		int i;

		cout << "<";
		for (i = 0; i < DIM; i++)
		{
			cout << "  " << m_pmin[i] << "  ";
		}
		cout << "> ";

		cout << "<";
		for (i = 0; i < DIM; i++)
		{
			cout << "  " << m_pmax[i] << "  ";
		}
		cout << "> ";
	}
};

int main()
{

	CBox<int> bx;
	int pt[2] = { 1,2 }, qt[2] = { 4, 8 };
	bx.AddPoint(pt);
	bx.AddPoint(qt);
	bx.Output();

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
