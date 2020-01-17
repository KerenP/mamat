#include "parcel.H"
#include "DeliveryVehicle.H"
int main()
{
    int numDeliveries=0;
    Parcel *par1 = new Parcel("boots",0);
    Parcel *par2 = new Parcel("Ram",1);
    Parcel *par3 = new Parcel("Deress",2);
    Parcel *par4 = new Parcel("Fluffy Unicorn",3);
    Parcel *par5 = new Parcel("Invisibility Cloak",4);
    Parcel *par6 = new Parcel("Puppet",5);
    DeliveryVehicle *car= new DeliveryVehicle("mazda",good);
    if(!car->addParcel(par1))
        cout << "BAD1"<<endl;
    if(!car->addParcel(par2))
        cout << "BAD2"<<endl;
    if(!car->addParcel(par3))
        cout << "BAD3"<< endl;
    if(!car->addParcel(par3))
        cout << "BAD4" << endl;
    if(!car->addParcel(par4))
        cout << "BAD5" << endl;
    if(!car->addParcel(par5))
        cout << "BAD6" << endl;
    if(!car->addParcel(par6))
        cout << "BAD7" << endl;
    car->performDeliveryDay(&numDeliveries);
    delete car;
}
