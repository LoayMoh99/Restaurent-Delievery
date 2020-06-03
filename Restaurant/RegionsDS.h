#pragma once

#include"Rest\Motorcycle.h"
#include "Rest\Order.h"
#include "PriQueue.h"		  												//DS of VIP
#include "Generic_DS\Queue.h"										//DS of FRZ 
#include "SortingList.h"													//DS of Motorcycle(Available && Assigned)
#include "DoubleLinkedList.h"											//DS of NRM

#define MaxMotorcycleCount 200
class RegionsDS
{
public:
	PriQueue<Order*>  VIPs;
	DoubleLinkedList<Order*> NRMs;  
	Queue<Order*> FRZs;
	SortingList<Motorcycle*>AvaliableFASTMotor;
	SortingList<Motorcycle*>AssignedFASTMotor;
	SortingList<Motorcycle*>AvaliableNRMLMotor;
	SortingList<Motorcycle*>AssignedNRMLMotor;
	SortingList<Motorcycle*>AvaliableFRZNMotor;
	SortingList<Motorcycle*>AssignedFRZNMotor;
	Motorcycle * MotorcycleListForPrinting[MaxMotorcycleCount];
	int MotorcycleCountForPrinting;
	Motorcycle * MotorcyclePrinting[MaxMotorcycleCount];
	int MotorcycleCPrinting;
	int NoMotorCycles[3];  //0=Fast  ,  1=Normal    , 2=Frozen
	int avg_service,avg_wait;
	double As_froz=0, Aw_froz=0;
	double As_VIP=0, Aw_VIP=0;
	double As_norm=0, Aw_norm=0;
	void set_avg_service(int x)
	{
		avg_service=x;
	}
	void set_avg_wait(int x)
	{
		avg_wait=x;
	}
	int get_avg_service() 
	{if((NoOrders[0] + NoOrders[1] + NoOrders[2])!=0)
		return (As_froz + As_norm + As_VIP) / (NoOrders[0] + NoOrders[1] + NoOrders[2]);
	return 0;
	}
	int get_avg_wait()
	{if((NoOrders[0] + NoOrders[1] + NoOrders[2])!=0)
		return (Aw_froz + Aw_norm + Aw_VIP) / (NoOrders[0]+ NoOrders[1]+ NoOrders[2]);
	return 0;
	}
	int NoActiveOrders[3];   //0=Fast  ,  1=Normal    , 2=Frozen
	int NoOrders[3];   //0=Fast  ,  1=Normal    , 2=Frozen
	RegionsDS()
	{
		NoActiveOrders[0]=0;
		NoActiveOrders[1]=0;
		NoActiveOrders[2]=0;
		///////////////////////////////
		NoOrders[0]=0;
		NoOrders[1]=0;
		NoOrders[2]=0;
		///////////////////////////////
		NoMotorCycles[0]=0;
		NoMotorCycles[1]=0;
		NoMotorCycles[2]=0;
		MotorcycleCountForPrinting = 0;
		MotorcycleCPrinting = 0;
	}
	int get_number_of_orders()const
	{
		return NoOrders[0]+NoOrders[1]+NoOrders[2];
	}

	bool CancelNRMOrder(int id ,Order*& o)
	{
		if (NRMs.getitemAtPosition(id,o)){       ;
		NRMs.deleteItem(o);
		NoActiveOrders[1]--;
		NoOrders[1]--;
		return true;
	}
	return false;
	}

	bool promotion(int id, Order*&o)
	{
		return CancelNRMOrder(id, o);
	}

	bool AutoP(int a,Order* o)
	{
		if(o->GetWaiting()>=a)
		{
			return promotion(o->GetID(),o);
		}
	}

	bool AllInSerIsEmpty()
	{
		return AssignedFASTMotor.isempty() && AssignedFRZNMotor.isempty() && AssignedNRMLMotor.isempty(); 
	}

