#include <iostream>
#include <fstream>
#ifndef MENU_H
#define MENU_H
using namespace std;

void getCNIC(char CNIC[]);

int strL(char arr[]);

bool LeapCheck(int year);

void getPaymentDate(char billPaidDate[], int DateCheckLast, int MonthCheckLast, int YearCheckLast);

bool EmployeeLogin();

void addEmployeeData();

void editEmployeeData();

void RenewAllTarrifTaxFile();

void EditTarrifTaxFile();

void addCustomerInfoFile();

void addCustomerInfoFile(char CNIC[]);

void addBillingInfo();

//void addCNIC_file();

void addCNIC_file(char CNIC[]);

bool editAllBillingInfo();

void viewBill();

void editCustomerInfoFile();

#endif