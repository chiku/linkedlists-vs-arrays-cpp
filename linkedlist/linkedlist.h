#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct Node
{
	int value;
	Node *next;

	Node();
	Node(int value_, Node *next_);
};

class Linkedlist
{
private:
	Node *head;

public:
	Linkedlist();
	~Linkedlist();
	bool isEmpty() const;
	int operator[](int position);
	void insert(int value, int position);
	void dump() const;
};

#endif
