

#ifndef HW4_EMPLOYEE_H
#define HW4_EMPLOYEE_H
#include"Proj.H"

class Employee {
protected:
    char* employeeName;
    int salaryPerHour;
    char **workHours;
public:
    //constructor
    Employee(char* name, int salary, char** work_hours);
    //getters
    char* getName() const;
    int getSalary() const;
    int calcWeeklySalary();
    //destructor
    ~Employee();
};


#endif //HW4_EMPLOYEE_H
