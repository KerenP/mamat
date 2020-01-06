

#ifndef HW4_THEATER_H
#define HW4_THEATER_H


#include "Mat.H"
#include"Proj.H"

/******************************
class name:
Theater class inheriting from Mat class

Description:
In addition to all protected members of Mat theater has protected member - theater_num - the id of theater.
methods:
***********************************/

/******************************
Method name:
Theater::Theater

        Description:
constructor for class Theater
        initialise ancestor - Mat , by calling constructor with row as number of rows and col as number of columns.
initialise member theater_num with num.

Parameters:
row-number of rows
        col-number of columns
        num-theater id

return value:None
*******************************/
 /******************************
method name:
Theater::getTheaterNum

Description:
get the id of the Theater - theater_num

Parameters:
None

return value:
theater_num = the theater id
  *****************************/
 /******************************
method name:
Theater::Reset

Description:
set all the values in the Theater to be 0.

Parameters:
None

return value:
None
*********************************/
/******************************
Method name:
Theater:: ~Theater

Description:
Destructor for class Theater
Destructor of ancestor -Mat is automatically called.

Parameters:
None

return value:None
******************************/


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
