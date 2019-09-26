#include "MyVector.h"
#include <iostream>
using namespace std;

MyVector::MyVector() {
	size = capacity = 0;
	ar = NULL;
}
MyVector::MyVector(int n) {
	size = capacity = n;
	ar = new int[capacity];
	for (int i = 0; i < size; i++)
		ar[i] = 0;
}
MyVector::MyVector(int n, int value) {
	size = capacity = n;
	ar = new int[capacity];
	for (int i = 0; i < capacity; i++)
		ar[i] = value;
}
MyVector::MyVector(const MyVector &vec) {
	size = vec.size;
	capacity = vec.capacity;
	ar = new int[capacity];
	for (int i = 0; i < size; i++)
		ar[i] = vec.ar[i];
}
int MyVector::getCapacity() const {
	return capacity;
}
void MyVector::addCapacity(int n) {
	MyVector tmp = *this;
	delete[] ar;
	capacity += n;
	size = capacity;
	ar = new int[capacity+5];
	for (int i = 0; i < tmp.size; i++)
		ar[i] = tmp[i];
	for (int i = tmp.size; i < capacity; i++)
		ar[i] = 0;
}
void MyVector::pushBack(int val) {
	if (size > capacity)
		addCapacity(1);
	ar[size++] = val;
}
int MyVector::popBack() {
	int tmp = ar[--size];
	ar[size] = 0;
	return tmp;
}
void MyVector::insert(int index, int val) {
	if (index >= capacity) {
		addCapacity(index - capacity + 1);
		size = index;
	}
	ar[index] = val;
}
int MyVector::remove(int index) {
	int tmp = ar[index];
	for (int i = index; i < size - 1; i++)
		ar[i] = ar[i + 1];
	ar[--size] = 0;
	return tmp;
}
MyVector& MyVector:: operator=(const MyVector &vec) {
	if (this != &vec)
	{
		delete[] ar;
		size = vec.size;
		capacity = vec.capacity;
		ar = new int[capacity];
		for (int i = 0; i < vec.size; i++)
			ar[i] = vec.ar[i];
	}
	return *this;
}
