#pragma once

#include<iostream>
using namespace std;
template<typename t>
class DNode
{
	t item;
	DNode<t>*next; // point to next node
	DNode<t>*previous; // point to previous node

public:
	DNode();
	DNode(const t&); //a copy constructor
	void SetNext(DNode<t>*);
	void SetPrevious(DNode<t>*);
	DNode<t>* GetNext()const;
	DNode<t>* GetPrevious()const;
	void SetItem(t&);
	DNode<t>& operator++();
	DNode<t>& operator--();
	t GetItem()const;
	~DNode();
};


template<typename t>
DNode<t>::DNode():previous(NULL),next(NULL)
{

}
//////////////////////////////////////////////////////////////////////////
template<typename t>
void DNode<t>::SetNext(DNode<t>*n) {
	next = n;
}
/////////////////////////////////////////////////////////////////////////
template<typename t>
void DNode<t>::SetPrevious(DNode<t>*p) {
	previous = p;
}
/////////////////////////////////////////////////////////////////////////
template<typename t>
DNode<t>* DNode<t>::GetPrevious()const {
	return previous ;
}
///////////////////////////////////////////////////////////////////////////
template<typename t>
DNode<t>* DNode<t>::GetNext()const {
	return next;
}
/////////////////////////////////////////////////////////////////////////////
template<typename t>
t DNode<t>::GetItem()const {
	return item;
}
///////////////////////////////////////////////////////////////////////////////
template<typename t>
void DNode<t>::SetItem(t&e) {
	item = e;
}
//////////////////////////////////////////////////////////////////////
template<typename t>
DNode<t>::DNode(const t&e):previous(NULL),next(NULL)
{
	item = e;
}
///////////////////////////////////////////////////////////////////////////
template<typename t>
DNode<t>& DNode<t>::operator++(){
	this = this->next;
	return *this;
}
///////////////////////////////////////////////////////////////////////////
template<typename t>
DNode<t>& DNode<t>::operator--() {
	this = this->previous;
	return *this;
}
///////////////////////////////////////////////////////////////////////////
template<typename t>
DNode<t>::~DNode()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//