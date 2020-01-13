

#include "Theater.H"
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
******************************/

Theater ::Theater(int row, int col, int num) : Mat(row,col), theater_num(num) {}

/******************************
method name:
Theater::getTheaterNum

Description:
get the id of the Theater - theater_num

Parameters:
None

return value:
theater_num = the theater id
******************************/

int Theater :: getTheaterNum() const {return theater_num;}

/******************************
method name:
Theater::Reset

Description:
set all the values in the Theater to be 0.

Parameters:
None

return value:
None
******************************/

void Theater :: Reset(){
    int i=0;
    int j=0;
    for(; i<rows;i++){
        for (; j<cols; j++) {
            mat[i][j]=0;
        }
    }

}

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

Theater :: ~Theater(){}

