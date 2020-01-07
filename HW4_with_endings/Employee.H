

#ifndef HW4_EMPLOYEE_H
#define HW4_EMPLOYEE_H
#include"Proj.H"
/******************************
class name:
Employee class

Description:
 protected members - employeeName -a string containing the name of the employee, salaryPerHour= the hourly salary of
 the employee, workHours- an array of strings containing the working hours of the employee for each day of the week.
methods:
***********************************/
/******************************
Method name:
Employee::Employee

Description:
constructor for class Employee
initialise Employee, with given parameters - name, salary and working hours matrix.
initialise member profit with 0.

Parameters:
name- A string containing the name of the employee
salary- the salary per hour of the employee
workHours- an array with 7 strings containing the working hours of the employee for each day of the week

return value:None
******************************/

/******************************
method name:
Employee::getName

Description:
get the the name of the employee

Parameters:
None

return value:
employeeName - the name of the employee
******************************/

/******************************
method name:
Employee::getSalary

Description:
get the the hourly salary of the employee

Parameters:
None

return value:
salaryPerHour - the hourly salary of the employee
******************************/

/******************************
method name:
Employee::calcWeeklySalary

Description:
calculate the weekly salary of an employee by counting the sum of working hours during the week and multiplying by the
hourly salary.

Parameters:
None

return value:
the weekly salary of the employee
******************************/

/******************************
Method name:
Employee :: ~Employee

Description:
Destructor for class Employee, no memory was allocated so it behaves like a default destructor.

Parameters:
None

return value:None
******************************/
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
