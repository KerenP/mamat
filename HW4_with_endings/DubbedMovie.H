

#ifndef HW4_DUBBEDMOVIE_H
#define HW4_DUBBEDMOVIE_H
#include "Movie.H"
class DubbedMovie : public Movie{
protected:
  int hebrew_theater_num;
  Mat hebrew_weekly_screens;
public:
    DubbedMovie(char* name, int duration, char* Language, int theaterNum, int hebrewTheater);
    BOOL addHebrewScreening(int day,int hour);
    int getNextHebrewScreening(int day, int hour);
    int getHebrewTheaterNum() const;
    ~DubbedMovie();
};
#endif //HW4_DUBBEDMOVIE_H
