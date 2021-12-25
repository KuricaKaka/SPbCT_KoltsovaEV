#include <vector>




#pragma once
#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include "msclr\marshal_cppstd.h"

//#include "myvector.h"
//#include "lib.h"
#define dll_MyVector

typedef struct
{
	//дескрипторы событий
	HANDLE  hePipeStart;
	HANDLE  hePipeReply;
	//дескрипторы пайпов
	HANDLE  child_in;
	HANDLE  parent_out;
	HANDLE  child_out;
	HANDLE  parent_in;
	//буфера
	char    read[1024];     //буфер для чтения данных
	char    send[1024];     //передаваемое значение
}TheadParms;

namespace testtest 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(312, 184);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(233, 62);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Запуск вычислений в многопоточном режиме";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Honeydew;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(39, 262);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 339);
			this->label2->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Honeydew;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(39, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(506, 102);
			this->label1->TabIndex = 7;
			this->label1->Text = L"\r\n";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(312, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(233, 62);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Сделать файл только для чтения";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(39, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(233, 62);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Считать данные из файла";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(39, 184);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(233, 62);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Преобразовать файл";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Honeydew;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(39, 617);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(506, 96);
			this->label3->TabIndex = 11;
			this->label3->Text = L"\r\n";
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Honeydew;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(225, 262);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(320, 339);
			this->label4->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Honeydew;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(39, 538);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(506, 63);
			this->label5->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateGray;
			this->ClientSize = System::Drawing::Size(580, 744);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}

		
#pragma endregion
		void writeTo(const std::vector<char>& data)
		{
			std::ofstream filestream("ep.csv", std::ios::app);
			copy(data.begin(), data.end(), std::ostream_iterator<char>(filestream, ";"));
			filestream << "\n";
			filestream.close();
		}

		//тред пайпов
		BOOL FAR PASCAL PipesProc(LPSTR lpData)
		{
			TheadParms* ptp = (TheadParms*)lpData;     //переданный параметр - адрес общих данных
			DWORD       num;                            //количество переданых/прочитаных байт

			while (1)                                   //бесконечный цикл
			{
				WaitForSingleObject(ptp->hePipeStart, INFINITE);   //ждем бесконечно событие

				//передача данных
				WriteFile(ptp->child_in, ptp->send, lstrlenA(ptp->send), &num, NULL);   //передаем готовые данные
				std::cout << "Данные переданы: " << ptp->send;   
				//s1 = s1 + "\n" + "Данные переданы: ";
				label5->Text = "Данные переданы 2"; //выведем переданные данные здесь

				//чтение данных
				ReadFile(ptp->child_out, ptp->read, 1023, &num, NULL);                  //читаем ответ в буфер
				SetEvent(ptp->hePipeReply);                                             //и взводим событие готовности
			}
		}

String ^s1 = "";

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ifstream fh("ep.txt");
	string s;
	fh >> s;
	String^ str = gcnew String(s.c_str());
	label1->Text = str;

	SYSTEMTIME st;
	GetLocalTime(&st);
	label3->Text = "Кольцова Елизавета " + "\n" + "Время: " + st.wHour + ":" + st.wMinute + ":" + st.wSecond + " " + "\n" + "Дата: " + st.wYear + "-" + st.wMonth + "-" + st.wDay + " ";
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SetFileAttributes(L"ep.txt", FILE_ATTRIBUTE_READONLY);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ifstream fh("ep.csv");
	string s;
	fh >> s;
	String^ str = gcnew String(s.c_str());
	s1 = str;
	label2->Text = str;

	vector<char> myVector;

	string name = "ep.txt";

	ifstream fin;
	label5->Text = "Данные переданы: 2";
	fin.open(name);

	char ch;
	int numb;
	int numb2;
	numb = 0;
	numb2 = 1;

	ofstream fout;
	fout.open("ep.csv");

	cout << "\n\n";
	cout << "\nVector \n\n";
	while (fin.get(ch))
	{
		myVector.push_back(ch);
		numb++;


		cout << ch;
		fout << ch;
		if (numb)
		{
			fout << ";";
		}
		if (numb == 10)
		{
			fout << "\n";
			numb = 0;
			numb2++;
		}
	}


	writeTo(myVector);
	fout.close();
	fin.close();

	SYSTEMTIME st;
	GetLocalTime(&st);

	SECURITY_ATTRIBUTES sa;//атрибуты защиты канала
	sa.lpSecurityDescriptor = NULL; //защита по умолчанию
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = true;//разрешаем наследование дескрипторов

//обработка ошибок
	SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX | SEM_NOALIGNMENTFAULTEXCEPT);

	TheadParms tp = {};         //структура общих данных

	//создаем анонимные каналы
	CreatePipe(&tp.parent_out, &tp.child_in, &sa, 0); //канал для stdin дочернего процесса
	CreatePipe(&tp.child_out, &tp.parent_in, &sa, 0); //канал для stdout дочернего процесса

	system("start C:\\Users\\Администратор\\source\\repos\\testtest\\testtest\\ep.csv");

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	vector<char> myVector;

	string name = "ep.txt";

	ifstream fin;

	fin.open(name);

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт" << endl;
	}

	static char  buff[1024][1024];
	int i = 0;

	cout << "\n";


	cout << "\nНачальный вид файла\n\n";
	while (!fin.eof())
	{
		fin.getline(buff[i], sizeof(buff));
		cout << buff[i] << "\n";
		++i;
	}

	fin.close();

	fin.open(name);

	char ch;
	int numb;
	int numb2;
	numb = 0;
	numb2 = 1;

	ofstream fout;
	fout.open("ep.csv");

	cout << "\n\n";
	cout << "\nVector \n\n";
	while (fin.get(ch))
	{
		myVector.push_back(ch);
		numb++;

		
		cout << ch;
		fout << ch;
		if (numb)
		{
			fout << ";";
		}
		if (numb == 10)
		{
			//fout << "\n";
			numb = 0;
			numb2++;
		}
	}


	writeTo(myVector);
	fout.close();

	

	}



};
}

