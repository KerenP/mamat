
#ifndef HW4_CASHIER_H
#define HW4_CASHIER_H


#include "Employee.H"
#include "Theater.H"
#include "Movie.H"

/******************************
class name:
Cashier class inheriting from Employee class

Description:
In addition to all protected members of Employee theater has protected member - profit - profit made by the cashier.
In addition to methods of Employee Cashier has methods:
***********************************/
/******************************
Method name:
Cashier::Cashier

Description:
constructor for class Cashier
initialise ancestor - Employee , by calling constructor with given parameters - name, salary and working hours matrix.
initialise member profit with 0.

Parameters:
name- A string containing the name of the cashier
salary- the salary per hour of the cashier
workHours- an array with 7 strings containing the working hours of the cashier for each day of the week

return value:None
******************************/

/******************************
method name:
Cashier::getTicketProfit

Description:
get the profit made by the cashier - the value of member profit

Parameters:
None

return value:
profit = the profit made by the cashier
******************************/

/******************************
method name:
Cashier::sellTickets

Description:
get a request for tickets to a movie in a requested theater and the number of seats at a requested row and column.
Check if the requested movie is screened at the theater and if the requested seats are available, if all conditions are
 met, set the seats to be taken in the theater, and add the total ticket cost to the cashier's profit.

Parameters:
requestedMovie - a pointer to a requested movie.
requestedTheater - a pointer to a requested theater.
isDubbed - a boolean variable that contains TRUE if the movie has a dubbed version and FALSE if not.
NumTickets - the number of requested tickets.
requestedRow - the number of the requested row.
RightSeatCol - the requested column of the first seat in the requested seats.

return value:
The total cost of the transaction if the transaction was preformed, and zero if not.
******************************/
class Cashier : public Employee {
protected:
    int profit;
public:
    Cashier(char* name, int salary, char**workHours);
    int getTicketProfit() const;
    int sellTickets(Movie* requestedMovie, Theater* requestedTheater,BOOL isDubbed,int NumTickets,int requestedRow, int RightSeatCol);
    ~Cashier();
};
#endif //HW4_CASHIER_H
