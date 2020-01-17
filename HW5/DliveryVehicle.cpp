#include "DeliveryVehicle.H"
DeliveryVehicle::DeliveryVehicle(const char *ID, Quality quality) : vehicle_quality(quality), station(0),
parcels_to_deliver(), vehicle_type(regular) {
    license_plate=new char[strlen(ID)+1];
    strcpy(license_plate,ID);}
bool DeliveryVehicle::checkParcelExist(Parcel* parcel){ //TODO:check if doesnt cause seg fault
    auto it=find(parcels_to_deliver.begin(), parcels_to_deliver.end(),parcel);
    return  (find(parcels_to_deliver.begin(), parcels_to_deliver.end(),parcel)!=parcels_to_deliver.end());
    }
bool DeliveryVehicle::addParcel(Parcel *parcel) {
    if(checkParcelExist(parcel) || parcels_to_deliver.size()==MAX_PARCEL_PER_VEHICLE)
        return false;
    parcels_to_deliver.push_back(parcel);
    return true;
}
 bool DeliveryVehicle::performSingleDelivery(int &profit, int &distance){
    if(parcels_to_deliver.empty()) //TODO: check if better to place in PreformDeliveryDay
        return false;
    Parcel* parcelToDeliver=parcels_to_deliver.front();
    if(parcelToDeliver->getParcelDest()>=station){
        distance=parcelToDeliver->getParcelDest()-station;
    }
    else
    {
        distance=10-station+parcelToDeliver->getParcelDest();
    }
    parcelToDeliver->printParcelInfo();
    station=parcelToDeliver->getParcelDest();
    profit=PARCEL_PRICE;
    parcels_to_deliver.erase(parcels_to_deliver.begin());
    delete parcelToDeliver;
    return true;
}
int DeliveryVehicle::performDeliveryDay(int* numberOfDeliveries){
    int profit=0;
    int distance=0;
    int total_profit=0;
    int total_distance=0;
    if(parcels_to_deliver.empty())
        cout<< "No parcels to deliver for vehicle " << license_plate << endl;
    else
        cout << "Starting deliveries for vehicle " << license_plate << endl;
    while(!parcels_to_deliver.empty() && (distance < MAX_STATIONS_PER_DAY)){
        performSingleDelivery(profit,distance);
        cout << "Fuel consumed: " << distance << " Revenue is: " << PARCEL_PRICE << endl;
        numberOfDeliveries++;
        total_distance+=distance;
        total_profit+=profit;
    }
    int final_revenue=total_profit-total_distance-vehicle_quality;
    cout << "Total travel distance is " << total_distance << endl;
    cout << "Total revenue is " << final_revenue << endl;
}
char* DeliveryVehicle :: getLicensePlate() const {return license_plate;}
Quality DeliveryVehicle :: getVehicleQuality() const {return vehicle_quality;}
int DeliveryVehicle :: getStation() const{return station;}
VehicleType DeliveryVehicle :: getVehicleType() const {return vehicle_type;}
DeliveryVehicle ::~DeliveryVehicle() {delete license_plate;}
