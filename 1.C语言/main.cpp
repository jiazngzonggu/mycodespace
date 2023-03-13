#pragma warning(disable:4996)
#include"view.h"
#include"title.h"
#include"userdao.h"

#define HightMax	10
#define HightMin	1
#define LowMax		5
#define LowMin		1
#define LimitTime	200

bool loginOn = false;
string name;
int timeUsed = 0;
DWORD threadID;
HANDLE  hThread;
bool isAnswer = true;

//��������
void initSystem();	//ϵͳ��ʼ�������������֤ģ��
void mainSystem();	//ϵͳ��ģ��
void lookHistory();	//�鿴ģ��
void exitOrLogOut();	//�˳���ע��ģ��������Ŀ����
void getTitle(string name,int n,int m,int level);	//������Ŀ(string �û���, int ������������Ŀ����,int �������,int �û������Ѷ�)
void startAnswer(string name);	//��ʼ����ǰѡ����Ŀ����
int isGrade(string grade);	//ע��ʱ���꼶�Ƿ��ǷǷ��ַ���������
int initView();	//�����֤�Ľ���
DWORD WINAPI getMsg(LPVOID lpParam);	//��ʱ���߳�





int main()
{
	


	return 0;
}




void initSystem()	//ϵͳ��ʼ�������������֤ģ��
{
	clearAll();
	int initViewReturn = initView();
	if (initViewReturn == 1)
	{
		cout << "                                   " << "�������û���" << endl;
		cin >> name;
		cout << "                                   " << "����������" << endl;
		string pwd;
		cin >> pwd;
		connectDatabase();
		loginOn = loginDao(name, pwd);
		if (loginOn)
		{
			//����������
			mainSystem();
		}
		else
		{
			//��¼ʧ��
			stop();
			initSystem();
		}
	}
	if (initViewReturn == 2)
	{
		cout << "              " << "�������û���" << endl;
		cin >> name;
		cout << "              " << "����������" << endl;
		string pwd;
		cin >> pwd;
		string ggrade;
		cout << "              " << "�������꼶1-6�����֣�" << endl;
		int grade;
		grade = isGrade(ggrade);
		string school;
		cout << "              " << "���������ڵ�ѧУ����" << endl;
		cin >> school;
		cin >> school;
		if (registerDao(name, pwd, grade, school))
		{
			cout << "                       " << "ע��ɹ�" << endl;
			stop();

			//����������
			mainSystem();
		}
		else
		{
			cout << "                  " << "ע��ʧ��" << endl;
			cout << "                   " << "��������Ƿ��ַ�" << endl;
			stop();
			initSystem();
		}
	}
	else
	{
		initSystem();
	}
}


void mainSystem()	//ϵͳ��ģ��
{
	TerminateThread(hThread, threadID);
	isAnswer = true;
	clearAll();
	mainView(name);
	string nnum;
	cin >> nnum;
	int num = toInt(nnum);
	if (num == 1)
	{
		//�������
		startAnswer(name);
	}
	else if (num == 2)
	{
		lookHistory();
	}
	else if (num == 3)
	{
		exitOrLogOut();
	}
	else
	{
		choiseError();
		stop();
		mainSystem();
	}
}


void lookHistory()	//�鿴ģ��
{
	clearAll();
	lookHistoryView(name);
	string nnum;
	cin >> nnum;
	int num = toInt(nnum);
	if (num == 1)
	{
		lookPersonalHistory(name);
		stop();
	}
	else if (num == 2)
	{
		lookFirstlGrade();
		stop();
	}
	else
	{
		choiseError();
		stop();
	}
	mainSystem();

}


void exitOrLogOut()	//�˳���ע��ģ��������Ŀ����
{
	clearAll();
	exitOrLogOutView(name);
	string nnum;
	cin >> nnum;
	int num = toInt(nnum);
	if (num == 1)
	{
		initSystem();
	}
	else if (num == 2)
	{
		exit(0);
	}
	else
	{
		choiseError();
		stop();
		exitOrLogOut();
	}
}


void getTitle(string name, int n, int m, int level)	//������Ŀ(string �û���, int ������������Ŀ����,int �������,int �û������Ѷ�)
{
	hThread = CreateThread(NULL, 0, getMsg, NULL, 0, &threadID);
	int num = level + 1;
	int max;
	int min;
	int score = 100;
	int titleNumber = 1;
	int lastTitleScore = 0;
	int freqMax = 0;
	int bestScore = getBestGrade(name);
	if (selectMaxFreq(name) != NULL)
	{
		freqMax = selectMaxFreq(name);	//��ʾ�������
	}

	welcomeView();
	freqMax++;
	if (num == 2)
	{
		max == LowMax;
		min == LowMin;
	}
	if (num == 3 || num == 4)
	{
		max = HightMax;
		min = HightMin;
	}
	//��������㿪ʼ
	for (int i = 0; i < n; ++i)
	{
		if (isAnswer)
		{
			startAnswerView();
			answerView(name, score, titleNumber, lastTitleScore, timeUsed);
			int number[5];
			
			//����level+1�������
			for (int j = 0; j < num + 1; ++j)
			{
				number[j] = getRandm(max, min);
			}
			/*
			�Ӽ��˳���˼·
			���������ֹ�������������ɼӷ��任
			���������ֹ�������ɳ˷��任
			*/

			if (level == 1)
			{
				string result = "-1";
				if (operatioSymbol(false))
				{
					cout << "         " << number[0] << "+" << number[1] << endl;
					cout << "        ��������ȷ��";
					cin >> result;
					int rs = atoi(result.c_str());

					if (rs == (number[0] + number[1]))
					{
						score += 5;
						lastTitleScore = 5;
					}
					else
					{
						score -= 5;
						lastTitleScore = -5;
					}
				}
				else
				{
					int rss = number[0] + number[1];
					cout << "     " << rss << " _ " << number[1] << endl;
					cout << "      ��������ȷ��";
					cin >> result;
				}
			}


		}

	}


}

void startAnswer(string name);	//��ʼ����ǰѡ����Ŀ����
int isGrade(string grade);	//ע��ʱ���꼶�Ƿ��ǷǷ��ַ���������
int initView();	//�����֤�Ľ���
DWORD WINAPI getMsg(LPVOID lpParam);	//��ʱ���߳