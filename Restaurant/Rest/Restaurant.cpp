#include <cstdlib>

#include <iostream>
#include <time.h>
using namespace std;

#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
#include "..\Events\cancel_event.h"
#include "..\PromotionEvent.h"

Restaurant::Restaurant() 
{
	pGUI = NULL;
	number_of_orders=0;
	Timestep = 0;
	
}

GUI* Restaurant::getInterface() const 
{
	return pGUI;
}

Order* Restaurant::remove_order(int id)
{
	Order* c = NULL;
	if(Arr[0].CancelNRMOrder(id,c)|| Arr[1].CancelNRMOrder(id,c)|| Arr[2].CancelNRMOrder(id,c)|| Arr[3].CancelNRMOrder(id,c))
			return c;
	else return NULL;
}
void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	// a function for each mode in next phases
	{
	case MODE_INTR:
		InterActiveMode();
		break;
	case MODE_STEP:
		StepByStepMode();
		break;
	case MODE_SLNT:
		SilentMode();
		break;
	};

}



//////////////////////////////////  Event handling functions   /////////////////////////////
void Restaurant::AddEvent(Event* pE)	//adds a new event to the queue of events
{
	EventsQueue.enqueue(pE);
}

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current time
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		if(pE!=NULL)
		delete pE;		//deallocate event object from memory
	}

}

void Restaurant::LoadFile()
{
	ifstream inFile;
	pGUI->PrintMessage("Enter a 'txt' file name to load ");
	inFile.open(pGUI->GetString()+".txt");
	// Check for ERRORs in opening the file
	if(inFile.fail()) { 
		pGUI->PrintMessage ("ERROR opening the file..TRY Again Please!! ");
		Sleep(1500);
		exit(1);
	}
	Event *pE;
	int SN,SF, SV, NA, FA, VA, NB, FB, VB, NC, FC, VC, ND, FD, VD;
		inFile >>SN>> SF>> SV                  //In the load func
				 >>NA>> FA>> VA					  //We have to create new motorcycles !!
				 >>NB>> FB>> VB
				 >>NC>> FC>> VC
				 >>ND>> FD>> VD
				 >>Auto
				 >>numEv;
		Arr[0].NoMotorCycles[0]=VA; Arr[0].NoMotorCycles[1]=NA; Arr[0].NoMotorCycles[2]=FA;	//RegionA Motorcycles numbers
		Arr[1].NoMotorCycles[0]=VB; Arr[1].NoMotorCycles[1]=NB; Arr[1].NoMotorCycles[2]=FB;	//RegionB Motorcycles numbers
		Arr[2].NoMotorCycles[0]=VC; Arr[2].NoMotorCycles[1]=NC; Arr[2].NoMotorCycles[2]=FC;	//RegionC Motorcycles numbers
		Arr[3].NoMotorCycles[0]=VD; Arr[3].NoMotorCycles[1]=ND; Arr[3].NoMotorCycles[2]=FD;	//RegionD Motorcycles numbers
		int idAll=1;
int TotalA = NA + FA + VA;
int TotalB = TotalA + NB + FB + VB;
int TotalC = TotalB + NC + FC + VC;
int speed = 0;
for (int j = 0; j < NA;j++)
{
	speed = rand() % 3 + SN;
	Motorcycle *Motor = new Motorcycle(idAll, speed, A_REG, IDLE, TYPE_NRMmotor);
	Arr[0].AvaliableNRMLMotor.insertDesc(Motor);
		idAll++;
}
for (int j = 0; j < FA ; j++)
{
	speed = rand() % 3 + SF;

	Motorcycle *Motor = new Motorcycle(idAll, speed, A_REG, IDLE, TYPE_FROZmotor);
	Arr[0].AvaliableFRZNMotor.insertDesc(Motor);
	idAll++;
}
for (int j =0; j < VA ; j++)
{
	speed = rand() % 3 + SV ;

	Motorcycle *Motor = new Motorcycle(idAll, speed, A_REG, IDLE, TYPE_FAStmotor);
	Arr[0].AvaliableFASTMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < NB; j++)
{
	speed = rand() % 3 + SN;

	Motorcycle *Motor = new Motorcycle(idAll, speed, B_REG, IDLE, TYPE_NRMmotor);
	Arr[1].AvaliableNRMLMotor.insertDesc(Motor);
		idAll++;
}
for (int j = 0; j < FB; j++)
{
	speed = rand() % 3 + SF;

	Motorcycle *Motor = new Motorcycle(idAll, speed, B_REG, IDLE, TYPE_FROZmotor);
	Arr[1].AvaliableFRZNMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < VB; j++)
{
	speed = rand() % 3 + SV;

	Motorcycle *Motor = new Motorcycle(idAll, speed, B_REG, IDLE, TYPE_FAStmotor);
	Arr[1].AvaliableFASTMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < NC; j++)
{
	speed = rand() % 3 + SN;

	Motorcycle *Motor = new Motorcycle(idAll, speed, C_REG, IDLE, TYPE_NRMmotor);
	Arr[2].AvaliableNRMLMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < FC; j++)
{
	speed = rand() % 3 + SF;

	Motorcycle *Motor = new Motorcycle(idAll, speed, C_REG, IDLE, TYPE_FROZmotor);
	Arr[2].AvaliableFRZNMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < VC; j++)
{
	speed = rand() % 3 + SV;

	Motorcycle *Motor = new Motorcycle(idAll, speed, C_REG, IDLE, TYPE_FAStmotor);
	Arr[2].AvaliableFASTMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < ND; j++)
{
	speed = rand() % 3 + SN;

	Motorcycle *Motor = new Motorcycle(idAll, speed, D_REG, IDLE, TYPE_NRMmotor);
	Arr[3].AvaliableNRMLMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < FD; j++)
{
	speed = rand() % 3 + SF;

	Motorcycle *Motor = new Motorcycle(idAll, speed, D_REG, IDLE, TYPE_FROZmotor);
	Arr[3].AvaliableFRZNMotor.insertDesc(Motor);
	idAll++;
}
for (int j = 0; j < VD; j++)
{
	speed = rand() % 3 + SV;

	Motorcycle *Motor = new Motorcycle(idAll, speed, D_REG, IDLE, TYPE_FAStmotor);
	Arr[3].AvaliableFASTMotor.insertDesc(Motor);
	idAll++;
}

		int i = 0;
		int ts,oid,mon,dist,exmon;
		while (inFile && i < numEv)
		{
			char ev;
			inFile >> ev;
			switch (ev)
			{
			case('R') :
				char otype,reg;
				inFile >> ts >>otype>>oid>>dist>>mon>>reg;
				pE = new ArrivalEvent(ts,oid,chartoOrdT(otype),chartoReg(reg),mon,dist);
				AddEvent (pE);
				//last_time_step=ts;
				break;
			case('X'):
				inFile >> ts>>oid;
				pE = new cancel_event(oid,ts);
				AddEvent (pE);
				//last_time_step=ts;
				break;
			case('P'):
				inFile >> ts>>oid>>exmon;
				pE = new PromotionEvent(ts,oid,exmon);
				AddEvent (pE);
				//last_time_step=ts;
				break;
			}
			i++;
		}
}

