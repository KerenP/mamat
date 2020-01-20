#include "DeliveryCompany.H"
DeliveryCompany ::DeliveryCompany(int money) : delivery_vehicle_list(), income(money), number_of_deliveries(0),
received_last_parcel(0) {}
bool DeliveryCompany ::  addVehicle(DeliveryVehicle* vehicle){
    auto it=find(delivery_vehicle_list.vehicle_list.begin(), delivery_vehicle_list.vehicle_list.end(),vehicle);
    if(it!=delivery_vehicle_list.vehicle_list.end()){
        cout<<"Can't add vehicle, it already exists";
        return false;
    }
    for(auto curr_vehicle : delivery_vehicle_list.vehicle_list){
       if(!strcmp(curr_vehicle->getLicensePlate(),vehicle->getLicensePlate())){
           cout<<"Can't add vehicle, it already exists";
           delete vehicle;
           return false;
       }
    }
    delivery_vehicle_list.vehicle_list.insert(delivery_vehicle_list.vehicle_list.begin(),vehicle);
    return true;
}
bool DeliveryCompany :: receiveParcel(Parcel* parcel){
    if(!delivery_vehicle_list.vehicle_list.empty()) {
        unsigned searchAvailable = received_last_parcel+1;
        while(searchAvailable!=received_last_parcel ){
            if (received_last_parcel == delivery_vehicle_list.vehicle_list.size() - 1) {
                searchAvailable=0;
            }
            else
                searchAvailable++;
          if( delivery_vehicle_list.vehicle_list[searchAvailable]->addParcel(parcel)){
              received_last_parcel = searchAvailable;
              return true;
          }
        }
    }
    delete parcel;
    return false;
}
bool DeliveryCompany :: performDeliveryDay(){
    int dailyDeliveries=0;
    int dailyProfit=0;
    int singleVehicleDeliveries=0;
    if(delivery_vehicle_list.vehicle_list.empty()){
        return false;
    }
    cout << "Starting days deliveries:"<<endl;
    for(auto curr_vehicle : delivery_vehicle_list.vehicle_list){
        dailyProfit+=curr_vehicle->performDeliveryDay(&singleVehicleDeliveries);
        dailyDeliveries+=singleVehicleDeliveries;
        singleVehicleDeliveries=0;
    }
    income+=dailyProfit;
    number_of_deliveries+=dailyDeliveries;
    cout<<"Total revenue for company is " << dailyProfit<<endl;
    return true;
}
void DeliveryCompany :: displayFunds(){
    cout << "Company balance is now " << income;
}
void DeliveryCompany :: displayNumberOfDeliveries(){
    cout << "Till now company has delivered " << number_of_deliveries << " parcels";
}
DeliveryCompany ::~DeliveryCompany() {}