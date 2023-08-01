#include <iostream>
#include <string.h>
using namespace std;


class IntArray
{
	int *m_intArray{};
	int m_quantity{};

public:
	// X(X&)
	// Constructors
	//
	IntArray(const IntArray& r) {
		cout << "IntArray::IntArray(const IntArray&)" << endl;

		*this = r;
	}
	IntArray(unsigned quantity = 1) : m_quantity(quantity){
		m_intArray = new int[quantity];
		cout << "IntArray::IntArray(unsigned quantity)" << endl;
	}

	 ~IntArray(){ cout << "IntArray::~IntArray()" << endl;
		delete[]m_intArray;
	}

	// Accessors and mutators
	//
	void Set(unsigned index, int value) { 
		m_intArray[index] = value; 
	}

	int Get(unsigned index) {
		return m_intArray[index];
	}

	// Operators
	//
	int& operator[](unsigned index)
	{
		return m_intArray[index];
	}
	//
	IntArray& operator=(const IntArray& right)
	{
		cout << "IntArray& operator=(const IntArray& right)" << endl;

		if (this == &right) { return *this; }
		// perform copy
		//
		this->m_quantity = right.m_quantity;

		if(m_intArray != nullptr){ 
			delete[]m_intArray;
		}
		this->m_intArray = new int[m_quantity];

		memcpy(m_intArray, right.m_intArray, sizeof(int) * m_quantity);

		return *this;
	}

	friend istream& operator>>(istream& in, IntArray& right)
	{
		cout << "istream& operator>>(istream& in, IntArray& right)" << endl;
		for (int i = 0; i < right.m_quantity; i++)
		{
			in >> right.m_intArray[i];
		}

		return in;
	}

	friend ostream& operator<<(ostream& out, const IntArray& right)
	{
		cout << "ostream& operator<<(ostream& out, IntArray& right)" << endl;
		for (int i = 0; i < right.m_quantity; i++)
		{
			out << " " << right.m_intArray[i] << " ";
		}

		return out;
	} 

	IntArray& operator++()
	{
		for (int i = 0; i < m_quantity; i++)
		{
			++m_intArray[i];
		}

		return *this;
	}

	IntArray operator++(int)
	{
		IntArray r = *this;
		for (int i = 0; i < m_quantity; i++)
		{
			m_intArray[i]++;
		}

		return r;
	}
};


