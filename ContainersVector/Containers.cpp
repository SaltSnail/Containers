#include "Containers.h"

#include "Containers.h"
#include <iostream>
using namespace std;

MyArray::MyArray() {
	size = 0;
	ar = NULL;
}
MyArray::MyArray(int n) {
	size = n;
	ar = new int[size]();
}
MyArray::MyArray(const MyArray& ar) {
	this->size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < size; i++)
		this->ar[i] = ar.ar[i];
}
int MyArray::getSize() const {
	return size;
}
int MyArray::getCapacity() const {
	return size;
}
void MyArray::show() const {
	for (int i = 0; i < size; i++)
		cout << ar[i] << ' ';
}
void MyArray::addCapacity(int n) {
	MyArray tmp = *this;
	delete[] ar;
	size += n;
	ar = new int[size];
	for (int i = 0; i < size - n; i++)
		ar[i] = tmp.ar[i];
	for (int i = size - n; i < size; i++)
		ar[i] = 0;
}

int& MyArray :: operator[](int index) {
	if (index < 0 || index >= size)
		throw 0;
	return ar[index];
}
MyArray& MyArray :: operator=(const MyArray& ar) {
	if (this != &ar)
	{
		delete[] this->ar;
		this->size = ar.size;
		this->ar = new int[size];
		for (int i = 0; i < size; i++)
			this->ar[i] = ar.ar[i];
	}
	return *this;
}

MyArray :: ~MyArray() {
	if (ar != NULL)
		delete[] ar;
}

Container :: ~Container() {
	size = 0;
}


