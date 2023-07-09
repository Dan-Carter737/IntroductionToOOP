#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator * (Fraction left, Fraction right);

#define delimeter "\n-----------------\n"

//#define CONSTRUCTORS_CHECK
//#define ARIPHMETICAL_OPERATORS_CHECK
//#define COMPARISONS_OPERATORS_CHECK
//#define OPERATORS_PLUS_MINUS
#define INPUT_CHECK_1 

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)  denominator = 1;
		this->denominator = denominator;
	}

	//           Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor: \t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Single_Constructor: \t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor: \t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy_Constructor: \t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor: \t" << this << endl;
	}

	//                         Operators

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy_Assignment: \t" << this << endl;
		return *this;
	}


	//        Methods

	Fraction& reduce()
	{
		/*int more, less, rest;
if (numerator > denominator) more = numerator, less = denominator;
else less = numerator, more = denominator;*/
		to_proper();
		int less = numerator;
		int more = denominator;
		int rest;
		if (less == 0) return *this;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // Greatest Common Divisor (наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;

	}

	void print() const
	{
		if (integer)cout << integer; // Если есть целая часть - выводим ее на экран
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
	Fraction& to_proper()
	{

		integer += numerator / denominator;
		numerator = numerator % denominator;
		return *this;

	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted() const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& operator *= (const Fraction& other)
	{
		return *this = *this * other;
	}
};

Fraction operator * (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator / (Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/
	return left * right.inverted();

}

bool operator == (Fraction left, Fraction right)
{
	/*left.to_improper;
	right.to_improper;
	if (left.get_numerator * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/

	return (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator());
}
bool operator != (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator >= (const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
}
bool operator <= (const Fraction& left, const Fraction& right)
{
	return !(left > right);

}
std::ostream& operator <<(std::ostream& os, const  Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator >> (std::istream& is, Fraction& obj)
{
	/*if (in)
	{
		int numerator, denominator;
		in >> numerator >> denominator;
		obj.set_numerator(numerator);
		obj.set_denominator(denominator);
	}
	return in;*/
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_denominator(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;*/
	const int SIZE = 256;
	char buffer[SIZE] = {};
	is >> buffer;
	//is.getline(buffer, SIZE);

	int number[3] = {};
	int n = 0; // счетчик введенных чисел 
	char delimitors[] = "()/";
	for (char* pch = strtok(buffer, delimitors); pch; pch = strtok(NULL, delimitors))
		number[n++] = std::atoi(pch); // from a to i ASKI-string to 'int' принимает строку и вовзращает целое число, которое содержится в этой сроке
	//for (int i = 0; i < n; i++) cout << number[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1: obj.set_denominator(number[0]); break;
	case 2:obj = Fraction(number[0], number[1]); break;
		//case 2: obj.set_denominator(number[1]); break;
	case 3: obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);
		break;
	}
	return is;

}
Fraction operator +(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	if (left.get_denominator() != right.get_denominator()) {
		int nok = left.get_denominator() * right.get_denominator();
		return Fraction
		(
			((left.get_numerator() * right.get_denominator()) + (left.get_denominator() * right.get_numerator())), nok
		);
	}
	else if (left.get_denominator() == right.get_denominator()) {
		int nok = left.get_denominator();
		return Fraction
		(
			(left.get_numerator() + right.get_numerator()), nok
		);
	}
}
Fraction operator -(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	if (left.get_denominator() != right.get_denominator()) {
		int nok = left.get_denominator() * right.get_denominator();
		return Fraction
		(
			(left.get_numerator() * right.get_denominator()) - (left.get_denominator() * right.get_numerator()), nok
		);
	}
	else if (left.get_denominator() == right.get_denominator()) {
		int nok = left.get_denominator();
		return Fraction
		(
			(left.get_numerator() - right.get_numerator()), nok
		);
	}
}

void main()
{

	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C; //Copy_Constructor
	E.print();

	Fraction F;
	F = D;
	F.print();

#endif 

#ifdef ARIPHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.to_improper();
	A.print();

	Fraction B(3, 16, 20);
	B.to_proper();
	B.print();

	/*Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();*/

	A *= B;
	A.print();
#endif

#ifdef COMPARISONS_OPERATORS_CHECK

	Fraction A(1, 3);
	Fraction B(5, 10);
	cout << (A <= B) << endl;

#endif 

#ifdef OPERATORS_PLUS_MINUS

	Fraction A(2, 5);
	Fraction B(1, 5);
	Fraction C = A + B;
	A.print();
	B.print();
	C.print();
	//A.reduce();
	//A.print();

#endif

#ifdef INPUT_CHECK_1 
	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif 
}
