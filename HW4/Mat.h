

#ifndef HW4_MAT_H
#define HW4_MAT_H


class Mat {
protected:
    int rows;
    int cols;
    int** mat;
public:
    //constructor
    Mat(int rows, int cols);
    // Getters
    int getRowsNum() const ;
    int getColumnsNum() const;
    int getElement(int row, int col) const;
    //Setter
    void setElement(int row, int col, int elem);
    //destructor
    ~Mat();
};
#endif //HW4_MAT_H
