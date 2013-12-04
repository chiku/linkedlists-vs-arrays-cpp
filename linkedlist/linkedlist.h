#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

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