void Restaurant::SilentMode()
{
	LoadFile();
	pGUI->UpdateInterface();
	pGUI->PrintMessage("Generating orders that are loaded from the input file..");

		
	int CurrentTimeStep = 1;
	while (!EventsQueue.isEmpty() || !Arr[0].FRZs.isEmpty() || !Arr[1].FRZs.isEmpty() || !Arr[2].FRZs.isEmpty() || !Arr[3].FRZs.isEmpty() || !Arr[0].VIPs.isEmpty() || !Arr[1].VIPs.isEmpty() || !Arr[2].VIPs.isEmpty() || !Arr[3].VIPs.isEmpty() || !Arr[0].NRMs.isempty() || !Arr[1].NRMs.isempty() || !Arr[2].NRMs.isempty() || !Arr[3].NRMs.isempty() || !AllRegionInsServEmpty())
	{
		Order* pOrdf;
		Order* pOrdn;
		Order* pOrdv;
		//print current timestep
		char timestep[10];
		itoa(Timestep, timestep, 10);
		pGUI->PrintMessage(timestep);
	
		ExecuteEvents(Timestep);            //execute all events at current time step
		pGUI->UpdateInterface();

		
		//Let's draw all arrived orders by passing them to the GUI to draw
		for (int i = 0; i < REG_CNT; i++)
		{
			while (!(Arr[i].AvaliableFASTMotor.isempty() && Arr[i].AvaliableNRMLMotor.isempty() && Arr[i].AvaliableFRZNMotor.isempty()) && Arr[i].VIPs.dequeue(pOrdv))
			{
				AssignVIPtoMC(pOrdv, Timestep);
				Add_to_list_of_orders(pOrdv);
				pGUI->DeleteOrderFromList(pOrdv);
				Arr[i].NoActiveOrders[0]--;
			}
			while (!Arr[i].AvaliableFRZNMotor.isempty() && Arr[i].FRZs.dequeue(pOrdf))
			{
				AssignFRZtoMC(pOrdf, Timestep);
				Add_to_list_of_orders(pOrdf);
				pGUI->DeleteOrderFromList(pOrdf);
				Arr[i].NoActiveOrders[2]--;
			}
			while (Arr[i].NRMs.peekfront(pOrdn) && !AutoProm(pOrdn) && !(Arr[i].AvaliableFASTMotor.isempty() && Arr[i].AvaliableNRMLMotor.isempty()))
			{
				AssignNRMtoMC(pOrdn, Timestep);
				Add_to_list_of_orders(pOrdn);
				Arr[i].NRMs.deletefront();
				pGUI->DeleteOrderFromList(pOrdn);
				Arr[i].NoActiveOrders[1]--;
			}
		}

		ReturnMCs(Timestep);
		Timestep++;	//advance timestep
	}
	save_output_file();
	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();
}

