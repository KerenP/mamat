#ifndef DELIVERYVEHICLE_H_
#define DELIVERYVEHICLE_H_

#include "Parcel.H"
#include <stack>
#include <string.h>
#define MAX_PARCEL_PER_VEHICLE 5
#define MAX_STATIONS_PER_DAY 12
using namespace std;
typedef enum quality{good = 3, ok = 4, bad = 5} Quality;
typedef enum  zz{good = 3, ok = 4, bad = 5} Quality;
class DeliveryVehicle{
public:
	//c'tor
	DeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~DeliveryVehicle();
	
	//adds parcel to vehicle returns false if add failed
	virtual bool addParcel(Parcel* parcel);
	
	//performs all possible deliveries for one day
	//output example
	//Starting deliveries for vehicle riksha
	//Delivering parcel hot_air to position 3
	//Fuel consumed: 3 Revenue is: 4
	//Delivering parcel mice to position 2
	//Fuel consumed: 9 Revenue is: 4
	//Total travel distance is 12
	//Total revenue is -4
	//
	//if no parcels present:
	//No parcels to deliver for vehicle riksha
	virtual int performDeliveryDay(int* numberOfDeliveries);


protected:
   char* license_plate;
   Quality vehicle_type;
   int station;
   stack <Parcel*> parcels_to_deliver; //TODO:check if doesnt cause memory leak
   virtual bool performSingleDelivery(int *profit, int *distance);
   virtual void printDailySummary();
   bool checkParcelExist(Parcel* parcel);
};

#endif /* DELIVERYVEHICLE_H_ */
