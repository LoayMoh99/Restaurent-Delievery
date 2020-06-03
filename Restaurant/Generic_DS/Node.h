
#ifndef __NODE_H_
#define __NODE_H_

template < typename T>
class Node
{
private :
	T item; // A data item
	Node<T>* next; // Pointer to next node
	int priVal ; // Pri Value
public :
	Node();
	Node( const T & r_Item);	//passing by const ref.
	Node( const T & r_Item, Node<T>* nextNodePtr);
	Node( const T & r_Item, const int & pV);	//passing by const ref.
	Node( const T & r_Item, Node<T>* nextNodePtr, const int & pV);
	void setItem( const T & r_Item);
	void setNext(Node<T>* nextNodePtr);
	void setPV( int pV);
	T getItem() const ;
	Node<T>* getNext() const ;
	int getPV() const ;
}; // end Node


template < typename T>
Node<T>::Node() 
{
	next = nullptr;
	pV = 0;
} 

template < typename T>
Node<T>::Node( const T& r_Item)
{
	item = r_Item;
	next = nullptr;
	priVal=0;
} 

template < typename T>
Node<T>::Node( const T& r_Item, Node<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
	priVal=0;
}

template < typename T>
Node<T>::Node( const T& r_Item, const int & pV)
{
	item = r_Item;
	next = nullptr;
	priVal = pV;
} 

template < typename T>
Node<T>::Node( const T& r_Item, Node<T>* nextNodePtr, const int & pV)
{
	item = r_Item;
	next = nextNodePtr;
	priVal = pV;
}

template < typename T>
void Node<T>::setItem( const T& r_Item)
{
	item = r_Item;
} 

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template < typename T>
void Node<T>::setPV( int pV)
{
	priVal=pV;
} 

template < typename T>
T Node<T>::getItem() const
{
	return item;
} 

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
} 

template <typename T>
int Node<T>:: getPV() const
{
	return priVal;
}

#endif