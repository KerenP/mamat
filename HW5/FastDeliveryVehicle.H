#ifndef FASTDELIVERYVEHICLE_H_
#define FASTDELIVERYVEHICLE_H_

#include "DeliveryVehicle.H"

class FastDeliveryVehicle : public  DeliveryVehicle{
public:
	
	//c'tor
	FastDeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~FastDeliveryVehicle();

	//performs all possible deliveries for one day
	//output example
	//Starting deliveries for vehicle soosita
	//Delivering parcel code to position 3
	//Fuel consumed: 9 Revenue is: 18
	//Total travel distance is 9
	//
	//if no parcels present:
	//No parcels to deliver for vehicle riksha
	virtual int performDeliveryDay(int* numberOfDeliveries);
};
#endif /* FASTDELIVERYVEHICLE_H_ */
