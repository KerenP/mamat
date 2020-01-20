#include "Parcel.H"

Parcel::Parcel (const char* ID, int dest) : parcelDest(dest){
    parcelID=new char[strlen(ID)+1];
    strcpy(parcelID ,ID);
}

char* Parcel::getParcelID() const { return parcelID;}
int Parcel::getParcelDest() { return parcelDest;}
void Parcel::printParcelInfo() {cout<<"Delivering parcel " << parcelID << " to position " << parcelDest <<endl;}
Parcel::~Parcel() {}