void Restaurant::StepByStepMode()
{
	//CALLING the loading function
	LoadFile();
	pGUI->PrintMessage("STEP BY STEP MODE !! ");
	pGUI->UpdateInterface();
	pGUI->PrintMessage("Generating orders that are loaded from the input file..");

	Timestep++;
	
	//as long as events queue is not empty yet
	while (!EventsQueue.isEmpty() || !Arr[0].FRZs.isEmpty() || !Arr[1].FRZs.isEmpty() || !Arr[2].FRZs.isEmpty() || !Arr[3].FRZs.isEmpty() || !Arr[0].VIPs.isEmpty() || !Arr[1].VIPs.isEmpty() || !Arr[2].VIPs.isEmpty() || !Arr[3].VIPs.isEmpty() || !Arr[0].NRMs.isempty() || !Arr[1].NRMs.isempty() || !Arr[2].NRMs.isempty() || !Arr[3].NRMs.isempty() || !AllRegionInsServEmpty())
	{
		Order* pOrdf;
		Order* pOrdn;
		Order* pOrdv;
		//print current timestep
		char timestep[10];
		itoa(Timestep, timestep, 10);
		pGUI->PrintMessage(timestep);
		

		ExecuteEvents(Timestep);            //execute all events at current time step
		pGUI->UpdateInterface();
    /*string Message0 = Arr[0].OptimizingMotorcyclePrintingList(0);
	pGUI->PrintMessage6(Message0);

	string Message1 = Arr[1].OptimizingMotorcyclePrintingList(1);
	pGUI->PrintMessage7(Message1);

	string Message2 = Arr[2].OptimizingMotorcyclePrintingList(2);
	pGUI->PrintMessage8(Message2);

	string Message3 = Arr[3].OptimizingMotorcyclePrintingList(3);
	pGUI->PrintMessage9(Message3);*/


	string Message0 = Arr[0].OptimizingMotorcyclePrinting(0);
	pGUI->PrintMessage6(Message0);

	string Message1 = Arr[1].OptimizingMotorcyclePrinting(1);
	pGUI->PrintMessage7(Message1);

	string Message2 = Arr[2].OptimizingMotorcyclePrinting(2);
	pGUI->PrintMessage8(Message2);

	string Message3 = Arr[3].OptimizingMotorcyclePrinting(3);
	pGUI->PrintMessage9(Message3);


		string ActiveVip, ActiveNormal, ActiveFrozen, Motorfast, MotorNormal, MotorFrozen;

		ActiveVip = to_string(Arr[0].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[0].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[0].NoActiveOrders[2]);
		Motorfast = to_string(Arr[0].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[0].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[0].NoMotorCycles[2]);
		string MessageA = "Region A: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage2(MessageA);

		ActiveVip = to_string(Arr[1].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[1].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[1].NoActiveOrders[2]);
		Motorfast = to_string(Arr[1].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[1].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[1].NoMotorCycles[2]);
		string MessageB = "Region B: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage3(MessageB);

		ActiveVip = to_string(Arr[2].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[2].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[2].NoActiveOrders[2]);
		Motorfast = to_string(Arr[2].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[2].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[2].NoMotorCycles[2]);
		string MessageC = "Region C: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage4(MessageC);

		ActiveVip = to_string(Arr[3].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[3].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[3].NoActiveOrders[2]);
		Motorfast = to_string(Arr[3].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[3].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[3].NoMotorCycles[2]);
		string MessageD = "Region D: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage5(MessageD);


		//Let's draw all arrived orders by passing them to the GUI to draw
		for (int i = 0; i < REG_CNT; i++)
		{
			while (!(Arr[i].AvaliableFASTMotor.isempty() && Arr[i].AvaliableNRMLMotor.isempty() && Arr[i].AvaliableFRZNMotor.isempty()) && Arr[i].VIPs.dequeue(pOrdv))
			{
				AssignVIPtoMC(pOrdv, Timestep);
				Add_to_list_of_orders(pOrdv);
				pGUI->DeleteOrderFromList(pOrdv);
				Arr[i].NoActiveOrders[0]--;
			}
			while (!Arr[i].AvaliableFRZNMotor.isempty() && Arr[i].FRZs.dequeue(pOrdf))
			{
				AssignFRZtoMC(pOrdf, Timestep);
				Add_to_list_of_orders(pOrdf);
				pGUI->DeleteOrderFromList(pOrdf);
				Arr[i].NoActiveOrders[2]--;
			}
			while (Arr[i].NRMs.peekfront(pOrdn) && !AutoProm(pOrdn) && !(Arr[i].AvaliableFASTMotor.isempty() && Arr[i].AvaliableNRMLMotor.isempty()))
			{
				AssignNRMtoMC(pOrdn, Timestep);
				Add_to_list_of_orders(pOrdn);
				Arr[i].NRMs.deletefront();
				pGUI->DeleteOrderFromList(pOrdn);
				Arr[i].NoActiveOrders[1]--;
			}
		}

		ReturnMCs(Timestep);
		Sleep(1000);
		Timestep++;	//advance timestep
		
	}
	pGUI->UpdateInterface();
	save_output_file();
	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();
}

