#include "DeliveryVehicleList.H"

DeliveryVehicleList::DeliveryVehicleList() : vehicle_list(){}
DeliveryVehicleList::~DeliveryVehicleList() {
    while(!vehicle_list.empty()){
        DeliveryVehicle *curr_vehicle = vehicle_list.front();
        vehicle_list.erase(vehicle_list.begin());
        delete curr_vehicle;
    }
}