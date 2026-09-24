#include <iostream>
#include"MyString.h"
using namespace std;
istream& operator>>(istream& s, MyString& obj) {
	obj.CinString();
	return s;
}
ostream& operator<<(ostream& s, MyString& obj) {
	obj.Print();
	return s;
}
int main() {
	MyString obj1("Hello");
	MyString obj2("sa");
	obj1.MyDelChr('l');
	obj1.Print();
	obj1.MyStrCat(obj2);
	obj1.Print();
	cout << "sds"<<endl;
	cin >> obj1;
	obj1.Print();
	cout << obj1;
}