#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<random>
#include<string>

int getRandm(int max, int min);	//���������������[b,a]������
int operatioSymbol(bool multy);	//�������true��false
std::string toString(int n);		//��int ��������תΪstring����
int toInt(std::string a);	//��string��������תΪint����


////������������///////
int getRandm(int max, int min)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	int random_val = mt();	//������������
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

std::string toString(int n)		//��int ��������תΪstring����
{
	std::string s= std::to_string(n);
	return s;
}

int toInt(std::string a)	//��string��������תΪint����
{
	int c = atoi(a.c_str());
	return c;
}
