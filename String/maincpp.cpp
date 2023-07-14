#include<iostream>
using namespace std;


#define MOVE 

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
//:: Scope operator оператор разрешения видимости
int String::get_size() const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//ключевое слово explicit о использовать ТОЛЬКО внутри класса. При помощи этого слова мы только объявляем метод, но он реализуется БЕЗ explicit
String::String(int size /* = 80 */ ) : size(size), str(new char [size] {}) //Параметры по умолчанию пишутся ТОЛЬКО в протатипе функции
{

	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)

{
	for (int i = 0; str[i]; i++) this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{


	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str) // Конструктор переноса 
{

	//str = other.str;
	//size = other.size;

	other.str = nullptr;
	other.size = 0;


}

String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

String operator +(const String& left, const String& right);

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();


}
String& String::operator = (String&& other) // Оператор переноса 
{
	if (this != &other)
	{
	}
	delete[] str;
	str = other.str;
	size = other.size;

	other.str = nullptr;
	other.size = 0;

	cout << "MOVE_Assignment:\t" << this << endl;
	return *this;
}
String& String::operator = (const String& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String operator +(const String& left, const String& right)
{
	/*const int a = 2;
	a = 3;*/
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];

	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

char String::operator[](int i) const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

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
