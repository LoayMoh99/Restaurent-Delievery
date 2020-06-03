#pragma once

#include"Rest\Order.h"
#include<iostream>
using namespace std;

class PriNode
{
private:
	double priority;
	Order* PtrOrder;
	PriNode* next; // Pointer to next node
public:
	PriNode();
	PriNode(Order&  r_Item);
	PriNode(Order&  r_Item, PriNode* nextNodePtr);
	void SetItemAndPri(Order&  r_Item);
	void setNext(PriNode* nextNodePtr);
	Order* getItem() const;
	PriNode* getNext() const;
	double getPri() const;
};

PriNode::PriNode()
{
	priority = 0;
	PtrOrder = NULL;
	next = nullptr;
}


PriNode::PriNode(Order& r_Item)
{
	SetItemAndPri(r_Item);
	next = nullptr;
}


PriNode::PriNode(Order& r_Item, PriNode* nextNodePtr)
{
	SetItemAndPri(r_Item);
	next = nextNodePtr;
}


void PriNode::SetItemAndPri(Order& r_Item)
{
	if (r_Item.GetType() != 3)
	{
		//cout << "Your Order MUST BE ==> VIP" << endl;
		return;
	}

	priority = (0.7*r_Item.GetMoney()) - (0.3* r_Item.GetArrTime() + 0.5*r_Item.GetDistance());

	PtrOrder = &r_Item;
}


void PriNode::setNext(PriNode* nextNodePtr)
{
	next = nextNodePtr;
}


Order* PriNode::getItem() const
{
	return PtrOrder;
}

PriNode* PriNode::getNext() const
{
	return next;
}

double PriNode::getPri() const
{
	return priority;
}