void Restaurant::InterActiveMode()
{
//CALLING the loading function
	LoadFile();
	pGUI->PrintMessage("INTERACTIVE MODE !! ");
	pGUI->UpdateInterface();
	pGUI->PrintMessage("Generating orders that are loaded from the input file..");

	Timestep++;
	Order* pOrdf;
	Order* pOrdn;
	Order* pOrdv;
	
	//as long as events queue is not empty yet
	while (!EventsQueue.isEmpty() || !Arr[0].FRZs.isEmpty() || !Arr[1].FRZs.isEmpty() || !Arr[2].FRZs.isEmpty() || !Arr[3].FRZs.isEmpty() || !Arr[0].VIPs.isEmpty() || !Arr[1].VIPs.isEmpty() || !Arr[2].VIPs.isEmpty() || !Arr[3].VIPs.isEmpty() || !Arr[0].NRMs.isempty() || !Arr[1].NRMs.isempty() || !Arr[2].NRMs.isempty() || !Arr[3].NRMs.isempty() || !AllRegionInsServEmpty())
	{
		//print current timestep
		if (Timestep == 50)
			bool b = true;
		char timestep[10];
		itoa(Timestep, timestep, 10);
		pGUI->PrintMessage(timestep);
		
        
		
		ExecuteEvents(Timestep);            //execute all events at current time step
		pGUI->UpdateInterface();


        /*string Message0 = Arr[0].OptimizingMotorcyclePrintingList(0);
		pGUI->PrintMessage6(Message0);

		string Message1 = Arr[1].OptimizingMotorcyclePrintingList(1);
		pGUI->PrintMessage7(Message1);

		string Message2 = Arr[2].OptimizingMotorcyclePrintingList(2);
		pGUI->PrintMessage8(Message2);

		string Message3 = Arr[3].OptimizingMotorcyclePrintingList(3);
		pGUI->PrintMessage9(Message3);*/

		string Message0 = Arr[0].OptimizingMotorcyclePrinting(0);
		pGUI->PrintMessage6(Message0);

		string Message1 = Arr[1].OptimizingMotorcyclePrinting(1);
		pGUI->PrintMessage7(Message1);

		string Message2 = Arr[2].OptimizingMotorcyclePrinting(2);
		pGUI->PrintMessage8(Message2);

		string Message3 = Arr[3].OptimizingMotorcyclePrinting(3);
		pGUI->PrintMessage9(Message3);

		string ActiveVip, ActiveNormal, ActiveFrozen, Motorfast, MotorNormal, MotorFrozen;

		ActiveVip = to_string(Arr[0].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[0].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[0].NoActiveOrders[2]);
		Motorfast = to_string(Arr[0].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[0].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[0].NoMotorCycles[2]);
		string MessageA = "Region A: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage2(MessageA);

		ActiveVip = to_string(Arr[1].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[1].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[1].NoActiveOrders[2]);
		Motorfast = to_string(Arr[1].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[1].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[1].NoMotorCycles[2]);
		string MessageB = "Region B: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage3(MessageB);

		ActiveVip = to_string(Arr[2].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[2].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[2].NoActiveOrders[2]);
		Motorfast = to_string(Arr[2].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[2].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[2].NoMotorCycles[2]);
		string MessageC = "Region C: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage4(MessageC);

		ActiveVip = to_string(Arr[3].NoActiveOrders[0]);
		ActiveNormal = to_string(Arr[3].NoActiveOrders[1]);
		ActiveFrozen = to_string(Arr[3].NoActiveOrders[2]);
		Motorfast = to_string(Arr[3].NoMotorCycles[0]);
		MotorNormal = to_string(Arr[3].NoMotorCycles[1]);
		MotorFrozen = to_string(Arr[3].NoMotorCycles[2]);
		string MessageD = "Region D: FastMC= " + Motorfast + " ,NormalMC= " + MotorNormal + " ,FrozenMC= " + MotorFrozen + ",VIPO= " + ActiveVip + " ,NormalO= " + ActiveNormal + " ,FrozenO= " + ActiveFrozen;
		pGUI->PrintMessage5(MessageD);


//Let's draw all arrived orders by passing them to the GUI to draw
		for(int i=0;i<REG_CNT;i++)
		{
			while(!(Arr[i].AvaliableFASTMotor.isempty() &&Arr[i].AvaliableNRMLMotor.isempty() &&Arr[i].AvaliableFRZNMotor.isempty()) &&Arr[i].VIPs.dequeue(pOrdv))
			{
				AssignVIPtoMC(pOrdv, Timestep);
				Add_to_list_of_orders(pOrdv);
				pGUI->DeleteOrderFromList(pOrdv);
				Arr[i].NoActiveOrders[0]--;
			}
			while(!Arr[i].AvaliableFRZNMotor.isempty() && Arr[i].FRZs.dequeue(pOrdf))
			{
				AssignFRZtoMC(pOrdf, Timestep);
				Add_to_list_of_orders(pOrdf);
				pGUI->DeleteOrderFromList(pOrdf);
				Arr[i].NoActiveOrders[2]--;
			}
			while(Arr[i].NRMs.peekfront(pOrdn)&& !AutoProm(pOrdn) && !(Arr[i].AvaliableFASTMotor.isempty() && Arr[i].AvaliableNRMLMotor.isempty()) )
				{
					AssignNRMtoMC(pOrdn, Timestep);
					Add_to_list_of_orders(pOrdn);
					Arr[i].NRMs.deletefront();
					pGUI->DeleteOrderFromList(pOrdn);
					Arr[i].NoActiveOrders[1]--;
				}
		}
	
		ReturnMCs(Timestep);
		pGUI->waitForClick();
		Timestep++;	//advance timestep
		
	}
	pGUI->UpdateInterface();
	save_output_file();
	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();
}

