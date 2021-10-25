// prog4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _WIN32_WINNT 0x0500
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <sddl.h>
void main(void) {
	DWORD TokenUserBufSize = 256;
	LPTSTR StringSid;
	TOKEN_USER* ptUser;
	HANDLE hHeap;
	HANDLE hToken = NULL;
	hHeap = GetProcessHeap();
	ptUser = (TOKEN_USER*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, TokenUserBufSize);
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
		printf("OpenProcessToken Error\n");
	if (!GetTokenInformation(hToken, // описатель маркера доступа
		TokenUser, // нужна информация о пользователе
		ptUser, // буфер для информации
		TokenUserBufSize, &TokenUserBufSize))
		printf("GetTokenInformation Error\n");;

	if (!ConvertSidToStringSid(ptUser->User.Sid, &StringSid))
		printf("Convert SID to string SID failed.");
	wprintf(L"StringSid %s\n", StringSid);
	CloseHandle(hToken);
	LocalFree(StringSid);
	HeapFree(hHeap, 0, ptUser);
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
