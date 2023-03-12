#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<mysql.h>
#include<string>
#include"title.h"

using namespace std;

#define QUERYSUCCESS "请求数据成功\n"
#define CONNECTSUCCESS "连接数据库成功\n"

const char *host = "127.0.0.1";
const char *user = "root";
const char *pass = "123456";
const char *db = "practicesystem";

MYSQL mysql;	//mysql连接
MYSQL_FIELD *fd;	//字段列数组
MYSQL_RES *res;	//这个结构代表返回行的一个查询结果集
MYSQL_ROW column;	//一个行数据的类型安全(type-safe)的表示，表示数据行的列
char field[32][32];	//存字段名二维数组
char query[150];	//查询语句

bool connectDatabase();	//连接数据库
bool QueryDatabase1();
//bool QueryDatabase2();
bool InsertData();
bool ModifyData();
bool DeleteData();
bool loginDao(string name, string pwd);		//向数据库请求登录信息
bool registerDao(string name, string pwd, int grade, string school);	//向数据库写入注册信息
bool lookPersonalHistory(string name);	//向数据库请求个人答题信息
bool lookFirstlGrade();	//向数据库请求排行榜排名情况
bool setPracticeInfo(string name, int titleNumber, int titleScore, int freqScore, int freq, int time);	//向数据库写入个人答题历史信息
int selectMaxFreq(string name);	//查询用户当前答题次数
int getUserLevel(string name);	//根据用户姓名在数据库查询年级
int getBestGrade(string name);	//向数据库请求当前用户的历史最佳成绩
bool setBestGrade(string name, int grade);	//填入个人历史最佳成绩
bool setFreqScore(string name, int grade, int freq);	//向数据库写入当次答题总成绩
void clearAll();	//清除屏幕





//////函数定义//////
bool connectDatabase()  //连接数据库
{
	//初始化mysql
	mysql_init(&mysql);

	//如果连接成功，返回MYSQL*连接句柄。如果连接失败，返回NULL。
	//对于成功的连接，返回值与第1个参数的值相同。
	if (!mysql_real_connect(&mysql, host, user, pass, db, 3306, 0, 0))
	{
		cout << "Connect Database Failed" << endl;
		return false;
	}
	else
	{
		cout << CONNECTSUCCESS << endl;
		return true;
	}
}

//释放资源
void FreeConnect()
{
	mysql_free_result(res);

	mysql_close(&mysql);
}

/*********************************数据库操作*******************************/

//其实所有的数据库操作都是先写个sql语句，然后用mysql_query(&mysql,query)来完成，包括创建数据库或表，增删改查
//查询数据

bool QueryDatabase1()
{
	if (connectDatabase())
	{
		sprintf(query, "select * from userinfo");	//执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以

		mysql_query(&mysql, "set names gbk");	//设置编码格式(SET NAMES GBK也行),否则cmd下中文乱码

		//返回0 查询成功，返回1查询失败
		if (mysql_query(&mysql, query))		//执行SQL语句
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("QUERYSUCESS");
		}

		//获取结果集
		if (!(res = mysql_store_result(&mysql)))	//获得sql语句结束后返回的结果集
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}

		//打印数据行数
		printf("number of dataline returned: %lld\n", mysql_affected_rows(&mysql));

		//获取字段的信息
		char *str_field[32];	//定义一个字符串数组存储字段信息

		for (int i = 0; i < 2; ++i)	//在已知字段数量的情况下获取字段名
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i < 2; ++i)	//打印字段
		{
			printf("%10s\t", str_field[i]);
		}

		printf("\n");
		clearAll();

		//打印获取的数据
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < mysql_affected_rows(&mysql); ++i)
			{
				printf("%10s\t", row[i]);
			}
			cout << endl;
		}
		return true;
	}
	return 0;
}


bool InsertData()
{
	sprintf(query, "insert into userinfo values ('ddd','ddd');");	//可以向办法实现手动在控制台手动输入指令	
	clearAll();
	
	//执行SQL语句
	if (mysql_query(&mysql, query))
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf(QUERYSUCCESS);
		return true;
	}

}


//修改数据
bool ModifyData()
{
	sprintf(query, "update userinfo set password='111' where name='ddd'");
	clearAll();

	//执行SQL语句
	if (mysql_query(&mysql, query))
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf(QUERYSUCCESS);
		return true;
	}


}


//删除数据
bool DeleteData()
{
	char query[100];
	printf("please input the sql:\n");
	sprintf(query, "delete from userinfo where name='ddd'");
	clearAll();

	if (mysql_query(&mysql, query))
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf(QUERYSUCCESS);
		return true;
	}
}


bool loginDao(string name, string pwd)
{
	if (connectDatabase())
	{
		//方法1
		//sprintf(query, "select * from userinfo where name= '%s' and pwd='%s'", name, pwd);	//执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以.

		//方法2
		string sql = "select * from userinfo where name='" + name + "'and pwd='" + pwd + "';";
		cout << sql << endl;
		const char* c_s = sql.c_str();

		sprintf(query, c_s);
		char q[150] = "set names \'GBK\'";
		mysql_query(&mysql, q);	//设置编码格式(SET NAMES GBK也行），否则cmd下中文乱码

		//返回0 查询成功，返回1查询失败
		clearAll();

		//执行SQL语句
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
		}
	
		//获取结果集
		//获得sql语句结束后返回的结果集
		if (!(res = mysql_store_result(&mysql)))
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			clearAll();
			return false;
		}

		//打印数据行数
		printf("number of dataline returned:%lld\n",mysql_affected_rows(&mysql));

		//获取字段的信息
		char *str_field[32];	//定义一个字符串数组存储字段信息

		//在已知字段数量的情况下获取字段名
		for (int i = 0; i < 2; ++i)
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i < 2; ++i)
		{//打印字段
			printf("%10s\t", str_field[i]);
		}
		clearAll();
		printf("\n");

		//打印获取的数据
		MYSQL_ROW row;
		bool success = false;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < mysql_affected_rows(&mysql); ++i)
			{
				printf("%10s\t", row[i]);
				success = true;
			}
			cout << endl;

		}
		clearAll();

		if (success)
		{
			cout << QUERYSUCCESS << endl;
		}
		return success;
	}
	return 0;
}


bool registerDao(string name, string pwd, int grade, string school)	//向数据库写入注册信息
{
	if (connectDatabase())
	{
		string sql = "insert into userinfo values('" + name + "','" + pwd + "'," + toString(grade) + ",'" + school + "',0);";
		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);
		char q[100] = "set names \'GBK\'";

		mysql_query(&mysql, q);	//设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码

		clearAll();
		//返回0 查询成功，返回1查询失败
		//执行SQL语句
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
			return true;
		}

	}
	return true;
}


bool lookPersonalHistory(string name)
{
	if (connectDatabase())
	{
		string sql = "select name,freq,freqscore,titleNumber,titleScore,time from practiceinfo where name='" + name + "';";
		cout << sql << endl;
		const char* c_s = sql.c_str();
		sprintf(query, c_s);

		mysql_query(&mysql, "SET NAMES UTF8");	//设置编码格式(SET NAMES GBK)，否则CMD下中文乱码

		clearAll();
		//返回0 查询成功，返回1查询失败
		//执行SQL语句
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
		}

		//获取结果集
		if (!(res = mysql_store_result(&mysql)))	//获得sql语句结束后返回的结果集
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}

		//打印数据行数
		printf("number of dataline returned: %lld\n", mysql_affected_rows(&mysql));
		clearAll();

		//获取字段的信息
		char *str_field[32];	//定义一个字符串数组存储字段信息

		//在已知字段数量的情况下获取字段名
		for (int i = 0; i < 6; ++i)
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}

		printf("%10s\t", "姓名");
		printf("%10s\t","答题次数");
		printf("%10s\t","当次答题次数");
		printf("%10s\t","题目编号");
		printf("%10s\t","题目得分");
		printf("%10s\t","答题用时");

		//打印获取的数据
		MYSQL_ROW row;
		bool success = false;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < 6; ++i)
			{
				printf("%10s\t", row[i]);
			}
			cout << endl;
		}
		if (success)
		{
			cout << QUERYSUCCESS << endl;
		}
		return success;
	}
	return 0;
}


bool lookFirstlGrade()
{
	if (connectDatabase())
	{
		string sql = "select name,grade,school,bestScore from userinfo froup by name order by bestScore desc;";

		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);
		mysql_query(&mysql, "SET NAMES GBK");

		//返回0 查询成功， 返回1查询失败
		//执行SQL语句
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
		}

		//获取结果集
		//获得sql语句结束后返回的结果集
		if (!(res = mysql_store_result(&mysql)))
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}

		//打印数据行数
		printf("number of dataline returned: %lld\n", mysql_affected_rows(&mysql));

		//获取字段的信息
		char *str_field[32];	//定义一个字符串数组存储字段信息

		//在已知字段数量的情况下获取字段名
		for (int i = 0; i < 4; ++i)
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		clearAll();

		printf("\n");
		printf("%10s\t", "姓名");
		printf("%10s\t", "年级");
		printf("%10s\t", "所在学校");
		printf("%10s\t", "历史最佳成绩");

		printf("\n");

		//打印获取的数据
		MYSQL_ROW row;
		bool success = false;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < 4; ++i)
			{
				printf("%10s\t", row[i]);
				success = true;
			}
			cout << endl;
		}
		if (success)
		{
			cout << QUERYSUCCESS;
		}
		else
		{
			cout << "登录失败" << endl;
		}
		return success;
	}
	return false;
}


//向数据库写入个人答题历史信息
bool setPracticeInfo(string name, int titleNumber, int titleScore, int freqScore, int freq, int time)
{
	if (connectDatabase())
	{
		string titNumber = toString(titleNumber);
		string titScore = toString(titleScore);
		string freScore = toString(freqScore);

		string fre = toString(freq);
		string tim = toString(time);

		string sql = "insert into practiceinfo values('" + name + "','" + titNumber + "','" + titScore + "','" + freScore + "','" + fre + "','" + tim + " ');";
		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);	//可以想办法手动输入在控制台手动输入指令
		clearAll();

		//执行SQL语句
		if(mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
			return true;
		}
	}
	return false;
}


int selectMaxFreq(string name)//查询用户当前答题次数
{
	if (connectDatabase())
	{
		string sql = "SELECT MAX(freq) FROM 'practiceinfo' WHERE name='" + name + "'";
		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);	
		mysql_query(&mysql, "set name gbk");

		//返回0 查询成功，返回1查询失败
		//执行SQL
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
		}

		//获取结果集
		//获得sql语句结束后返回的结果集
		if (!(res = mysql_store_result(&mysql)))
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}

		//打印数据行数
		printf("number of dataline returned: %lld\n", mysql_affected_rows(&mysql));

		//获取字段的信息
		char *str_field[32];	//定义一个字符串数组存储字段信息

		//在已知字段数量的情况下获取字段名
		for (int i = 0; i < 1; ++i)
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i < 1; ++i)
		{//打印字段
			printf("%10s\t", str_field[i]);
		}

		printf("\n");

		//打印获取的数据
		MYSQL_ROW row;
		//string *s;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < 1; ++i)
			{
				printf("%10s\t", row[i]);
				char *t;
				t = row[i];
				if (t == NULL)
				{
					clearAll();
					return 0;
				}
				string a = t;
				int c = atoi(a.c_str());
				clearAll();
				return c;
			}
			cout << endl;
		}
		return 0;
	}
	return 0;
}

int getUserLevel(string name)	//根据用户姓名在数据库查询年级
{
	if (connectDatabase())
	{
		string sql = "select grade FROM 'userinfo' WHERE name='" + name + "'";
		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);	
		mysql_query(&mysql, "set names gbk");
		clearAll();

		//返回0 查询成功，返回1查询失败
		//执行SQL语句
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
		}

		//获取结果集
		if (!(res = mysql_store_result(&mysql)))
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}

		//打印数据行数
		printf("number of dataline returned: %lld\n", mysql_affected_rows(&mysql));
		clearAll();

		//获取字段信息
		char *str_field[32];	//定义一个字符串数组存储字段信息

		//在已知字段数量的情况下获取字段名
		for (int i = 0; i < 1; ++i)
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}

		//打印字段
		for (int i = 0; i < 1; ++i)
		{
			printf("%10s\t", str_field[i]);
		}

		printf("\n");
		//打印获取的数据
		MYSQL_ROW row;
		//string *s;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i<1; ++i)
			{
				printf("%10s\t", row[i]);
				char *t;
				t = row[i];
				string a = t;
				int c = atoi(a.c_str());
				if (c <= 2 && c >= 1)
					return 1;
				if (c <= 4 && c >= 3)
					return 2;
				if (c <= 6 && c >= 5)
					return 3;
				else
				{
					return 0;
				}

			}
			cout << endl;
		}
		return 0;
	}
	return 0;
}


int getBestGrade(string name)	//向数据库请求当前用户的历史最佳成绩
{
	if (connectDatabase())
	{
		string sql = "SELECT bestScore FROM userinfo WHERE name='" + name + "'";
		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);
		mysql_query(&mysql, "set names gbk");	//设置编码格式

		//返回0 查询成功，返回1 查询失败
		clearAll();

		//执行SQL语句
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
		}

		//获取结果集
		//获得sql语句结束后返回的结果集
		if (!(res = mysql_store_result(&mysql)))
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}

		//打印数据行数
		printf("number of dataline returned； %lld\n", mysql_affected_rows(&mysql));
		clearAll();

		//获取字段的信息
		char *str_field[32];	//定义一个字符串数组存储字段信息
		for (int i = 0; i < 1; ++i)
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i < 1; ++i)
		{
			printf("%10s\t", str_field[i]);
		}

		printf("\n");

		//打印获取的数据
		MYSQL_ROW row;
		//string *s;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < 1; ++i)
			{
				printf("%10s\t", row[i]);
				char *t;
				t = row[i];
				if (t == NULL)
				{
					return 0;
				}
				string a = t;
				int c = atoi(a.c_str());
				return c;
			}
			cout << endl;
		}
		return 0;
	}
	return 0;
}



bool setBestGrade(string name, int grade)	//填入个人历史最佳成绩
{
	if (connectDatabase())
	{
		string sql = "UPDATE userinfo SET bestScore = " + toString(grade) + " WHERE name = '" + name + "'";
		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);
		clearAll();
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
			return true;
		}
	}
	return false;
}


bool setFreqScore(string name, int grade, int freq)	//向数据库写入当次答题总成绩
{
	if (connectDatabase())
	{
		string sql = "UPDATE practiceinfo SET frescore = " + toString(grade) + "WHERE name = '" + name + "' and freq=" + toString(freq);
		cout << sql << endl;
		const char *c_s = sql.c_str();
		sprintf(query, c_s);
		clearAll();
		if (mysql_query(&mysql, query))
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf(QUERYSUCCESS);
			return true;
		}

	}
	return false;
}


void clearAll()	//清除屏幕
{
	system("cls");
}