Restaurant::~Restaurant()
{
	Motorcycle * temp=nullptr;
	for (int i = 0; i < REG_CNT; i++)
	{
		while (Arr[i].AvaliableFASTMotor.remove(temp))

		{
			delete temp;
			temp = nullptr;
		}
		while (Arr[i].AvaliableFRZNMotor.remove(temp))

		{
			delete temp;
			temp = nullptr;
		}
		while (Arr[i].AvaliableNRMLMotor.remove(temp))

		{
			delete temp;
			temp = nullptr;
		}
	}
		delete pGUI;
}

void Restaurant::AddtoVIPs(Order *pOrd)
{
	PNode<Order*> VIP(pOrd);
	int r=pOrd->GetRegion();
	double pri= (0.7*pOrd->GetMoney()) - (0.3*pOrd->GetArrTime() + 0.5*pOrd->GetDistance());
	VIP.SetPriority(pri);
	Arr[r].VIPs.enqueue(pOrd);
	Arr[r].NoActiveOrders[0]++; 
	Arr[r].NoOrders[0]++;
}



void Restaurant::AddtoNRMs(Order *pOrd)
{
	int r=pOrd->GetRegion();
	Arr[r].NRMs.insert(pOrd);
	Arr[r].NoActiveOrders[1]++;
	Arr[r].NoOrders[1]++;
}



