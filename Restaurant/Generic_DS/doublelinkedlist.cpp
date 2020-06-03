#include "doublelinkedlist.h"
#include <iostream>
using namespace std;
doublelinkedlist::doublelinkedlist(){head=NULL;count=0;back=NULL;}
bool doublelinkedlist::delete_order(int Id)
{
	Order *ptr=head;
	while (ptr!=NULL)
	{
		if (head->GetID()==Id)
		{
			if(head->get_next()!=NULL)
			head=head->get_next();
			else
				head=NULL;
			delete ptr;
			count--;
			return true;
		}
		if(ptr->GetID()==Id)
		{
			ptr->get_prev()->set_next(ptr->get_next());
			ptr->get_next()->set_prev(ptr->get_prev());
			delete ptr;
			count--;
			return true;
			
		}
		ptr=ptr->get_next();

	}
	return false;
}
Order* doublelinkedlist::get_head()const{return head;}
void doublelinkedlist::add(Order* p)
{
	
	if (head==NULL)
	{
		back=p;
		head=p;
		count++;
		return;
	}
	head->set_prev(p);
	p->set_next(head);
	head=p;
	count++;
}
Order* doublelinkedlist::get_back()const
{if(count==0)
	return NULL;

	return back;}
doublelinkedlist::~doublelinkedlist()
{
	Order* ptr ;
	while (head!=NULL)
	{
		ptr=head;
		head=head->get_next();
		delete ptr;
	}
}
bool doublelinkedlist::isEmpty()
{
	if (head==NULL)
	{return true;}
	return false;
}