

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
    BOOL inner_addScreening(int day,int hour,Mat& screens);
    int inner_getNextScreening(int day, int hour,const Mat& screens) const;
public:
    //constructor
    Movie(char* name, int duration, char* Language, int theaterNum ); //TODO: see if needed to add const to all strings and string array in employee
    //Getters
    char* getName() const;
    int getLength() const;
    char* getLanguage() const;
    int getTheaterNum() const;
    static int getTicketPrice() ;
    int getNextScreening(int day, int hour) const;
    //Setter
    BOOL addScreening(int day,int hour);
    ~Movie();
};


#endif //HW4_MOVIE_H
