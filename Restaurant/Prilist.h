#pragma once
#include"Prinode.h"


class PriList
{
	PriNode*Head;
	int count;
public:
	PriList();
	bool isEmpty();
	void Add(Order& O);
	Order* remove();
};

PriList::PriList()
{
	Head = NULL;
	count = 0;
}

bool PriList::isEmpty()
{
	if (Head == NULL)
		return true;

	return false;
}

void PriList::Add(Order& O)
{
	PriNode*ptr = new PriNode(O);
	PriNode*p = Head;
	PriNode*temp=NULL;

	if (isEmpty())
	{
		Head = ptr;
		return;
	}
	while (p != NULL)
	{
		
		if (p->getPri() >= ptr->getPri())
		{
			temp = p;
			p = p->getNext();
			if (p == NULL)
			{
				temp->setNext(ptr);
				ptr->setNext(p);
				return;
			}
		}
		else
		{
			if (temp == NULL)
			{
				ptr->setNext(Head);
				Head = ptr;
				return;

			}
			temp->setNext(ptr);
			ptr->setNext(p);
			return;
		}

		
	}

}

Order*PriList::remove()
{
	if (isEmpty())
		return NULL;

	PriNode*temp = Head;
	Order*O;
	
	O = Head->getItem();
	Head = Head->getNext();
	delete temp;
	temp = NULL;
	return O;
}
