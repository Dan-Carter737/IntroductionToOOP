#include<iostream>
using namespace std;

#define delimeter "\n-----------------\n"

//#define CONSTRUCTORS_CHECK

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

	Fraction(int inteder, int numerator, int denominator)
	{
		this->integer = inteder;
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

	void print() const
	{
		if (integer)cout << integer; // Åñëè åñòü öåëàÿ ÷àñòü - âûâîäèì åå íà ýêðàí
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
	void to_proper(int numerator, int denominator)
	{
		if (numerator > denominator) {
			integer = numerator / denominator;
			this->numerator = numerator % denominator;

		}
		else {
			cout << "Äðîáü ÿâëÿåòñÿ ïðàâèëüíîé" << endl;

		}
	}
	/*void to_improper(int numerator, int denominator, int integer)
	{
		int numerator = integer * denominator + numerator;

	}*/
};


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

	Fraction Test;
	//Test.set_numerator(45);
	//Test.set_denominator(12);
	Test.print();
	Test.to_proper(58, 22);
	Test.print();

}