#include "DeliveryCompany.H"
DeliveryCompany ::DeliveryCompany(int money) : delivery_vehicle_list(), income(money), number_of_deliveries(0),
/*received_last_parcel(0)*/received_last_parcel(NULL),has_parcels(false) {}
bool DeliveryCompany ::  addVehicle(DeliveryVehicle* vehicle){
    auto it=find(delivery_vehicle_list.vehicle_list.begin(), delivery_vehicle_list.vehicle_list.end(),vehicle);
    if(it!=delivery_vehicle_list.vehicle_list.end()){
        cout<<"Can't add vehicle, it already exists"<<endl;
        return false;
    }
    for(auto curr_vehicle : delivery_vehicle_list.vehicle_list){
       if(!strcmp(curr_vehicle->getLicensePlate(),vehicle->getLicensePlate())){
           cout<<"Can't add vehicle, it already exists"<<endl;
           delete vehicle;
           return false;
       }
    }
    delivery_vehicle_list.vehicle_list.insert(delivery_vehicle_list.vehicle_list.begin(),vehicle);
    return true;
}
bool DeliveryCompany :: receiveParcel(Parcel* parcel) {
    unsigned countRecievingAttempts =0;
    auto lastRecievedParcel=delivery_vehicle_list.vehicle_list.begin();
    unsigned searchAvailable=0;
    if (!delivery_vehicle_list.vehicle_list.empty()) {
        lastRecievedParcel=find(delivery_vehicle_list.vehicle_list.begin(),delivery_vehicle_list.vehicle_list.end(),received_last_parcel);
        if(lastRecievedParcel==delivery_vehicle_list.vehicle_list.end()) {
            for (auto curr_vehicle : delivery_vehicle_list.vehicle_list) {
                if (curr_vehicle->addParcel(parcel)) {
                    received_last_parcel = curr_vehicle;
                    has_parcels=true;
                    return true;
                }
                countRecievingAttempts++;
            }
        }
        else {
            unsigned indexOfLastRecieved = distance(delivery_vehicle_list.vehicle_list.begin(), lastRecievedParcel);
            searchAvailable = ((indexOfLastRecieved == (delivery_vehicle_list.vehicle_list.size() - 1) )|| (!has_parcels))
                              ? 0 : indexOfLastRecieved + 1;
        }
        while(  countRecievingAttempts<delivery_vehicle_list.vehicle_list.size() ){
            if (delivery_vehicle_list.vehicle_list[searchAvailable]->addParcel(parcel)) {
                received_last_parcel=delivery_vehicle_list.vehicle_list[searchAvailable];
                has_parcels=true;
                return true;
            }
            countRecievingAttempts++;
            searchAvailable=((searchAvailable==delivery_vehicle_list.vehicle_list.size() - 1)?0:searchAvailable+1);
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
    cout << "Company balance is now " << income<<endl;
}
void DeliveryCompany :: displayNumberOfDeliveries(){
    cout << "Till now company has delivered " << number_of_deliveries << " parcels" <<endl;
}
DeliveryCompany ::~DeliveryCompany() {}