#include <iostream>
#include <cstddef>

#include "linkedlist.h"

Node::Node(int value_, Node *next_)
{
	value = value_;
	next = next_;
}

Linkedlist::Linkedlist()
{
	head = NULL;
}

Linkedlist::~Linkedlist() {
	Node *p;

	while (head != NULL) {
		p = head->next;
		delete head;
		head = p;
	}
}

bool
Linkedlist::isEmpty() const
{
	return head == NULL;
}

int
Linkedlist::operator[](int position)
{
	Node *p;
	int i;

	for (i = 0, p = head; i < position && p != NULL; i++, p = p->next) ;

	return p != NULL ? p->value : 0;
}

void
Linkedlist::insert(int value, int position)
{
	Node *p;
	int i;

	if (isEmpty() || position == 0) {
		head = new Node(value, head);
		return;
	}

	for (i = 0, p = head; i < position-1 && p->next != NULL; i++, p = p->next) ;

	p->next = new Node(value, p->next);
}

void
Linkedlist::dump() const
{
	std::cout << std::endl << "dump: [";

	for (Node *p = head; p != NULL; p = p->next) {
		std::cout << '<' << p->value << '>' << " -> ";
	}

	std::cout << "NULL" << ']' << std::endl;
}
