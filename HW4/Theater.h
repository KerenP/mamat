

#ifndef HW4_THEATER_H
#define HW4_THEATER_H


#include "Mat.h"
#include"Proj.H"
class Theater : public Mat {
protected:
    int theater_num;
public:
    //constructor
    Theater(int num, int row, int col);
    //Getter
    int getTheaterNum() const;
    //Setter
    void reset();
};
#endif //HW4_THEATER_H
