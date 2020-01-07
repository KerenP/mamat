
#include "DubbedMovie.H"
/******************************
Method name:
DubbedMovie :: DubbedMovie

Description:
constructor for class DubbedMovie
initialise ancestor - Movie , by calling constructor with given parameters - name, duration Language, theaterNum.
initialise member hebrew_theater_num by hebrewTheater.
initialise member hebrew_weekly_screens of type Mat by calling constructor with DAYS_OF_WEEK and MAX_SCREENINGS_PER_DAY.

Parameters:
name- A string containing the name of the movie
duration- the duration of the movie in minutes
Language - A string containing the language of the movie
theaterNum- the id of the theater in which the movie is screened
hebrewTheater -  the id of the theater in which the dubbed version of the movie is screened

return value:None
******************************/
DubbedMovie :: DubbedMovie (char* name, int duration, char* Language, int theaterNum, int hebrewTheater) :
Movie(name,duration,Language,theaterNum),hebrew_weekly_screens(DAYS_OF_WEEK,MAX_SCREENINGS_PER_DAY),
hebrew_theater_num(hebrewTheater){}

/******************************
method name:
DubbedMovie::getNextHebrewScreening

Description:
get the closest screening of the dubbed movie in relation to the given day and hour.
uses the inner func inner_getNextScreening inherited from Movie with the hebrew_weekly_screens matrix

Parameters:
day & hour of the requested dubbed movie.

return value:
the hour of the closest screening of the dubbed movie.
******************************/

int DubbedMovie :: getNextHebrewScreening(int day, int hour){inner_getNextScreening(day,hour,hebrew_weekly_screens);}

/******************************
method name:
DubbedMovie::getHebrewTheaterNum

Description:
get the id of the theater in which the dubbed version of the movie is screened

Parameters:
None

return value:
hebrew_theater_num = the id of the theater in which the dubbed version of the movie is screened
 ******************************/

int DubbedMovie :: getHebrewTheaterNum() const {return hebrew_theater_num;}

/******************************
method name:
DubbedMovie::addHebrewScreening

Description:
uses the inner func inner_addScreening inherited from Movie with the hebrew_weekly_screens matrix to  check if the
dubbed movie screening can be added at the requested day and time, add it if possible.

Parameters:
day & hour of the requested dubbed movie.

return value:
TRUE if the screening was added successfully
FALSE if the screening couldn't be added
******************************/

BOOL DubbedMovie :: addHebrewScreening(int day,int hour){inner_addScreening(day,hour,hebrew_weekly_screens);}

/******************************
Method name:
DubbedMovie :: ~DubbedMovie

Description:
Destructor for class DubbedMovie
Destructor of ancestor -Movie is automatically called.
Destructor for member hebrew_weekly_screens is automatically called.

Parameters:
None

return value:None
******************************/

DubbedMovie :: ~DubbedMovie(){}