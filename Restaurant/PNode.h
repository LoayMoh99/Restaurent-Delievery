#pragma once

#include<iostream>
using namespace std;
template<typename t>
class PNode  //Priority Node
{
	t item;
	PNode<t>*next; // point to next node
	PNode<t>*previous; // point to previous node
	double priority;

public:
	PNode();
	PNode(const t&); //a copy constructor
	void SetNext(PNode<t>*);
	void SetPrevious(PNode<t>*);
	PNode<t>* GetNext()const;
	PNode<t>* GetPrevious()const;
	void SetItem(t&);
	void SetPriority(double&);
	PNode<t>& operator++();
	PNode<t>& operator--();
	bool operator>(PNode<t>*&);
	bool operator<(PNode<t>*&);
	t GetItem()const;
	int GetPriority() const;
	~PNode();
};


template<typename t>
PNode<t>::PNode():previous(NULL),next(NULL)
{}
//////////////////////////////////////////////////////////////////////////
template<typename t>
void PNode<t>::SetNext(PNode<t>*n)
{
	next = n;
}
/////////////////////////////////////////////////////////////////////////
template<typename t>
void PNode<t>::SetPrevious(PNode<t>*p)
{
	previous = p;
}
/////////////////////////////////////////////////////////////////////////
template<typename t>
PNode<t>* PNode<t>::GetPrevious()const 
{
	return previous ;
}
///////////////////////////////////////////////////////////////////////////
template<typename t>
PNode<t>* PNode<t>::GetNext()const
{
	return next;
}
/////////////////////////////////////////////////////////////////////////////
template<typename t>
t PNode<t>::GetItem()const
{
	return item;
}
///////////////////////////////////////////////////////////////////////////////
template<typename t>
void PNode<t>::SetItem(t&e)
{
	item = e;
}
//////////////////////////////////////////////////////////////////////
template<typename t>
int PNode<t>::GetPriority()const
{
	return priority;
}
///////////////////////////////////////////////////////////////////////////////
template<typename t>
void PNode<t>::SetPriority(double&pri)
{
	priority = pri;
}
//////////////////////////////////////////////////////////////////////
template<typename t>
PNode<t>::PNode(const t&e):previous(NULL),next(NULL)
{
	item = e;
}
///////////////////////////////////////////////////////////////////////////
//template<typename t>
//PNode<t>& PNode<t>::operator++(){
//	this = this->next;
//	return *this;
//}
/////////////////////////////////////////////////////////////////////////////
//template<typename t>
//PNode<t>& PNode<t>::operator--() {
//	this = this->previous;
//	return *this;
//}
///////////////////////////////////////////////////////////////////////////
template<typename t>
bool PNode<t>::operator>(PNode<t>* &a) {
	return priority > a->GetPriority();
}
//////////////////////////////////////////////////////////////////////////////////
template<typename t>
bool PNode<t>::operator<(PNode<t>* &a) {
	return priority < a->GetPriority();
}
///////////////////////////////////////////////////////////////////////////
template<typename t>
PNode<t>::~PNode()
{}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//