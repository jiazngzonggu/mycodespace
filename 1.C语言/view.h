#pragma once
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

void welcomeView();	//ϵͳ��ʼ����ӭҳ��
int initView();
void loginView();	//��¼ҳ��
void registerView();	//ע��ҳ��
void mainView(string name);	//��ҳ��
void choiseError();	//ѡ�������ʾҳ��
void startAnswerView();	//��ʼ����ҳ��
void exitOrLogOutView(string name);	//ע����¼�����˳�ѡ��ҳ��
void answerView(string name, int score, int titleNumber, int lastTitleScore, int time);	//���������ʾҳ��
void stop();	//��ͣҳ��
bool isNumber(char num);	//�ж����������Ƿ�Ϊ����




void welcomeView()	//ϵͳ��ʼ����ӭҳ��
{
	cout << "************************************************************************************" << endl;
	cout << "******************************��ӭʹ����ѧ������ϰϵͳ******************************" << endl;
	cout << "************************************************************************************" << endl;
	cout << endl;

}


int initView()
{



}
void loginView()	//��¼ҳ��
{
	cout << "                       " << "��ѡ�������û���������-->" << endl;
	cout << "                       " << "���밴�س�������" << endl;
}


void registerView()	//ע��ҳ��
{
	cout << "                        " << "��һ�������û��������룬�꼶����ѧ����ѧУ-->" << endl;
	cout << "                        " << "���밴�س�������" << endl;
}

void mainView(string name)	//��ҳ��
{
	welcomeView();

	cout << "     " << "��ǰ�û�Ϊ: ";
	cout << name;
	cout << endl;
	cout << "                  " << "��ѡ������-->" << endl;
	cout << "                  " << "���밴�س�����" << endl;
	cout << "                             " << "1.��ʼ����" << endl;
	cout << "                             " << "2.�鿴" << endl;
	cout << "                             " << "3.ע����¼���˳�����" << endl;

}



void choiseError()	//ѡ�������ʾҳ��
{
	cout<<"                "<<"\033[32m������������ȷ�Ϸ�������\033[0m" << endl;
}
void startAnswerView()//��ʼ����ҳ��
{
	cout << "        " << "\033[32m�뿪ʼ����\033[0m" << endl;
	cout << "        " << "\033[32m���밴�س�������\033[0m" << endl;
}

void exitOrLogOutView(string name)  //ע����¼�����˳�ѡ��ҳ��
{
	cout << "      " << "��ǰ�û�Ϊ��";
	cout << name;
	cout << endl;
	cout << "                " << "��ѡ������-->" << endl;
	cout << "				" << "���밴�س�������" << endl;
	cout << "                        " << "1.ע����ǰ�û�" << endl;
	cout << "                        " << "2.�˳�����" << endl;

}


void answerView(string name, int score, int titleNumber, int lastTitleScore, int time)	//���������ʾҳ��
{
	cout << "      " << "��ǰ�û�Ϊ��" << name << "        �ۼƵ÷֣�" << score << "      �ۼ���ʱ��" << time << endl;
	cout << endl;
	cout << "      " << "��ǰ��ţ�" << titleNumber << "       ��һ��÷֣�" << lastTitleScore << endl;
}


void stop()	//��ͣҳ��
{
	system("pause");
}

bool isNumber(char num) 	//�ж����������Ƿ�Ϊ����
{
	bool isNumber = false;
	if ((num >= 'a' && num <= 'z') || (num >= 'A' && num <= 'Z'))
	{
		isNumber = false;
	}
	else if (num >= '0' && num <= '9')
	{
		isNumber = true;
	}
	else
	{
		isNumber = false;
	}
	return isNumber;
}


void querySuccess()
{
	cout << "            " << "��¼�ɹ�" << endl;
}


void choseTitleNumberView(string name)
{
	cout << "      " << "��ǰ�û�Ϊ:" << name << endl;
	cout << "           " << "��һ��������Ŀ����-->" << endl;
	cout << "			" << "���밴�س�������" << endl;

}

void lookHistoryView(string name)
{
	welcomeView();
	cout << "      " << "��ǰ�û�Ϊ��";
	cout << name;
	cout << endl;
	cout << "                 " << "��ѡ�����֡���>" << endl;
	cout << "                 " << "���밴�س�������" << endl;
	cout << "                                    " << "1.�鿴���˴�����ʷ" << endl;//������ʷ�����¼
	cout << "                                    " << "2.�鿴���а�" << endl;
}