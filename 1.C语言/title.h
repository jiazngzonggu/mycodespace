#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<random>
#include<string>

int getRandm(int max, int min);	//用来生成随机数在[b,a]区间内
int operatioSymbol(bool multy);	//随机生成true或false
std::string toString(int n);		//将int 类型数据转为string类型
int toInt(std::string a);	//将string类型数据转为int类型


////函数定义区间///////
int getRandm(int max, int min)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	int random_val = mt();	//用来存放随机数
	if (random_val < 0)
	{
		getRandm(max, min);
	}
	else
	{
		return random_val % (max + 1) + min;
	}
	return 0;
}

int operatioSymbol(bool multy)
{
	int result;
	if (multy == true)
	{
		result = getRandm(4, 0);
	}
	if (multy == false)
	{
		result = getRandm(2, 0);
	}
	return result;
}

std::string toString(int n)		//将int 类型数据转为string类型
{
	std::string s= std::to_string(n);
	return s;
}

int toInt(std::string a)	//将string类型数据转为int类型
{
	int c = atoi(a.c_str());
	return c;
}
