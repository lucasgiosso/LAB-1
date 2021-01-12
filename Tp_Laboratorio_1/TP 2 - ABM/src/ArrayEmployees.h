/*
 * ArrayEmployees.h
 *
 *  Created on: 2 may. 2020
 *      Author: lucasgiosso
 */

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

int initEmployees(eEmployee* list, int len);
int checkEmployees(eEmployee* list, int len);
int printEmployees(eEmployee* list, int len);
int findEmpty(eEmployee* list, int len, int* position);
int addEmployee(eEmployee* list, int len, int id, char* name,char* lastName,float salary,int sector, int position);
int insertEmployee(eEmployee* list, int len, int* idCount);
int menuModififyEmployee();
int modifyEmployee(eEmployee* list,int len);
int removeEmployee(eEmployee* list, int len);
int getEmptyIndexEmployee(eEmployee* list,int limite);
int findEmployeeById(eEmployee* list, int len, int id, int* position);
int sortEmployeesByLastNameSector(eEmployee* list,int len, int order);
int averageSalary(eEmployee* list,int len);
int reportEmployee(eEmployee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */


