/*
 *程序名：
		1、用scanf和printf等函数开发以下功能，假设一个班级有3个学生。
		定义3组变量，每一组包括：学号、姓名和一些学科成绩（数学、语文、英语）
		a)首先根据让用户输入3组测试数据到对应的3组变量中；
		b)（横向计算）并打印以上3组数据的学号姓名等信息，还有每个学生的3科总分和3科平均分；
		c)（纵向计算）并打印每门课程的平均分，以及3门课全班平均分；
 *作者; 姜宗谷
 *时间：2023年3月3日 13:50:23
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//学号
	unsigned int StudentID1, StudentID2, StudentID3;
	//姓名
	char Name1[20], Name2[20], Name3[20];
	//数学
	float Math1, Math2, Math3;
	//语文
	float Chinese1, Chinese2, Chinese3;
	//英语
	float English1, English2, English3;

	printf("请输入学生信息(例:1 张三 89 85 90)并回车:\n");
	//输入第一个学生信息
	printf("请输入第一个学生信息:");
	scanf("%d%s%f%f%f", &StudentID1, Name1, &Math1, &Chinese1, &English1);
	
	//输入第二个学生信息
		printf("请输入第二个学生信息:");
	scanf("%d%s%f%f%f", &StudentID2, Name2, &Math2, &Chinese2, &English2);
	
	//输入第三个学生信息
	printf("请输入第三个学生信息:");
	scanf("%d%s%f%f%f", &StudentID3, Name3, &Math3, &Chinese3, &English3);
	
	//（横向计算）并打印以上3组数据的学号姓名等信息，还有每个学生的3科总分和3科平均分
	//打印第一个学生信息
	printf("\n\n打印成绩:\n");
	printf("ID\tName\tMath\tChinese\tEnglish\tSum\tAverage\n");
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", StudentID1, Name1, Math1, Chinese1, English1,Math1+Chinese1+English1,(Math1 + Chinese1 + English1)/3);

	//打印第二个学生信息
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", StudentID2, Name2, Math2, Chinese2, English2, Math2 + Chinese2 + English2, (Math2 + Chinese2 + English2) / 3);
	
	//打印第三个学生信息
	printf("%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", StudentID3, Name3, Math3, Chinese3, English3, Math3 + Chinese3 + English3, (Math3 + Chinese3 + English3) / 3);

	//（纵向计算）并打印每门课程的平均分，以及3门课全班平均分；
	printf("\n\n打印平均分:\n");
	printf("Ave_m\tAve_c\tAve_e\tAve_all\n");
	printf("%.1f\t%.1f\t%.1f\t%.1f",(Math1+Math2+Math3)/3,(Chinese1+Chinese2+Chinese3)/3,(English1+English2+English3)/3,((Math1 + Math2 + Math3) / 3+(Chinese1 + Chinese2 + Chinese3) / 3+(English1 + English2+ English3) / 3)/3);






	return 0;
}


