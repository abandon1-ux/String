//String.cpp
#include "String.h"
#include <cstring>
#include <iomanip>
String::String(const char* s)
{
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}

String::String(const String& Str, int pos, int n)
{
	int i, m;
	m = strlen(Str.str);
	if (pos > m)
	{
		str = new char[1];
		str[0] = '\0';
		return;
	}
	if (m - pos < n) n = m - pos;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = Str.str[pos + i];
	str[i] = '\0';
}

String::String(const char* s, int n)
{
	int i, m = strlen(s);
	if (m < n) n = m;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = s[i];
	str[i] = '\0';
}

String::String(int n, char c)
{
	int i;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = c;
	str[i] = '\0';
}

String::String(const String& Str)
{
	str = new char[strlen(Str.str) + 1];
	strcpy(str, Str.str);
}

String& String::operator=(const String& Str)
{
	if (&Str == this) return *this;
	delete[] str;
	str = new char[strlen(Str.str) + 1];
	strcpy(str, Str.str);
	return *this;
}

String::~String()
{
	if (str != NULL)
		delete[] str;
}
ostream& operator<<(ostream& out, const String& Str)
{
	out << Str.str;
	return out;
}

istream& operator>>(istream& in, String& Str)
{
	char str[1000];
	in >> str;
	Str = str;				// 利用转换构造函数（自动转换），再利用赋值运算
	return in;
}
