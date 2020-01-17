#include "FastDeliveryVehicle.H"

FastDeliveryVehicle::FastDeliveryVehicle(const char *ID, Quality quality) : DeliveryVehicle(ID, quality) {}

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