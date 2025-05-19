// Author::    Chirantan Mitra
// Copyright:: Copyright (c) 2013-2025. All rights reserved
// License::   MIT

#include <sstream>
#include <cstddef>

#include "arraylist.h"

Arraylist::Arraylist(int capacity_)
{
	capacity = capacity_;
	tail = -1;
	values = new int[capacity];

	for (int i = 0; i < capacity; i++) {
		values[i] = 0;
	}
}

Arraylist::~Arraylist()
{
	delete[] values;
}

bool
Arraylist::isEmpty() const
{
	return tail == -1;
}

int
Arraylist::operator[](int position)
{
	return values[position];
}

void
Arraylist::insert(int value, int position)
{
	tail++;
	position = position > tail ? tail : position;

	for (int i = capacity - 2; i > position - 1; i--) {
		values[i + 1] = values[i];
	}

	values[position] = value;
}

std::string
Arraylist::dump() const
{
	std::ostringstream s;

	s << "[ ";

	for (int i = 0; i < capacity; i++) {
		s << "<" << values[i] << "> -> ";
	}

	s << "NULL ]";

	return s.str();
}
