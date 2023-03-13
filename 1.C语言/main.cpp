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

//函数声明
void initSystem();	//系统初始化，进入身份验证模块
void mainSystem();	//系统主模块
void lookHistory();	//查看模块
void exitOrLogOut();	//退出或注销模块运算题目数量
void getTitle(string name,int n,int m,int level);	//生成题目(string 用户名, int 简单四则运算题目数量,int 混合四则,int 用户答题难度)
void startAnswer(string name);	//开始答题前选择题目数量
int isGrade(string grade);	//注册时对年级是否是非法字符进行彦祖
int initView();	//身份验证的界面
DWORD WINAPI getMsg(LPVOID lpParam);	//计时子线程





int main()
{
	


	return 0;
}




void initSystem()	//系统初始化，进入身份验证模块
{
	clearAll();
	int initViewReturn = initView();
	if (initViewReturn == 1)
	{
		cout << "                                   " << "请输入用户名" << endl;
		cin >> name;
		cout << "                                   " << "请输入密码" << endl;
		string pwd;
		cin >> pwd;
		connectDatabase();
		loginOn = loginDao(name, pwd);
		if (loginOn)
		{
			//进入主界面
			mainSystem();
		}
		else
		{
			//登录失败
			stop();
			initSystem();
		}
	}
	if (initViewReturn == 2)
	{
		cout << "              " << "请输入用户名" << endl;
		cin >> name;
		cout << "              " << "请输入密码" << endl;
		string pwd;
		cin >> pwd;
		string ggrade;
		cout << "              " << "请输入年级1-6（数字）" << endl;
		int grade;
		grade = isGrade(ggrade);
		string school;
		cout << "              " << "请输入所在的学校名称" << endl;
		cin >> school;
		cin >> school;
		if (registerDao(name, pwd, grade, school))
		{
			cout << "                       " << "注册成功" << endl;
			stop();

			//进入主界面
			mainSystem();
		}
		else
		{
			cout << "                  " << "注册失败" << endl;
			cout << "                   " << "请勿输入非法字符" << endl;
			stop();
			initSystem();
		}
	}
	else
	{
		initSystem();
	}
}


void mainSystem()	//系统主模块
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
		//进入答题
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


void lookHistory()	//查看模块
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


void exitOrLogOut()	//退出或注销模块运算题目数量
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


void getTitle(string name, int n, int m, int level)	//生成题目(string 用户名, int 简单四则运算题目数量,int 混合四则,int 用户答题难度)
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
		freqMax = selectMaxFreq(name);	//显示答题次数
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
	//四则简单运算开始
	for (int i = 0; i < n; ++i)
	{
		if (isAnswer)
		{
			startAnswerView();
			answerView(name, score, titleNumber, lastTitleScore, timeUsed);
			int number[5];
			
			//生成level+1个随机数
			for (int j = 0; j < num + 1; ++j)
			{
				number[j] = getRandm(max, min);
			}
			/*
			加减乘除的思路
			减法运算防止减不过，可以由加法变换
			除法运算防止除不尽由乘法变换
			*/

			if (level == 1)
			{
				string result = "-1";
				if (operatioSymbol(false))
				{
					cout << "         " << number[0] << "+" << number[1] << endl;
					cout << "        请输入正确答案";
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
					cout << "      请输入正确答案";
					cin >> result;
				}
			}


		}

	}


}

void startAnswer(string name);	//开始答题前选择题目数量
int isGrade(string grade);	//注册时对年级是否是非法字符进行彦祖
int initView();	//身份验证的界面
DWORD WINAPI getMsg(LPVOID lpParam);	//计时子线程