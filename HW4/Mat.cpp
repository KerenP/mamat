

#include "Mat.h"
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
int Mat::getRowsNum() const {return rows;}
int Mat::getColumnsNum() const { return cols;}
int Mat::getElement(int row, int col) const {return mat[row-1][col-1];}
void Mat::setElement(int row, int col, int elem) {mat[row-1][col-1]=elem;}
Mat::~Mat() {
    for(int i=0;i<rows;i++){
        delete[] mat[i];
    }
    delete [] mat;
}


