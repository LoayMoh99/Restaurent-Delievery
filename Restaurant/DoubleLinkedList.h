#pragma once
#include<iostream>
#include"DNode.h"
#include "Rest\Order.h"
#include "Rest\Motorcycle.h"
using namespace std;
template<typename t>
class DoubleLinkedList // this list will be used to store elements in a sorted way 
{
	DNode<t>*head; //head of the list
	DNode<t>*tail; // tail is a node point to the last element in the list
	int count;
	DNode<t> *itemPosition(t&)const;
public:
	DoubleLinkedList();
	bool isempty()const;
	void insert(t&e);// insert from the back
	bool deleteItem(t&);// delete nodethat contain the item sent item
	bool peekfront(t&); // get the front element
	bool deletefront();
	bool getitemAtPosition(t,t&);

	~DoubleLinkedList();
};





///////////////////////////////////////////////////////////////////////////////
template<typename t>
DoubleLinkedList<t>::DoubleLinkedList(): count(0)
{
	head = new DNode<t>;
	tail = new DNode<t>;
	head->SetNext(tail);
	tail->SetPrevious(head);
}
///////////////////////////////////////////////////////////////////////////
template<typename t>
DNode<t>* DoubleLinkedList<t>::itemPosition(t& e) const //it return the first node that contains the element smaller than or equal=> (e) 
{ 
	DNode<t>*trans = tail->GetPrevious();
	while (trans != head && e != trans->GetItem())
	{

		trans = trans->GetPrevious();
	return trans;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
void DoubleLinkedList<t>::insert(t&e) {
	DNode<t>* New = new DNode<t>(e);
	 
		New->SetNext(tail);
		New->SetPrevious(tail->GetPrevious());
		tail->GetPrevious()->SetNext(New);
		tail->SetPrevious(New);
		count++;
		return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool DoubleLinkedList<t>::isempty()const {
	return head->GetNext() == tail;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool DoubleLinkedList<t>::peekfront(t&e) {
	if (isempty())
		return false;
	e = head->GetNext()->GetItem();
	return true;



}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool DoubleLinkedList<t>::deleteItem(t&e){
	DNode<t>*item = itemPosition(e);
	if (item == head)
		return false;
	DNode<t>*p = item->GetPrevious();
	DNode<t>*n = item->GetNext();
	p->SetNext(n);
	n->SetPrevious(p);
	delete item;
	count--;
	return true;


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool DoubleLinkedList<t>::deletefront() {

	if (isempty())
		return false;
	DNode<t>*old = head->GetNext();
	head->SetNext(old->GetNext());
	old->GetNext()->SetPrevious(head);
	count-- ;
	return true;


}
/////////////////////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool DoubleLinkedList<t>::getitemAtPosition(t e,t& a) {
	DNode<t>*tr = tail->GetPrevious();
	while (tr != head && tr->GetItem()!=e )
		tr = tr->GetPrevious();
	a = tr->GetItem();
	return tr!=head;

}
////////////////////////////////////////////////////////////////////////////
template<typename t>
DoubleLinkedList<t>::~DoubleLinkedList()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <>
//template specification for Orders pointer
class DoubleLinkedList<Order*> // this list will be used to store elements in a sorted way 
{
	DNode<Order*>* head; //head of the list
	DNode<Order*>* tail; // tail is a node point to the last element in the list
	int count;
	DNode<Order*>* itemPosition( Order*&e)const //it return the first node that contains the element smaller than or equal=> (e) 
	{ 
		DNode<Order*>* trans = tail->GetPrevious();
		while (trans != head && *trans->GetItem() != *e) 
		{
			trans = trans->GetPrevious();
		}
			return trans;
	}
public:
	int get_avg_serv() const
	{
		DNode<Order*>* t=NULL;
		t=head;
		int time=0;
		for (int i=0;i<count;i++)
		{
			if(t!=NULL)
				time=time+t->GetItem()->GetServTime();
			t=t->GetNext();
		}
		int avg;
		if(count!=0)
		avg=time/count;
		else
			avg=0;
		return avg;
	}
	int get_avg_wait() const
	{
		DNode<Order*>* t=head;
		int time=0;
		for (int i=0;i<count;i++)
		{
			if(t!=NULL)
			time=time+t->GetItem()->GetWaiting();
			t=t->GetNext();
		}
		int avg;
		if(count!=0)
		avg=time/count;
		else
			avg=0;
		return avg;


	}
	DoubleLinkedList() : count(0)
	{
		head = new DNode<Order*>;
		tail = new DNode<Order*>;
		head->SetNext(tail);
		tail->SetPrevious(head);
	}
	int get_count()const
	{
		return count;
	}
	//////////////////////////////////////////////////////////////////////////////////////
	bool isempty()const {
		return head->GetNext() == tail;
	}
	////////////////////////////////////////////////////////////////////////////////////
	void insert(Order*& e) {
		DNode<Order*>* New = new DNode<Order*>(e);

		New->SetNext(tail);
		New->SetPrevious(tail->GetPrevious());
		tail->GetPrevious()->SetNext(New);
		tail->SetPrevious(New);
		count++;
		return;
}// insert from the back
	//////////////////////////////////////////////////////////////////////////////////////////////
	bool deleteItem(Order*&e)	// delete nodethat contain the item sent item
	{
		DNode<Order*>* item = itemPosition(e);
		if (item == head)
			return false;
		DNode<Order*> * p = item->GetPrevious();
		DNode<Order*> * n = item->GetNext();
		p->SetNext(n);
		n->SetPrevious(p);
		delete item;
		count--;
		return true;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool peekfront(Order*&e) {// get the front element
		if (isempty())
			return false;
		e = head->GetNext()->GetItem();
		return true;



	} 
	DNode<Order*>* get_head()
	{
		return head;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	bool deletefront() {

		if (isempty())
			return false;
		DNode<Order*>* old = head->GetNext();
		head->SetNext(old->GetNext());
		old->GetNext()->SetPrevious(head);
		count--;
		return true;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool getitemAtPosition(int e , Order*& a)
	{
		DNode<Order*>* tr = tail->GetPrevious();
		while (tr != head && *tr->GetItem() != e)
			tr = tr->GetPrevious();
		a = tr->GetItem();
		return tr != head;

	}
////////////////////////////////////////////////////////////////////////////////////////

	~DoubleLinkedList() {}
};

///////////////////////////////////////
//template specification for Motorcycles pointer
template<>
class DoubleLinkedList<Motorcycle*> // this list will be used to store elements in a sorted way 
{
	DNode<Motorcycle*>* head; //head of the list
	DNode<Motorcycle*>* tail; // tail is a node point to the last element in the list
	int count;
	DNode<Motorcycle*>* itemPosition( Motorcycle*&e)const //it return the first node that contains the element smaller than or equal=> (e) 
	{ 
		DNode<Motorcycle*>* trans = tail->GetPrevious();
		while (trans != head && trans->GetItem()->getID() != e->getID()) 
		{
			trans = trans->GetPrevious();
		}
			return trans;
	}
public:
	DoubleLinkedList() : count(0)
	{
		head = new DNode<Motorcycle*>;
		tail = new DNode<Motorcycle*>;
		head->SetNext(tail);
		tail->SetPrevious(head);
	}
	//////////////////////////////////////////////////////////////////////////////////////
	bool isempty()const {
		return head->GetNext() == tail;
	}
	////////////////////////////////////////////////////////////////////////////////////
	void insert(Motorcycle*& e) {
		DNode<Motorcycle*>* New = new DNode<Motorcycle*>(e);

		New->SetNext(tail);
		New->SetPrevious(tail->GetPrevious());
		tail->GetPrevious()->SetNext(New);
		tail->SetPrevious(New);
		count++;
		return;
}// insert from the back
	//////////////////////////////////////////////////////////////////////////////////////////////
	bool deleteItem(Motorcycle*&e) {// delete nodethat contain the item sent item
	
		DNode<Motorcycle*>* item = itemPosition(e);
		if (item == head)
			return false;
		DNode<Motorcycle*> * p = item->GetPrevious();
		DNode<Motorcycle*> * n = item->GetNext();
		p->SetNext(n);
		n->SetPrevious(p);
		delete item;
		count--;
		return true;


	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool peekfront(Motorcycle*&e) {// get the front element
		if (isempty())
			return false;
		e = head->GetNext()->GetItem();
		return true;



	} 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	bool deletefront() {

		if (isempty())
			return false;
		DNode<Motorcycle*>* old = head->GetNext();
		head->SetNext(old->GetNext());
		old->GetNext()->SetPrevious(head);
		count--;
		return true;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool getitemAtPosition(int e , Motorcycle*& a)
	{
		DNode<Motorcycle*>* tr = tail->GetPrevious();
		while (tr != head && tr->GetItem()->getID() != e)
			tr = tr->GetPrevious();
		a = tr->GetItem();
		return tr != head;

	}
////////////////////////////////////////////////////////////////////////////////////////

	~DoubleLinkedList() {}
};





