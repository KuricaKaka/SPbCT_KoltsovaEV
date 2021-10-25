// prog3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _WIN32_WINNT 0x0500
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <sddl.h>
#include <Aclapi.h>
void main(void) 
{	
	PSID pSid;
	PSECURITY_DESCRIPTOR pSD;
	PACL pDACL;
	LPTSTR StringSid = NULL;
	ULONG Error;
	HANDLE hFile;
	hFile = CreateFile(TEXT("MyFile.txt"), READ_CONTROL, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);
	Error = GetSecurityInfo(hFile,
		SE_FILE_OBJECT, // тип объекта
		OWNER_SECURITY_INFORMATION |
		DACL_SECURITY_INFORMATION,
		&pSid, // Sid владельца
		NULL, // Sid группы
		&pDACL, NULL, // списки прав доступа
		&pSD // дескриптор защиты);
		if (Error != ERROR_SUCCESS) printf("GetSecurityInfo Error\n");
	if (!ConvertSidToStringSid(pSid, &StringSid)) /* память для строки выделяет сама функция */
		printf("Convert SID to string SID failed.");
	wprintf(L"StringSid %s\n", StringSid);
	LocalFree(pSD);
	LocalFree(StringSid);
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
