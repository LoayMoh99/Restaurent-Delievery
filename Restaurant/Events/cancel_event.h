#pragma once
#include "Event.h"
class cancel_event:public Event
{
//private: 
//	int id; 
//	//int etime;
public:
	cancel_event(int order_id,int order_time);
	virtual void Execute(Restaurant *pRest);	

};