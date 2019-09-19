#include "MyVector.h"
#include <iostream>

using namespace std;

MyVector::MyVector()
{
	capacity = 0;
	int *ar = NULL;
}

MyVector::MyVector(int n)
{
	ar = new int[n]();
}

MyVector::MyVector(int n, int value)
{
	for (size_t i = 0; i < n; i++)
		ar[i] = value;
	
}

MyVector::MyVector(const MyVector& vec)
{
}

int MyVector::getCapacity() const
{
	return capacity;
}

void MyVector::addCapacity(int n)
{
	capacity += n;
}

void MyVector::pushBack(int val)
{
}

int MyVector::popBack()
{
	return 0;
}

void MyVector::insert(int index, int val)
{
}

int MyVector::remove(int index)
{
	return 0;
}

MyVector& MyVector::operator=(const MyVector& vec)
{
	// TODO: вставьте здесь оператор return
}