void Restaurant::AddtoFRZs(Order *pOrd)
{
	int r=pOrd->GetRegion();
	Arr[r].FRZs.enqueue(pOrd);
	Arr[r].NoActiveOrders[2]++;
	Arr[r].NoOrders[2]++;
}

////////////////

ORD_TYPE Restaurant::chartoOrdT(const char &o)
{
	if (o == 'N' || o == 'n')
		return TYPE_NRM;
	else if (o == 'F' || o == 'f')
		return TYPE_FROZ;
	else
		return TYPE_VIP;
}
REGION Restaurant::chartoReg(const char &r)
{
	if (r == 'A' || r == 'a')
		return A_REG;
	else if (r == 'B' || r == 'b')
		return B_REG;
	else if (r == 'C' || r == 'c')
		return C_REG;
	else
		return D_REG;
}

void Restaurant::AssignVIPtoMC(Order *&pOrd,int ts)
{
	Motorcycle* MC =NULL;
	 int r=pOrd->GetRegion();
	 if(Arr[r].NoMotorCycles[0]>0) //there is a fast MC
	 {
		 Arr[r].AvaliableFASTMotor.remove(MC);
		 MC->setServiceTime(pOrd->GetDistance()/MC->getSpeed());
		 MC->setFinishTime(pOrd->GetArrTime() + pOrd->GetWaiting() + (2 * MC->getServiceTime()));
		 Arr[r].AssignedFASTMotor.insertAsc(MC);   //inserted ascendingly according to the Finish time of the motorcycle
		 Arr[r].NoMotorCycles[0]--;
	 }
	 else if (Arr[r].NoMotorCycles[1]>0)  //there is a normal MC
	 {
		 Arr[r].AvaliableNRMLMotor.remove(MC);
		 MC->setServiceTime(pOrd->GetDistance()/MC->getSpeed());
		 MC->setFinishTime(pOrd->GetArrTime() + pOrd->GetWaiting() + (2 * MC->getServiceTime()));
		 Arr[r].AssignedNRMLMotor.insertAsc(MC);
		 Arr[r].NoMotorCycles[1]--;
	 }
	 else		 //there is a frozen MC
	 {
		 Arr[r].AvaliableFRZNMotor.remove(MC);
		 MC->setServiceTime(pOrd->GetDistance()/MC->getSpeed());
		MC->setFinishTime(pOrd->GetArrTime() + pOrd->GetWaiting() + (2 * MC->getServiceTime()));
		  Arr[r].AssignedFASTMotor.insertAsc(MC);
		  Arr[r].NoMotorCycles[2]--;
	 }
	 pOrd->SetServTime(pOrd->GetDistance() / MC->getSpeed());
	 MC->setOrderID(pOrd->GetID());
	 MC->setType(pOrd->getType());
	 Arr[r].AddToMotorcycleList(MC);
	 Arr[r].AddToMotorcycleListPrinting(MC);

	 pOrd->setWaitingTime(ts-pOrd->GetArrTime());
	 Arr[r].Aw_VIP = Arr[r].Aw_VIP + pOrd->GetWaiting();
	 Arr[r].As_VIP = Arr[r].As_VIP + pOrd->GetServTime();
}
void Restaurant::AssignNRMtoMC(Order *&pOrd,int ts)
{
	Motorcycle* MC =NULL;
	 int r=pOrd->GetRegion();
	 int w=pOrd->GetWaiting();
	 if(Arr[r].NoMotorCycles[1]>0) //there is a norm al MC
	 {
		 Arr[r].AvaliableNRMLMotor.remove(MC);
		 MC->setServiceTime(pOrd->GetDistance()/MC->getSpeed());
		 MC->setFinishTime(pOrd->GetArrTime() + pOrd->GetWaiting() + (2 * MC->getServiceTime()));
		 Arr[r].AssignedNRMLMotor.insertAsc(MC);
		 Arr[r].NoMotorCycles[1]--;
	 }
	 else   //there is a fast MC
	 {
		  Arr[r].AvaliableFASTMotor.remove(MC);
		 MC->setServiceTime(pOrd->GetDistance()/MC->getSpeed());
		 MC->setFinishTime(pOrd->GetArrTime() + pOrd->GetWaiting() + (2 * MC->getServiceTime()));
		 Arr[r].AssignedFASTMotor.insertAsc(MC);
		 Arr[r].NoMotorCycles[0]--;
	 }
	 pOrd->SetServTime(pOrd->GetDistance() / MC->getSpeed());
	 MC->setOrderID(pOrd->GetID());
	 MC->setType(pOrd->getType());
	 Arr[r].AddToMotorcycleList(MC);
	 Arr[r].AddToMotorcycleListPrinting(MC);

	 pOrd->setWaitingTime(ts-pOrd->GetArrTime());
	 Arr[r].Aw_norm = Arr[r].Aw_norm + pOrd->GetWaiting();
	 Arr[r].As_norm = Arr[r].As_norm + pOrd->GetServTime();
}
void Restaurant::AssignFRZtoMC(Order *&pOrd,int ts)
{
		Motorcycle* MC =NULL;
		int r=pOrd->GetRegion();
		if (Arr[r].NoMotorCycles[2]>0)
		{
			Arr[r].AvaliableFRZNMotor.remove(MC);
			pOrd->SetServTime(pOrd->GetDistance() / MC->getSpeed());
			MC->setServiceTime(pOrd->GetDistance() / MC->getSpeed());
			MC->setFinishTime(pOrd->GetArrTime() + pOrd->GetWaiting() + (2 * MC->getServiceTime()));
			MC->setOrderID(pOrd->GetID());
			MC->setType(pOrd->getType());
			Arr[r].AssignedFRZNMotor.insertAsc(MC);
			Arr[r].NoMotorCycles[2]--;
			Arr[r].AddToMotorcycleList(MC);
			Arr[r].AddToMotorcycleListPrinting(MC);

			pOrd->setWaitingTime(ts - pOrd->GetArrTime());
			Arr[r].Aw_froz = Arr[r].Aw_froz + pOrd->GetWaiting();
			Arr[r].As_froz = Arr[r].As_froz + pOrd->GetServTime();
		}
}

