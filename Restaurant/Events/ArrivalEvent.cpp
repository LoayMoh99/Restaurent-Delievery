#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg ,double mon , int dist):Event(eTime, oID)
{
	OrdType = oType;
	OrdRegion = reg;
	OrdDistance = dist;
	OrdMoney = mon;
	OrdAT = eTime;
}

void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create and order and and fills its data 
	// Then adds it to normal, frozen, or VIP order lists that you will create in phase1
	Order* pOrd = new Order(OrderID,OrdType,OrdRegion,OrdMoney,OrdDistance,OrdAT);
	switch (OrdType)
	{
	case 2: //VIP
		pRest->AddtoVIPs(pOrd);
		break;
	case 1: //Frozen
		pRest->AddtoFRZs(pOrd);
		break;
	case 0: //Normal
		pRest->AddtoNRMs(pOrd);
		break;
	}
	//pRest->Add_to_list_of_orders(pOrd);
	pRest->getInterface()->AddOrderForDrawing(pOrd);
}
