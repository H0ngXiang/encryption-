

#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdio>
#include <clocale>
#include <iomanip>
#include <algorithm>
#include<array>
#include <conio.h>
#include <cstring>
#include <fcntl.h>
#include <io.h>
#include <cstring>
#include <locale>
#include <codecvt>
using namespace std;
int wmain(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	std::wcout  <<L"Русский" << std::endl;
	return 0;
}
constexpr bool IsRussianChar1251(const char c)
{

	return (c >= 'А' && c <= 'я') || c == 'ё' || c == 'Ё';
}
int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, ".1251");
	string s, str, strh;
	int x, y;
    double kolrus;
	double kol;
	double l;
	std::ofstream out;          
	out.open("C:/Users/guani/source/repos/ConsoleApplication17/ConsoleApplication17/chastota.txt"); 
	/*std::wifstream ifs("C:/Users/guani/source/repos/ConsoleApplication17/ConsoleApplication17/warandpeace1.txt");*/
	ifstream fin("C:/Users/guani/source/repos/ConsoleApplication17/ConsoleApplication17/warandpeace.txt");
	std::ifstream inf{ "C:/Users/guani/source/repos/ConsoleApplication17/ConsoleApplication17/warandpeace.txt" };
	if (!inf)
	{
		std::cerr << "файл не найден" << std::endl;
		return 1;
	}
	while (!fin.eof()) {


		getline(fin, strh);
		str += strh;
		if (!fin.eof()) {
			str += '\n';
		}
		for (int i = 0; str[i]; i++)
		{
			if (isalpha(static_cast<unsigned char>(str[i])))
				s += tolower(str[i]);
		}
		sort(s.begin(), s.end());
		
		x = y = l = 0;
		kol = 0;
		kolrus = 0;
		for (int i = 0; i < s.length(); i++) {
			kol += 1;
			if (IsRussianChar1251(s[i])) {
				kolrus += 1;
			}
		}
		cout << "Число вхождений русской буквы (по алфавиту) с процентами:" << endl;
		cout << kolrus << " русских символов" << endl;
		cout << kol << " всего символого" << endl;
		if (out.is_open())
			out << "Число вхождений русской буквы (по алфавиту) с процентами:" << endl;
			out << kolrus << " русских символов" << endl;
			out << kol << " всего символого" << endl;
			for (int i = y; s[i]; i++)
			{
				if (IsRussianChar1251(s[i])) {
					if (s[i] == s[i + 1])
					{
						x++;
					}
					else
					{
						y = x;
						x++;
						l = (x * 100) / kol;
						cout.precision(3);
						cout << "количество буквы " << "(" << s[i] << ")" << ": " << x << " процент вхождения: " << l << endl;
						out << "количество буквы " << "(" << s[i] << ")" << ": " << x << " процент вхождения: " << l << endl;
						x = 0;
					}
				}
			}
	
		system("pause");
		return 0;
	
	}
}