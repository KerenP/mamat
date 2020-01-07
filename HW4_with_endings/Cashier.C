
#include "Cashier.H"
#include "DubbedMovie.H"
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
Cashier :: Cashier(char* name, int salary, char** workHours) : Employee(name,salary,workHours) ,profit(0){}

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

int Cashier ::getTicketProfit() const {return profit;}

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


int Cashier ::sellTickets(Movie *requestedMovie, Theater *requestedTheater, BOOL isDubbed, int NumTickets,
                          int requestedRow, int RightSeatCol) {
   if(requestedTheater->getRowsNum()<requestedRow)
       return 0;
    BOOL foundTheater=FALSE; // A flag that indicates if the movie is screened in the requested theater
    int price=Movie :: getTicketPrice();
    int requestedTheaterNum = requestedTheater->getTheaterNum();
    if(isDubbed){
        /*To check if the hebrew theater of a dubbed movie is the requested theater, a casting from a pointer to Movie
        to the inheriting type is needed. The static cast is valid because we only do it if the isDubbled
         flag indicated TRUE meaning the Movie pointer contains a pointer to DubbedMovie  */
        DubbedMovie* Dmovie= static_cast<DubbedMovie*>(requestedMovie);
        if((Dmovie->getHebrewTheaterNum()== requestedTheaterNum) || (Dmovie->getTheaterNum() == requestedTheaterNum) )
           foundTheater=TRUE;
    }
    else if(requestedMovie->getTheaterNum() == requestedTheaterNum ) {
        foundTheater=TRUE;
    }
    if(foundTheater){
        int i=RightSeatCol;
        //Check if the requested seats are available
        while((i<RightSeatCol+NumTickets) && (i<=requestedTheater->getColumnsNum()) && !requestedTheater->getElement(requestedRow,i)){
            i++;
        }
        if(i==RightSeatCol+NumTickets){
            //If the seats are available assign them with 1 (taken)
            for(i=RightSeatCol;i<RightSeatCol+NumTickets;i++){
                requestedTheater->setElement(requestedRow,i,1);
            }
            int totCost=NumTickets*price;
            profit+=totCost;
            return totCost;
        }
    }
    return 0;
}
/******************************
Method name:
Cashier :: ~Cashier

Description:
Destructor for class Cashier
Destructor of ancestor -Employee is automatically called.

Parameters:
None

return value:None
******************************/
Cashier :: ~Cashier(){}

