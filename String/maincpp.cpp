#include<iostream>
#include <String.h>
using namespace std;


#define MOVE


/// <summary>
/// /////////////////////////////////////////////////////////////////////////////////////// ОБъявление класса 
/// </summary>

#ifdef OLD
class String
{
	int size;	//размер строки в Байтах
	char* str;	//адрес строки в динамической памяти
public:
	int get_size() const;
	const char* get_str() const;
	char* get_str();
	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);



	~String();
	//                         Operators:
	String& operator = (const String& other);
	String& operator = (String&& other);


	char operator[](int i) const;
	char& operator[](int i);




	//						Methods:
	void print()const;
};


////////////////////////////////////////////////////////////////////////////////конец объявления класса
// 
// //////////////////////////////////////////////////////////////// Определение класса 
//:: Scope operator оператор разрешения видимости
String operator +(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
#endif // OLD

#include "MyString.h"
/// <summary>
/// ////////////////////////////////////////////////////////////////конец определения класса 
/// </summary>

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef MOVE
	cout << sizeof("Hello") << endl;
	String str(5);
	str.print();
	5.;

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + " " + str2;
	cout << str3 << endl;

	String str4;
	str4 = str1 + str2;
	cout << str4 << endl;

	String str6 = str1 + str2;
	cout << "str6 = " << str6 << endl;

#endif


	


}
