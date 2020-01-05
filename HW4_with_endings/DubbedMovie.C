
#include "DubbedMovie.H"
DubbedMovie :: DubbedMovie (char* name, int duration, char* Language, int theaterNum, int hebrewTheater) :
Movie(name,duration,Language,theaterNum),hebrew_weekly_screens(DAYS_OF_WEEK,MAX_SCREENINGS_PER_DAY),
hebrew_theater_num(hebrewTheater){}
int DubbedMovie :: getNextHebrewScreening(int day, int hour){inner_getNextScreening(day,hour,hebrew_weekly_screens);}
int DubbedMovie :: getHebrewTheaterNum() const {return hebrew_theater_num;}
BOOL DubbedMovie :: addHebrewScreening(int day,int hour){inner_addScreening(day,hour,hebrew_weekly_screens);}
DubbedMovie :: ~DubbedMovie(){}