#ifndef HW5_DELIVERYVEHICLELIST_H
#define HW5_DELIVERYVEHICLELIST_H

#include <vector>
#include "DeliveryVehicle.H"
using namespace std;
class DeliveryVehicleList {
public:
    DeliveryVehicleList();
    ~DeliveryVehicleList();
    vector <DeliveryVehicle*> vehicle_list;
};


#endif //HW5_DELIVERYVEHICLELIST_H
