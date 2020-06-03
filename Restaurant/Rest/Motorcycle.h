#ifndef __MOTORCYCLE_H_
#define __MOTORCYCLE_H_


#include "..\Defs.h"

#pragma once
class Motorcycle	
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding motorcycle type 
	int speed;		//meters it can move in one clock tick (in one timestep)
	REGION	region;	//region of the motorcycle
	STATUS	status;	//idle or in-service
	int ServiceTime;
	int FinishTime; //two service time
	int AvaliabilityTime;
	int Order_ID;
	Motor_TYPE motorType;

public:
	Motorcycle();
	Motorcycle(int id, int Speed, REGION rgion, STATUS sttus,  Motor_TYPE motortyp);
	int getID() const;
	int getFinishTime() const;
	int getServiceTime() const;
	int getSpeed() const;
	void setFinishTime(int ft);
	void setServiceTime(int st);
	void setType(ORD_TYPE a);
	ORD_TYPE getType()const;
	void setOrderID(int orderid);
	int getOrderID();
	void setMotorType(Motor_TYPE a);
	Motor_TYPE getMotorType();
	STATUS getStatus()const;
	void setStatus(STATUS s);
	virtual ~Motorcycle();
};

#endif