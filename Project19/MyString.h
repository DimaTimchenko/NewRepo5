#pragma once
#include <iostream>

class MyString
{
	char* str;
	int l;

public:
	MyString();
	MyString(const char* s);
	MyString(int size);
	void Print();
	void CinString();
	~MyString();
	MyString MyStrcpy(MyString& obj);
	int GetL();
	bool MyStrStr(const char* str);
	char operator[](int index);
	int MyChr(char c);
	void MyDelChr(char c);
	MyString& operator=(const MyString& obj);
	void MyStrCat(MyString& b);
	int MyStrCmp(MyString& b);
	char* GetStr() {
		return str;
	}
};