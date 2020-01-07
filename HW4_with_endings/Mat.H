

#ifndef HW4_MAT_H
#define HW4_MAT_H


class Mat {
protected:
    int rows;
    int cols;
    int** mat;
public:
    //constructor
    /******************************
function name:
Mat::Mat

Description:
constructor for class Mat
initialized with given number of rows and columns

Parameters:
rows, cols

return value:None
******************************/
    Mat(int rows, int cols);
    // Getters
    /******************************
function name:
Mat::getRowsNum

Description:
get number of rows

Parameters:
None

return value:
number of rows
******************************/
    int getRowsNum() const ;
    /******************************
function name:
Mat::getColumnsNum

Description:
get number of columns

Parameters:
None

return value:
number of columns
******************************/
    int getColumnsNum() const;
    /******************************
function name:
Mat::getElement

Description:
get element from matrix

Parameters:
row, col

return value:
matrix element (int)
******************************/
    int getElement(int row, int col) const;
    //Setter
    /******************************
function name:
Mat::setElement

Description:
set element in matrix

Parameters:
row, col, element

return value:
None
******************************/
    void setElement(int row, int col, int elem);
    //destructor
    /******************************
function name:
Mat::~Mat

Description:
destructor of class Mat

Parameters:
None

return value:None
******************************/
    ~Mat();
};
#endif //HW4_MAT_H
