#pragma once

#include "Rest\Order.h"
#include "PriQueue.h"						//DS of VIP
#include "List.h"								//DS of NRM
#include "Generic_DS\Queue.h"		//DS of FRZ &
													//DS of Motorcycle (TO BE CHANGED) 


class RegionsDS
{
	PriQueue<Order*> VIPs;
	//List<Order*> NRMs;   {{to be completed}}
	Queue<Order*> FRZs;
	Queue<Order*> Motors;
};