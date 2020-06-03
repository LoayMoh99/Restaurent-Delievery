#pragma once
#include "Events\Event.h"
class PromotionEvent :public Event
{
	double ExMoney;	//Total order money
public:
	PromotionEvent(int eTime, int oID, double ExM);
	//Add more constructors if needed
	
	virtual void Execute(Restaurant *pRest);	//override execute function
	~PromotionEvent();
};

