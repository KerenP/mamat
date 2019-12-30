

#ifndef HW4_MOVIE_H
#define HW4_MOVIE_H
#include <string.h>
#include"Proj.H"
#include "Mat.h"
#define DAYS_OF_WEEK 7

class Movie {
protected:
    char* movie_name;
    int duration;
    char* language;
    static const int price;
    int theater_num;
    Mat weekly_screens;
public:
    //constructor
    Movie(char* name, int duration, char* language, int theaterNum );
    //Getters
    char* getName() const;
    int getLength() const;
    char* getLanguage() const;
    int getTheaterNum() const;
    static int getTicketPrice() ;
    //Setter
    BOOL addScreening(int day,int hour);
    int getNextScreening(int day, int hour);
    ~Movie();
};


#endif //HW4_MOVIE_H
