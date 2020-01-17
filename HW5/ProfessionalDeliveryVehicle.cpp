#include "ProfessionalDeliveryVehicle.H"
ProfessionalDeliveryVehicle ::ProfessionalDeliveryVehicle(const char *ID, Quality quality) :DeliveryVehicle(ID,quality)
{vehicle_type=professional;}
bool ProfessionalDeliveryVehicle :: addParcel(Parcel* parcel){
    int last_dest;
    if(!parcels_to_deliver.empty()) {
        last_dest = parcels_to_deliver.back()->getParcelDest();

        if (checkParcelExist(parcel) || parcels_to_deliver.size() == MAX_PARCEL_PER_VEHICLE)
            return false;
        int new_parcel_dest = parcel->getParcelDest();
        int distance_to_last =
                last_dest < new_parcel_dest ? new_parcel_dest - last_dest : 10 - last_dest + new_parcel_dest;
        if (distance_to_last > PARCEL_PRICE)
            return false;
    }
        parcels_to_deliver.push_back(parcel);
        return true;
}
 int ProfessionalDeliveryVehicle :: performDeliveryDay(int* numberOfDeliveries){
    int profit = DeliveryVehicle :: performDeliveryDay(numberOfDeliveries);
    if(!numberOfDeliveries){

    }
return profit;
}

