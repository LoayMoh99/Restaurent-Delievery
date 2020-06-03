#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include <fstream>
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "..\Events\cancel_event.h"
#include "..\Generic_DS\doublelinkedlist.h"
#include "../RegionsDS.h"
#include "Order.h"

// it is the maestro of the project

class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	RegionsDS Arr[4]; //Regions' DS for each region(A,B,C,D)
	
	int Auto, numEv, Timestep;

	SortingList<Order*> list_of_orders;
	int number_of_orders;


public:
	
	Restaurant();
	~Restaurant();
	void AddEvent(Event* pE);	//adds a new event to the queue of events
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();
	void LoadFile();
	ORD_TYPE chartoOrdT(const char &o);
	REGION chartoReg(const char &r);
	void AddtoVIPs(Order* po);	
	void AddtoNRMs(Order* po);	
	void AddtoFRZs(Order* po);	
	void InterActiveMode();
	void StepByStepMode();
	void SilentMode();
	Order* remove_order(int id);
	GUI* getInterface() const ;

	void AssignVIPtoMC(Order *&pOrd,int ts);
	void AssignNRMtoMC(Order *&pOrd,int ts);
	void AssignFRZtoMC(Order *&pOrd,int ts);
	void ReturnMCs(int TS);
	bool AutoProm(Order* o);

	void promoteOrder(int id, int money);
	bool AllRegionInsServEmpty();
	void save_output_file();
	void Add_to_list_of_orders(Order*p);
};

#endif