void Restaurant::ReturnMCs(int TimeStep)
{
	Motorcycle* TEMP =NULL;
	for(int i=0; i< REG_CNT; i++)
	{
		while(Arr[i].AssignedFASTMotor.peekfront(TEMP))
		{
			if(TEMP->getFinishTime() <=TimeStep )
			{
				Arr[i].AssignedFASTMotor.remove(TEMP);
				Arr[i].AvaliableFASTMotor.insertDesc(TEMP);
				Arr[i].NoMotorCycles[0]++;
				Arr[i].RemoveFromMotorcycleList(TEMP);
				TEMP->setStatus(IDLE);
			}
			else break;
		}
		TEMP=NULL;
		while(Arr[i].AssignedNRMLMotor.peekfront(TEMP))
		{
			if(TEMP->getFinishTime() <=TimeStep )
			{
				Arr[i].AssignedNRMLMotor.remove(TEMP);
				Arr[i].AvaliableNRMLMotor.insertDesc(TEMP);
				Arr[i].NoMotorCycles[1]++;
				Arr[i].RemoveFromMotorcycleList(TEMP);
				TEMP->setStatus(IDLE);
			}
			else break;
		}
		TEMP=NULL;
		while(Arr[i].AssignedFRZNMotor.peekfront(TEMP))
		{
			if(TEMP->getFinishTime() <=TimeStep )
			{
				Arr[i].AssignedFRZNMotor.remove(TEMP);
				Arr[i].AvaliableFRZNMotor.insertDesc(TEMP);
				Arr[i].NoMotorCycles[2]++;
				Arr[i].RemoveFromMotorcycleList(TEMP);
				TEMP->setStatus(IDLE);
			}
			else break;
		}
	}
}

void Restaurant::promoteOrder(int id, int money)
{
	Order*p=NULL;
	if (Arr[0].promotion(id, p))  //Region A promotion
	{
		p->setType(TYPE_VIP);
		double m = p->GetMoney() + money;
		p->SetMoney(m);
		AddtoVIPs(p);
	}
	else if (Arr[1].promotion(id, p))   //Region B promotion
	{
		p->setType(TYPE_VIP);
		double m = p->GetMoney() + money;
		p->SetMoney(m);
		AddtoVIPs(p);
	}
	else if (Arr[2].promotion(id, p))  //Region C promotion
	{
		p->setType(TYPE_VIP);
		double m = p->GetMoney() + money;
		p->SetMoney(m);
		AddtoVIPs(p);
	}
	else if (Arr[3].promotion(id, p))  //Region D promotion
	{
		p->setType(TYPE_VIP);
		double m = p->GetMoney() + money;
		p->SetMoney(m);
		AddtoVIPs(p);
	}
}

