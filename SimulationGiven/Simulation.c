/******************************************************************************
implementation file	: Simulation.c
Author				: Y. Cotronis 14/03/2015
Purpose				: Ylopoihsh prosomoiwshs trapezas me oura,pelates,tamies.
Revision			: <Costas Chatzopoulos -1115201300202- 23/03/2015>
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Queue.h"
#include "Cashier.h"

#define CASHIERS 3						/*Plithos tameiwn*/

int main(void){
	Queue			queue;				/*Queue pointer*/
	Customer		customer;			/*Customer*/
	Cashier			cashier[CASHIERS];	/*Array of Cashiers*/
	time_t			t;
	unsigned int	maxServise;			/*Megisti diarkia exipiretisis enos pelati*/
	unsigned int	standby;			/*Synolikos xronos anamonis*/
	unsigned int	served;				/*Plithos pelaton pou exipiretithikan*/
	unsigned int	custIn;				/*Metritis pelatwn pou mpikan stin trapeza*/
	unsigned int	custOut;			/*Metritis pelatwn pou den mporesan na mpoun stin trapeza*/
	float			average;			/*Mesos xronos anamonis pelatwn*/
	float			pbArrival;			/*Pithanotita afixis pelati se 1 lepto [0%-100%]*/
	float			randArrival;		/*Tyxaia afixi gia ton ypologismo eisodou tou pelati*/
	int				i;
	int				clock;				/*Roloi prosomiosis xronou se lepta*/
	int				simTime;			/*Synolikos xronos prosomiosis*/
	int				close;				/*O xronos pou tha klisei i trapeza*/
	int				extra;				/*O epipleon xronos pou emine anikti i trapeza*/
	
	maxServise = 0;
	standby = 0;
	average = 0.0;
	simTime = 0;
	clock = 0;
	close = 0;

	served = 0;
	custIn = 0;
	custOut = 0;

	randArrival = 0.0;
	pbArrival = 0.0;

	extra = 0;
	while (simTime < 1){
		printf("\nGive minutes of simulation:\n");
		scanf_s("%u", &simTime);
	}

	while ( !(close > 0 && close <= simTime) ){
		printf("\nGive minute of closing bank:\n");
		scanf_s("%d", &close);
	}

	do{
		printf("\nGive probability of customer arrival in 1 minute: (0%%-100%%^)\n");
		scanf_s("%f", &pbArrival);
	}while ( !(pbArrival >= 0 && pbArrival <= 100) );


	do{
		printf("\nGive maximum minutes of service time in cashier:\n");
		scanf_s("%u", &maxServise);
	}while ( !(maxServise > 0) );

	printf("\n______________________________________________________________________________");
	printf("\nThe simulation time is %u minutes.", simTime);
	printf("\nThe customer arrival probability in 1 minute is %3.2f%%.", pbArrival);
	printf("\nThe maximum minutes of service time in cashier for a customer is %d minutes.", maxServise);
	printf("\nThe capacity of queue of bank: %d", QSIZE);
	printf("\nThe number of cashiers of bank: %d", CASHIERS);
	printf("\n______________________________________________________________________________");

	pbArrival /= 100;

	queue = QCreate();

	/*Dimiourgia twn tamiwn*/
	for ( i = 0; i < CASHIERS ; i++)
		CashCreate(&cashier[i]);

	srand(time(&t));

	while (clock < simTime)
	{	/*Pelatis*/
		if (clock < close)
		{
			randArrival = (float)rand() / (float)RAND_MAX;
			if (randArrival < pbArrival){
				/*Katagrafi wras eisodou pelati*/
				CustSetEntryTime(&customer, clock);
				/*o x pelatis tha parei y xrono sto tameio*/
				CustSetServiseTime(&customer, rand() % maxServise + 1);

				if (!QInsert(queue, &customer))
					custOut++;		/*Metrisi pelatwn pou den mporesan na mpoun stin trapeza*/
				else
					custIn++;		/*Metrisi pelatwn pou mporesan na mpoun stin trapeza*/
			}
		}
		else
			extra++;

		for ( i = 0; i < CASHIERS ; i++)
		{
			/*Tamias*/
			if (CashFree(&cashier[i]))
			{ /*o i tamias einai eleytheros*/
				if (QRemove(queue, &customer))
				{ /*Yparxei pelatis stin oura, opote feygei apo tin oura kai paei sto tameio*/
					standby += clock - CustGetEntryTime(&customer); /*Ypologismos xronou paramonis twn pelatwn stin trapeza.*/
					served++;
					CashNewCust(&cashier[i]);	//O tamias dektike ena pelati.
					CashSetRemTime(&cashier[i], CustGetServiseTime(&customer) - 1); /*Kalyptei to trexon lepto.*/
				}
				else
				{ /*Den yparxei pelatis stin oura opote ayxisi tou xronou adranias gia ton i tamia*/
					CashInactive(&cashier[i]);
				}
			}
			else
			{ /*O i tamias einai apasxolimenos, opote tha ginei ayxisi tou busy tou kata 1 kai 
				meiosi tou enapominonta xronou tou kata 1 me ti boithia tis sinartisis CashBusy.*/
				CashBusy(&cashier[i]);
			}

		}

		clock++; /*Ayxisi tou xronou prosomiosis kata 1 lepto*/
	}


	/*Ypologismos tou mesou orou anamonis pelatwn.*/
	if (served == 0)
		average = 0.0;
	else
		average = ((float)standby) / ((float)served);


	printf("\nTotal customers: %d", custIn+custOut);
	printf("\n______________________________________________________________________________");
	printf("\nCustomers who:");
	printf("\n-entered in the bank: %u", custIn);
	printf("\n-entered in the bank and served: %d", served);

	if (custOut)
		printf("\n-can not enter in the bank (because the bank was full): %u", custOut);
	
	if (i = QSize(queue))
		printf("\n-are stuck in the queue of bank! (because the simulation has stopped earlier): %d", i);

	printf("\nThe waiting average time for a customer is %0.0f minutes.", average);

	printf("\n______________________________________________________________________________");

	/*Ektyposi gia tous tamies*/
	for (i = 0; i < CASHIERS ; i++)
	{
		printf("\nThe cashier %d:", i+1);
		printf("\n-was inactive for %d minutes.", CashGetInactiveTime(&cashier[i]));
		printf("\n-was busy for %d minutes.", CashGetBusyTime(&cashier[i]));
		printf("\n-has served %d customers.\n", CashGetNoCustomers(&cashier[i]));
		printf("\n------------------------------------------------------------------------------");
	}

	printf("\n______________________________________________________________________________");
	printf("\nThe real work time for cashiers is %d minutes.", close + extra);

	if (extra >= 0) 
		printf("\nCashiers has working extra %d minutes.", extra);
	else 
		printf("\nThe bank was inactive for %d minutes before closing.", abs((int)extra));

	/*Katastrofi ouras.*/
	QDestroy(queue);

	getchar();
	return 0;
}
