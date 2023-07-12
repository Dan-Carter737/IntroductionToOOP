#include <iostream>
using namespace std;



	class StringHome
	{
		int size;
		char* data;

	public:

		int get_size() const
		{
			return size;
		}

		int get_size()
		{
			return size;
		}

		char* get_data()
		{
			return data;
		}

		// Constructors

		explicit StringHome(int size)
		{
			this->size = size;
			this->data = new char [size] {};
			cout << "DefConstructor:\t" << this << endl;
		}

		StringHome(const char* data)
		{
			this->size = strlen(data) + 1;
			this->data = new char [size] {};
			for (int i = 0; data[i]; i++) this->data[i] = data[i];
			cout << "Constructor:\t" << this << endl;
		}

		StringHome(const StringHome& other)
		{
			this->size = other.size;
			this->data = new char[size] {};
			for (int i = 0; i < size; i++) this->data[i] = other.data[i];
			cout << "Constructor:\t" << this << endl;
		}

		StringHome(StringHome&& other) noexcept
		{
			size = other.size;
			data = other.data;

			other.size = 0;
			other.data = 0;
		}
		~StringHome()
		{
			delete[] data;
			cout << "Destructor:\t" << this << endl;
		}


		//Operators

		StringHome& operator =(const StringHome& other)
		{
			if (this == &other) return *this;
			delete[] this->data;
			this->data = new char[size] {};
			for (int i = 0; i < size; i++) this->data[i] = other.data[i];
			cout << "CopyAssignment:\t" << this << endl;
			return *this;
		}

		StringHome& operator = (StringHome&& other) // Оператор переноса 
		{
			if (this == &other)
			{
				return *this;
			}
			delete[] data;
			data = other.data;
			size = other.size;

			other.data = nullptr;
			other.size = 0;

			cout << "MOVE_Assignment:\t" << this << endl;
			return *this;
		}


		char operator[](int i) const
		{
			return data[i];
		}
		char& operator[](int i)
		{
			return data[i];
		}

		//Methods

		void print() const
		{
			cout << "Size " << size << endl;
			cout << "Data " << data << endl;
		}
	};



	StringHome operator +(const StringHome& left, const StringHome& right)
	{
		StringHome cat(left.get_size() + right.get_size() - 1);
		for (int i = 0; i < left.get_size(); i++)
			
			cat[i] = left[i];

		for (int i = 0; i < right.get_size(); i++)
			
			cat[i + left.get_size() - 1] = right[i];
		return cat;
	}

	std::ostream& operator<<(std::ostream& os, StringHome& obj)
	{
		return os << obj.get_data();
	}


	void main() {


		setlocale(LC_ALL, "");

		StringHome FirstStr = "Good";
		StringHome SecondStr = "Weather";
		StringHome ThirdStr = FirstStr + SecondStr;

		cout << ThirdStr << endl;


	}