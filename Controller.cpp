#include <iostream>
#include <fstream>
#include "Menu.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;


int main()
{
	// max window func
	
	cout << endl << endl << endl << endl << "\t\t\t\t\t" << "Welcome to LESCO";

	Sleep(1000);

	system("cls");

	char choice = '=';


	do {
		cout << "Press 1 for Employee Login" << endl;
		cout << "Press 2 Customer Login" << endl;
		cout << "Press ESC to exit" << endl;
		cout << "Enter a choice : ";

		do {

			if (choice != '=')
			{
				cout << endl << "Enter the correct choice : ";
			}
			choice = _getch();

			cout << choice << endl;

		} while (choice != 49 && choice != 50 && choice != 27);

		system("cls");


		if (choice == 49)
		{
			if (EmployeeLogin())
			{
				system("cls");

				cout << "Login Successful" << endl << endl;

				system("cls");


				do
				{

					choice = 'a';

					do
					{
						if (choice != 'a')
						{
							cout << endl << endl << "Invalid Input";
							Sleep(500);

							system("cls");
						}

						cout << "Press 1 for new Employee ID" << endl;
						cout << "Press 2 to change your password" << endl;
						cout << "Press 3 to Add new Customer Info" << endl;
						cout << "Press 4 to edit an existing Customer's Info" << endl;
						cout << "Press 5 to Add new Bill to existing Customers" << endl;
						cout << "Press 6 to change the payment status of existing Bills" << endl;
						cout << "Press 7 to Re-Enter Tariff Info" << endl;
						cout << "Press 8 to Edit existing values of Tariff Info" << endl;
						cout << "Press 9 to View Latest Bill" << endl;
						cout << "Press ESC to Log Out" << endl;


						choice = _getch();
						cout << choice;

					} while ((choice < 49 || choice > 57) && choice != 27);

					//Sleep(1200);

					system("cls");

					switch (choice)
					{
					case 49:
					{
						addEmployeeData();

						Sleep(1200);

						system("cls");
					}
					break;
					case 50:
					{
						editEmployeeData();
					}
					break;
					case 51:
					{

						char CNICdata[20];

						getCNIC(CNICdata);

						addCNIC_file(CNICdata);


						//Sleep(5000);

						system("cls");

						addCustomerInfoFile(CNICdata);

						Sleep(1000);
					}
					break;
					case 52:
					{
						editCustomerInfoFile();
					}
					break;
					case 53:
					{
						cout << "You have to clear all the previous bills and If all paid then you will be redirected to add new bills" << endl << endl;

						cout << "Redirecting you to the page to edit ";

						for (int i = 3; i > 0; i--)
						{
							cout << i << "  ";

							Sleep(700);
						}

						system("cls");

						do {} while (editAllBillingInfo());

						cout << "Redirecting you to the page to add new Bills ";

						system("cls");

						for (int i = 3; i > 0; i--)
						{
							cout << i << "  ";

							Sleep(700);
						}

						system("cls");

						addBillingInfo();
					}
					break;
					case 54:
					{
						do {
						} while (editAllBillingInfo());
					}
					break;
					case 55:
					{
						RenewAllTarrifTaxFile();
					}
					break;
					case 56:
					{
						EditTarrifTaxFile();
					}
					break;
					case 57:
					{
						viewBill();
					}
					break;

					}

					system("cls");

					//Sleep(200);


				} while (choice != 27);


			}
		}
		else if (choice == 50)
		{
			viewBill();

			system("cls");
		}


	}while (choice != 27);

}