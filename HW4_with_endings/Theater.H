

#ifndef HW4_THEATER_H
#define HW4_THEATER_H


#include "Mat.H"
#include"Proj.H"
class Theater : public Mat {
protected:
    int theater_num;
public:
    //constructor
    Theater( int row, int col,int num);
    //Getter
    int getTheaterNum() const;
    //Setter
    void Reset();
    ~Theater();
};
#endif //HW4_THEATER_H
