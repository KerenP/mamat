#ifndef PROFESSIONALDELIVERYVEHICLE_H_
#define PROFESSIONALDELIVERYVEHICLE_H_

#include "DeliveryVehicle.H"
class ProfessionalDeliveryVehicle : public DeliveryVehicle{
public:
	//c'tor
	ProfessionalDeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	virtual ~ProfessionalDeliveryVehicle();
	
	//adds parcel to vehicle returns false if add failed
	virtual bool addParcel(Parcel* parcel);
	
	//Delivering parcel treasure to position 2
	//Fuel consumed: 2 Revenue is: 4
	//Total travel distance is 2
	//Total revenue is -2
	//Revenue per distance: -1
	//Revenue per parcel: -2
	//
	//if no parcels present:
	//No parcels to deliver for vehicle riksha
	virtual int performDeliveryDay(int* numberOfDeliveries);

};

#endif /* PROFFESSIONALDELIVERYVEHICLE_H_ */
