/*
 *��������
		1����scanf_s��printf_s�Ⱥ����������¹��ܣ�����һ���༶��3��ѧ����
		����3�������ÿһ�������ѧ�š�������һЩѧ�Ƴɼ�����ѧ�����ġ�Ӣ�
		a)���ȸ������û�����3��������ݵ���Ӧ��3������У�
		b)��������㣩����ӡ����3�����ݵ�ѧ����������Ϣ������ÿ��ѧ����3���ֺܷ�3��ƽ���֣�
		c)��������㣩����ӡÿ�ſγ̵�ƽ���֣��Լ�3�ſ�ȫ��ƽ���֣�
 *����; ���ڹ�
 *ʱ�䣺2023��3��3�� 13:50:23
*/

#include<stdio.h>

int main()
{
	//ѧ��
	unsigned int StudentID1, StudentID2, StudentID3;
	//����
	char Name1[20], Name2[20], Name3[20];
	//��ѧ
	float Math1, Math2, Math3;
	//����
	float Chinese1, Chinese2, Chinese3;
	//Ӣ��
	float English1, English2, English3;

	printf_s("������ѧ����Ϣ(��:1 ���� 89 85 90)���س�:\n");
	//�����һ��ѧ����Ϣ
	printf_s("�������һ��ѧ����Ϣ:");
	/*scanf_s("%d", &StudentID1);
	scanf_s("%s", Name1, sizeof(Name1)-1);
	scanf_s("%f", &Math1);
	scanf_s("%f", &Chinese1);
	scanf_s("%f", &English1);*/
	
	//��ʹ��scanf_s����ʱ�����ռλ����%s,����������ַ�����Ҫ��������б�����ռλ����Ӧ�ĳ���������֮��������С��
	scanf_s("%d%s%f%f%f", &StudentID1, Name1, sizeof(Name1), &Math1, &Chinese1, &English1);

	//����ڶ���ѧ����Ϣ
	printf_s("������ڶ���ѧ����Ϣ:");
	/*scanf_s("%d", &StudentID2);
	scanf_s("%s", Name2, sizeof(Name2)-1);
	scanf_s("%f", &Math2);
	scanf_s("%f", &Chinese2);
	scanf_s("%f", &English2);*/
	scanf_s("%d%s%f%f%f", &StudentID2, Name2, sizeof(Name2), &Math2, &Chinese2, &English2);

	//���������ѧ����Ϣ
	printf_s("�����������ѧ����Ϣ:");
	/*scanf_s("%d", &StudentID3);
	scanf_s("%s", Name3, sizeof(Name3)-1);
	scanf_s("%f", &Math3);
	scanf_s("%f", &Chinese3);
	scanf_s("%f", &English3);*/
	scanf_s("%d%s%f%f%f", &StudentID3, Name3, sizeof(Name3), &Math3, &Chinese3, &English3);

	//��������㣩����ӡ����3�����ݵ�ѧ����������Ϣ������ÿ��ѧ����3���ֺܷ�3��ƽ����
	//��ӡ��һ��ѧ����Ϣ
	printf_s("\n\n��ӡ�ɼ�:\n");
	printf_s("ID\tName\tMath\tChinese\tEnglish\tSum\tAverage\n");
	printf_s("%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", StudentID1, Name1, Math1, Chinese1, English1, Math1 + Chinese1 + English1, (Math1 + Chinese1 + English1) / 3);

	//��ӡ�ڶ���ѧ����Ϣ
	printf_s("%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", StudentID2, Name2, Math2, Chinese2, English2, Math2 + Chinese2 + English2, (Math2 + Chinese2 + English2) / 3);

	//��ӡ������ѧ����Ϣ
	printf_s("%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", StudentID3, Name3, Math3, Chinese3, English3, Math3 + Chinese3 + English3, (Math3 + Chinese3 + English3) / 3);

	//��������㣩����ӡÿ�ſγ̵�ƽ���֣��Լ�3�ſ�ȫ��ƽ���֣�
	printf_s("\n\n��ӡƽ����:\n");
	printf_s("Ave_m\tAve_c\tAve_e\tAve_all\n");
	printf_s("%.1f\t%.1f\t%.1f\t%.1f", (Math1 + Math2 + Math3) / 3, (Chinese1 + Chinese2 + Chinese3) / 3, (English1 + English2 + English3) / 3, ((Math1 + Math2 + Math3) / 3 + (Chinese1 + Chinese2 + Chinese3) / 3 + (English1 + English2 + English3) / 3) / 3);


	return 0;
}
