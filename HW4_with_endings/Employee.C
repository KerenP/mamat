

#include "Employee.H"
Employee::Employee(char *name, int salary, char **work_hours) : employeeName(name), salaryPerHour(salary),
workHours(work_hours) {}
char* Employee::getName() const{ return employeeName;}
int Employee::getSalary() const{ return salaryPerHour;}
int Employee::calcWeeklySalary(){
    int salarySum = 0;
    for(int i=0; i<7; i++){//TODO: move const from Movie to Proj.H
        salarySum+=((workHours[i][3]-'0')*10+(workHours[i][4]-'0'))-((workHours[i][0]-'0')*10+(workHours[i][1]-'0'));
    }
    return (salarySum*salaryPerHour);
}
Employee ::~Employee() {}