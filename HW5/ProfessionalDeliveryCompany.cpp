#include "ProfessionalDeliveryCompany.H"

ProfessionalDeliveryCompany ::ProfessionalDeliveryCompany(int money) : DeliveryCompany(money){}
bool ProfessionalDeliveryCompany :: addVehicle(DeliveryVehicle* vehicle){
    if(vehicle->getVehicleType()!=professional){
        delete vehicle;
        return false;
    }
    return DeliveryCompany :: addVehicle(vehicle);
}
ProfessionalDeliveryCompany ::~ProfessionalDeliveryCompany() {}
