#include "DeliveryVehicle.H"
DeliveryVehicle::DeliveryVehicle(const char *ID, Quality quality) : vehicle_type(quality) {
    license_plate=new char[strlen(ID)+1];
    strcpy(license_plate,ID);}
bool DeliveryVehicle::checkParcelExist(Parcel* parcel){
    stack <Parcel*> temp;
    bool isParcelFound= false;
    while(!parcels_to_deliver.empty()){
        temp.push(parcels_to_deliver.top());
        if(parcel==parcels_to_deliver.top())
        {
            isParcelFound = true;
        }
        parcels_to_deliver.pop();
    }
    while(!temp.empty()){
        parcels_to_deliver.push(temp.top());
        temp.pop();
    }
    return isParcelFound;
}
bool DeliveryVehicle::addParcel(Parcel *parcel) {//TODO:Check if a virtual inner function is required
if(checkParcelExist(parcel) || parcels_to_deliver.size()==MAX_PARCEL_PER_VEHICLE)
    return false;
    parcels_to_deliver.push(parcel);
    return true;
}
 bool DeliveryVehicle::performSingleDelivery(int *profit, int *distance){
    Parcel* parcelToDeliver=parcels_to_deliver.top();
    if(parcelToDeliver->getParcelDest()>=station){
        *distance=parcelToDeliver->getParcelDest()-station;
    }
    else
    {
        *distance=10-station+parcelToDeliver->getParcelDest();
    }
    station=parcelToDeliver->getParcelDest();
}
int performDeliveryDay(int* numberOfDeliveries){
    int numStations=0;
    while(numStations<MAX_STATIONS_PER_DAY){

    }
}
