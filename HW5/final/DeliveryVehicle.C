#include "DeliveryVehicle.H"
DeliveryVehicle::DeliveryVehicle(const char *ID, Quality quality) : vehicle_quality(quality), station(0),
distance_traveled_today(0),vehicle_type(regular),parcels_to_deliver()  {
    license_plate=new char[strlen(ID)+1];
    strcpy(license_plate,ID);}
bool DeliveryVehicle::checkParcelExist(Parcel* parcel){
    auto it=find(parcels_to_deliver.begin(), parcels_to_deliver.end(),parcel);
    return  (it!=parcels_to_deliver.end());
    }
bool DeliveryVehicle::addParcel(Parcel *parcel) {
    if(checkParcelExist(parcel) || parcels_to_deliver.size()==MAX_PARCEL_PER_VEHICLE)
        return false;
    parcels_to_deliver.push_back(parcel);
    return true;
}
 bool DeliveryVehicle::performSingleDelivery(int &distance){
    if(parcels_to_deliver.empty())
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
    parcels_to_deliver.erase(parcels_to_deliver.begin());
    delete parcelToDeliver;
    return true;
}

int DeliveryVehicle::performDeliveryDay(int* numberOfDeliveries){
    int distance=0;
    int total_profit=0;
    int total_distance=0;
    int distance_to_next_dest=0;
    int nextDest=0;
    int final_revenue=0;
    distance_traveled_today=0;
    if(parcels_to_deliver.empty())
        cout<< "No parcels to deliver for vehicle " << license_plate << endl;
    else
        cout << "Starting deliveries for vehicle " << license_plate << endl;
    while(!parcels_to_deliver.empty() && (total_distance+distance_to_next_dest < MAX_STATIONS_PER_DAY)){
        performSingleDelivery(distance);
        cout << "Fuel consumed: " << distance << " Revenue is: " << PARCEL_PRICE << endl;
        (*numberOfDeliveries)++;
        total_distance+=distance;
        if(!parcels_to_deliver.empty()){
            nextDest =parcels_to_deliver.front()->getParcelDest();
            distance_to_next_dest=(nextDest>station)?nextDest-station:10-station+nextDest;
        }
    }
    if((*numberOfDeliveries)!=0) {
        total_profit=*numberOfDeliveries*PARCEL_PRICE;
        final_revenue = total_profit - total_distance - vehicle_quality;
        distance_traveled_today = total_distance;
        cout << "Total travel distance is " << total_distance << endl;
        cout << "Total revenue is " << final_revenue << endl;
    }
    return final_revenue;
}
char* DeliveryVehicle :: getLicensePlate() const {return license_plate;}
Quality DeliveryVehicle :: getVehicleQuality() const {return vehicle_quality;}
int DeliveryVehicle :: getStation() const{return station;}
VehicleType DeliveryVehicle :: getVehicleType() const {return vehicle_type;}
DeliveryVehicle ::~DeliveryVehicle() {
    delete[] license_plate;
    while(!parcels_to_deliver.empty()){
        Parcel *curr_parcel = parcels_to_deliver.front();
        parcels_to_deliver.erase(parcels_to_deliver.begin());
        delete curr_parcel;
    }
}
