#include "FastDeliveryCompany.H"
#include "ProfessionalDeliveryCompany.H"
#include "DeliveryCompany.H"
#include "DeliveryVehicle.H"
#include "FastDeliveryVehicle.H"
#include "ProfessionalDeliveryVehicle.H"
#include "Parcel.H"
#include <string.h>
#include <cstdio>
#include <math.h>
#include <iostream>
#define parcelNum 10
using namespace  std;

char* createNameID(const char* name, int ID)
{
	int IDlen = (ID > 1 ? (int)ceil(log10(float(ID + 1))) : 1);
	char* name_ = new char[strlen(name) + IDlen + 1];
	char* num = new char[IDlen + 1];
	strcpy(name_, name);
	sprintf(num, "%d", ID);
	strcat(name_, num);
	delete[] num;
	return name_;
}

int main()
{
	// create compnies
	DeliveryCompany* Noy = new DeliveryCompany(150);
	FastDeliveryCompany* Hodaya = new FastDeliveryCompany();
	ProfessionalDeliveryCompany* Shir = new ProfessionalDeliveryCompany(50);

	// create Vehicle's
	DeliveryVehicle* Horse = new DeliveryVehicle("Horse",bad);
	DeliveryVehicle* Donkey = new DeliveryVehicle("Donkey", bad);
	FastDeliveryVehicle* Turtle = new FastDeliveryVehicle("Turtle",ok);
	ProfessionalDeliveryVehicle* Cheetah = new ProfessionalDeliveryVehicle("Cheetah", good);
	ProfessionalDeliveryVehicle* Zebra = new ProfessionalDeliveryVehicle("Zebra", good);
	ProfessionalDeliveryVehicle* Lion = new ProfessionalDeliveryVehicle("Lion", good);


	// create Parcel's
	Parcel** p = new Parcel * [parcelNum];
	for (int i = 0; i < parcelNum; i++)
	{
		char* name = createNameID("p", i);
		p[i] = new Parcel(name, (i * 7) % parcelNum);
		delete[] name;
	}
	Parcel* same = new Parcel("same", 6);

	Noy->addVehicle(Horse);

	// test to see that no more than 5 parcel's can be added
	for (int i = 0; i <= 5; i++)
	{
		Noy->receiveParcel(p[i]);
	}

	Noy->addVehicle(Cheetah);
	Noy->receiveParcel(p[6]);
	// supposed to be destroyed not profitable + the other Vehicle is full
	Noy->receiveParcel(p[7]);

	// check that the compines only recieve the right type of Vehicle
	Hodaya->addVehicle(Zebra);
	Shir->addVehicle(Donkey);

	// check that 2 parcels to the same dest in a fast company only is profitable for the 
	// first parcel
	Hodaya->addVehicle(Turtle);
	Hodaya->receiveParcel(p[8]);
	Hodaya->receiveParcel(same);

	Noy->displayNumberOfDeliveries();
	Noy->performDeliveryDay();
	Noy->displayFunds();

	// check if we recieve the same parcel twice
	Shir->addVehicle(Lion);
	Shir->receiveParcel(p[9]);
	// remove // in the next row to check the exit
	//Shir->receiveParcel(p[9]);

	delete Noy;
	delete Hodaya;
	delete Shir;
	delete[] p;

	return 0;
}
