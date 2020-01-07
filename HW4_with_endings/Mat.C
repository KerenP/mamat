

#include "Mat.H"
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
Mat::Mat (const int rows, const int cols)   {
    this->rows=rows;
    this->cols=cols;
    mat=new int*[rows];
    int i=0;
    for( i=0; i<rows;i++) {
        mat[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }
}
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
int Mat::getRowsNum() const {return rows;}
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
int Mat::getColumnsNum() const { return cols;}
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
int Mat::getElement(int row, int col) const {return mat[row-1][col-1];}
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
void Mat::setElement(int row, int col, int elem) {
    mat[row-1][col-1]=elem;
}
/******************************
function name:
Mat::~Mat

Description:
destructor of class Mat

Parameters:
None

return value:None
******************************/
Mat::~Mat() {
    for(int i=0;i<rows;i++){
        delete[] mat[i];
    }
    delete [] mat;
}


