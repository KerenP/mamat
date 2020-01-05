
#include "Cashier.H"
#include "DubbedMovie.H"
Cashier :: Cashier(char* name, int salary, char** workHours) : Employee(name,salary,workHours) ,profit(0){}
int Cashier ::getTicketProfit() const {return profit;}
//BOOL Cashier :: checkoutPlaces(Movie* movie, int row, int col, int numTickets){

//}
int Cashier ::sellTickets(Movie *requestedMovie, Theater *requestedTheater, BOOL isDubbed, int NumTickets,
                          int requestedRow, int RightSeatCol) {
   if(requestedTheater->getRowsNum()<requestedRow-1)
       return 0;
    BOOL foundTheater=FALSE;
    BOOL availableSeats=FALSE;
    int price=Movie :: getTicketPrice();
    int requestedTheaterNum = requestedTheater->getTheaterNum();
    if(isDubbed){
        DubbedMovie* Dmovie= static_cast<DubbedMovie*>(requestedMovie);
        if((Dmovie->getHebrewTheaterNum()== requestedTheaterNum) || (Dmovie->getTheaterNum() == requestedTheaterNum) )
           foundTheater=TRUE;
    }
    else if(requestedMovie->getTheaterNum() == requestedTheaterNum ) {
        foundTheater=TRUE;
    }
    if(foundTheater){
        int i=RightSeatCol;//TODO: check if indexes start from 1
        while((i<RightSeatCol+NumTickets) && (i<=requestedTheater->getColumnsNum()) && !requestedTheater->getElement(requestedRow,i)){
            i++;
        }
        if(i==RightSeatCol+NumTickets){
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
Cashier :: ~Cashier(){}

