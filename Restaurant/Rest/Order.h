#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, Frozen, VIP
	REGION Region;  //Region of this order
	int Distance;	//The distance (in meters) between the order location and the resturant 
	                
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times
	int WaitingTime;
	int DeliveryPeriod;
	//
	// TODO: Add More Data Members As Needed
	//
	Order* prev;
	Order*next;
public:
	Order (int ID,int AT);
	Order(int ID, ORD_TYPE r_Type, REGION r_region,int AT);
	Order(int ID, ORD_TYPE r_Type, REGION r_region, double mon , int dist,int AT);
	virtual ~Order();

	int GetID() const;

	int GetType() const;
	REGION GetRegion() const;

	void SetDistance(int d);
	int GetDistance() const;
	void set_next(Order* p);
	void set_prev(Order* p);
	Order* get_next()const;
	Order* get_prev()const;
	void ChangeType(); //change the order type to vip (When promoted)
	void SetArrTime(int AT);
	int GetArrTime() const;

	void SetServTime(int ST);
	int GetServTime() const;

	int GetFinishTime() const;

	void SetMoney(double M);
	int GetMoney() const;

	void setWaitingTime(int wt);
	int GetWaiting() const;

	bool operator==(Order&);
	bool operator!=(int)const;
	bool operator!=(Order&)const;
	ORD_TYPE getType()const;
	void setType(ORD_TYPE o);
};

#endif