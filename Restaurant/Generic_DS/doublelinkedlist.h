
#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST
#include "..\Rest\Order.h"

class doublelinkedlist
{
private:
	Order *head;
	Order* back;
	int count;
public:
	doublelinkedlist();
	void add(Order *p);
	Order* get_back()const;
	Order* get_head()const;
	bool isEmpty();
	~doublelinkedlist();
	bool delete_order(int Id);
};

#endif