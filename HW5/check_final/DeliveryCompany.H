#ifndef DELIVERYCOMPANY_H_
#define DELIVERYCOMPANY_H_
#include "DeliveryVehicle.H"
#include "DeliveryVehicleList.H"
#define INITIAL_MONEY 100

class DeliveryCompany{
protected:
    DeliveryVehicleList delivery_vehicle_list;
    int income;
    int number_of_deliveries;
    //unsigned received_last_parcel;
    DeliveryVehicle* received_last_parcel;
    bool has_parcels;
public:
	//c'tor
	DeliveryCompany(int money=INITIAL_MONEY);
	
	//d'tor
	virtual ~DeliveryCompany();
	
	//adds vehicle to vehicle queue
	//if vehicle exists - output is
	//Can't add vehicle, it already exists
	//
	//returns false if not possible and deletes vehicle
	virtual bool addVehicle(DeliveryVehicle* vehicle);
	
	//receives parcel if possible
	//returns false if not possible and deletes parcel
	 bool receiveParcel(Parcel* parcel);
	
	//performs all deliveries possible for one day
	//returns false if no vehicles are present
	//output example:
	//Starting days deliveries:
	//<here comes output for each vehicle>
	//Total revenue for company is -2
	 bool performDeliveryDay();
	
	//displays company funds
	//output example:
	//Company balance is now 148
	void displayFunds();
	
	//displays number of deliveries company has done so far
	//output example:
	//Till now company has delivered 3 parcels
	void displayNumberOfDeliveries();
};

#endif /* DELIVERYCOMPANY_H_ */
