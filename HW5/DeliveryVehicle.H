#ifndef DELIVERYVEHICLE_H_
#define DELIVERYVEHICLE_H_

#include "Parcel.H"

typedef enum quality{good = 3, ok = 4, bad = 5} Quality;

class DeliveryVehicle{
public:
	//c'tor
	DeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~DeliveryVehicle();
	
	//adds parcel to vehicle returns false if add failed
	bool addParcel(Parcel* parcel);
	
	//performs all possible deliveries for one day
	//output example
	//Starting deliveries for vehicle riksha
	//Delivering parcel hot_air to position 3
	//Fuel consumed: 3 Revenue is: 4
	//Delivering parcel mice to position 2
	//Fuel consumed: 9 Revenue is: 4
	//Total travel distance is 9
	//Total revenue is -4
	//
	//if no parcels present:
	//No parcels to deliver for vehicle riksha
	int performDeliveryDay(int* numberOfDeliveries);
};

#endif /* DELIVERYVEHICLE_H_ */
