#ifndef PARCEL_H_
#define PARCEL_H_

#include <string.h>
#define PARCEL_PRICE 4
using namespace std;
class Parcel{
protected:
    char* parcelID;
    int parcelDest;
public:
	//c'tor	
	Parcel(const char* ID, int dest);
	
	//d'tor
	~Parcel();

	char* getParcelID() const ;
	int getParcelDest();
};

#endif /* PARCEL_H_ */
