// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "python_interface.h"

void Login()
{
	char szUserName[100] = { 0 }, szPassword[100] = { 0 };
	cout << "�������˺�:" << endl;
	gets_s(szUserName);
	cout << "����������:" << endl;
	char ch;
	int nLenPwd = 0;
	while ((ch = getch()) != '\r')
	{
		if (ch != 8)
		{
			szPassword[nLenPwd++] = ch;
			printf("*");
		}
		else if (nLenPwd)
		{
			printf("\b \b");
			nLenPwd--;
		}
	}
	szPassword[nLenPwd] = 0;
	printf("\n");

	pPython->Login(szUserName, szPassword);
}

int main()
{
	pPython->InitAll();
	Login();

	system("pause");
	return 0;
}

