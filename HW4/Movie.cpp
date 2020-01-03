

#include "Movie.h"
const int Movie :: price=35;
int Movie ::getTicketPrice() { return  price;}
Movie :: Movie(char *name, int duration, char *Language, int theaterNum) : weekly_screens(DAYS_OF_WEEK , MAX_SCREENINGS_PER_DAY),
duration(duration), theater_num(theaterNum), movie_name(name),language(Language){}
char* Movie :: getName() const {return movie_name;}
int Movie :: getLength() const {return duration;}
int Movie :: getTheaterNum() const { return theater_num;}
char* Movie :: getLanguage() const {return language;}

BOOL Movie ::inner_addScreening(int day, int hour, Mat& screening) {
    int i=1;
    int endTime;
    while(screening.getElement(day,i)!=0 && i<=MAX_SCREENINGS_PER_DAY){
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
BOOL Movie ::addScreening(int day, int hour) {inner_addScreening( day, hour, weekly_screens);}
int Movie :: inner_getNextScreening(int day, int hour,const Mat& screens) const{
    for(int i=1;i<=MAX_SCREENINGS_PER_DAY; i++){
        if(screens.getElement(day,i)>hour){
            return screens.getElement(day,i);
        }
    }
    return 0;
}
int Movie ::getNextScreening(int day, int hour) const { inner_getNextScreening(day,hour,weekly_screens);}
Movie :: ~Movie(){
    //delete [] movie_name;
    //delete [] language;
    //TODO: call mat destructor??
}






