// Author::    Chirantan Mitra
// Copyright:: Copyright (c) 2013-2025. All rights reserved
// License::   MIT

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <string>

class Linkedlist
{
	struct Node
	{
		int value;
		Node *next;

		Node(int value_, Node *next_);
	};

private:
	Node *head;

public:
	Linkedlist();
	~Linkedlist();
	bool isEmpty() const;
	int operator[](int position);
	void insert(int value, int position);
	std::string dump() const;
};

#endif
