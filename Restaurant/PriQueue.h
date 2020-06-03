#pragma once
#include"PNode.h"
#include "Rest\Order.h"
template<typename t>
class PriQueue                     //a priorityQueue
{
	PNode<t>*head;
	PNode<t>*rear;
	PNode<t>* Sortback(PNode<t>*); //find the position of the item that keep the list sorted descendingly according to the priority
	int count;
public:
	PriQueue();
	bool isEmpty()const;
	bool enqueue(t&);
	bool dequeue(t&);
	bool  peekfront (t&frntEntry)const;
	int get_count() const;
	~PriQueue();
};


template<typename t>
PriQueue<t>::PriQueue():count(0)
{
	head = new PNode<t>; rear = new PNode<t>;
	head->SetNext(rear); rear->SetPrevious(head);
}
////////////////////////////////////////////////////////////////////////////
template<typename t>
bool PriQueue<t>::isEmpty()const
{
	return head->GetNext() == rear;
}
////////////////////////////////////////////////////////////////////////////
template<typename t>
int PriQueue<t>::get_count()const
{
	return count;
}
///////////////////////////////////////////////////////////////////////
template<typename t>
bool PriQueue<t>::enqueue(t&e)
{
	PNode<t>*New = new PNode<t>(e);
	if (New == NULL)
		return false;
	if (isEmpty()) 
	{
		head ->SetNext(New);
		New->SetPrevious(head);
		rear->SetPrevious(New);
		New->SetNext(rear);
		count++;
		return true;
	}
	
	PNode<t>*beforeitem = Sortback(New);
	if(beforeitem==head)
	{
		New->SetNext(head->GetNext());
		head->SetNext(New);
		New->SetPrevious(head);
		New->GetNext()->SetPrevious(New);
		count++;
		return true;
	}
	PNode<t>*afteritem = beforeitem->GetNext();
	afteritem->SetPrevious(New);
	New->SetNext(afteritem);
	beforeitem->SetNext(New);
	New->SetPrevious(beforeitem);
	count++;
	return true;
}

///////////////////////////////////////////////////////////////////////      
template<typename t>
PNode<t>* PriQueue<t>::Sortback(PNode<t>* e) 
{
	PNode<t>*backtrk = rear->GetPrevious();
	while (backtrk != head && e > backtrk) /////
	backtrk=backtrk->GetPrevious();
	return backtrk;

}
////////////////////////////////////////////////////////////////////////////
template<typename t>
bool PriQueue<t>::dequeue(t&e){
	if (isEmpty())
		return false;
	PNode<t>*old = head->GetNext();
	head->SetNext(old->GetNext());
	old->GetNext()->SetPrevious(head);
	e = old->GetItem();
	delete old;
	count--;
	return true;
}
/////////////////////////////////////////////////////////////////////////
template<typename t>
bool PriQueue<t>::peekfront(t&frntEntry)const{
	if (!isEmpty()) {
		frntEntry = head->GetNext()->GetItem();
		return true;
}
	return false;
}
////////////////////////////////////////////////////////////////////////////
template<typename t>
PriQueue<t>::~PriQueue()
{
}