

#include "Movie.h"
const int Movie :: price=35;
int Movie ::getTicketPrice() { return  price;}
Movie :: Movie(char *name, int duration, char *language, int theaterNum) : weekly_screens(DAYS_OF_WEEK , MAX_SCREENINGS_PER_DAY),
duration(duration), theater_num(theaterNum){
    //movie_name=new char[strlen(name)+1];
    //this->language=new char[strlen(language)+1];
    //strcpy(movie_name,name);
    //strcpy(this->language,language);
    movie_name=name;
    this->language=language;
}
char* Movie :: getName() const {return movie_name;}
int Movie :: getLength() const {return duration;}
int Movie :: getTheaterNum() const { return theater_num;}

BOOL Movie ::addScreening(int day, int hour) {
    int i=0;
    int endTime;
    while(weekly_screens.getElement(day,i)!=0 && i<MAX_SCREENINGS_PER_DAY){
        i++;
    }
    if(i==MAX_SCREENINGS_PER_DAY ){
        return FALSE;
    }
    if(i!=0){
        endTime=weekly_screens.getElement(day,i-1)*60+duration;
        if(endTime>hour*60){
            return FALSE;
        }
    }
    weekly_screens.setElement(day,i,hour);
    return TRUE;
}
int Movie ::getNextScreening(int day, int hour) {
    for(int i=0;i<MAX_SCREENINGS_PER_DAY; i++){
        if(weekly_screens.getElement(day,i)>hour){
            return weekly_screens.getElement(day,i);
        }
    }
    return 0;
}
Movie :: ~Movie(){
    //delete [] movie_name;
    //delete [] language;
    //TODO: call mat destructor??
}






