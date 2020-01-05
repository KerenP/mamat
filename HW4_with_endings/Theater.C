//
// Created by Marina on 30/12/19.
//

#include "Theater.H"
Theater ::Theater(int row, int col, int num) : Mat(row,col), theater_num(num) {}
int Theater :: getTheaterNum() const {return theater_num;}
void Theater :: Reset(){
    int i=0;
    int j=0;
    for(; i<rows;i++){
        for (; j<cols; j++) {
            mat[i][j]=0;
        }
    }

}
Theater :: ~Theater(){}

