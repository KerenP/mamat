#ifndef FASTDELIVERYCOMPANY_H_
#define FASTDELIVERYCOMPANY_H_

#include "DeliveryCompany.H"

class FastDeliveryCompany : public DeliveryCompany{
public:
	//c'tor
	FastDeliveryCompany(int money);
	
	//d'tor
	virtual ~FastDeliveryCompany();
	
	//adds vehicle to vehicle queue
	//if vehicle exists - output is
	//Can't add vehicle, it already exists
	//
	//returns false if not possible and deletes vehicle
	virtual bool addVehicle(DeliveryVehicle* vehicle);
	
	//receives parcel if possible
	//returns false if not possible and deletes parcel
	//bool receiveParcel(Parcel* parcel);
	
	//performs all deliveries possible for one day
	//returns false if no vehicles are present
	//output example:
	//Starting days deliveries:
	//<here comes output for each vehicle>
	//Total revenue for company is -2
	//Company balance is now 123
	//bool performDeliveryDay();
	
	//displays company funds
	//output example:
	//Company balance is now 148
	//void displayFunds();
	
	//displays number of deliveries company has done so far
	//output example:
	//Till now company has delivered 3 parcels
	//void displayNumberOfDeliveries();
};

#endif /* FASTDELIVERYCOMPANY_H_ */
