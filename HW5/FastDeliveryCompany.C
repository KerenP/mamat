#include "FastDeliveryCompany.H"

FastDeliveryCompany ::FastDeliveryCompany(int money) : DeliveryCompany(money){}
bool FastDeliveryCompany :: addVehicle(DeliveryVehicle* vehicle){
    if(vehicle->getVehicleType()!=fast){
        delete vehicle;
        return false;
    }
    return DeliveryCompany :: addVehicle(vehicle);
}
FastDeliveryCompany ::~FastDeliveryCompany() {}

