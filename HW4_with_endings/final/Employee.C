

#include "Employee.H"

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

Employee::Employee(char *name, int salary, char **work_hours) : employeeName(name), salaryPerHour(salary),
workHours(work_hours) {}

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
char* Employee::getName() const{ return employeeName;}

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

int Employee::getSalary() const{ return salaryPerHour;}

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

int Employee::calcWeeklySalary(){
    int salarySum = 0;
    for(int i=0; i<7; i++){//TODO: move const from Movie to Proj.H
        salarySum+=((workHours[i][3]-'0')*10+(workHours[i][4]-'0'))-((workHours[i][0]-'0')*10+(workHours[i][1]-'0'));
    }
    return (salarySum*salaryPerHour);
}
/******************************
Method name:
Employee :: ~Employee

Description:
Destructor for class Employee, no memory was allocated so it behaves like a default destructor.

Parameters:
None

return value:None
******************************/
Employee ::~Employee() {}