bool Restaurant::AllRegionInsServEmpty()
{
	return Arr[0].AllInSerIsEmpty()&& Arr[1].AllInSerIsEmpty()&& Arr[2].AllInSerIsEmpty()&& Arr[3].AllInSerIsEmpty();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Restaurant::save_output_file()
{
	ofstream outputfile;
	Order*p;

	pGUI->PrintMessage("Enter a file name to save in ");

	outputfile.open(pGUI->GetString() + ".txt");
	outputfile << "FT" << "	 " << "ID" << "	 " << "AT" << "	 " << "WT" << "	 " << "ST" << "\n";
	for (int i = 0; i < number_of_orders; i++)
	{
		if (list_of_orders.remove(p))
			outputfile << p->GetFinishTime() << "	 " << p->GetID() << "	 " << p->GetArrTime() << "	 " << p->GetWaiting() << "	 " << p->GetServTime() << "\n";
	}
	int no = 0;
	int no_norm = 0;
	int no_froz = 0;
	int no_VIP = 0;
	int mo = 0;
	int mo_norm = 0;
	int mo_froz = 0;
	int mo_VIP = 0;
	double  total_avrg_wait=0, total_avrg_serv=0;
	for (int i = 0; i < 4; i++)
	{
		outputfile << "............................" << "\n";
		outputfile << "............................" << "\n";
		outputfile << "Region";
		if (i == 0) { outputfile << "A" << "\n"; }
		if (i == 1) { outputfile << "B" << "\n"; }
		if (i == 2) { outputfile << "C" << "\n"; }
		if (i == 3) { outputfile << "D" << "\n"; }
		no = no + Arr[i].get_number_of_orders();
		no_norm = no_norm + Arr[i].NoOrders[1];
		no_froz = no_froz + Arr[i].NoOrders[2];
		no_VIP = no_VIP + Arr[i].NoOrders[0];
		mo = mo + Arr[i].NoMotorCycles[0] + Arr[i].NoMotorCycles[1] + Arr[i].NoMotorCycles[2];
		mo_froz = mo_froz + Arr[i].NoMotorCycles[2];
		mo_norm = no_norm + Arr[i].NoMotorCycles[1];
		mo_VIP = mo_VIP + Arr[i].NoMotorCycles[0];
		outputfile << "	 " << "Orders :" << "  " << Arr[i].get_number_of_orders() << "  " << "[Norm :" << Arr[i].NoOrders[1] << ", Froz :" << Arr[i].NoOrders[2] << " ,VIP :" << Arr[i].NoOrders[0] << "]" << "\n";
		outputfile << "	 " << "MotorC :  " << Arr[i].NoMotorCycles[0] + Arr[i].NoMotorCycles[1] + Arr[i].NoMotorCycles[2] << "[Norm:" << Arr[i].NoMotorCycles[1] << ",Froz:" << Arr[i].NoMotorCycles[2] << ",VIP:" << Arr[i].NoMotorCycles[0] << "]" << "\n";
		double avg_wait, avg_serv;
		avg_wait = Arr[i].get_avg_wait();
		avg_serv = Arr[i].get_avg_service();
		total_avrg_wait += avg_wait;
		total_avrg_serv += avg_serv;
		outputfile << "Avg Wait =" << avg_wait << ", Avg Serv =" << avg_serv << "\n";
	}
	//for the all rest
	outputfile << "............................" << "\n";
	outputfile << "............................" << "\n";
	outputfile << "Resturant " << "\n";
	outputfile << "	 " << "orders :" << no << "[Norm:" << no_norm << ", Froz:" << no_froz << ", VIP:" << no_VIP << "]" << "\n";
	outputfile << "	 " << "motor cycles :" << mo << "[Norm:" << mo_norm << ", Froz:" << mo_froz << ", VIP:" << mo_VIP << "]" << "\n";
	outputfile << "	 " << "Avg Wait =" << (total_avrg_wait/4.0) << ", Avg Serv =" << (total_avrg_serv/4.0) << "\n";
	outputfile.close();
}
void Restaurant::Add_to_list_of_orders(Order*p)
{
	list_of_orders.insertAsc(p);
	number_of_orders++;
}

bool Restaurant::AutoProm(Order* o)
{
	int r = o->GetRegion();
	return Arr[r].AutoP(Auto, o);
}

