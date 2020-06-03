#include "Order.h"

Order::Order(int id,int AT)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	WaitingTime=0;
	ArrTime = AT;
	ServTime = 0;
}

Order::Order(int id, ORD_TYPE r_Type, REGION r_region,int AT)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	Region = r_region;	
	WaitingTime=0;
	ArrTime =AT;
	ServTime = 0;
}

Order::Order(int id, ORD_TYPE r_Type, REGION r_region, double mon , int dist,int AT)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	Region = r_region;	
	totalMoney = mon;
	Distance = dist;
	ArrTime = AT;
	WaitingTime=0;
	ServTime = 0;
}

Order::~Order()
{
}

int Order::GetID() const
{
	return ID;
}
Order* Order::get_next()const
{return next;}
Order* Order::get_prev()const
{
	return prev;
}
void Order::set_next(Order* ptr)
{
	next=ptr;
}
void Order::set_prev(Order *ptr)
{
	prev=ptr;
}

int Order::GetType() const
{
	return type;
}

ORD_TYPE Order::getType()const
{
	return type;
}

REGION Order::GetRegion() const
{
	return Region;
}

void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}

void Order::SetArrTime(int AT)
{
	ArrTime = AT > 0 ? AT : 0;
}
int Order::GetArrTime() const
{
	return ArrTime;
}

void Order::SetServTime(int ST)
{
	ServTime = ST > 0 ? ST : 0;
}
int Order::GetServTime() const
{
	return ServTime;
}

int Order::GetFinishTime() const
{
	return ArrTime+WaitingTime+ServTime;
}

void Order::SetMoney(double M)
{
	totalMoney = M > 0 ? M : 0;
}
int Order::GetMoney() const
{
	return totalMoney;
}

void Order::setWaitingTime(int wt)
{
	WaitingTime=wt;
}
int Order::GetWaiting() const
{
	return WaitingTime;
}

void Order::ChangeType()
{
	type = TYPE_VIP;
}

bool Order::operator==(Order&o) {
	return ID == o.ID;
}

bool Order::operator!=(int a) const {
	return this->ID != a;
}

bool Order::operator!=(Order& a) const {
	return this->ID  != a.ID;
}

void Order::setType(ORD_TYPE o)
{
	type =o;
}