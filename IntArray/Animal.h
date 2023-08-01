
#include <iostream>

using namespace std;


class Animal
{
	int m_id{};
public:
	Animal() {}
	void MakeSound();
	void Attack() {} // ?

	int GetID() { return m_id; }
	void SetID(int id) { m_id = id; }
};

class Cat
{
	string m_name{};

public:
	explicit Cat(string name) : m_name(name){ 
		cout << "Cat::Cat() my name is " << m_name << endl;
	}
	string GetName() { return m_name; }

	Cat(){ cout << "Cat::Cat()" << endl; }

	bool CatName() {
		cout << m_name << endl;
		return !m_name.empty();
	}
	

	
	virtual ~Cat() { cout << "~Cat::Cat()" << endl; }
};

class Dog
{
	Cat m_cat{};
	string m_name;
public:
	Dog(Cat cat) { cout << "you are inside Dog..." << endl; }
	Dog(string str) : m_name(str){}

	operator Cat() { return Cat(m_name); }
};