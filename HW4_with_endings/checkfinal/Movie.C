

#include "Movie.H"
const int Movie :: price=35;
/******************************
function name:
Movie ::getTicketPrice

Description:
static method, get ticket price (const movie::price)

Parameters:
None

return value:price
******************************/
int Movie ::getTicketPrice() { return  price;}
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
Movie :: Movie(char *name, int duration, char *Language, int theaterNum) : weekly_screens(DAYS_OF_WEEK , MAX_SCREENINGS_PER_DAY),
duration(duration), theater_num(theaterNum), movie_name(name),language(Language){}
/******************************
function name:
Movie :: getName

Description:
get name of movie

Parameters:
None

return value:movie_name
******************************/
char* Movie :: getName() const {return movie_name;}
/******************************
function name:
Movie :: getLength

Description:
get duration of movie

Parameters:
None

return value:duration
******************************/
int Movie :: getLength() const {return duration;}
/******************************
function name:
Movie :: getTheaterNum

Description:
get theater number

Parameters:
None

return value:theater_num
******************************/
int Movie :: getTheaterNum() const { return theater_num;}
/******************************
function name:
Movie :: getLanguage

Description:
get movie language

Parameters:
None

return value:language
******************************/
char* Movie :: getLanguage() const {return language;}
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
BOOL Movie ::inner_addScreening(int day, int hour, Mat& screening) {
    int i=1;
    int endTime;
    while(i<=MAX_SCREENINGS_PER_DAY && screening.getElement(day,i)!=0){
        i++;
    }
    if(i==MAX_SCREENINGS_PER_DAY+1 ){
        return FALSE;
    }
    if(i!=1){
        endTime=screening.getElement(day,i-1)*60+duration;
        if(endTime>hour*60){
            return FALSE;
        }
    }
    screening.setElement(day,i,hour);
    return TRUE;
}
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
BOOL Movie ::addScreening(int day, int hour) {inner_addScreening( day, hour, weekly_screens);}
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
int Movie :: inner_getNextScreening(int day, int hour,const Mat& screens) const{
    for(int i=1;i<=MAX_SCREENINGS_PER_DAY; i++){
        if(screens.getElement(day,i)>hour){
            return screens.getElement(day,i);
        }
    }
    return 0;
}
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
int Movie ::getNextScreening(int day, int hour) const { inner_getNextScreening(day,hour,weekly_screens);}
/******************************
function name:
Movie::~Movie

Description:
destructor of class Movie

Parameters:
None

return value:None
******************************/
Movie :: ~Movie(){}






