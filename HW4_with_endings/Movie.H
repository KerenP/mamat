

#ifndef HW4_MOVIE_H
#define HW4_MOVIE_H
#include <string.h>
#include"Proj.H"
#include "Mat.H"
#define DAYS_OF_WEEK 7

class Movie {
protected:
    char* movie_name;
    int duration;
    char* language;
    static const int price;
    int theater_num;
    Mat weekly_screens;
    /******************************
function name:
Movie :: inner_addScreening

Description:
check if possible to add screening,
if so add screening with given parameters.
this is a method for inner use,
used in Movie::addScreening and DubbedMovie::addHebrewScreening.

Parameters:
day, hour, screening(Mat element)

return value: BOOL(FALSE/TRUE)
******************************/
    BOOL inner_addScreening(int day,int hour,Mat& screens);
    /******************************
function name:
Movie :: inner_getNextScreening

Description:
inner use function,
get closest screening to given hour

Parameters:
day, hour, screens(Mat element)

return value: hour of closest screening (0 if none)
******************************/
    int inner_getNextScreening(int day, int hour,const Mat& screens) const;
public:
    //constructor
    /******************************
function name:
Movie :: Movie

Description:
constructor for class Movie
initialize movie element:
weekly_screens, duration, theater_num, movie_name, language.

Parameters:
name(string), duration, language(string), theaterNum.

return value:None
******************************/
    Movie(char* name, int duration, char* Language, int theaterNum ); //TODO: see if needed to add const to all strings and string array in employee
    //Getters
    /******************************
function name:
Movie :: getName

Description:
get name of movie

Parameters:
None

return value:movie_name
******************************/
    char* getName() const;
    /******************************
function name:
Movie :: getLength

Description:
get duration of movie

Parameters:
None

return value:duration
******************************/
    int getLength() const;
    /******************************
function name:
Movie :: getLanguage

Description:
get movie language

Parameters:
None

return value:language
******************************/
    char* getLanguage() const;
    /******************************
function name:
Movie :: getTheaterNum

Description:
get theater number

Parameters:
None

return value:theater_num
******************************/
    int getTheaterNum() const;
    /******************************
function name:
Movie ::getTicketPrice

Description:
static method, get ticket price(const movie::price)

Parameters:
None

return value:price(static)
******************************/
    static int getTicketPrice() ;
    /******************************
function name:
Movie :: getNextScreening

Description:
use inner_getNextScreening.
get closest screening to given hour

Parameters:
day, hour, screens(Mat element)

return value: hour of closest screening (0 if none)
******************************/
    int getNextScreening(int day, int hour) const;
    //Setter
    /******************************
function name:
Movie :: addScreening

Description:
use inner_addScreening to check if possible to add screening,
if so add screening with given parameters.

Parameters:
day, hour

return value: BOOL(FALSE/TRUE), return value of inner_addScreening
******************************/
    BOOL addScreening(int day,int hour);
    /******************************
function name:
Movie::~Movie

Description:
destructor of class Movie

Parameters:
None

return value:None
******************************/
    ~Movie();
};


#endif //HW4_MOVIE_H
