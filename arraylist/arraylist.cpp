#include <iostream>
#include <cstddef>

#include "arraylist.h"

Arraylist::Arraylist(int capacity_)
{
	capacity = capacity_;
	values = new int[capacity];
	empty = true;

	for (int i = 0; i < capacity; i++) {
		values[i] = 0;
	}
}

bool
Arraylist::isEmpty() const
{
	return empty;
}

int
Arraylist::operator[](int position)
{
	return values[position];
}

void
Arraylist::insert(int value, int position)
{
	empty = false;

	for (int i = capacity - 1; i > position - 1; i--) {
		values[i + 1] = values[i];
	}

	values[position] = value;
}

void
Arraylist::dump() const
{
	std::cout << std::endl << "dump: [";

	for (int i = 0; i < capacity; i++) {
		std::cout << '<' << values[i] << "> -> ";
	}

	std::cout << "NULL" << ']' << std::endl;
}
