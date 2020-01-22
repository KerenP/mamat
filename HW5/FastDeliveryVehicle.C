#include "FastDeliveryVehicle.H"

FastDeliveryVehicle::FastDeliveryVehicle(const char *ID, Quality quality) : DeliveryVehicle(ID, quality) {
    vehicle_type=fast;
}

int FastDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries){
    int distance=0;
    int total_profit=0;
    int total_distance=0;
    int next_dest=0;
    distance_traveled_today=0;
    if(parcels_to_deliver.empty())
        cout<< "No parcels to deliver for vehicle " << license_plate << endl;
    else
        cout << "Starting deliveries for vehicle " << license_plate << endl;
    while(!parcels_to_deliver.empty() && (total_distance+next_dest < MAX_STATIONS_PER_DAY)){
        performSingleDelivery(distance);
        int revenue = distance*2;
        cout << "Fuel consumed: " << distance << " Revenue is: " << revenue << endl;
        (*numberOfDeliveries)++;
        total_distance+=distance;
        total_profit+=revenue;
        if(!parcels_to_deliver.empty()){
            next_dest=parcels_to_deliver.front()->getParcelDest();
        }
    }
    int final_revenue=total_profit-total_distance-vehicle_quality;
    cout << "Total travel distance is " << total_distance << endl;
    cout << "Total revenue is " << final_revenue << endl;
    return final_revenue;
}


FastDeliveryVehicle::~FastDeliveryVehicle(){}