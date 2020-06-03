#include "cancel_event.h"

#include "..\Rest\Restaurant.h"
cancel_event::cancel_event( int oID,int eTime):Event(eTime, oID)
{
}


void cancel_event::Execute(Restaurant* pRest) // remove item
{
	Order* pOrd=NULL;
	pOrd = pRest->remove_order(OrderID);
	if (pOrd != NULL)
		pRest->getInterface()->DeleteOrderFromList(pOrd);

}
