#include "PromotionEvent.h"
#include "Rest\Restaurant.h"


PromotionEvent::PromotionEvent(int eTime, int oID, double ExM):Event(eTime, oID)
{
	ExMoney = ExM;
}

void PromotionEvent::Execute(Restaurant* pRest)
{
	//The promotion excution
	pRest->promoteOrder(OrderID, ExMoney);
	pRest->getInterface()->SortType();
	
}

PromotionEvent::~PromotionEvent()
{
}
