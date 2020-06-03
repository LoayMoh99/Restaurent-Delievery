#pragma once
#include "Events\Event.h"
class CancelationEvent :
	public Event
{

public:
	CancelationEvent(int eTime, int oID);

	//virtual void Execute(Restaurant *pRest);	//override execute function
	virtual ~CancelationEvent();
};

