// prog6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <stdio.h>
#pragma hdrstop
void main()
{
	HANDLE hToken;
	LUID setcbnameValue;
	TOKEN_PRIVILEGES tkp;
	DWORD errcod;
	LPVOID lpMsgBuf;
	LPCTSTR msgptr;
	UCHAR InfoBuffer[1000];
	PTOKEN_PRIVILEGES ptgPrivileges = (PTOKEN_PRIVILEGES)InfoBuffer;
	DWORD dwInfoBufferSize;
	DWORD dwPrivilegeNameSize;
	DWORD dwDisplayNameSize;
	UCHAR ucPrivilegeName[500];
	UCHAR ucDisplayName[500];
	DWORD dwLangId;
	UINT i;
	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		puts("OpenProcessToken");
		return;
	}
	GetTokenInformation(hToken, TokenPrivileges, InfoBuffer,
		sizeof InfoBuffer, &dwInfoBufferSize);
	printf("Account privileges: \n\n");
	for (i = 0; i < ptgPrivileges->PrivilegeCount; i++)
	{
		dwPrivilegeNameSize = sizeof ucPrivilegeName;
		dwDisplayNameSize = sizeof ucDisplayName;
		LookupPrivilegeName(NULL, &ptgPrivileges->Privileges[i].Luid,
			(char*)ucPrivilegeName, &dwPrivilegeNameSize);
		LookupPrivilegeDisplayName(NULL, (char*)ucPrivilegeName,
			(char*)ucDisplayName, &dwDisplayNameSize, &dwLangId);
		printf("%s (%s)\n", ucPrivilegeName, ucDisplayName);
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
