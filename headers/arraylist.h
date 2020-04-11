// Author::    Chirantan Mitra
// Copyright:: Copyright (c) 2013-2020. All rights reserved
// License::   MIT

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

class Arraylist
{
private:
	int capacity;
	int tail;
	int *values;

public:
	Arraylist(int capacity);
	~Arraylist();
	bool isEmpty() const;
	int operator[](int position);
	void insert(int value, int position);
	std::string dump() const;
};

#endif