	void AddToMotorcycleList(Motorcycle*MC)
	{
		
		Motorcycle*newMC = MC;
		MotorcycleListForPrinting[MotorcycleCountForPrinting] = newMC;
		MotorcycleCountForPrinting++;
	}

	void RemoveFromMotorcycleList(Motorcycle*MC)
	{
		int index = -1;
		for (int i = 0; i < MotorcycleCountForPrinting; i++)
		{
			if (MC->getID() == MotorcycleListForPrinting[i]->getID())
			{
				index = i;
				break;
			}
		}
		if (index == -1)
			return;
		Motorcycle * Temp = MotorcycleListForPrinting[index];
		for (int i = index; i < MotorcycleCountForPrinting - 1; i++)
		{
			MotorcycleListForPrinting[i] = MotorcycleListForPrinting[i + 1];
		}
		MotorcycleCountForPrinting--;
		
		Temp = nullptr;
	}

	void AddToMotorcycleListPrinting(Motorcycle*MC)
	{

		Motorcycle*newMC = MC;
		MotorcyclePrinting[MotorcycleCPrinting] = newMC;
		MotorcycleCPrinting++;
	}
	

	string  OptimizingMotorcyclePrintingList(int i)
	{
		string r;
		if (i == 0)
			r = 'A';
		else if (i == 1)
			r = 'B';
		else if (i == 2)
			r = 'C';
		else
			r = 'D';
		string Message = "Region " + r + ": ";
		string motortypestring;
		string ID;
		string ORDERID;
		string ORDERType;

		for (int i = 0; i < MotorcycleCountForPrinting; i++)
		{

			Motor_TYPE motortype = MotorcycleListForPrinting[i]->getMotorType();
			if (motortype == TYPE_FAStmotor)
				motortypestring = "V";
			else if (motortype == TYPE_NRMmotor)
				motortypestring = "N";
			else
				motortypestring = "F";
			ID = to_string(MotorcycleListForPrinting[i]->getID());
			ORDERID = to_string(MotorcycleListForPrinting[i]->getOrderID());
			ORD_TYPE ordertype = MotorcycleListForPrinting[i]->getType();
			if (ordertype == TYPE_VIP)
				ORDERType = "V";
			else if (ordertype == TYPE_NRM)
				ORDERType = "N";
			else
				ORDERType = "F";

			Message = Message + motortypestring + ID + "(" + ORDERType + ORDERID + ") -";

		}

		return Message;
	}

	string  OptimizingMotorcyclePrinting(int i)
	{
		string r1;
		if (i == 0)
			r1 = 'A';
		else if (i == 1)
			r1 = 'B';
		else if (i == 2)
			r1 = 'C';
		else
			r1 = 'D';
		string Message1 = "Region " + r1 + ": ";
		string motortypestring1;
		string ID1;
		string ORDERID1;
		string ORDERType1;

		for (int i = 0; i < MotorcycleCPrinting; i++)
		{

			Motor_TYPE motortype1 = MotorcyclePrinting[i]->getMotorType();
			if (motortype1 == TYPE_FAStmotor)
				motortypestring1 = "V";
			else if (motortype1 == TYPE_NRMmotor)
				motortypestring1 = "N";
			else
				motortypestring1 = "F";
			ID1 = to_string(MotorcyclePrinting[i]->getID());
			ORDERID1 = to_string(MotorcyclePrinting[i]->getOrderID());
			ORD_TYPE ordertype = MotorcyclePrinting[i]->getType();
			if (ordertype == TYPE_VIP)
				ORDERType1 = "V";
			else if (ordertype == TYPE_NRM)
				ORDERType1 = "N";
			else
				ORDERType1 = "F";

			Message1 = Message1 + motortypestring1 + ID1 + "(" + ORDERType1 + ORDERID1 + ") -";

		}
		int z = MotorcycleCPrinting;
		for (int i = z; i>0; i--)
		{
			MotorcyclePrinting[i] = nullptr;
			MotorcycleCPrinting--;

		}
		return Message1;
	}
};