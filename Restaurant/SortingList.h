#pragma once
#include"DNode.h"
#include "Rest\Motorcycle.h"
template<typename t>
class SortingList  
{
	DNode<t>*head;
	DNode<t>*tail;
public:
	SortingList();
	bool insertDesc(t&); // insert descendingly according to the speed(Motorcycles)
	void insertAsc(t&); // insert ascendingly according to the finish time(Motorcycles)
	bool remove(t&); //remove from front
	bool isempty()const;
	bool peekfront(t&)const;
	~SortingList();
};

/////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
SortingList<t>::SortingList()
{
	head = new DNode<t>; tail = new DNode<t>;
	head->SetNext(tail); tail->SetPrevious(head);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
void SortingList<t>::insertAsc(t&e)
{
	DNode<t>*n = new DNode<t>(e);
	if (n == NULL)
		return ;
	if (isempty()) {
		n->SetNext(tail);
		n->SetPrevious(head);
		tail->SetPrevious(n);
		head->SetNext(n);
		return;
	}
	DNode<t>*t = tail->GetPrevious();
	while (t != head && e < t->GetItem())
		t = t->GetPrevious();
	t->GetNext()->SetPrevious(n);
	n->SetNext(t->GetNext());
	t->SetNext(n);
	n->SetPrevious(t);
}

template<typename t>
bool SortingList<t>::insertDesc(t&e) {
	DNode<t>*n = new DNode<t>(e);
	if (n == NULL)
		return false;
	if (isempty()) {
		n->SetNext(tail);
		n->SetPrevious(head);
		tail->SetPrevious(n);
		head->SetNext(n);
		return true;
	}
	DNode<t>*t = tail->GetPrevious();
	while (t != head && e > t->GetItem())
		t = t->GetPrevious();
	t->GetNext()->SetPrevious(n);
	n->SetNext(t->GetNext());
	t->SetNext(n);
	n->SetPrevious(t);
	return true;

}
//////////////////////////////////////////////////////////////////////////////
template<typename t>
bool SortingList<t>::isempty()const { return head->GetNext() == tail; }
/////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool SortingList<t>::remove(t&e){ 
	if (isempty())
		return false;
	DNode<t>*o = head->GetNext();
	head->SetNext(o->GetNext());
	o->GetNext()->SetPrevious(head);
	e = o->GetItem();
	delete o;


}
////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool SortingList<t>::peekfront(t&e)const {
	if (isempty())
		return false;
	e = head->GetNext()->GetItem();
	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
SortingList<t>::~SortingList()
{
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Template specialization for (Motorcycle*) type
/////////////////////////////////////////////////////////////////////////////////////////
template<>
class SortingList <Motorcycle*>
{
	DNode<Motorcycle*>*head;
	DNode<Motorcycle*>*tail;
public:


SortingList()
{
	head = new DNode<Motorcycle*>; tail = new DNode<Motorcycle*>;
	head->SetNext(tail); tail->SetPrevious(head);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void insertAsc(Motorcycle*&e) 
{
	DNode<Motorcycle*>*n = new DNode<Motorcycle*>(e);
	if (n == NULL)
		return ;
	if (isempty()) {
		n->SetNext(tail);
		n->SetPrevious(head);
		tail->SetPrevious(n);
		head->SetNext(n);
		return;
	}
	DNode<Motorcycle*>*t = tail->GetPrevious();
	while (t != head && e->getFinishTime() < t->GetItem()->getFinishTime())
		t = t->GetPrevious();
	t->GetNext()->SetPrevious(n);
	n->SetNext(t->GetNext());
	t->SetNext(n);
	n->SetPrevious(t);

}
bool insertDesc(Motorcycle*&e) 
{
	DNode<Motorcycle*>*n = new DNode<Motorcycle*>(e);
	if (n == NULL)
		return false;
	if (isempty())
	{
		n->SetNext(tail);
		n->SetPrevious(head);
		tail->SetPrevious(n);
		head->SetNext(n);
		return true;
	}
	DNode<Motorcycle*>*t = tail->GetPrevious();
	while (t != head && e->getSpeed() >= t->GetItem()->getSpeed())
		t = t->GetPrevious();
	t->GetNext()->SetPrevious(n);
	n->SetNext(t->GetNext());
	t->SetNext(n);
	n->SetPrevious(t);
	return true;

}
//////////////////////////////////////////////////////////////////////////////
bool isempty()const
{ 
	return head->GetNext() == tail;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool remove(Motorcycle*&e)
{ 
	if (isempty())
		return false;
	DNode<Motorcycle*>*o = head->GetNext();
	head->SetNext(o->GetNext());
	o->GetNext()->SetPrevious(head);
	e = o->GetItem();
	delete o;
	return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

bool peekfront(Motorcycle*&e)const
{
	if (isempty())
		return false;
	e = head->GetNext()->GetItem();
	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
~SortingList()
{
}

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Template specialization for (Order*) type
/////////////////////////////////////////////////////////////////////////////////////////
template<>
class SortingList <Order*>
{
	DNode<Order*>*head;
	DNode<Order*>*tail;
public:


	SortingList()
	{
		head = new DNode<Order*>; tail = new DNode<Order*>;
		head->SetNext(tail); tail->SetPrevious(head);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	void insertAsc(Order*&e)
	{
		DNode<Order*>*n = new DNode<Order*>(e);
		if (n == NULL)
			return;
		if (isempty()) {
			n->SetNext(tail);
			n->SetPrevious(head);
			tail->SetPrevious(n);
			head->SetNext(n);
			return;
		}
		DNode<Order*>*t = tail->GetPrevious();
		while (t != head && e->GetFinishTime() < t->GetItem()->GetFinishTime())
			t = t->GetPrevious();
		t->GetNext()->SetPrevious(n);
		n->SetNext(t->GetNext());
		t->SetNext(n);
		n->SetPrevious(t);

	}
	bool insertDesc(Order*&e)
	{
		DNode<Order*>*n = new DNode<Order*>(e);
		if (n == NULL)
			return false;
		if (isempty())
		{
			n->SetNext(tail);
			n->SetPrevious(head);
			tail->SetPrevious(n);
			head->SetNext(n);
			return true;
		}
		DNode<Order*>*t = tail->GetPrevious();
		while (t != head && e >= t->GetItem())
			t = t->GetPrevious();
		t->GetNext()->SetPrevious(n);
		n->SetNext(t->GetNext());
		t->SetNext(n);
		n->SetPrevious(t);
		return true;

	}
	//////////////////////////////////////////////////////////////////////////////
	bool isempty()const
	{
		return head->GetNext() == tail;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	bool remove(Order*&e)
	{
		if (isempty())
			return false;
		DNode<Order*>*o = head->GetNext();
		head->SetNext(o->GetNext());
		o->GetNext()->SetPrevious(head);
		e = o->GetItem();
		delete o;
		return true;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool peekfront(Order*&e)const
	{
		if (isempty())
			return false;
		e = head->GetNext()->GetItem();
		return true;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	~SortingList()
	{
	}

};