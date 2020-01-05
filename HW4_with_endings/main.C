//main.C

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "Proj.H"
#include "Mat.H"
#include "Theater.H"
#include "Movie.H"
#include "DubbedMovie.H"
#include "Employee.H"
#include "Cashier.H"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>



#define CHECK_THREE_PARAMS		if (!x_str || !y_str || !z_str) {    \
			x_str = NULL; y_str = NULL; z_str = NULL; w_str = NULL;    \
			fgets(szLine,MAX_LINE_SIZE,stdin);     \
			continue;     \
		}

#define CHECK_TWO_PARAMS		if (!x_str || !y_str) {    \
			x_str = NULL; y_str = NULL; z_str = NULL; w_str = NULL;    \
			fgets(szLine,MAX_LINE_SIZE,stdin);     \
			continue;     \
		}

#define CHECK_ONE_PARAMS		if (!x_str) {    \
			x_str = NULL; y_str = NULL; z_str = NULL; w_str = NULL;   \
			fgets(szLine,MAX_LINE_SIZE,stdin);     \
			continue;     \
		}

#define INIT_PARAMS			x_str = NULL; y_str = NULL; z_str = NULL; w_str = NULL;

#define MAX_LINE_SIZE 255

using namespace std;

int main() {
	int i;
	

	///// parser //////////////////////
  char szLine[MAX_LINE_SIZE];
  const char* delimiters = " \t\n\r";
  char* command;
  char* x_str, *y_str, *z_str, *w_str;
  INIT_PARAMS

  // params of mat, theater:
//  double x, y, data;
  int x_int, y_int, z_int;

  // params of movie:
  char *movieName1=NULL, *movieName2=NULL, *language1=NULL, *language2=NULL;
  int length, theater_num, dubbed_theater_num;
  int day, hour;

  // params of employee
  char *empName1=NULL, *empName2=NULL;
  // pointers to point the new classes:
  Mat *mat1 = NULL;
  Theater* theaters[5];
  for (i=0;i<5;i++){
  	theaters[i]=NULL;
  }
  int theater_index = 0;
  Movie *movie1 = NULL;
  DubbedMovie *movie2 = NULL;
  Employee *employee1 = NULL;
  Cashier *cashier1 = NULL;

  char *workHours[7] ,*workHours2[7];
	for (int ii=0;ii<7;ii++)
	{
		workHours[ii] = new char[6];
		workHours2[ii] = new char[6];
	}

  fgets(szLine,MAX_LINE_SIZE,stdin);
  while (!feof(stdin)) {
	command = strtok(szLine, delimiters);
    if (NULL == command )
        {
			fgets(szLine,MAX_LINE_SIZE,stdin);
            continue;
        }
	// matrix functions:
	if (!strncmp(command, "createMat", 9)) {
		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		x_int = atoi(x_str);
		y_int = atoi(y_str);
		mat1 = new Mat(x_int, y_int);
		INIT_PARAMS
	}
	else if (!strncmp(command, "setElement", 10)) {
		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		z_str = strtok(NULL, delimiters);
		CHECK_THREE_PARAMS
		x_int = atoi(x_str);
		y_int = atoi(y_str);
		z_int = atoi(z_str);
		if (mat1)
		{
			mat1->setElement(x_int,y_int,z_int);
		}
		INIT_PARAMS
	}
	else if (!strncmp(command, "getElement", 10)) {
		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		x_int = atoi(x_str);
		y_int = atoi(y_str);
		if (mat1)
		{
			cout << "mat["<<x_int <<"," << y_int << "]= " << mat1->getElement(x_int,y_int) << endl;
		}
		INIT_PARAMS
	}
	// end of matrix functions	
	// Theater functions:
	else if (!strncmp(command, "createTheater", 13)) {
		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		z_str = strtok(NULL, delimiters);
		CHECK_THREE_PARAMS
		x_int = atoi(x_str);
		y_int = atoi(y_str);
		z_int = atoi(z_str);
		if (theater_index<5)
		{ 
			theaters[theater_index] = new Theater(x_int, y_int, z_int);
			theater_index++;
		}
		else {cout << "cannot create more than 4 theaters!" << endl;}
		INIT_PARAMS
	}

	else if (!strncmp(command, "resetTheater", 12)) {
		x_str = strtok(NULL, delimiters);
		theater_index = atoi(x_str);

		if (theater_index<5)
		{ 
			theaters[theater_index]->Reset();
		}
		else {cout <<" theater number (parameter 1 must be between 0 -> 4! " << endl; }
		INIT_PARAMS
	}
	// end of matrix Theater	
	// Movie functions:
	else if (!strncmp(command, "getTicketPrice", 14)) {
		cout << "Ticket price in NIS is " << Movie::getTicketPrice() << endl;
	}
	//	Movie movie1("Cinema Paradiso", 155, "Italian", 1);
	else if (!strncmp(command, "createMovie", 11)) {

		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		if (movieName1 != NULL) {delete movieName1;}
		movieName1 = new char[y_str-x_str];
		strncpy(movieName1,x_str, y_str-x_str);
		length = atoi(y_str);

		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		if (language1 != NULL) {delete language1;}
		language1 = new char[y_str-x_str];
		strncpy(language1,x_str, y_str-x_str);

		theater_num = atoi(y_str);

		if (theater_num<5)
		{
			movie1 = new Movie(movieName1,length,language1,theater_num);
		}
		else { cout << " theater number (parameter 4 must be between 0 -> 4! " << endl; }
		INIT_PARAMS
	}
	// DubbedMovie movie2("Lion King", 87, "English", 2, 3); //English version in theater 2 and hebrew version in theater 3. 
	else if (!strncmp(command, "createDubbedMovie", 17)) {
		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		if (movieName2 != NULL) {delete movieName2;}
		movieName2 = new char[y_str-x_str];
		strncpy(movieName2,x_str, y_str-x_str);
		length = atoi(y_str);

		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		z_str = strtok(NULL, delimiters);
		CHECK_THREE_PARAMS
		if (language2 != NULL) {delete language2;}
		language2 = new char[y_str-x_str];
		strncpy(language2,x_str, y_str-x_str);

		theater_num = atoi(y_str);
		dubbed_theater_num = atoi(z_str);
		if (theater_num<5)
		{
			movie2 = new DubbedMovie(movieName2,length,language2,theater_num, dubbed_theater_num);
		}
		INIT_PARAMS
	}
	// movie1.addScreening(1, 20); //Adding a screening on Sunday 20:00 o'clock.
	else if (!strncmp(command, "addScreening1", 13)) {

		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		day = atoi(x_str);
		hour = atoi(y_str);
		if (movie1)
		{  movie1->addScreening(day,hour);  }
		else { cout << "no movie created!" << endl;}
		INIT_PARAMS
	}
		else if (!strncmp(command, "addScreening2", 13)) {

		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		day = atoi(x_str);
		hour = atoi(y_str);
		if (movie2)
		{  movie2->addScreening(day,hour);  }
		else { cout << "no movie created!" << endl;}
		INIT_PARAMS
	}
	// movie2.addHebrewScreening(1, 12); //Adding a dubbed screening on Sunday 12:00 o'clock. 
	else if (!strncmp(command, "addHebrewScreening", 18)) {

		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		day = atoi(x_str);
		hour = atoi(y_str);
		if (movie2) { movie2->addHebrewScreening(day,hour); } 
		else { cout << "no dubbed movie created!" << endl;}
		INIT_PARAMS
	}
	// print movies:
	else if (!strncmp(command, "printMovies", 11)) {
		x_str = strtok(NULL, delimiters); // day
		y_str = strtok(NULL, delimiters); // hour
		CHECK_TWO_PARAMS
		day = atoi(x_str);
		hour = atoi(y_str);

		cout << "The movies are:" << endl;
		if (movie1){
			cout << "Name: " << movie1->getName() << endl;
			cout << "Length in minutes: " << movie1->getLength() << endl;
			cout << "Language: " << movie1->getLanguage() << endl;
			cout << "Theater #" << movie1->getTheaterNum() << endl;
			cout << "Next screening is at " << movie1->getNextScreening(day, hour) << ":00 o'clock." << endl;
		}
		if (movie2){
			cout << "Name: " << movie2->getName() << endl;
			cout << "Length in minutes: " << movie2->getLength() << endl;
			cout << "Theater #" << movie2->getHebrewTheaterNum() << " (dubbed)" << endl;
			cout << "Next screening is at " << movie2->getNextScreening(day, hour) << ":00 o'clock." << endl;
			cout << "Next Hebrew screening is at " << movie2->getNextHebrewScreening(day, hour) << ":00 o'clock." << endl;
		}
		INIT_PARAMS
	}
	// parser for Employee:

	else if (!strncmp(command, "createEmployee", 14)) {

		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		if (empName1 != NULL) {delete empName1;}
		empName1 = new char[y_str-x_str];
		strncpy(empName1,x_str, y_str-x_str);

		bool wrongParams = false;
		for (int ii=0;ii<7 && wrongParams == false;ii++)
		{
			z_str = strtok(NULL, delimiters);
			if (z_str)
			{
				strcpy(workHours[ii],z_str);
			}
			else {
				wrongParams = true;
				cout << "wrong parameters!"<< endl;
				INIT_PARAMS
				continue;
			}
		}
		if (wrongParams == false)
		{
			y_int = atoi(y_str);
			employee1 = new Employee(empName1,y_int,workHours);
			
		}
		INIT_PARAMS
	}
	else if (!strncmp(command, "createCashier", 13)) {
		x_str = strtok(NULL, delimiters);
		y_str = strtok(NULL, delimiters);
		CHECK_TWO_PARAMS
		if (empName2 != NULL) {delete empName2;}
		empName2 = new char[y_str-x_str];
		strncpy(empName2,x_str, y_str-x_str);

		bool wrongParams = false;
		for (int ii=0;ii<7 && wrongParams == false;ii++)
		{
			z_str = strtok(NULL, delimiters);
			if (z_str)
			{
				strcpy(workHours2[ii],z_str);
			}
			else {
				wrongParams = true;
				cout << "wrong parameters!"<< endl;
				INIT_PARAMS
				continue;
			}
		}
		if (wrongParams == false)
		{
			y_int = atoi(y_str);
			cashier1 = new Cashier(empName2,y_int,workHours2);
			
		}
		INIT_PARAMS
	}

//		int temp_profit1 = cashier.sellTickets(&movie1, theaters[0], FALSE, 3, 1, 2); //The chosen seats are 2-4 in row 1.
//		int temp_profit2 = cashier.sellTickets(&movie2, theaters[4], TRUE, 3, 1, 2);

	else if (!strncmp(command, "sellTickets", 11)) {
		x_str = strtok(NULL, delimiters); // movie index
		y_str = strtok(NULL, delimiters); // theater index
		z_str = strtok(NULL, delimiters); // 1/0
		CHECK_THREE_PARAMS
		z_int = atoi(z_str);
		BOOL z_bool;
		switch (z_int)
		{
		case 0: z_bool = FALSE; break;
		case 1: z_bool = TRUE; break;
		default: cout << "3rd parameter must be 0 or 1!" << endl;  INIT_PARAMS continue;
		}

		
		x_int = atoi(x_str);			// movie index
		theater_index = atoi(y_str);    // theater index

		z_str = strtok(NULL, delimiters); // number of tickets
		x_str = strtok(NULL, delimiters); //  desired row
		y_str = strtok(NULL, delimiters); // desired col
		CHECK_THREE_PARAMS
		int temp_profit1 = 0;
		switch (x_int)
		{
		case 1:
			temp_profit1 = cashier1->sellTickets(movie1, theaters[theater_index], z_bool, atoi(z_str), atoi(x_str), atoi(y_str));
			break;
		case 2:
			temp_profit1 = cashier1->sellTickets(movie2, theaters[theater_index], z_bool, atoi(z_str), atoi(x_str), atoi(y_str));
			break;
		default:
			cout << "movie index must be 1 or 2!" << endl;
			break;
		}
		if (temp_profit1 != 0)
		{ cout << "Ticket Profit (NIS):" << cashier1->getTicketProfit() << endl; }
		else { cout << "Transaction Failed!" << endl;}
		INIT_PARAMS
	}
	else if (!strncmp(command, "printEmployees", 14)) {

		cout << "The Employees are:" << endl;
		if (employee1){
			cout << "Employee:" << endl;
			cout << "Name: " << employee1->getName() << endl;
			cout << "Salary in NIS: " << employee1->getSalary() << endl;
			cout << "Weekly Salary in NIS: " << employee1->calcWeeklySalary() << endl;
		}
		if (cashier1){
			cout << "Cashier:" << endl;
			cout << "Name: " << cashier1->getName() << endl;
			cout << "Salary in NIS: " << cashier1->getSalary() << endl;
			cout << "Weekly Salary in NIS: " << cashier1->calcWeeklySalary() << endl;
			cout << "Ticket Profit (NIS): " << cashier1->getTicketProfit() << endl;
		}
		INIT_PARAMS
	}

	fgets(szLine,MAX_LINE_SIZE,stdin);
  }
  

  ///// end of parser //////////////////////


	for(i=0; i<5; i++) {
		if (theaters[i]!=NULL) {delete theaters[i];}
	} 
	for (i=0;i<7;i++)
	{
		delete[] workHours[i];
		delete[] workHours2[i];
	}
	delete[] movieName1; delete[] movieName2; delete[] language1; delete[] language2; delete[] empName1; delete[] empName2;
	delete movie1; delete movie2; delete employee1; delete cashier1; 
	delete mat1;
	return 0;
}


