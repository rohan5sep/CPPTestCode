#include "Animal.h"
#include "IntArray.h"
#include <sstream>

IntArray GetIntArray()
{
	IntArray r(5);

	for (int i = 0; i < 5; i++)
	{
		r[i] = (i * 2);

		//
		// r.operator[](i);
	}
	return r;
}

void ConstTest(const IntArray& r)
{

}

void CatCatcher(Cat cat)
{
	cout << "I am a cat " << cat.CatName() << endl;
}

void PostIncreamentTest(const IntArray& r)
{
	cout << "PostIncreamentTest " << r;
}
int main()
{
	IntArray r(5) ;
	IntArray x(10);

	x = r;

	stringstream ss("10 11 12 13 14");

	ss >> r;
	cout << r;

	PostIncreamentTest(++r);

	cout << "After PostIncreamentTest " << r; 

	Dog dog("Tommy");

	CatCatcher(dog) ;

	// 1. Overload + operator
	// 2. Write a class called BoundingBox 
	//	and overload < operator (optional)
	// 3. Write class called Integer which can hold big numbers 
	// overload + operator 
	// 4. Write SmartPoiner class for IntArray

	return 0;
}