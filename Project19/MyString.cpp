#include <string.h>
#include "MyString.h"
#include <iostream>

using namespace std;

MyString::MyString()
{
	l = 80;
	str = new char[l + 1];
	str[l] = '\0';
}

MyString::MyString(const char* s)
{
	l = strlen(s);
	str = new char[l + 1];
	strcpy_s(str, l + 1, s);
}

MyString::MyString(int size)
{
	l = size;
	str = new char[l + 1];
	str[l] = '\0';
}

void MyString::Print()
{
	cout << str << endl;
}

void MyString::CinString()
{
	char rez[100];
	cin >> rez;
delete[] str;          
	l = strlen(rez);       
	str = new char[l + 1]; 
	strcpy_s(str, l + 1, rez); 
}

MyString::~MyString()
{
	delete[] str;
	cout << "destructor" << endl;
}

MyString MyString::MyStrcpy(MyString& obj)
{
	delete[] str;
	l = obj.l;
	str = new char[l + 1];
	strcpy_s(str, l + 1, obj.str);
	return str;
}

int MyString::GetL()
{
	return l;
}

bool MyString::MyStrStr(const char* t)
{
	if (strstr(str, t) != nullptr) {
		return true;
	}
	return false;
}

char MyString::operator[](int index)
{
	if (index >= 0 && index <= l) {
		return str[index];
	}
	return -1;
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < l; i++) {
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}

void MyString::MyDelChr(char c)
{
	int temp = 0;
	for (int i = 0; i < l; i++) {
		if (str[i] == c) {
			temp++;
		}
	}
	char* newstr = new char[l - temp + 1];
	int j = 0;
	for (int i = 0; i < l; i++) {
		if (str[i] == c) {
			continue;
		}
		newstr[j] = str[i];
		j++;
	}
	newstr[j] = '\0';
	delete[] str;
	str = newstr;
	l = l - temp;
}

MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj) {
		return *this;
	}
	if (str != nullptr) {
		delete[] str;
		l = 0;
	}
	l = obj.l;
	str = new char[l + 1];
	strcpy_s(str, l + 1, obj.str);
	return *this;
}

void MyString::MyStrCat(MyString& b)
{
	int newsize = l + b.l;
	int i = 0;
	char* newstr = new char[newsize + 1];
	for (i = 0; i < l; i++) {
		newstr[i] = str[i];
	}
	for (int j = 0; j < b.l; j++) {
		newstr[i] = b.str[j];
		i++;
	}
	newstr[i] = '\0';
	delete[] str;
	l = newsize;
	str = newstr;
}

int MyString::MyStrCmp(MyString& b)
{
	if (strcmp(str, b.str) < 0) {
		return -1;
	}
	else if (strcmp(str, b.str) > 0) {
		return 1;
	}
	else {
		return 0;
	}
}