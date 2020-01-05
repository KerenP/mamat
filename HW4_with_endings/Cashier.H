
#ifndef HW4_CASHIER_H
#define HW4_CASHIER_H


#include "Employee.H"
#include "Theater.H"
#include "Movie.H"
class Cashier : public Employee {
protected:
    int profit;
    //BOOL checkoutPlaces(Movie* movie, int row, int col, int numTickets);
public:
    Cashier(char* name, int salary, char**workHours);
    int getTicketProfit() const;
    int sellTickets(Movie* requestedMovie, Theater* requestedTheater,BOOL isDubbed,int NumTickets,int requestedRow, int RightSeatCol);
    ~Cashier();
};//TODO: distructor???
#endif //HW4_CASHIER_H
