#include "Motorcycle.h"

Motorcycle::Motorcycle()
{}

Motorcycle::Motorcycle(int id, int Speed, REGION rgion, STATUS sttus, Motor_TYPE motortyp)
{
    ID = id;
	speed = Speed;
	region = rgion;
	status = sttus;
	motorType = motortyp;
}

int Motorcycle::getID() const
{
	return ID;
}

int Motorcycle::getFinishTime() const
{
	return FinishTime;
}

int Motorcycle::getServiceTime() const
{
	return ServiceTime;
}

int Motorcycle::getSpeed() const
{
	return speed;
}

void Motorcycle::setFinishTime(int ft)
{
	FinishTime = ft;
}

void Motorcycle::setServiceTime(int st)
{
	ServiceTime = st;
}

void Motorcycle::setOrderID(int orderid)
{
	Order_ID = orderid;
}

int Motorcycle::getOrderID()
{
	return Order_ID;
}

void Motorcycle::setMotorType(Motor_TYPE a)
{
	motorType = a;
}

Motor_TYPE Motorcycle::getMotorType()
{
	return motorType;
}

void Motorcycle::setType(ORD_TYPE a)
{
	type = a;
}

ORD_TYPE Motorcycle::getType()const
{
	return type;
}

STATUS Motorcycle::getStatus()const
{
	return status;
}
void Motorcycle::setStatus(STATUS s)
{
	status = s;
}

Motorcycle::~Motorcycle()
{
}
