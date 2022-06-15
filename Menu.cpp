#include <iostream>

#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

void getCNIC(char CNIC[])
{


	bool flag = 1;

		do
		{
			for (int i = 0; i < 13; i++)
			{
				CNIC[i] = 'a';
			}

			CNIC[13] = '\0';

			cout << "Enter CNIC : ";
			cin.getline(CNIC, 20);
			

			if (CNIC[13] == '\0')
			{
				flag = 1;

				for (int i = 0; i < 13 && flag; i++)
				{
					if (CNIC[i] < 48 || CNIC[i] > 57)
					{
						flag = 0;
					}
					else if (CNIC[i] == '-')
					{
						flag = 0;
					}
				}
			}
			else if(CNIC[13] != '\0')
			{
				flag = 0;
			}


		} while (flag == 0);
}

int strL(char arr[])
{
	int count = 0;
	while (arr[count] != '\0')
	{
		count++;
	}

	return count;
}

bool LeapCheck(int year)
{
	// leap year if perfectly divisible by 400
	if (year % 400 == 0) {
		return 1;
	}
	// not a leap year if divisible by 100
	// but not divisible by 400
	else if (year % 100 == 0) {
		return 0;
	}
	// leap year if not divisible by 100
	// but divisible by 4
	else if (year % 4 == 0) {
		return 1;
	}
	// all other years are not leap years
	else {
		return 0;
	}
}

void getPaymentDate(char billPaidDate[], int DateCheckLast, int MonthCheckLast, int YearCheckLast)
{
	// bill payment date

	int num = 0;
	bool flagTemp = 1;
	bool flagCheck = 1;
	char input[50];
	int temp = 0;
	bool flag = 1;
	int YearCheckCurrent = 0;
	int MonthCheckCurrent = 0;
	int DateCheckCurrent = 0;

	input[0] = 0;


	do
	{
		num = 0;
		flagTemp = 1;

		do
		{
			flagCheck = 1;
			flagTemp = 1;

			for (int k = 0; k < 50; k++)
			{
				input[k] = 'a';
			}

			cout << "Enter Year of Payment : ";

			cin.getline(input, 50);


			//if (input[0] == '\0' || input[1] == '\0' || input[2] == '\0' || input[3] == '\0')
			//{
			//	flagCheck == 0;
			//}

			if (input[4] == '\0')
			{
				for (int k = 0; k < 4; k++)
				{
					if (input[k] < 48 || input[k] > 57)
					{
						flagCheck = 0;
					}
				}
			}
			else
			{
				flagCheck = 0;
			}

		} while (flagCheck == 0);

		num = 0;

		for (int k = 0; k < 4; k++)
		{
			num = (num * 10) + (input[k] - 48);
		}

		if (num < YearCheckLast)
		{
			flagTemp = 0;
			cout << endl << "Enter Year less than Entry Year" << endl;
		}

	} while (flagTemp == 0);

	YearCheckCurrent = num;
	temp = num;
	int countDigit = 0;

	while (temp > 0)
	{
		temp = temp / 10;
		countDigit++;
	}

	if (countDigit != 4)
	{
		do {

			cout << "Enter Year of Payment : ";
			cin >> num;
			temp = num;
			countDigit = 0;

			while (temp > 0)
			{
				temp /= 10;
				countDigit++;
			}

		} while (countDigit != 4);
	}



	bool leapYear = 1;

	if (!LeapCheck(num))
	{
		leapYear = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		billPaidDate[9 - i] = (num % 10) + 48;
		num /= 10;
	}

	// year done


	do {
		num = 0;
		flagTemp = 1;

		do
		{
			flagCheck = 1;
			flagTemp = 1;

			for (int k = 0; k < 50; k++)
			{
				input[k] = 'a';
			}

			cout << "Enter Month of Payment : ";

			cin.getline(input, 50);


			if (input[0] == 'a')
			{
				flagCheck = 0;
			}

			if (input[1] == 'a')
			{
				flagCheck = 0;
			}

			if (input[1] != '\0' && input[2] != '\0')
			{
				flagCheck = 0;
			}

			if (input[1] == '\0')
			{
				if (input[0] < 48 && input[0] > 57)
				{
					flagCheck = 0;
				}
			}

			if (input[2] == '\0')
			{
				if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
				{
					flagCheck = 0;
				}
			}

		} while (flagCheck == 0);

		num = 0;

		for (int k = 0; input[k] != '\0'; k++)
		{
			num = (num * 10) + (input[k] - 48);
		}

		if (YearCheckLast == YearCheckCurrent)
		{
			if (num < MonthCheckLast)
			{
				flagTemp = 0;
				cout << endl << "Enter Month less than Entry Month" << endl;
			}
		}

	} while (!flagTemp);

	flag = 1;

	flagCheck = 1;

	do {
		flag = 1;

		flagCheck = 1;

		if (num < 1 || num > 12)
		{
			flag = 0;
		}

		if (flag == 0)
		{
			flagCheck = 1;

			do {
				num = 0;
				flagTemp = 1;

				do
				{
					flagCheck = 1;
					flagTemp = 1;

					for (int k = 0; k < 50; k++)
					{
						input[k] = 'a';
					}

					cout << "Enter Month of Payment : ";

					cin.getline(input, 50);


					if (input[0] == 'a')
					{
						flagCheck = 0;
					}

					if (input[1] == 'a')
					{
						flagCheck = 0;
					}

					if (input[1] != '\0' && input[2] != '\0')
					{
						flagCheck = 0;
					}

					if (input[1] == '\0')
					{
						if (input[0] < 48 && input[0] > 57)
						{
							flagCheck = 0;
						}
					}

					if (input[2] == '\0')
					{
						if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
						{
							flagCheck = 0;
						}
					}

				} while (flagCheck == 0);

				num = 0;

				for (int k = 0; input[k] != '\0'; k++)
				{
					num = (num * 10) + (input[k] - 48);
				}

				if (YearCheckLast == YearCheckCurrent)
				{
					if (num < MonthCheckLast)
					{
						flagTemp = 0;
						cout << endl << "Enter Month less than Entry Month" << endl;
					}
				}

			} while (!flagTemp);
		}

	} while (flag == 0);

	MonthCheckCurrent = num;
	int laterCheck = num;
	temp = num;

	if (num < 10)
	{
		billPaidDate[3] = '0';
		billPaidDate[4] = (num + 48);
	}
	else
	{
		billPaidDate[4] = (num % 10) + 48;
		num /= 10;
		billPaidDate[3] = num + 48;
	}

	// month done

	num = 0;
	flagTemp = 1;

	do {
		flagTemp = 1;
		flagCheck = 1;

		do
		{
			flagCheck = 1;

			for (int k = 0; k < 50; k++)
			{
				input[k] = 'a';
			}

			cout << "Enter Date of Payment : ";

			cin.getline(input, 50);


			if (input[0] == 'a')
			{
				flagCheck = 0;
			}

			if (input[1] == 'a')
			{
				flagCheck = 0;
			}

			if (input[1] != '\0' && input[2] != '\0')
			{
				flagCheck = 0;
			}

			if (input[1] == '\0')
			{
				if (input[0] < 48 && input[0] > 57)
				{
					flagCheck = 0;
				}
			}

			if (input[2] == '\0')
			{
				if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
				{
					flagCheck = 0;
				}
			}

		} while (flagCheck == 0);

		num = 0;

		for (int k = 0; input[k] != '\0'; k++)
		{
			num = (num * 10) + (input[k] - 48);
		}

		if (YearCheckLast == YearCheckCurrent)
		{
			if (MonthCheckCurrent == MonthCheckLast)
			{
				if (num < DateCheckLast)
				{
					flagTemp = 0;
					cout << endl << "Enter Date less than Entry Date" << endl;
				}
			}
		}

	} while (flagTemp == 0);

	flag = 1;

	if (leapYear && laterCheck == 2)
	{
		do {
			flag = 1;

			if (num < 1 || num > 29)
			{
				flag = 0;
				flagTemp = 1;

				do {
					flagTemp = 1;
					flagCheck = 1;

					do
					{
						flagCheck = 1;

						for (int k = 0; k < 50; k++)
						{
							input[k] = 'a';
						}

						cout << "Enter Date of Payment : ";

						cin.getline(input, 50);


						if (input[0] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] != '\0' && input[2] != '\0')
						{
							flagCheck = 0;
						}

						if (input[1] == '\0')
						{
							if (input[0] < 48 && input[0] > 57)
							{
								flagCheck = 0;
							}
						}

						if (input[2] == '\0')
						{
							if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
							{
								flagCheck = 0;
							}
						}

					} while (flagCheck == 0);

					num = 0;

					for (int k = 0; input[k] != '\0'; k++)
					{
						num = (num * 10) + (input[k] - 48);
					}

					if (YearCheckLast == YearCheckCurrent)
					{
						if (MonthCheckCurrent == MonthCheckLast)
						{
							if (num < DateCheckLast)
							{
								flagTemp = 0;
								cout << endl << "Enter Date less than Entry Date" << endl;
							}
						}
					}

				} while (flagTemp == 0);
			}
		} while (flag == 0);
	}
	else if (!leapYear && laterCheck == 2)
	{
		do {
			flag = 1;

			if (num < 1 || num > 28)
			{
				flag = 0;
				flagTemp = 1;

				do {
					flagTemp = 1;
					flagCheck = 1;

					do
					{
						flagCheck = 1;

						for (int k = 0; k < 50; k++)
						{
							input[k] = 'a';
						}

						cout << "Enter Date of Payment : ";

						cin.getline(input, 50);


						if (input[0] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] != '\0' && input[2] != '\0')
						{
							flagCheck = 0;
						}

						if (input[1] == '\0')
						{
							if (input[0] < 48 && input[0] > 57)
							{
								flagCheck = 0;
							}
						}

						if (input[2] == '\0')
						{
							if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
							{
								flagCheck = 0;
							}
						}

					} while (flagCheck == 0);

					num = 0;

					for (int k = 0; input[k] != '\0'; k++)
					{
						num = (num * 10) + (input[k] - 48);
					}

					if (YearCheckLast == YearCheckCurrent)
					{
						if (MonthCheckCurrent == MonthCheckLast)
						{
							if (num < DateCheckLast)
							{
								flagTemp = 0;
								cout << endl << "Enter Date less than Entry Date" << endl;
							}
						}
					}

				} while (flagTemp == 0);
			}
		} while (flag == 0);
	}
	else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
	{
		do {
			flag = 1;

			if (num < 1 || num > 30)
			{
				flag = 0;
				flagTemp = 1;

				do {
					flagTemp = 1;
					flagCheck = 1;

					do
					{
						flagCheck = 1;

						for (int k = 0; k < 50; k++)
						{
							input[k] = 'a';
						}

						cout << "Enter Date of Payment : ";

						cin.getline(input, 50);


						if (input[0] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] != '\0' && input[2] != '\0')
						{
							flagCheck = 0;
						}

						if (input[1] == '\0')
						{
							if (input[0] < 48 && input[0] > 57)
							{
								flagCheck = 0;
							}
						}

						if (input[2] == '\0')
						{
							if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
							{
								flagCheck = 0;
							}
						}

					} while (flagCheck == 0);

					num = 0;

					for (int k = 0; input[k] != '\0'; k++)
					{
						num = (num * 10) + (input[k] - 48);
					}

					if (YearCheckLast == YearCheckCurrent)
					{
						if (MonthCheckCurrent == MonthCheckLast)
						{
							if (num < DateCheckLast)
							{
								flagTemp = 0;
								cout << endl << "Enter Date less than Entry Date" << endl;
							}
						}
					}

				} while (flagTemp == 0);
			}
		} while (flag == 0);
	}
	else
	{
		do
		{
			flag = 1;

			if (num < 0 || num > 31)
			{
				flag = 0;
				flagTemp = 1;

				do {
					flagTemp = 1;
					flagCheck = 1;

					do
					{
						flagCheck = 1;

						for (int k = 0; k < 50; k++)
						{
							input[k] = 'a';
						}

						cout << "Enter Date of Payment : ";

						cin.getline(input, 50);


						if (input[0] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] == 'a')
						{
							flagCheck = 0;
						}

						if (input[1] != '\0' && input[2] != '\0')
						{
							flagCheck = 0;
						}

						if (input[1] == '\0')
						{
							if (input[0] < 48 && input[0] > 57)
							{
								flagCheck = 0;
							}
						}

						if (input[2] == '\0')
						{
							if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
							{
								flagCheck = 0;
							}
						}

					} while (flagCheck == 0);

					num = 0;

					for (int k = 0; input[k] != '\0'; k++)
					{
						num = (num * 10) + (input[k] - 48);
					}

					if (YearCheckLast == YearCheckCurrent)
					{
						if (MonthCheckCurrent == MonthCheckLast)
						{
							if (num < DateCheckLast)
							{
								flagTemp = 0;
								cout << endl << "Enter Date less than Entry Date" << endl;
							}
						}
					}

				} while (flagTemp == 0);
			}

		} while (flag == 0);

		// date done

		// date month year done with exception handling
	}

	if (num < 10)
	{
		billPaidDate[0] = '0';
		billPaidDate[1] = (num + 48);
	}
	else
	{
		billPaidDate[1] = (num % 10) + 48;
		num /= 10;
		billPaidDate[0] = (num + 48);
	}

	billPaidDate[2] = billPaidDate[5] = '/';

	billPaidDate[10] = '\0';
}

bool EmployeeLogin()
{
	fstream fout;
	char Username[20];
	char password[20];
	char userNameByUser[20];
	char passwordByUser[20];
	char reEnterCheck = 0;
	bool flagStopCheck = 1;

	do {
		cout << "Enter Username : ";
		cin.getline(userNameByUser, 20);
		

		cout << "Enter password : ";
		cin.getline(passwordByUser, 20);
		

		fout.open("EmployeesData.txt", ios::in);

		int count = 0;
		int countText = 0;
		char ch = 'a';
		int countRow = 0;
		flagStopCheck = 1;

		while (!fout.eof() && flagStopCheck)
		{

			fout >> ch;

			if (ch == ',')
			{
				Username[countText] = '\0';
				count++;
				countText = 0;

			}

			if (ch != '^')
			{
				if (ch != ',')
				{
					if (count == 0)
					{
						Username[countText++] = ch;
					}
					else if (count == 1)
					{
						password[countText++] = ch;
					}
				}
			}
			else
			{
				countRow++;

				if (!fout.eof())
				{
					password[countText] = '\0';

					bool flag = 1;

					if (strL(Username) != strL(userNameByUser))
					{
						flag = 0;
					}

					for (int i = 0; Username[i] != '\0' && userNameByUser[i] != '\0' && flag; i++)
					{
						if (Username[i] != userNameByUser[i])
						{
							flag = 0;
						}
					}

					if (flag)
					{
						for (int i = 0; password[i] != '\0' && passwordByUser[i] != '\0' && flag; i++)
						{
							if (password[i] != passwordByUser[i])
							{
								flag = 0;
							}
						}
					}

					if (flag)
					{
						flagStopCheck = 0;
					}

					count = 0;
					countText = 0;
				}
			}
		}

		fout.close();

		if (flagStopCheck == 1)
		{
			cout << endl << "Invalid Credentials" << endl;

			cout << endl << "Press ESC to exit or Press any Key to continue" << endl;

			reEnterCheck = _getch();

			cout << endl << endl;
			
		}
	}while (reEnterCheck != 27 && flagStopCheck);

	if (flagStopCheck == 0)
	{
		return true;
	}

	return false;
}

void addEmployeeData()
{
	fstream fout;

	char Username[20]; //must include first name,last name
	char password[20]; //can include anytype of symbols,letters or words both upper and lower case.

	char userNameByUser[20];
	char passwordByUser[20];
	char chh = 'a';

	bool flagStopCheck = 1;

	do {
		cout << "Enter Username : ";
		cin.getline(userNameByUser, 20);


		cout << "Enter password : ";
		cin.getline(passwordByUser, 20);


		fout.open("EmployeesData.txt", ios::in);

		int count = 0;
		int countText = 0;
		char ch = 'a';
		int countRow = 0;

		while (!fout.eof() && flagStopCheck)
		{

			fout >> ch;

			if (ch == ',')
			{
				Username[countText] = '\0';
				count++;
				countText = 0;

			}

			if (ch != '^')
			{
				if (ch != ',')
				{
					if (count == 0)
					{
						Username[countText++] = ch;
					}
					else if (count == 1)
					{
						password[countText++] = ch;
					}
				}
			}
			else
			{
				countRow++;

				if (!fout.eof())
				{
					password[countText] = '\0';

					bool flag = 1;

					if (strL(Username) != strL(userNameByUser))
					{
						flag = 0;
					}

					for (int i = 0; Username[i] != '\0' && userNameByUser[i] != '\0' && flag; i++)
					{
						if (Username[i] != userNameByUser[i])
						{
							flag = 0;
						}
					}

					if (flag)
					{
						flagStopCheck = 0;
					}

					count = 0;
					countText = 0;
				}
			}
		}

		fout.close();

		if (!flagStopCheck)
		{
			cout << endl << "UserName already exists" << endl;

			cout << endl << "Press any key to re-Enter Employee data  -OR-  ESC to exit" << endl << endl;

			chh = _getch();
		}

		if (ch == 27)
		{
			flagStopCheck = 1;
		}

	} while (flagStopCheck == 0 && chh != 27);

	if (!flagStopCheck)
	{
		cout << endl << "UserName already exists" << endl;
	}
	else
	{
		fout.open("EmployeesData.txt", ios::app);

		fout << userNameByUser << "," << passwordByUser << "^" << endl;

		cout << endl << endl << "User Name successfully registered" << endl;
	}

}

void editEmployeeData()
{
	fstream fout;

	char Username[20]; //must include first name,last name
	char password[20]; //can include anytype of symbols,letters or words both upper and lower case.

	char userNameByUser[20];
	char passwordByUser[20];

	cout << "Enter Username : ";
	cin.getline(userNameByUser, 20);
	

	cout << "Enter password : ";
	cin.getline(passwordByUser, 20);
	

	fout.open("EmployeesData.txt", ios::in);

	int count = 0;
	int countText = 0;
	char ch = 'a';
	int countRow = 0;
	bool flagStopCheck = 1;

	while (!fout.eof() && flagStopCheck)
	{

		fout >> ch;

		if (ch == ',')
		{
			Username[countText] = '\0';
			count++;
			countText = 0;

		}

		if (ch != '^')
		{
			if (ch != ',')
			{
				if (count == 0)
				{
					Username[countText++] = ch;
				}
				else if (count == 1)
				{
					password[countText++] = ch;
				}
			}
		}
		else
		{
			countRow++;

			if (!fout.eof())
			{
				password[countText] = '\0';

				bool flag = 1;

				if (strL(Username) != strL(userNameByUser))
				{
					flag = 0;
				}

				for (int i = 0; Username[i] != '\0' && userNameByUser[i] != '\0' && flag; i++)
				{
					if (Username[i] != userNameByUser[i])
					{
						flag = 0;
					}
				}

				if (flag)
				{
					for (int i = 0; password[i] != '\0' && passwordByUser[i] != '\0' && flag; i++)
					{
						if (password[i] != passwordByUser[i])
						{
							flag = 0;
						}
					}
				}

				if (flag)
				{
					flagStopCheck = 0;
				}

				count = 0;
				countText = 0;
			}
		}
	}

	fout.close();

	if (!flagStopCheck)
	{
		cout << endl << endl << "User has been verified successfully" << endl << endl;

		char changedPassword[20];

		cout << "Enter the new password : ";
		cin.getline(changedPassword, 20);
		

		char rowFile[30];
		fstream file1;
		fstream file2;

		file1.open("EmployeesData.txt", ios::in);

		file2.open("temp.txt", ios::out);

		countText = 0;
		int countSymbol = 0;
		bool flag = 1;

		while (!file1.eof())
		{

			if (countSymbol == countRow - 1)
			{
				file1 >> ch;

				if (flag)
				{
					rowFile[countText++] = ch;
				}

				if (ch == ',')
				{
					flag = 0;

					for (int i = 0; changedPassword[i] != '\0'; i++)
					{
						rowFile[countText++] = changedPassword[i];
					}
					rowFile[countText++] = '^';
				}

			}
			else
			{
				file1 >> ch;

				rowFile[countText++] = ch;
			}

			if (ch == '^')
			{
				countSymbol++;

				rowFile[countText] = '\0';

				if (rowFile[0] != '^')
				{
					file2 << rowFile << endl;
				}

				countText = 0;
			}
		}

		file1.close();
		file2.close();

		file1.open("temp.txt", ios::in);
		file2.open("EmployeesData.txt", ios::out);

		countText = 0;

		while (!file1.eof())
		{
			file1 >> ch;

			rowFile[countText++] = ch;

			if (ch == '^')
			{
				rowFile[countText] = '\0';

				if (rowFile[0] != '^')
				{
					file2 << rowFile << endl;
				}

				countText = 0;
			}
		}

		cout << endl << "Password changed Successfully" << endl << endl;
	}
	else
	{
		cout << "Invalid Credentials" << endl;
	}
}

void RenewAllTarrifTaxFile()
{
	fstream fout;
	fout.open("TariffTaxInfo.txt", ios::out);
	char data[10];

	for (int i = 0; i < 4; i++)
	{
		if (i == 0 || i == 1)
		{
			fout << "1Phase" << ",";

			if (i == 0)
			{
				cout << endl << "Enter Info for 1 Phase Domestic" << endl << endl;
			}
			else if (i == 1)
			{
				cout << endl << "Enter Info for 1 Phase Commercial" << endl << endl;
			}
		}
		else
		{
			fout << "3Phase" << ",";

			if (i == 2)
			{
				cout << endl << "Enter Info for 3 Phase Domestic" << endl << endl;
			}
			else if (i == 3)
			{
				cout << endl << "Enter Info for 3 Phase Commercial" << endl << endl;
			}
		}

		cout << "Enter Normal Units Price : ";
		cin.getline(data, 10);
		
		bool flag = 1;

		do {
			flag = 1;
			if (data[0] == '\0')
			{
				flag = 0;
			}
			for (int j = 0; data[j] != '\0' && flag; j++)
			{
				if (data[j] < 48 || data[j] > 57)
				{
					flag = 0;
				}
			}
			if (flag == 0)
			{
				cout << "Enter Normal Units Price : ";
				cin.getline(data, 10);
				
			}

		} while (flag == 0);


		fout << data << ",";

		if (i == 2 || i == 3)
		{
			cout << "Enter Peak Hour Units Price : ";					// Peak Hour
			cin.getline(data, 10);
			
			flag = 1;

			do {
				flag = 1;
				if (data[0] == '\0')
				{
					flag = 0;
				}
				for (int j = 0; data[j] != '\0' && flag; j++)
				{
					if (data[j] < 48 || data[j] > 57)
					{
						flag = 0;
					}
				}
				if (flag == 0)
				{
					cout << "Enter Peak Hour Units Price : ";
					cin.getline(data, 10);
					
				}

			} while (flag == 0);

			fout << data << ",";

		}
		else
		{
			fout << ",";
		}

		cout << "Enter Percentage of tax : ";					//  Percentage of tax
		cin.getline(data, 10);
		
		flag = 1;

		do {
			flag = 1;
			if (data[0] == '\0')
			{
				flag = 0;
			}
			for (int j = 0; data[j] != '\0' && flag; j++)
			{
				if (data[j] < 48 || data[j] > 57)
				{
					flag = 0;
				}
			}
			if (flag == 0)
			{
				cout << "Enter Percentage of tax : ";
				cin.getline(data, 10);
				
			}

		} while (flag == 0);

		fout << data << ",";



		cout << "Enter Fixed Charges : ";					//  Fixed Charges
		cin.getline(data, 10);
		
		flag = 1;

		do {
			flag = 1;
			if (data[0] == '\0')
			{
				flag = 0;
			}
			for (int j = 0; data[j] != '\0' && flag; j++)
			{
				if (data[j] < 48 || data[j] > 57)
				{
					flag = 0;
				}
			}
			if (flag == 0)
			{
				cout << "Enter Fixed Charges : ";
				cin.getline(data, 10);
				
			}

		} while (flag == 0);

		fout << data << "^" << endl;

	}

	fout.close();
}

void EditTarrifTaxFile()
{
	fstream file1;
	fstream file2;
	int phaseType = 0;
	int choiceSelect = 0;
	int ConnectionType = 0;
	bool flag = 1;
	int calculatedRow = 0;
	char ch = 'a';
	int countText = 0;

	file1.open("TariffTaxInfo.txt", ios::in);
	file2.open("TariffTemp.txt", ios::out);

	do {

		cout << endl << endl;
		cout << "Enter Phase type you want to edit : ";

		cin >> phaseType;

	} while (phaseType != 1 && phaseType != 3);

	do {

		cout << endl << endl;
		cout << "1. Domestic Customer" << endl;
		cout << "2. Commercial Customer" << endl;

		cout << endl << "Enter a choice from above : ";
		cin >> ConnectionType;

	} while (ConnectionType < 1 || ConnectionType > 2);

	if (phaseType == 1 && ConnectionType == 1)
	{
		calculatedRow = 1;
	}
	else if (phaseType == 1 && ConnectionType == 2)
	{
		calculatedRow = 2;
	}
	else if (phaseType == 3 && ConnectionType == 1)
	{
		calculatedRow = 3;
	}
	else if (phaseType == 3 && ConnectionType == 2)
	{
		calculatedRow = 4;
	}

	do {

		cout << endl << endl;
		cout << "1. Normal Units" << endl;
		cout << "2. Peak Hour Units" << endl;
		cout << "3. Tax Percentage" << endl;
		cout << "4. Fixed Charges" << endl;

		cout << endl << "Enter a choice from above : ";
		cin >> choiceSelect;

		if (phaseType == 1)
		{
			if (choiceSelect == 2)
			{
				cout << endl << endl << "1 phase Meter do not have Peak Hour Units" << endl;

				choiceSelect = -1;
			}
		}


	} while (choiceSelect < 1 || choiceSelect > 4);

	char data[10];


	cout << endl << "Enter changed Value : ";
	cin.getline(data, 10);
	

	flag = 1;

	do {
		flag = 1;

		if (data[0] == '\0')
		{
			flag = 0;
		}

		for (int i = 0; data[i] != '\0' && flag; i++)
		{
			if (data[i] < 48 || data[i] > 57)
			{
				flag = 0;
			}
		}

		if (!flag)
		{
			cout << endl << "Enter changed Value : ";
			cin.getline(data, 10);
			
		}

	} while (flag == 0);

	char readingData[2000];
	ch = 'a';
	int commaCount = 0;
	int rowCount = 0;
	countText = 0;
	bool flagShit = 1;

	while (!file1.eof())
	{
		file1 >> ch;

		readingData[countText++] = ch;

	}

	readingData[countText] = '\0';

	for (int i = 0; readingData[i] != '\0'; i++)
	{
		if (rowCount != 4)
		{
			if (rowCount == calculatedRow - 1)
			{
				if (commaCount == choiceSelect)
				{
					if (flagShit)
					{
						file2 << data;
						flagShit = 0;
						commaCount++;
					}

				}
				else
				{
					if (flagShit == 0)
					{
						if (readingData[i] == ',' || readingData[i] == '^')
						{
							flagShit = 1;
							file2 << readingData[i];
						}
					}
					else
					{
						file2 << readingData[i];
					}
				}
			}
			else
			{
				file2 << readingData[i];
			}

			if (readingData[i] == '^')
			{

				rowCount++;
				commaCount = 0;

				file2 << endl;
			}

			if (readingData[i] == ',')
			{

				commaCount++;
			}
		}


	}

	file1.close();
	file2.close();

	file1.open("TariffTemp.txt", ios::in);
	file2.open("TariffTaxInfo.txt", ios::out);


	while (!file1.eof())
	{
		file1 >> ch;

		if (ch != '\0')
			file2 << ch;

		if (ch == '^')
		{
			file2 << endl;
		}
	}

}

void addCustomerInfoFile()
{
	fstream fout;

	fout.open("CustomersInfo.txt", ios::in);

	char dummy = 'a';
	int count = 0;
	char customerType = 0;

	while (!fout.eof())
	{
		fout >> dummy;

		if (dummy == '^')
		{
			count++;
		}
	}

	//count = count--;

	if (count == 0)
	{
		count = 1;
	}

	fout.close();


	fout.open("CustomersInfo.txt", ios::app);

	char id[5];

	for (int i = 0; i < 4; i++)
	{
		id[i] = '0';
	}

	id[4] = '\0';

	int countDigit = 0;
	int temp = count;

	while (temp > 0)
	{
		temp = temp / 10;
		countDigit++;
	}

	for (int i = 0; i < countDigit; i++)
	{
		id[3 - i] = (count % 10) + 48;
		count = (count / 10);
	}

	cout << endl << "Enter Information of Customer ID " << id << endl << endl;


	// CNIC Input

	char CNIC[20]; // no dashes

	for (int i = 0; i < 13; i++)
	{
		CNIC[i] = 'a';
	}

	CNIC[13] = '\0';

	cout << "Enter CNIC : ";
	cin.getline(CNIC, 20);
	

	CNIC[13] = '\0';

	bool flag = 1;

	do
	{
		flag = 1;

		for (int i = 0; i < 13 && flag; i++)
		{
			if (CNIC[i] < 48 || CNIC[i] > 57)
			{
				flag = 0;
			}
			else if (CNIC[i] == '-')
			{
				flag = 0;
			}
		}

		if (flag == 0)
		{
			for (int i = 0; i < 20; i++)
			{
				CNIC[i] = 'a';
			}

			cout << "Enter CNIC : ";
			cin.getline(CNIC, 20);
			

			if (CNIC[13] >= 48 && CNIC[13] <= 57)
			{
				flag = 0;
			}

			CNIC[13] = '\0';
		}

	} while (flag == 0);

	fstream checkCNIC;
	char checkCNICFromFile[300];
	bool checkCNICflag = 1;
	flag = 1;
	char chh = 'a';
	bool flagStopLine = 1;
	int countCNIC = 0;
	int checkCNICflagCount = 0;

	checkCNIC.open("CustomersInfo.txt", ios::in);

	while (!checkCNIC.eof())
	{
		checkCNICflagCount = 0;
		flagStopLine = 1;

		for (int i = 0; flagStopLine && !checkCNIC.eof(); i++)
		{
			checkCNIC >> chh;

			checkCNICFromFile[i] = chh;

			if (chh == '^')
			{
				flagStopLine = 0;
			}
		}


		if (checkCNICFromFile[0] != '^' && !checkCNIC.eof())
		{
			checkCNICflag = 1;

			for (int i = 5; i < 18 && checkCNICflagCount == 0; i++)
			{
				if (checkCNICFromFile[i] != CNIC[i - 5])
				{
					checkCNICflagCount++;
				}
			}

			if (checkCNICflagCount == 0)
			{
				countCNIC++;
			}
		}
	}

	checkCNIC.close();

	// CNIC Input end

	if (countCNIC < 3)
	{

		// Name Input

		char name[50]; // no numbers

		cout << "Enter Name : ";
		cin.getline(name, 50);
		

		for (int i = 0; name[i] != '\0'; i++)
		{
			if (name[i] == 32)
			{
				name[i] = '?';
			}
		}

		cout << endl;

		// Name input end

		// Address Input

		char address[100];	// no comma in address // if(address[i] == ',') { cout << "no comma to be used" })

		cout << "Enter Address : ";
		cin.getline(address, 100);
		
		cout << endl;

		//flag = 1;

		for (int i = 0; address[i] != '\0'; i++)
		{
			if (address[i] == ',')
			{
				address[i] = '%';
			}

			if (address[i] == 32)
			{
				address[i] = '?';
			}
		}


		// Adreess input end

		// number Input

		char number[15]; // no alphabets letter

		cout << "Enter Contact Number : ";
		cin.getline(number, 15);
		

		flag = 1;

		do {
			flag = 1;

			for (int i = 0; number[i] != '\0' && flag; i++)
			{
				if (i == 0)
				{
					if (number[i] < 48 || number[i] > 57)
					{
						flag = 0;
					}

					if (number[i] == '+')
					{
						flag = 1;
					}
				}
				else
				{
					if (number[i] < 48 || number[i] > 57)
					{
						flag = 0;
					}
				}
			}

			if (flag == 0)
			{
				cout << "Enter Contact Number : ";
				cin.getline(number, 15);
				
			}

		} while (flag == 0);

		//number input end

		// meter input

		cout << endl;

		char metertype = 1; // 3 // check if 1 or 3

		cout << "Enter Meter Type : ";
		cin >> metertype;

		flag = 1;

		do {

			flag = 1;

			if (metertype != (48 + 3) && metertype != (48 + 1))
			{
				flag = 0;
			}

			if (flag == 0)
			{
				cout << "Enter Meter Type : ";
				cin >> metertype;
			}

		} while (flag == 0);

		cout << endl;

		// metertype input end

		//  Connection date input

		char connectionDate[11];

		connectionDate[2] = connectionDate[5] = '/';
		connectionDate[10] = '\0';

		int num = 0;

		cout << "Enter Year of Connection : ";
		cin >> num;
		temp = num;
		countDigit = 0;

		while (temp > 0)
		{
			temp = temp / 10;
			countDigit++;
		}

		if (countDigit != 4)
		{
			do {

				cout << endl;
				cout << "Enter Year of Connection : ";
				cin >> num;
				temp = num;
				countDigit = 0;

				while (temp > 0)
				{
					temp /= 10;
					countDigit++;
				}

			} while (countDigit != 4);
		}


		bool leapYear = 1;

		if (!LeapCheck(num))
		{
			leapYear = 0;
		}

		for (int i = 0; i < 4; i++)
		{
			connectionDate[9 - i] = (num % 10) + 48;
			num /= 10;
		}

		// year done

		num = 0;

		cout << endl;

		cout << "Enter Month of Connection : ";
		cin >> num;

		flag = 1;

		do {
			flag = 1;

			if (num < 1 || num > 12)
			{
				flag = 0;
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Enter Month of Connection : ";
				cin >> num;
			}
		} while (flag == 0);

		int laterCheck = num;
		temp = num;

		if (num < 10)
		{
			connectionDate[3] = '0';
			connectionDate[4] = (num + 48);
		}
		else
		{
			connectionDate[4] = (num % 10) + 48;
			num /= 10;
			connectionDate[3] = num + 48;
		}

		// month done

		num = 0;

		cout << endl;

		cout << "Enter Date of Connection : ";
		cin >> num;

		flag = 1;

		if (leapYear && laterCheck == 2)
		{
			do {
				flag = 1;

				if (num < 1 || num > 29)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else if (!leapYear && laterCheck == 2)
		{
			do {
				flag = 1;

				if (num < 1 || num > 28)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
		{
			do {
				flag = 1;

				if (num < 1 || num > 30)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else
		{
			do
			{
				flag = 1;

				if (num < 0 || num > 31)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}

			} while (flag == 0);
		}

		if (num < 10)
		{
			connectionDate[0] = '0';
			connectionDate[1] = (num + 48);
		}
		else
		{
			connectionDate[1] = (num % 10) + 48;
			num /= 10;
			connectionDate[0] = (num + 48);
		}

		// date done

		// date month year done with exception handling

		//// normal units consumed INPUT

		//char normalUnits[10];

		//num = 0;

		//cout << "Enter Regular Units Consumed : ";
		//cin >> num;

		//flag = 1;

		//if (num < 0)
		//{
		//	do
		//	{
		//		flag = 1;

		//		if (num < 0)
		//		{
		//			cout << "Enter Regular Units Consumed : ";
		//			cin >> num;

		//			flag = 0;
		//		}
		//	} while (flag == 0);
		//}

		//temp = num;
		//countDigit = 0;

		//while (temp > 0)
		//{
		//	temp /= 10;
		//	countDigit++;
		//}

		//for (int i = 0; i < countDigit; i++)
		//{
		//	normalUnits[countDigit - i - 1] = (num % 10) + 48;
		//	num = num / 10;
		//}
		//normalUnits[countDigit] = '\0';


		//// normal units consumed INPUT done

		//// Peak Hour Units Consumed INPUT

		//char peakUnits[10];


		//if (metertype - 48 == 3)
		//{
		//	num = 0;

		//	cout << "Enter Peak Hour Units Consumed : ";
		//	cin >> num;

		//	flag = 1;

		//	if (num < 0)
		//	{
		//		do
		//		{
		//			flag = 1;

		//			if (num < 0)
		//			{
		//				cout << "Enter Peak Hour Units Consumed : ";
		//				cin >> num;

		//				flag = 0;
		//			}
		//		} while (flag == 0);
		//	}

		//	temp = num;
		//	countDigit = 0;

		//	while (temp > 0)
		//	{
		//		temp /= 10;
		//		countDigit++;
		//	}

		//	for (int i = 0; i < countDigit; i++)
		//	{
		//		peakUnits[countDigit - i - 1] = (num % 10) + 48;
		//		num = num / 10;
		//	}
		//	peakUnits[countDigit] = '\0';
		//}
		//else
		//{
		//	peakUnits[0] = '0';
		//	peakUnits[1] = '\0';
		//}

		cout << endl << "The Regular Units and Peak Units have been set to 0 for new meters" << endl << endl;

		// customer type

		do {
			cout << "Press 1 for Domestic Customer" << endl;
			cout << "Press 2 for Commercial Customer" << endl;
			cout << "Enter from above : ";
			customerType = _getch();
			cout << customerType - 48;
		} while (customerType < 49 || customerType > 50);




		fout << id << "," << CNIC << "," << name << "," << address << "," << number << "," << metertype << "," << connectionDate << "," << "0" << "," << "0" << "," << customerType << '^' << endl;

		fout.close();

		//UserName,Password^
	}
	else
	{
		cout << endl << endl << "Exiting here. Given CNIC has been used 3 times!!!" << endl << endl;
	}



}

void addCustomerInfoFile(char CNIC[])
{
	fstream fout;

	fout.open("CustomersInfo.txt", ios::in);

	char dummy = 'a';
	int count = 0;
	char customerType = 0;

	while (!fout.eof())
	{
		fout >> dummy;

		if (dummy == '^')
		{
			count++;
		}
	}

	//count = count--;

	if (count == 0)
	{
		count = 1;
	}

	fout.close();


	fout.open("CustomersInfo.txt", ios::app);

	char id[5];

	for (int i = 0; i < 4; i++)
	{
		id[i] = '0';
	}

	id[4] = '\0';

	int countDigit = 0;
	int temp = count;

	while (temp > 0)
	{
		temp = temp / 10;
		countDigit++;
	}

	for (int i = 0; i < countDigit; i++)
	{
		id[3 - i] = (count % 10) + 48;
		count = (count / 10);
	}

	cout << endl << "Enter Information of Customer ID " << id << endl << endl;

	bool flag = 1;
	 
	 
	// CNIC Input

	//char CNIC[20]; // no dashes

	//for (int i = 0; i < 13; i++)
	//{
	//	CNIC[i] = 'a';
	//}

	//CNIC[13] = '\0';

	//cout << "Enter CNIC : ";
	//cin.getline(CNIC, 20);
	//

	//CNIC[13] = '\0';


	//do
	//{
	//	flag = 1;

	//	for (int i = 0; i < 13 && flag; i++)
	//	{
	//		if (CNIC[i] < 48 || CNIC[i] > 57)
	//		{
	//			flag = 0;
	//		}
	//		else if (CNIC[i] == '-')
	//		{
	//			flag = 0;
	//		}
	//	}

	//	if (flag == 0)
	//	{
	//		for (int i = 0; i < 20; i++)
	//		{
	//			CNIC[i] = 'a';
	//		}

	//		cout << "Enter CNIC : ";
	//		cin.getline(CNIC, 20);
	//		

	//		if (CNIC[13] >= 48 && CNIC[13] <= 57)
	//		{
	//			flag = 0;
	//		}

	//		CNIC[13] = '\0';
	//	}

	//} while (flag == 0);

	fstream checkCNIC;
	char checkCNICFromFile[300];
	bool checkCNICflag = 1;
	flag = 1;
	char chh = 'a';
	bool flagStopLine = 1;
	int countCNIC = 0;
	int checkCNICflagCount = 0;

	checkCNIC.open("CustomersInfo.txt", ios::in);

	while (!checkCNIC.eof())
	{
		checkCNICflagCount = 0;
		flagStopLine = 1;

		for (int i = 0; flagStopLine && !checkCNIC.eof(); i++)
		{
			checkCNIC >> chh;

			checkCNICFromFile[i] = chh;

			if (chh == '^')
			{
				flagStopLine = 0;
			}
		}


		if (checkCNICFromFile[0] != '^' && !checkCNIC.eof())
		{
			checkCNICflag = 1;

			for (int i = 5; i < 18 && checkCNICflagCount == 0; i++)
			{
				if (checkCNICFromFile[i] != CNIC[i - 5])
				{
					checkCNICflagCount++;
				}
			}

			if (checkCNICflagCount == 0)
			{
				countCNIC++;
			}
		}
	}

	checkCNIC.close();

	// CNIC Input end

	if (countCNIC < 3)
	{

		cout << "CNIC : " << CNIC << endl << endl;

		// Name Input

		char name[50]; // no numbers

		cout << "Enter Name : ";
		cin.ignore();
		cin.getline(name, 50);
		

		for (int i = 0; name[i] != '\0'; i++)
		{
			if (name[i] == 32)
			{
				name[i] = '?';
			}
		}

		cout << endl;

		// Name input end

		// Address Input

		char address[100];	// no comma in address // if(address[i] == ',') { cout << "no comma to be used" })

		cout << "Enter Address : ";
		cin.getline(address, 100);
		

		//flag = 1;

		for (int i = 0; address[i] != '\0'; i++)
		{
			if (address[i] == ',')
			{
				address[i] = '%';
			}

			if (address[i] == 32)
			{
				address[i] = '?';
			}
		}


		// Adreess input end

		// number Input

		cout << endl;

		char number[15]; // no alphabets letter

		cout << "Enter Contact Number : ";
		cin.getline(number, 15);
		

		flag = 1;

		do {
			flag = 1;

			for (int i = 0; number[i] != '\0' && flag; i++)
			{
				if (i == 0)
				{
					if (number[i] < 48 || number[i] > 57)
					{
						flag = 0;
					}

					if (number[i] == '+')
					{
						flag = 1;
					}
				}
				else
				{
					if (number[i] < 48 || number[i] > 57)
					{
						flag = 0;
					}
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Enter Contact Number : ";
				cin.getline(number, 15);
				
			}

		} while (flag == 0);

		//number input end

		// meter input

		char metertype = 1; // 3 // check if 1 or 3


		cout << endl;
		cout << "Enter Meter Type : ";
		cin >> metertype;

		flag = 1;

		do {

			flag = 1;

			if (metertype != (48 + 3) && metertype != (48 + 1))
			{
				flag = 0;
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Enter Meter Type : ";
				cin >> metertype;
			}

		} while (flag == 0);

		// metertype input end

		//  Connection date input

		char connectionDate[11];

		connectionDate[2] = connectionDate[5] = '/';
		connectionDate[10] = '\0';

		int num = 0;

		cout << endl;
		cout << "Enter Year of Connection : ";
		cin >> num;
		temp = num;
		countDigit = 0;

		while (temp > 0)
		{
			temp = temp / 10;
			countDigit++;
		}

		if (countDigit != 4)
		{
			do {
				cout << endl;
				cout << "Enter Year of Connection : ";
				cin >> num;
				temp = num;
				countDigit = 0;

				while (temp > 0)
				{
					temp /= 10;
					countDigit++;
				}

			} while (countDigit != 4);
		}


		bool leapYear = 1;

		if (!LeapCheck(num))
		{
			leapYear = 0;
		}

		for (int i = 0; i < 4; i++)
		{
			connectionDate[9 - i] = (num % 10) + 48;
			num /= 10;
		}

		// year done

		num = 0;
		cout << endl;
		cout << "Enter Month of Connection : ";
		cin >> num;

		flag = 1;

		do {
			flag = 1;

			if (num < 1 || num > 12)
			{
				flag = 0;
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Enter Month of Connection : ";
				cin >> num;
			}
		} while (flag == 0);

		int laterCheck = num;
		temp = num;

		if (num < 10)
		{
			connectionDate[3] = '0';
			connectionDate[4] = (num + 48);
		}
		else
		{
			connectionDate[4] = (num % 10) + 48;
			num /= 10;
			connectionDate[3] = num + 48;
		}

		// month done

		num = 0;

		cout << endl;
		cout << "Enter Date of Connection : ";
		cin >> num;

		flag = 1;

		if (leapYear && laterCheck == 2)
		{
			do {
				flag = 1;

				if (num < 1 || num > 29)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else if (!leapYear && laterCheck == 2)
		{
			do {
				flag = 1;

				if (num < 1 || num > 28)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
		{
			do {
				flag = 1;

				if (num < 1 || num > 30)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else
		{
			do
			{
				flag = 1;

				if (num < 0 || num > 31)
				{
					flag = 0;
					cout << endl;
					cout << "Enter Date of Connection : ";
					cin >> num;
				}

			} while (flag == 0);
		}

		if (num < 10)
		{
			connectionDate[0] = '0';
			connectionDate[1] = (num + 48);
		}
		else
		{
			connectionDate[1] = (num % 10) + 48;
			num /= 10;
			connectionDate[0] = (num + 48);
		}

		// date done

		// date month year done with exception handling

		//// normal units consumed INPUT

		//char normalUnits[10];

		//num = 0;

		//cout << "Enter Regular Units Consumed : ";
		//cin >> num;

		//flag = 1;

		//if (num < 0)
		//{
		//	do
		//	{
		//		flag = 1;

		//		if (num < 0)
		//		{
		//			cout << "Enter Regular Units Consumed : ";
		//			cin >> num;

		//			flag = 0;
		//		}
		//	} while (flag == 0);
		//}

		//temp = num;
		//countDigit = 0;

		//while (temp > 0)
		//{
		//	temp /= 10;
		//	countDigit++;
		//}

		//for (int i = 0; i < countDigit; i++)
		//{
		//	normalUnits[countDigit - i - 1] = (num % 10) + 48;
		//	num = num / 10;
		//}
		//normalUnits[countDigit] = '\0';


		//// normal units consumed INPUT done

		//// Peak Hour Units Consumed INPUT

		//char peakUnits[10];


		//if (metertype - 48 == 3)
		//{
		//	num = 0;

		//	cout << "Enter Peak Hour Units Consumed : ";
		//	cin >> num;

		//	flag = 1;

		//	if (num < 0)
		//	{
		//		do
		//		{
		//			flag = 1;

		//			if (num < 0)
		//			{
		//				cout << "Enter Peak Hour Units Consumed : ";
		//				cin >> num;

		//				flag = 0;
		//			}
		//		} while (flag == 0);
		//	}

		//	temp = num;
		//	countDigit = 0;

		//	while (temp > 0)
		//	{
		//		temp /= 10;
		//		countDigit++;
		//	}

		//	for (int i = 0; i < countDigit; i++)
		//	{
		//		peakUnits[countDigit - i - 1] = (num % 10) + 48;
		//		num = num / 10;
		//	}
		//	peakUnits[countDigit] = '\0';
		//}
		//else
		//{
		//	peakUnits[0] = '0';
		//	peakUnits[1] = '\0';
		//}

		cout << endl << "The Regular Units and Peak Units have been set to 0 for new meters" << endl << endl;

		// customer type

		do {
			cout << "Press 1 for Domestic Customer" << endl;
			cout << "Press 2 for Commercial Customer" << endl;
			cout << "Enter from above : ";
			customerType = _getch();
			cout << customerType - 48;
		} while (customerType < 49 || customerType > 50);




		fout << id << "," << CNIC << "," << name << "," << address << "," << number << "," << metertype << "," << connectionDate << "," << "0" << "," << "0" << "," << customerType << '^' << endl;

		fout.close();

		//UserName,Password^

		cout << endl << endl << "User Registered Successfully" << endl;
	}
	else
	{
		cout << endl << endl << "Exiting here. Given CNIC has been used 3 times!!!" << endl << endl;
	}



}

void addBillingInfo()
{
	if (true)
	{
		fstream C;
		fstream S;
		char dataO[250];

		C.open("CustomersInfo.txt", ios::in);
		S.open("CustomerCopy.txt", ios::out);

		while (!C.eof())
		{
			C.getline(dataO, 250);

			if (dataO[0] == '^' || dataO[0] == '\0')
			{

			}
			else
			{
				S << dataO << endl;
			}
		}

	}

	fstream getCustomerID;
	fstream readTaxFile;
	fstream fout;

	fout.open("BillingInfo.txt", ios::app);
	getCustomerID.open("CustomersInfo.txt", ios::in);

	char CustomerID[5];
	char ch = 'a';
	int countTextID = 0;
	int countRow = 0;
	bool flag = 1;
	int countRows = 0;
	int billingMonth = 0;
	int countBillingMonthR = 0;
	int temp = 0;
	int countDigit = 0;
	char ReadingDate[11];
	bool flagReadingDate = 1;
	int commaCount = 0;
	int meterType = 0;
	int regularUnits = 0;
	int peakUnits = 0;
	int CustomerType = 1;
	int costOfElectricity = 0;
	int salesTax = 0;
	int FixedAmount = 0;
	int priceRUnits = 0;
	int pricePUnits = 0;
	int percentageTax = 0;
	int FixedCharges = 0;
	char TaxFile[40];
	int totalAmountE = 0;
	int billPaidStatus = 0;
	char dueDate[11];
	char billPaidDate[11];
	int regularUnitsLast = 0;
	int peakUnitsLast = 0;
	int UnitsRegularE = 0;
	int UnitsPeakE = 0;
	char billingYear[5];
	char input[50];
	int DateCheckLast = 0;
	int MonthCheckLast = 0;
	int YearCheckLast = 0;
	int DateCheckCurrent = 0;
	int MonthCheckCurrent = 0;
	int YearCheckCurrent = 0;

	// here we get the billing month

	fstream getBillingMonth;
	getBillingMonth.open("BillingInfo.txt", ios::in);

	getBillingMonth >> ch;

	if (ch == 'a')
	{
		billingMonth = 1;

		if (billingMonth == 1)
		{
			billingYear[0] = '2';
			billingYear[1] = '0';
			billingYear[2] = '2';
			billingYear[3] = '2';
			billingYear[4] = '\0';
		}
	}

	getBillingMonth.close();

	if (billingMonth == 0)
	{
		getBillingMonth.open("BillingInfo.txt", ios::in);
		int commaCountX = 0;

		while (!getBillingMonth.eof())
		{
			getBillingMonth >> ch;

			countBillingMonthR++;

			if (countBillingMonthR == 6)
			{
				billingMonth = ch - 48;

				getBillingMonth >> ch;

				countBillingMonthR++;

				if (ch >= 48 && ch <= 57)
				{
					billingMonth = billingMonth * 10;
					billingMonth = billingMonth + (ch - 48);
				}
			}

			if (ch == ',')
			{
				commaCountX++;
			}

			if (commaCountX == 4)
			{
				for (int k = 0; k < 10; k++)
				{
					getBillingMonth >> ch;

					if (k >= 6)
					{
						billingYear[k - 6] = ch;
					}
				}
			}

			if (ch == '^')
			{
				countBillingMonthR = 0;
			}
		}

		billingMonth++;

		getBillingMonth.close();
	}

	billingYear[4] = '\0';

	if (billingMonth == 13)
	{
		billingMonth = 1;

		if (billingYear[3] == '9')
		{
			billingYear[2] += 1;
			billingYear[3] = '0';
		}
	}


	switch (billingMonth)
	{
	case 1:
	{
		cout << endl << "\t\t\t\tBilling Info of January" << endl << endl;
	}
	break;
	case 2:
	{
		cout << endl << "\t\t\t\tBilling Info of February" << endl << endl;
	}
	break;
	case 3:
	{
		cout << endl << "\t\t\t\tBilling Info of March" << endl << endl;
	}
	break;
	case 4:
	{
		cout << endl << "\t\t\t\tBilling Info of April" << endl << endl;
	}
	break;
	case 5:
	{
		cout << endl << "\t\t\t\tBilling Info of May" << endl << endl;
	}
	break;
	case 6:
	{
		cout << endl << "\t\t\t\tBilling Info of June" << endl << endl;
	}
	break;
	case 7:
	{
		cout << endl << "\t\t\t\tBilling Info of July" << endl << endl;
	}
	break;
	case 8:
	{
		cout << endl << "\t\t\t\tBilling Info of August" << endl << endl;
	}
	break;
	case 9:
	{
		cout << endl << "\t\t\t\tBilling Info of September" << endl << endl;
	}
	break;
	case 10:
	{
		cout << endl << "\t\t\t\tBilling Info of Octuber" << endl << endl;
	}
	break;
	case 11:
	{
		cout << endl << "\t\t\t\tBilling Info of Novermber" << endl << endl;
	}
	break;
	case 12:
	{
		cout << endl << "\t\t\t\tBilling Info of December" << endl << endl;
	}
	break;
	}

	// billing month done

	while (!getCustomerID.eof())
	{
		getCustomerID >> ch;

		if (commaCount == 5 && ch != ',')
		{
			meterType = ch - 48;
		}


		// to get last reading of customer


		if (commaCount == 7 && ch != ',')
		{
			regularUnitsLast = ch - 48;

			getCustomerID >> ch;

			while (ch != ',')
			{
				regularUnitsLast = regularUnitsLast * 10;
				regularUnitsLast = regularUnitsLast + (ch - 48);

				getCustomerID >> ch;

			}
		}

		// for only 3 phase meter type

		if (meterType == 3 && commaCount == 8 && ch != ',' && ch != '^')
		{
			peakUnitsLast = ch - 48;

			getCustomerID >> ch;

			while (ch != ',' && ch != '^')
			{
				peakUnitsLast = peakUnitsLast * 10;
				peakUnitsLast = peakUnitsLast + (ch - 48);

				getCustomerID >> ch;

			}
		}

		// end of units taking

		// CustomerType Input from CustomerInfo file

		if (commaCount == 9 && ch != ',' && ch != '^')
		{
			CustomerType = ch - 48;
		}

		// end

		if (ch == ',')
		{

			commaCount++;
		}

		if (!getCustomerID.eof())
		{
			if (ch == ',' && flag)
			{
				CustomerID[countTextID] = '\0';
				countRow++;
				flagReadingDate = 0;
				flag = 0;

			}
			else
			{
				if (flag)
				{
					CustomerID[countTextID++] = ch;
				}
			}


			if (ch == '^')
			{

				// nullifying the peak units if meter type is 1 phase


				if (meterType == 1)
				{
					peakUnitsLast = 0;
				}

				// done with above ( was not required but phr bhi kr dya xddddd )

				countTextID = 0;
				flag = 1;
				countRows;
				flagReadingDate = 1;
				commaCount = 0;


				cout << endl << "Enter Billing Info of " << CustomerID << endl << endl;



				// we have successfully got the customerID here

				// now rest of the codes here

				ReadingDate[2] = ReadingDate[5] = '/';
				ReadingDate[10] = '\0';

				int num = 0;

				//cout << "Enter Year of Reading : ";
				//cin >> num;
				//temp = num;
				//countDigit = 0;

				//while (temp > 0)
				//{
				//	temp = temp / 10;
				//	countDigit++;
				//}

				//if (countDigit != 4)
				//{
				//	do {

				//		cout << "Enter Year of Reading : ";
				//		cin >> num;
				//		temp = num;
				//		countDigit = 0;

				//		while (temp > 0)
				//		{
				//			temp /= 10;
				//			countDigit++;
				//		}

				//	} while (countDigit != 4);
				//}

				for (int k = 0; k < 4; k++)
				{
					num = (billingYear[k] - 48) + (num * 10);
				}

				cout << "Billing Year : " << num << endl;

				YearCheckLast = num;

				bool leapYear = 1;

				if (!LeapCheck(num))
				{
					leapYear = 0;
				}

				for (int i = 0; i < 4; i++)
				{
					ReadingDate[9 - i] = (num % 10) + 48;
					num /= 10;
				}

				// year done

				num = 0;

				//cout << "Enter Month of Reading : ";
				//cin >> num;

				//flagReadingDate = 1;

				//do {
				//	flagReadingDate = 1;

				//	if (num < 1 || num > 12)
				//	{
				//		flagReadingDate = 0;
				//	}

				//	if (flagReadingDate == 0)
				//	{
				//		cout << "Enter Month of Reading : ";
				//		cin >> num;
				//	}
				//} while (flagReadingDate == 0);

				cout << "Billing Month : " << billingMonth << endl;

				MonthCheckLast = billingMonth;
				int laterCheck = billingMonth;
				temp = billingMonth;

				if (num < 10)
				{
					ReadingDate[3] = '0';
					ReadingDate[4] = (temp + 48);
				}
				else
				{
					ReadingDate[4] = (temp % 10) + 48;
					temp /= 10;
					ReadingDate[3] = temp + 48;
				}

				// month done

				num = 0;
				bool flagCheck = 1;


				cout << "\nReading Date can not Exceed 20 of the month" << endl << endl;

				do
				{
					flagCheck = 1;

					for (int k = 0; k < 50; k++)
					{
						input[k] = 'a';
					}

					cout << "Enter Date of Reading : ";

					cin.getline(input, 50);
					

					if (input[0] == 'a')
					{
						flagCheck = 0;
					}

					if (input[1] == 'a')
					{
						flagCheck = 0;
					}

					if (input[1] != '\0' && input[2] != '\0')
					{
						flagCheck = 0;
					}

					if (input[1] == '\0')
					{
						if (input[0] < 48 && input[0] > 57)
						{
							flagCheck = 0;
						}
					}

					if (input[2] == '\0')
					{
						if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
						{
							flagCheck = 0;
						}
					}

				} while (flagCheck == 0);

				for (int k = 0; input[k] != '\0'; k++)
				{
					num = (num * 10) + (input[k] - 48);
				}


				flagReadingDate = 1;

				if (leapYear && laterCheck == 2)
				{
					do {
						flagReadingDate = 1;

						if (num < 1 || num > 20)
						{
							flagReadingDate = 0;
							flagCheck = 1;
							num = 0;
							do
							{
								flagCheck = 1;

								for (int k = 0; k < 50; k++)
								{
									input[k] = 'a';
								}

								cout << "Enter Date of Reading : ";

								cin.getline(input, 50);
								

								if (input[0] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] != '\0' && input[2] != '\0')
								{
									flagCheck = 0;
								}

								if (input[1] == '\0')
								{
									if (input[0] < 48 && input[0] > 57)
									{
										flagCheck = 0;
									}
								}

								if (input[2] == '\0')
								{
									if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
									{
										flagCheck = 0;
									}
								}

							} while (flagCheck == 0);

							for (int k = 0; input[k] != '\0'; k++)
							{
								num = (num * 10) + (input[k] - 48);
							}
						}
					} while (flagReadingDate == 0);
				}
				else if (!leapYear && laterCheck == 2)
				{
					do {
						flagReadingDate = 1;

						if (num < 1 || num > 20)
						{
							flagReadingDate = 0;
							flagCheck = 1;
							num = 0;
							do
							{
								flagCheck = 1;

								for (int k = 0; k < 50; k++)
								{
									input[k] = 'a';
								}

								cout << "Enter Date of Reading : ";

								cin.getline(input, 50);
								

								if (input[0] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] != '\0' && input[2] != '\0')
								{
									flagCheck = 0;
								}

								if (input[1] == '\0')
								{
									if (input[0] < 48 && input[0] > 57)
									{
										flagCheck = 0;
									}
								}

								if (input[2] == '\0')
								{
									if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
									{
										flagCheck = 0;
									}
								}

							} while (flagCheck == 0);

							for (int k = 0; input[k] != '\0'; k++)
							{
								num = (num * 10) + (input[k] - 48);
							}
						}
					} while (flagReadingDate == 0);
				}
				else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
				{
					do {
						flagReadingDate = 1;

						if (num < 1 || num > 20)
						{
							flagReadingDate = 0;
							flagCheck = 1;
							num = 0;
							do
							{
								flagCheck = 1;

								for (int k = 0; k < 50; k++)
								{
									input[k] = 'a';
								}

								cout << "Enter Date of Reading : ";

								cin.getline(input, 50);
								

								if (input[0] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] != '\0' && input[2] != '\0')
								{
									flagCheck = 0;
								}

								if (input[1] == '\0')
								{
									if (input[0] < 48 && input[0] > 57)
									{
										flagCheck = 0;
									}
								}

								if (input[2] == '\0')
								{
									if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
									{
										flagCheck = 0;
									}
								}

							} while (flagCheck == 0);

							for (int k = 0; input[k] != '\0'; k++)
							{
								num = (num * 10) + (input[k] - 48);
							}
						}
					} while (flagReadingDate == 0);
				}
				else
				{
					do
					{
						flagReadingDate = 1;


						if (num < 1 || num > 20)
						{
							flagReadingDate = 0;
							flagCheck = 1;
							num = 0;
							do
							{
								flagCheck = 1;

								for (int k = 0; k < 50; k++)
								{
									input[k] = 'a';
								}

								cout << "Enter Date of Reading : ";

								cin.getline(input, 50);
								

								if (input[0] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] == 'a')
								{
									flagCheck = 0;
								}

								if (input[1] != '\0' && input[2] != '\0')
								{
									flagCheck = 0;
								}

								if (input[1] == '\0')
								{
									if (input[0] < 48 && input[0] > 57)
									{
										flagCheck = 0;
									}
								}

								if (input[2] == '\0')
								{
									if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
									{
										flagCheck = 0;
									}
								}

							} while (flagCheck == 0);

							for (int k = 0; input[k] != '\0'; k++)
							{
								num = (num * 10) + (input[k] - 48);
							}
						}

					} while (flagReadingDate == 0);
				}

				DateCheckLast = num;
				int ReadingDateForDue = num;

				if (num < 10)
				{
					ReadingDate[0] = '0';
					ReadingDate[1] = (num + 48);
				}
				else
				{
					ReadingDate[1] = (num % 10) + 48;
					num /= 10;
					ReadingDate[0] = (num + 48);
				}

				// date done

				// date month year done with exception handling

				/* **************************************************************************** */

				// Units Regular input

				cout << endl << "Last Reading of Regular Units : " << regularUnitsLast << endl << endl;


				do {
					flagCheck = 1;

					do
					{
						for (int k = 0; k < 50; k++)
						{
							input[k] = 'a';
						}

						flagCheck = 1;

						cout << "Enter Regular Units Consumed : ";
						cin.getline(input, 50);
						

						for (int k = 0; input[k] != '\0' && flagCheck; k++)
						{
							if (input[k] < 48 || input[k] > 57)
							{
								flagCheck = 0;
							}
						}
					} while (flagCheck == 0);

					regularUnits = 0;

					for (int k = 0; input[k] != '\0'; k++)
					{
						regularUnits = (regularUnits * 10) + (input[k] - 48);
					}
				} while (regularUnits < 0 || regularUnits <= regularUnitsLast);

				UnitsRegularE = regularUnits - regularUnitsLast;

				// Regular Unit input end

				/* **************************************************************************** */

				// Units Peak Input

				if (meterType == 3)
				{
					cout << endl << "Last Reading of Peak Units : " << peakUnitsLast << endl << endl;

					do {
						flagCheck = 1;

						do
						{
							for (int k = 0; k < 50; k++)
							{
								input[k] = 'a';
							}

							flagCheck = 1;

							cout << "Enter Peak Units Consumed : ";
							cin.getline(input, 50);
							

							for (int k = 0; input[k] != '\0' && flagCheck; k++)
							{
								if (input[k] < 48 || input[k] > 57)
								{
									flagCheck = 0;
								}
							}
						} while (flagCheck == 0);

						peakUnits = 0;

						for (int k = 0; input[k] != '\0'; k++)
						{
							peakUnits = (peakUnits * 10) + (input[k] - 48);
						}
					} while (peakUnits < 0 || peakUnits <= peakUnitsLast);

					UnitsPeakE = peakUnits - peakUnitsLast;
				}

				// Peak Unit input end

				/* **************************************************************************** */

				// read data from TarrifTaxInfo file

				readTaxFile.open("TariffTaxInfo.txt", ios::in);

				int rowcountTax = 0;
				int rowToCheck = 0;

				if (meterType == 1 && CustomerType == 1)
				{
					rowToCheck = 1;
				}
				else if (meterType == 1 && CustomerType == 2)
				{
					rowToCheck = 2;
				}
				else if (meterType == 3 && CustomerType == 1)
				{
					rowToCheck = 3;
				}
				else if (meterType == 3 && CustomerType == 2)
				{
					rowToCheck = 4;
				}

				countRow = 0;
				commaCount = 0;


				while (!readTaxFile.eof())
				{
					readTaxFile >> ch;

					TaxFile[countRow++] = ch;

					if (ch == '^')
					{
						rowcountTax++;
						TaxFile[countRow] = '\0';
						countRow = 0;

						if (rowToCheck == rowcountTax)
						{
							for (int i = 0; TaxFile[i] != '^'; i++)
							{
								if (TaxFile[i] == ',')
								{
									commaCount++;
								}

								if (commaCount == 1 && TaxFile[i] != ',' && TaxFile[i] != '^')
								{
									if (TaxFile[i - 1] != ',')
									{
										priceRUnits = priceRUnits * 10;
										priceRUnits = priceRUnits + (TaxFile[i] - 48);
									}
									else if (TaxFile[i - 1] == ',')
									{
										priceRUnits = TaxFile[i] - 48;
									}
								}

								if (commaCount == 2 && meterType == 3 && TaxFile[i] != ',' && TaxFile[i] != '^')
								{

									if (TaxFile[i - 1] != ',')
									{
										pricePUnits = pricePUnits * 10;
										pricePUnits = pricePUnits + (TaxFile[i] - 48);
									}
									else if (TaxFile[i - 1] == ',')
									{
										pricePUnits = TaxFile[i] - 48;
									}
								}

								if (commaCount == 3 && TaxFile[i] != ',' && TaxFile[i] != '^')
								{

									if (TaxFile[i - 1] != ',')
									{
										percentageTax = percentageTax * 10;
										percentageTax = percentageTax + (TaxFile[i] - 48);
									}
									else if (TaxFile[i - 1] == ',')
									{
										percentageTax = TaxFile[i] - 48;
									}
								}

								if (commaCount == 4 && TaxFile[i] != ',' && TaxFile[i] != '^')
								{

									if (TaxFile[i - 1] != ',')
									{
										FixedCharges = FixedCharges * 10;
										FixedCharges = FixedCharges + (TaxFile[i] - 48);
									}
									else if (TaxFile[i - 1] == ',')
									{
										FixedCharges = TaxFile[i] - 48;
									}
								}
							}
						}

					}


				}

				readTaxFile.close();

				//cout << priceRUnits << " " << pricePUnits << "  " << percentageTax << "  " << FixedCharges << endl;


				// reading end

				// Cost of Electricity

				if (meterType == 1)
				{
					costOfElectricity = (priceRUnits * UnitsRegularE);
					salesTax = ((percentageTax * costOfElectricity) / 100);
					FixedAmount = FixedCharges;
				}
				else if (meterType == 3)
				{
					costOfElectricity = (priceRUnits * UnitsRegularE) + (pricePUnits * UnitsPeakE);
					salesTax = ((percentageTax * costOfElectricity) / 100);
					FixedAmount = FixedCharges;
				}

				totalAmountE = costOfElectricity + salesTax + FixedAmount;

				//cost of electricity done

				// Bill paid Status

				do {

					cout << "\nEnter 1 for paid" << endl;
					cout << "Enter 2 for Un-Paid" << endl;


					flagCheck = 1;

					do
					{
						for (int k = 0; k < 50; k++)
						{
							input[k] = 'a';
						}

						flagCheck = 1;


						cout << "Enter Bill Payment Status : ";
						cin.getline(input, 50);
						

						if (input[1] != '\0')
						{
							flagCheck = 0;
						}

						if (input[0] != '1' && input[0] != '2')
						{
							flagCheck = 0;
						}

					} while (flagCheck == 0);

					billPaidStatus = 0;

					for (int k = 0; input[k] != '\0'; k++)
					{
						billPaidStatus = (billPaidStatus * 10) + (input[k] - 48);
					}
				} while (billPaidStatus != 1 && billPaidStatus != 2);



				//Bill paid Status done

				//Due Date copy from reading date

				ReadingDateForDue += 7;

				for (int i = 2; i < 11; i++)
				{
					dueDate[i] = ReadingDate[i];
				}

				if (ReadingDateForDue < 10)
				{
					dueDate[0] = '0';
					dueDate[1] = (ReadingDateForDue + 48);
				}
				else
				{
					dueDate[1] = (ReadingDateForDue % 10) + 48;
					ReadingDateForDue /= 10;
					dueDate[0] = (ReadingDateForDue + 48);
				}



				//due date done


				// bill payment date


				bool flagTemp = 1;

				if (billPaidStatus == 1)
				{


					do
					{
						num = 0;
						flagTemp = 1;

						do
						{
							flagCheck = 1;
							flagTemp = 1;

							for (int k = 0; k < 50; k++)
							{
								input[k] = 'a';
							}

							cout << "Enter Year of Payment : ";

							cin.getline(input, 50);
							

							//if (input[0] == '\0' || input[1] == '\0' || input[2] == '\0' || input[3] == '\0')
							//{
							//	flagCheck == 0;
							//}

							if (input[4] == '\0')
							{
								for (int k = 0; k < 4; k++)
								{
									if (input[k] < 48 || input[k] > 57)
									{
										flagCheck = 0;
									}
								}
							}
							else
							{
								flagCheck = 0;
							}

						} while (flagCheck == 0);

						num = 0;

						for (int k = 0; k < 4; k++)
						{
							num = (num * 10) + (input[k] - 48);
						}

						if (num < YearCheckLast)
						{
							flagTemp = 0;
							cout << endl << "Enter Year less than Entry Year" << endl;
						}

					} while (flagTemp == 0);

					YearCheckCurrent = num;
					temp = num;
					countDigit = 0;

					while (temp > 0)
					{
						temp = temp / 10;
						countDigit++;
					}

					if (countDigit != 4)
					{
						do {

							cout << "Enter Year of Payment : ";
							cin >> num;
							temp = num;
							countDigit = 0;

							while (temp > 0)
							{
								temp /= 10;
								countDigit++;
							}

						} while (countDigit != 4);
					}



					bool leapYear = 1;

					if (!LeapCheck(num))
					{
						leapYear = 0;
					}

					for (int i = 0; i < 4; i++)
					{
						billPaidDate[9 - i] = (num % 10) + 48;
						num /= 10;
					}

					// year done


					do {
						num = 0;
						flagTemp = 1;

						do
						{
							flagCheck = 1;
							flagTemp = 1;

							for (int k = 0; k < 50; k++)
							{
								input[k] = 'a';
							}

							cout << "Enter Month of Payment : ";

							cin.getline(input, 50);
							

							if (input[0] == 'a')
							{
								flagCheck = 0;
							}

							if (input[1] == 'a')
							{
								flagCheck = 0;
							}

							if (input[1] != '\0' && input[2] != '\0')
							{
								flagCheck = 0;
							}

							if (input[1] == '\0')
							{
								if (input[0] < 48 && input[0] > 57)
								{
									flagCheck = 0;
								}
							}

							if (input[2] == '\0')
							{
								if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
								{
									flagCheck = 0;
								}
							}

						} while (flagCheck == 0);

						num = 0;

						for (int k = 0; input[k] != '\0'; k++)
						{
							num = (num * 10) + (input[k] - 48);
						}

						if (YearCheckLast == YearCheckCurrent)
						{
							if (num < MonthCheckLast)
							{
								flagTemp = 0;
								cout << endl << "Enter Month less than Entry Month" << endl;
							}
						}

					} while (!flagTemp);

					flag = 1;

					flagCheck = 1;

					do {
						flag = 1;

						flagCheck = 1;

						if (num < 1 || num > 12)
						{
							flag = 0;
						}

						if (flag == 0)
						{
							flagCheck = 1;

							do {
								num = 0;
								flagTemp = 1;

								do
								{
									flagCheck = 1;
									flagTemp = 1;

									for (int k = 0; k < 50; k++)
									{
										input[k] = 'a';
									}

									cout << "Enter Month of Payment : ";

									cin.getline(input, 50);
									

									if (input[0] == 'a')
									{
										flagCheck = 0;
									}

									if (input[1] == 'a')
									{
										flagCheck = 0;
									}

									if (input[1] != '\0' && input[2] != '\0')
									{
										flagCheck = 0;
									}

									if (input[1] == '\0')
									{
										if (input[0] < 48 && input[0] > 57)
										{
											flagCheck = 0;
										}
									}

									if (input[2] == '\0')
									{
										if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
										{
											flagCheck = 0;
										}
									}

								} while (flagCheck == 0);

								num = 0;

								for (int k = 0; input[k] != '\0'; k++)
								{
									num = (num * 10) + (input[k] - 48);
								}

								if (YearCheckLast == YearCheckCurrent)
								{
									if (num < MonthCheckLast)
									{
										flagTemp = 0;
										cout << endl << "Enter Month less than Entry Month" << endl;
									}
								}

							} while (!flagTemp);
						}

					} while (flag == 0);

					MonthCheckCurrent = num;
					int laterCheck = num;
					temp = num;

					if (num < 10)
					{
						billPaidDate[3] = '0';
						billPaidDate[4] = (num + 48);
					}
					else
					{
						billPaidDate[4] = (num % 10) + 48;
						num /= 10;
						billPaidDate[3] = num + 48;
					}

					// month done

					num = 0;
					flagTemp = 1;

					do {
						flagTemp = 1;
						flagCheck = 1;

						do
						{
							flagCheck = 1;

							for (int k = 0; k < 50; k++)
							{
								input[k] = 'a';
							}

							cout << "Enter Date of Payment : ";

							cin.getline(input, 50);
							

							if (input[0] == 'a')
							{
								flagCheck = 0;
							}

							if (input[1] == 'a')
							{
								flagCheck = 0;
							}

							if (input[1] != '\0' && input[2] != '\0')
							{
								flagCheck = 0;
							}

							if (input[1] == '\0')
							{
								if (input[0] < 48 && input[0] > 57)
								{
									flagCheck = 0;
								}
							}

							if (input[2] == '\0')
							{
								if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
								{
									flagCheck = 0;
								}
							}

						} while (flagCheck == 0);

						num = 0;

						for (int k = 0; input[k] != '\0'; k++)
						{
							num = (num * 10) + (input[k] - 48);
						}

						if (YearCheckLast == YearCheckCurrent)
						{
							if (MonthCheckCurrent == MonthCheckLast)
							{
								if (num < DateCheckLast)
								{
									flagTemp = 0;
									cout << endl << "Enter Date less than Entry Date" << endl;
								}
							}
						}

					} while (flagTemp == 0);

					flag = 1;

					if (leapYear && laterCheck == 2)
					{
						do {
							flag = 1;

							if (num < 1 || num > 29)
							{
								flag = 0;
								flagTemp = 1;

								do {
									flagTemp = 1;
									flagCheck = 1;

									do
									{
										flagCheck = 1;

										for (int k = 0; k < 50; k++)
										{
											input[k] = 'a';
										}

										cout << "Enter Date of Payment : ";

										cin.getline(input, 50);
										

										if (input[0] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] != '\0' && input[2] != '\0')
										{
											flagCheck = 0;
										}

										if (input[1] == '\0')
										{
											if (input[0] < 48 && input[0] > 57)
											{
												flagCheck = 0;
											}
										}

										if (input[2] == '\0')
										{
											if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
											{
												flagCheck = 0;
											}
										}

									} while (flagCheck == 0);

									num = 0;

									for (int k = 0; input[k] != '\0'; k++)
									{
										num = (num * 10) + (input[k] - 48);
									}

									if (YearCheckLast == YearCheckCurrent)
									{
										if (MonthCheckCurrent == MonthCheckLast)
										{
											if (num < DateCheckLast)
											{
												flagTemp = 0;
												cout << endl << "Enter Date less than Entry Date" << endl;
											}
										}
									}

								} while (flagTemp == 0);
							}
						} while (flag == 0);
					}
					else if (!leapYear && laterCheck == 2)
					{
						do {
							flag = 1;

							if (num < 1 || num > 28)
							{
								flag = 0;
								flagTemp = 1;

								do {
									flagTemp = 1;
									flagCheck = 1;

									do
									{
										flagCheck = 1;

										for (int k = 0; k < 50; k++)
										{
											input[k] = 'a';
										}

										cout << "Enter Date of Payment : ";

										cin.getline(input, 50);
										

										if (input[0] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] != '\0' && input[2] != '\0')
										{
											flagCheck = 0;
										}

										if (input[1] == '\0')
										{
											if (input[0] < 48 && input[0] > 57)
											{
												flagCheck = 0;
											}
										}

										if (input[2] == '\0')
										{
											if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
											{
												flagCheck = 0;
											}
										}

									} while (flagCheck == 0);

									num = 0;

									for (int k = 0; input[k] != '\0'; k++)
									{
										num = (num * 10) + (input[k] - 48);
									}

									if (YearCheckLast == YearCheckCurrent)
									{
										if (MonthCheckCurrent == MonthCheckLast)
										{
											if (num < DateCheckLast)
											{
												flagTemp = 0;
												cout << endl << "Enter Date less than Entry Date" << endl;
											}
										}
									}

								} while (flagTemp == 0);
							}
						} while (flag == 0);
					}
					else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
					{
						do {
							flag = 1;

							if (num < 1 || num > 30)
							{
								flag = 0;
								flagTemp = 1;

								do {
									flagTemp = 1;
									flagCheck = 1;

									do
									{
										flagCheck = 1;

										for (int k = 0; k < 50; k++)
										{
											input[k] = 'a';
										}

										cout << "Enter Date of Payment : ";

										cin.getline(input, 50);
										

										if (input[0] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] != '\0' && input[2] != '\0')
										{
											flagCheck = 0;
										}

										if (input[1] == '\0')
										{
											if (input[0] < 48 && input[0] > 57)
											{
												flagCheck = 0;
											}
										}

										if (input[2] == '\0')
										{
											if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
											{
												flagCheck = 0;
											}
										}

									} while (flagCheck == 0);

									num = 0;

									for (int k = 0; input[k] != '\0'; k++)
									{
										num = (num * 10) + (input[k] - 48);
									}

									if (YearCheckLast == YearCheckCurrent)
									{
										if (MonthCheckCurrent == MonthCheckLast)
										{
											if (num < DateCheckLast)
											{
												flagTemp = 0;
												cout << endl << "Enter Date less than Entry Date" << endl;
											}
										}
									}

								} while (flagTemp == 0);
							}
						} while (flag == 0);
					}
					else
					{
						do
						{
							flag = 1;

							if (num < 0 || num > 31)
							{
								flag = 0;
								flagTemp = 1;

								do {
									flagTemp = 1;
									flagCheck = 1;

									do
									{
										flagCheck = 1;

										for (int k = 0; k < 50; k++)
										{
											input[k] = 'a';
										}

										cout << "Enter Date of Payment : ";

										cin.getline(input, 50);
										

										if (input[0] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] == 'a')
										{
											flagCheck = 0;
										}

										if (input[1] != '\0' && input[2] != '\0')
										{
											flagCheck = 0;
										}

										if (input[1] == '\0')
										{
											if (input[0] < 48 && input[0] > 57)
											{
												flagCheck = 0;
											}
										}

										if (input[2] == '\0')
										{
											if (input[0] < 48 && input[0] > 57 && input[1] < 48 && input[1] > 57)
											{
												flagCheck = 0;
											}
										}

									} while (flagCheck == 0);

									num = 0;

									for (int k = 0; input[k] != '\0'; k++)
									{
										num = (num * 10) + (input[k] - 48);
									}

									if (YearCheckLast == YearCheckCurrent)
									{
										if (MonthCheckCurrent == MonthCheckLast)
										{
											if (num < DateCheckLast)
											{
												flagTemp = 0;
												cout << endl << "Enter Date less than Entry Date" << endl;
											}
										}
									}

								} while (flagTemp == 0);
							}

						} while (flag == 0);
					}

					if (num < 10)
					{
						billPaidDate[0] = '0';
						billPaidDate[1] = (num + 48);
					}
					else
					{
						billPaidDate[1] = (num % 10) + 48;
						num /= 10;
						billPaidDate[0] = (num + 48);
					}

					billPaidDate[2] = billPaidDate[5] = '/';

					billPaidDate[10] = '\0';

					// date done

					// date month year done with exception handling

				}
				else if (billPaidStatus == 2)
				{
					billPaidDate[2] = billPaidDate[5] = '/';
					billPaidDate[1] = billPaidDate[0] = billPaidDate[3] = billPaidDate[4] = billPaidDate[6] = billPaidDate[7] = billPaidDate[8] = billPaidDate[9] = '-';
					billPaidDate[10] = '\0';
				}

				char UnitR[10];

				temp = regularUnits;
				countDigit = 0;

				while (temp > 0)
				{
					temp /= 10;
					countDigit++;
				}

				temp = regularUnits;

				for (int k = 0; k < countDigit; k++)
				{
					UnitR[countDigit - k - 1] = (temp % 10) + 48;
					temp /= 10;
				}

				UnitR[countDigit] = '\0';

				//

				char UnitP[10];

				if (meterType == 3)
				{


					temp = peakUnits;
					countDigit = 0;

					while (temp > 0)
					{
						temp /= 10;
						countDigit++;
					}

					temp = peakUnits;

					for (int k = 0; k < countDigit; k++)
					{
						UnitP[countDigit - k - 1] = (temp % 10) + 48;
						temp /= 10;
					}

					UnitP[countDigit] = '\0';
				}


				if (billPaidStatus == 1)
				{
					fstream set;
					fstream fout1;
					char data[300];
					char copy_data[300];
					bool stopRead = 1;

					set.open("CustomerCopy.txt", ios::in);
					fout1.open("CopyCustomerInfo.txt", ios::out);

					while (!set.eof())
					{
						set.getline(data, 300);

						if (CustomerID[0] == data[0] && CustomerID[1] == data[1] && CustomerID[2] == data[2] && CustomerID[3] == data[3])
						{
							int countI = 0;
							int countTextH = 0;
							int countR = 0;
							bool flagOO = 1;
							stopRead = 0;

							for (int k = 0; data[k] != '\0'; k++)
							{

								if (data[k] == ',')
								{
									countI++;
									flagOO = 1;
									countR = 0;
								}

								if (countI == 7 && data[k] != ',')
								{
									flagOO = 0;

									while (UnitR[countR] != '\0')
										copy_data[countTextH++] = UnitR[countR++];
								}

								if (countI == 8 && data[k] != ',' && meterType == 3)
								{
									flagOO = 0;

									while (UnitR[countR] != '\0')
										copy_data[countTextH++] = UnitP[countR++];
								}

								if (flagOO)
								{
									copy_data[countTextH++] = data[k];
								}

								if (data[k] == '^')
								{
									copy_data[countTextH] = '\0';
								}
							}
						}
						else
						{
							int countTextH = 0;

							for (int k = 0; data[k] != '\0'; k++)
							{
								copy_data[countTextH++] = data[k];
							}

							copy_data[countTextH++] = '\0';
						}

						if (copy_data[0] != '\0' && copy_data[0] != '^')
							fout1 << copy_data << endl;
					}

					set.close();
					fout1.close();

					set.open("CopyCustomerInfo.txt", ios::in);
					fout1.open("CustomerCopy.txt", ios::out);

					while (!set.eof())
					{
						set.getline(data, 300);

						if (copy_data[0] == '\0' || copy_data[0] == '^')
						{

						}
						else
						{
							fout1 << data << endl;
						}
					}

				}



				//


				// testing cout **** delete later // deleted


				fout << CustomerID << "," << billingMonth << "," << UnitsRegularE << "," << UnitsPeakE << "," << ReadingDate << "," << costOfElectricity << ",";
				fout << salesTax << "," << FixedAmount << "," << totalAmountE << "," << dueDate << "," << billPaidStatus << "," << billPaidDate << "^" << endl;

				//Important to put them  equal to zero 
				// Note : very Important

				commaCount = 0;
				costOfElectricity = 0;
				priceRUnits = 0;
				pricePUnits = 0;
				percentageTax = 0;
				FixedCharges = 0;
				regularUnits = 0;
				peakUnits = 0;
				salesTax = 0;
				FixedAmount = 0;
				totalAmountE = 0;
				peakUnitsLast = 0;
				regularUnitsLast = 0;
				UnitsPeakE = 0;
				UnitsRegularE = 0;



			}


		}

	}

	getCustomerID.close();

	if (true)
	{

		//CustomersInfo
		fstream C;
		fstream S;
		char dataO[250];

		C.open("CustomerCopy.txt", ios::in);
		S.open("CustomersInfo.txt", ios::out);

		while (!C.eof())
		{
			C.getline(dataO, 250);

			if (dataO[0] == '\0' || dataO[0] == '^')
			{

			}
			else
			{
				S << dataO << endl;
			}
		}

	}


}

//void addCNIC_file()
//{
//	fstream fout;
//	fstream checkCNIC;
//	int dateOfIssue = 0;
//	int monthOfIssue = 0;
//	int yearOfIssue = 0;
//	int dateOfExpiry = 0;
//	int monthOfExpiry = 0;
//	int yearOfExpiry = 0;
//	char choiceReCNIC = 'a';
//
//	fout.open("NADRADB.txt", ios::app);
//
//	char chh = 'a';
//
//	// CNIC Input
//
//	char CNIC[20]; // no dashes
//
//
//	bool flag = 1;
//
//
//	do {
//		do
//		{
//			for (int i = 0; i < 13; i++)
//			{
//				CNIC[i] = 'a';
//			}
//
//			CNIC[13] = '\0';
//
//			cout << "Enter CNIC : ";
//			cin.getline(CNIC, 20);
//			
//
//			CNIC[13] = '\0';
//
//			flag = 1;
//
//			for (int i = 0; i < 13 && flag; i++)
//			{
//				if (CNIC[i] < 48 || CNIC[i] > 57)
//				{
//					flag = 0;
//				}
//				else if (CNIC[i] == '-')
//				{
//					flag = 0;
//				}
//			}
//
//		} while (flag == 0);
//
//		char checkCNICFromFile[45];
//		bool checkCNICflag = 1;
//		flag = 1;
//
//		checkCNIC.open("NADRADB.txt", ios::in);
//
//		while (!checkCNIC.eof() && checkCNICflag)
//		{
//
//			for (int i = 0; i < 36 && !checkCNIC.eof(); i++)
//			{
//				checkCNIC >> chh;
//
//				checkCNICFromFile[i] = chh;
//			}
//
//
//			if (checkCNICFromFile[0] != '^')
//			{
//				checkCNICflag = 1;
//
//				for (int i = 0; i < 13 && checkCNICflag; i++)
//				{
//					if (checkCNICFromFile[i] == CNIC[i])
//					{
//						checkCNICflag = 0;
//					}
//				}
//			}
//		}
//
//		if (checkCNICflag == 0)
//		{
//			flag = 0;
//			cout << endl << "The CNIC already exists" << endl << endl;
//		}
//
//		checkCNIC.close();
//
//		if (flag == 0)
//		{
//			do {
//
//				cout << endl << "Do you want to end another CNIC ? (y/n) ";
//				cin >> choiceReCNIC;
//
//			} while ((choiceReCNIC == 'y' && choiceReCNIC == 'Y') || (choiceReCNIC == 'n' && choiceReCNIC == 'N'));
//
//			
//
//
//
//			if (choiceReCNIC == 'n' || choiceReCNIC == 'N')
//			{
//				flag = 1;
//			}
//
//			cout << endl << endl;
//		}
//
//
//	} while (flag == 0);
//
//
//	// CNIC Input end
//
//	// Issuance Date Input
//
//	if (flag && (choiceReCNIC != 'n' && choiceReCNIC != 'N'))
//	{
//
//		int temp = 0;
//		int countDigit = 0;
//
//		char issuanceDate[11];
//
//		issuanceDate[2] = issuanceDate[5] = '/';
//		issuanceDate[10] = '\0';
//
//		int num = 0;
//
//		cout << "Enter Year of Issuance : ";
//		cin >> num;
//		temp = num;
//		countDigit = 0;
//
//		while (temp > 0)
//		{
//			temp = temp / 10;
//			countDigit++;
//		}
//
//		if (countDigit != 4)
//		{
//			do {
//
//				cout << "Enter Year of Issuance : ";
//				cin >> num;
//				temp = num;
//				countDigit = 0;
//
//				while (temp > 0)
//				{
//					temp /= 10;
//					countDigit++;
//				}
//
//			} while (countDigit != 4);
//		}
//
//		yearOfIssue = num;
//
//		bool leapYear = 1;
//
//		if (!LeapCheck(num))
//		{
//			leapYear = 0;
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			issuanceDate[9 - i] = (num % 10) + 48;
//			num /= 10;
//		}
//
//		// year done
//
//		num = 0;
//
//		cout << "Enter Month of Issuance : ";
//		cin >> num;
//
//		flag = 1;
//
//		do {
//			flag = 1;
//
//			if (num < 1 || num > 12)
//			{
//				flag = 0;
//			}
//
//			if (flag == 0)
//			{
//				cout << "Enter Month of Issuance : ";
//				cin >> num;
//			}
//		} while (flag == 0);
//
//		int laterCheck = num;
//		temp = num;
//		monthOfIssue = num;
//
//		if (num < 10)
//		{
//			issuanceDate[3] = '0';
//			issuanceDate[4] = (num + 48);
//		}
//		else
//		{
//			issuanceDate[4] = (num % 10) + 48;
//			num /= 10;
//			issuanceDate[3] = num + 48;
//		}
//
//		// month done
//
//		num = 0;
//
//		cout << "Enter Date of Issuance : ";
//		cin >> num;
//
//		flag = 1;
//
//		if (leapYear && laterCheck == 2)
//		{
//			do {
//				flag = 1;
//
//				if (num < 1 || num > 29)
//				{
//					flag = 0;
//					cout << "Enter Date of Issuance : ";
//					cin >> num;
//				}
//			} while (flag == 0);
//		}
//		else if (!leapYear && laterCheck == 2)
//		{
//			do {
//				flag = 1;
//
//				if (num < 1 || num > 28)
//				{
//					flag = 0;
//					cout << "Enter Date of Issuance : ";
//					cin >> num;
//				}
//			} while (flag == 0);
//		}
//		else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
//		{
//			do {
//				flag = 1;
//
//				if (num < 1 || num > 30)
//				{
//					flag = 0;
//					cout << "Enter Date of Issuance : ";
//					cin >> num;
//				}
//			} while (flag == 0);
//		}
//		else
//		{
//			do
//			{
//				flag = 1;
//
//				if (num < 0 || num > 31)
//				{
//					flag = 0;
//					cout << "Enter Date of Issuance : ";
//					cin >> num;
//				}
//
//			} while (flag == 0);
//		}
//
//		dateOfIssue = num;
//
//		if (num < 10)
//		{
//			issuanceDate[0] = '0';
//			issuanceDate[1] = (num + 48);
//		}
//		else
//		{
//			issuanceDate[1] = (num % 10) + 48;
//			num /= 10;
//			issuanceDate[0] = (num + 48);
//		}
//
//		// date done
//
//		// date month year done with exception handling of issuance date
//
//		 // Expiry Date Input
//
//		temp = 0;
//		countDigit = 0;
//		bool ExpiryYearCheck = 1;
//
//		char expiryDate[11];
//
//		expiryDate[2] = expiryDate[5] = '/';
//		expiryDate[10] = '\0';
//
//		num = 0;
//
//		do {
//			ExpiryYearCheck = 1;
//
//			cout << "Enter Year of Expiry : ";
//			cin >> num;
//			temp = num;
//			countDigit = 0;
//
//			while (temp > 0)
//			{
//				temp = temp / 10;
//				countDigit++;
//			}
//
//			if (countDigit != 4)
//			{
//				do {
//
//					cout << "Enter Year of Expiry : ";
//					cin >> num;
//					temp = num;
//					countDigit = 0;
//
//					while (temp > 0)
//					{
//						temp /= 10;
//						countDigit++;
//					}
//
//				} while (countDigit != 4);
//			}
//
//			if (num < yearOfIssue)
//			{
//				ExpiryYearCheck = 0;
//
//				cout << endl << endl << "ERROR : Enter Expiry Year which is greater than Issuance Year" << endl << endl;
//
//			}
//		} while (ExpiryYearCheck == 0);
//
//		yearOfExpiry = num;
//
//		leapYear = 1;
//
//		if (!LeapCheck(num))
//		{
//			leapYear = 0;
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			expiryDate[9 - i] = (num % 10) + 48;
//			num /= 10;
//		}
//
//		// year done
//
//		num = 0;
//		bool ExpiryMonthCheck = 1;
//
//		do {
//			ExpiryMonthCheck = 1;
//
//			cout << "Enter Month of Expiry : ";
//			cin >> num;
//
//			flag = 1;
//
//			do {
//				flag = 1;
//
//				if (num < 1 || num > 12)
//				{
//					flag = 0;
//				}
//
//				if (flag == 0)
//				{
//					cout << "Enter Month of Expiry : ";
//					cin >> num;
//				}
//			} while (flag == 0);
//
//			int laterCheck = num;
//			temp = num;
//
//			if (yearOfExpiry == yearOfIssue)
//			{
//				if (num < monthOfIssue)
//				{
//					ExpiryMonthCheck = 0;
//
//					cout << endl << endl << "ERROR : Enter Expiry Month which is greater than Issuance Month When Year of Issuance is same" << endl << endl;
//
//				}
//			}
//		} while (ExpiryMonthCheck == 0);
//
//		monthOfExpiry = num;
//
//		if (num < 10)
//		{
//			expiryDate[3] = '0';
//			expiryDate[4] = (num + 48);
//		}
//		else
//		{
//			expiryDate[4] = (num % 10) + 48;
//			num /= 10;
//			expiryDate[3] = num + 48;
//		}
//
//		// month done
//
//		num = 0;
//		bool ExpiryDateCheck = 1;
//
//		do {
//			ExpiryDateCheck = 1;
//
//			cout << "Enter Date of Expiry : ";
//			cin >> num;
//
//			flag = 1;
//
//			if (leapYear && laterCheck == 2)
//			{
//				do {
//					flag = 1;
//
//					if (num < 1 || num > 29)
//					{
//						flag = 0;
//						cout << "Enter Date of Expiry : ";
//						cin >> num;
//					}
//				} while (flag == 0);
//			}
//			else if (!leapYear && laterCheck == 2)
//			{
//				do {
//					flag = 1;
//
//					if (num < 1 || num > 28)
//					{
//						flag = 0;
//						cout << "Enter Date of Expiry : ";
//						cin >> num;
//					}
//				} while (flag == 0);
//			}
//			else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
//			{
//				do {
//					flag = 1;
//
//					if (num < 1 || num > 30)
//					{
//						flag = 0;
//						cout << "Enter Date of Expiry : ";
//						cin >> num;
//					}
//				} while (flag == 0);
//			}
//			else
//			{
//				do
//				{
//					flag = 1;
//
//					if (num < 0 || num > 31)
//					{
//						flag = 0;
//						cout << "Enter Date of Expiry : ";
//						cin >> num;
//					}
//
//				} while (flag == 0);
//			}
//
//			if (yearOfExpiry == yearOfIssue)
//			{
//				if (monthOfExpiry == monthOfIssue)
//				{
//					if (num >= dateOfIssue)
//					{
//						ExpiryDateCheck = 0;
//
//						cout << endl << endl << "ERROR : Enter Expiry Date which is greater than Issuance Date When Year and Month of Issuance is same" << endl << endl;
//					}
//				}
//			}
//		} while (ExpiryDateCheck == 0);
//
//
//		dateOfExpiry = num;
//
//		if (num < 10)
//		{
//			expiryDate[0] = '0';
//			expiryDate[1] = (num + 48);
//		}
//		else
//		{
//			expiryDate[1] = (num % 10) + 48;
//			num /= 10;
//			expiryDate[0] = (num + 48);
//		}
//
//		// date done
//
//		// date month year done with exception handling
//
//		fout << CNIC << "," << issuanceDate << "," << expiryDate << "^" << endl;
//
//
//	}
//
//	fout.close();
//}

void addCNIC_file(char CNIC[])
{
	fstream fout;
	fstream checkCNIC;
	int dateOfIssue = 0;
	int monthOfIssue = 0;
	int yearOfIssue = 0;
	int dateOfExpiry = 0;
	int monthOfExpiry = 0;
	int yearOfExpiry = 0;
	char choiceReCNIC = 'a';

	fout.open("NADRADB.txt", ios::app);

	char chh = 'a';


	bool flag = 1;


	do {
		
		if (flag == 0)
		{
			do
			{
				for (int i = 0; i < 13; i++)
				{
					CNIC[i] = 'a';
				}

				CNIC[13] = '\0';

				cout << "Enter CNIC : ";
				cin.getline(CNIC, 20);
				

				CNIC[13] = '\0';

				flag = 1;

				for (int i = 0; i < 13 && flag; i++)
				{
					if (CNIC[i] < 48 || CNIC[i] > 57)
					{
						flag = 0;
					}
					else if (CNIC[i] == '-')
					{
						flag = 0;
					}
				}

			} while (flag == 0);
		}


		char checkCNICFromFile[45];
		bool checkCNICflag = 1;
		flag = 1;
		bool Stop = 1;

		checkCNIC.open("NADRADB.txt", ios::in);

		while (!checkCNIC.eof() && Stop)
		{

			for (int i = 0; i < 36 && !checkCNIC.eof(); i++)
			{
				checkCNIC >> chh;

				checkCNICFromFile[i] = chh;
			}


			if (checkCNICFromFile[0] != '^')
			{
				checkCNICflag = 1;

				for (int i = 0; i < 13 && checkCNICflag; i++)
				{
					if (checkCNICFromFile[i] != CNIC[i])
					{
						checkCNICflag = 0;
					}
				}

				if (checkCNICflag == 1)
				{
					Stop = 0;
				}

			}
		}

		if (Stop == 0)
		{
			flag = 0;
			cout << endl << "The CNIC already exists" << endl << endl;
		}

		checkCNIC.close();

		if (flag == 0)
		{
			do {

				cout << endl << "Do you want to end another CNIC ? (y/n) ";
				cin >> choiceReCNIC;

			} while ((choiceReCNIC == 'y' && choiceReCNIC == 'Y') || (choiceReCNIC == 'n' && choiceReCNIC == 'N'));

			



			if (choiceReCNIC == 'n' || choiceReCNIC == 'N')
			{
				flag = 1;
			}

			cout << endl << endl;
		}


	} while (flag == 0);


	// CNIC Input end

	// Issuance Date Input

	if (flag && (choiceReCNIC != 'n' && choiceReCNIC != 'N'))
	{

		int temp = 0;
		int countDigit = 0;

		char issuanceDate[11];

		issuanceDate[2] = issuanceDate[5] = '/';
		issuanceDate[10] = '\0';

		int num = 0;

		cout << "Enter Year of Issuance : ";
		cin >> num;
		temp = num;
		countDigit = 0;

		while (temp > 0)
		{
			temp = temp / 10;
			countDigit++;
		}

		if (countDigit != 4)
		{
			do {

				cout << "Enter Year of Issuance : ";
				cin >> num;
				temp = num;
				countDigit = 0;

				while (temp > 0)
				{
					temp /= 10;
					countDigit++;
				}

			} while (countDigit != 4);
		}

		yearOfIssue = num;

		bool leapYear = 1;

		if (!LeapCheck(num))
		{
			leapYear = 0;
		}

		for (int i = 0; i < 4; i++)
		{
			issuanceDate[9 - i] = (num % 10) + 48;
			num /= 10;
		}

		// year done

		num = 0;

		cout << "Enter Month of Issuance : ";
		cin >> num;

		flag = 1;

		do {
			flag = 1;

			if (num < 1 || num > 12)
			{
				flag = 0;
			}

			if (flag == 0)
			{
				cout << "Enter Month of Issuance : ";
				cin >> num;
			}
		} while (flag == 0);

		int laterCheck = num;
		temp = num;
		monthOfIssue = num;

		if (num < 10)
		{
			issuanceDate[3] = '0';
			issuanceDate[4] = (num + 48);
		}
		else
		{
			issuanceDate[4] = (num % 10) + 48;
			num /= 10;
			issuanceDate[3] = num + 48;
		}

		// month done

		num = 0;

		cout << "Enter Date of Issuance : ";
		cin >> num;

		flag = 1;

		if (leapYear && laterCheck == 2)
		{
			do {
				flag = 1;

				if (num < 1 || num > 29)
				{
					flag = 0;
					cout << "Enter Date of Issuance : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else if (!leapYear && laterCheck == 2)
		{
			do {
				flag = 1;

				if (num < 1 || num > 28)
				{
					flag = 0;
					cout << "Enter Date of Issuance : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
		{
			do {
				flag = 1;

				if (num < 1 || num > 30)
				{
					flag = 0;
					cout << "Enter Date of Issuance : ";
					cin >> num;
				}
			} while (flag == 0);
		}
		else
		{
			do
			{
				flag = 1;

				if (num < 0 || num > 31)
				{
					flag = 0;
					cout << "Enter Date of Issuance : ";
					cin >> num;
				}

			} while (flag == 0);
		}

		dateOfIssue = num;

		if (num < 10)
		{
			issuanceDate[0] = '0';
			issuanceDate[1] = (num + 48);
		}
		else
		{
			issuanceDate[1] = (num % 10) + 48;
			num /= 10;
			issuanceDate[0] = (num + 48);
		}

		// date done

		// date month year done with exception handling of issuance date

		 // Expiry Date Input

		temp = 0;
		countDigit = 0;
		bool ExpiryYearCheck = 1;

		char expiryDate[11];

		expiryDate[2] = expiryDate[5] = '/';
		expiryDate[10] = '\0';

		num = 0;

		do {
			ExpiryYearCheck = 1;

			cout << "Enter Year of Expiry : ";
			cin >> num;
			temp = num;
			countDigit = 0;

			while (temp > 0)
			{
				temp = temp / 10;
				countDigit++;
			}

			if (countDigit != 4)
			{
				do {

					cout << "Enter Year of Expiry : ";
					cin >> num;
					temp = num;
					countDigit = 0;

					while (temp > 0)
					{
						temp /= 10;
						countDigit++;
					}

				} while (countDigit != 4);
			}

			if (num < yearOfIssue)
			{
				ExpiryYearCheck = 0;

				cout << endl << endl << "ERROR : Enter Expiry Year which is greater than Issuance Year" << endl << endl;

			}
		} while (ExpiryYearCheck == 0);

		yearOfExpiry = num;

		leapYear = 1;

		if (!LeapCheck(num))
		{
			leapYear = 0;
		}

		for (int i = 0; i < 4; i++)
		{
			expiryDate[9 - i] = (num % 10) + 48;
			num /= 10;
		}

		// year done

		num = 0;
		bool ExpiryMonthCheck = 1;

		do {
			ExpiryMonthCheck = 1;

			cout << "Enter Month of Expiry : ";
			cin >> num;

			flag = 1;

			do {
				flag = 1;

				if (num < 1 || num > 12)
				{
					flag = 0;
				}

				if (flag == 0)
				{
					cout << "Enter Month of Expiry : ";
					cin >> num;
				}
			} while (flag == 0);

			int laterCheck = num;
			temp = num;

			if (yearOfExpiry == yearOfIssue)
			{
				if (num < monthOfIssue)
				{
					ExpiryMonthCheck = 0;

					cout << endl << endl << "ERROR : Enter Expiry Month which is greater than Issuance Month When Year of Issuance is same" << endl << endl;

				}
			}
		} while (ExpiryMonthCheck == 0);

		monthOfExpiry = num;

		if (num < 10)
		{
			expiryDate[3] = '0';
			expiryDate[4] = (num + 48);
		}
		else
		{
			expiryDate[4] = (num % 10) + 48;
			num /= 10;
			expiryDate[3] = num + 48;
		}

		// month done

		num = 0;
		bool ExpiryDateCheck = 1;

		do {
			ExpiryDateCheck = 1;

			cout << "Enter Date of Expiry : ";
			cin >> num;

			flag = 1;

			if (leapYear && laterCheck == 2)
			{
				do {
					flag = 1;

					if (num < 1 || num > 29)
					{
						flag = 0;
						cout << "Enter Date of Expiry : ";
						cin >> num;
					}
				} while (flag == 0);
			}
			else if (!leapYear && laterCheck == 2)
			{
				do {
					flag = 1;

					if (num < 1 || num > 28)
					{
						flag = 0;
						cout << "Enter Date of Expiry : ";
						cin >> num;
					}
				} while (flag == 0);
			}
			else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
			{
				do {
					flag = 1;

					if (num < 1 || num > 30)
					{
						flag = 0;
						cout << "Enter Date of Expiry : ";
						cin >> num;
					}
				} while (flag == 0);
			}
			else
			{
				do
				{
					flag = 1;

					if (num < 0 || num > 31)
					{
						flag = 0;
						cout << "Enter Date of Expiry : ";
						cin >> num;
					}

				} while (flag == 0);
			}

			if (yearOfExpiry == yearOfIssue)
			{
				if (monthOfExpiry == monthOfIssue)
				{
					if (num <= dateOfIssue)
					{
						ExpiryDateCheck = 0;

						cout << endl << endl << "ERROR : Enter Expiry Date which is greater than Issuance Date When Year and Month of Issuance is same" << endl << endl;
					}
				}
			}
		} while (ExpiryDateCheck == 0);


		dateOfExpiry = num;

		if (num < 10)
		{
			expiryDate[0] = '0';
			expiryDate[1] = (num + 48);
		}
		else
		{
			expiryDate[1] = (num % 10) + 48;
			num /= 10;
			expiryDate[0] = (num + 48);
		}

		// date done

		// date month year done with exception handling

		fout << CNIC << "," << issuanceDate << "," << expiryDate << "^" << endl;


	}


	fout.close();
}

bool editAllBillingInfo()
{
	fstream x;
	char data[250];
	int rowCount = 0;
	int stop = 0;
	char EntryDate[11];
	int unitsR = 0;
	int unitsP = 0;
	char ID[5];

	ID[0] = 0;
	ID[4] = 0;
	EntryDate[0] = '\0';
	EntryDate[10] = '\0';
	data[0] = '\0';

	stop = 0;

	x.open("BillingInfo.txt", ios::in);

	while (!x.eof() && stop != 1)
	{
		x.getline(data, 200);

		int commaCount = 0;

		if (data[0] != '\0' && data[0] != '^')
		{
			for (int i = 0; data[i] != '\0'; i++)
			{
				if (data[i] == ',')
				{
					commaCount++;
				}

				if (commaCount == 11 && data[i] != ',')
				{
					if (data[i] == '-')
					{
						stop = 1;
					}
				}

				if (data[i] == '^')
				{
					rowCount++;
				}
			}
		}
	}

	x.close();

	if (stop == 1)
	{
		int commaCount = 0;

		for (int i = 0; data[i] != '\0'; i++)
		{
			if (data[i] == ',')
			{
				commaCount++;
			}

			if (commaCount == 4 && data[i] != ',')
			{
				for (int j = 0; j < 10; j++)
				{
					EntryDate[j] = data[i + j];
				}

				i += 9;
			}

			if (commaCount == 2 && data[i] != ',')
			{
				unitsR = (unitsR * 10) + (data[i] - 48);
			}

			if (commaCount == 3 && data[i] != ',')
			{
				unitsP = (unitsP * 10) + (data[i] - 48);
			}

			if (commaCount == 0)
			{
				for (int j = 0; j < 4; j++)
				{
					ID[j] = data[i + j];
				}

				i += 3;
			}
		}

		int entryDate = 0;

		entryDate = (entryDate * 10) + (EntryDate[0] - 48);
		entryDate = (entryDate * 10) + (EntryDate[1] - 48);

		int entryMonth = 0;

		entryMonth = (entryMonth * 10) + (EntryDate[3] - 48);
		entryMonth = (entryMonth * 10) + (EntryDate[4] - 48);

		int entryYear = 0;

		entryYear = (entryYear * 10) + (EntryDate[6] - 48);
		entryYear = (entryYear * 10) + (EntryDate[7] - 48);
		entryYear = (entryYear * 10) + (EntryDate[8] - 48);
		entryYear = (entryYear * 10) + (EntryDate[9] - 48);

		char PaymentDate[11];

		cout << endl << endl << "Reading Date : " << EntryDate << endl << endl;

		getPaymentDate(PaymentDate, entryDate, entryMonth, entryYear);

		commaCount = 0;

		for (int i = 0; data[i] != '\0'; i++)
		{
			if (data[i] == ',' || data[i] == '^')
			{
				commaCount++;
			}

			if (commaCount == 10 && data[i] != ',')
			{
				data[i] = '1';
			}

			if (commaCount == 11 && data[i] != ',')
			{
				for (int j = 0; j < 10; j++)
				{
					data[i + j] = PaymentDate[j];
				}

				i += 9;
			}
		}


		fstream y;

		x.open("BillingInfo.txt", ios::in);
		y.open("BillingInfoCopy.txt", ios::out);

		char idk[250];
		int count = 0;

		while (!x.eof())
		{
			if (!x.eof())
			{
				x.getline(idk, 250);
				count++;

				if (idk[0] != '^' && idk[0] != '\0')
				{
					if (rowCount == count)
					{
						y << data << endl;
					}
					else
					{
						y << idk << endl;
					}
				}
			}
		}

		x.close();
		y.close();


		y.open("BillingInfo.txt", ios::out);
		x.open("BillingInfoCopy.txt", ios::in);

		count = 0;

		while (!x.eof())
		{
			if (!x.eof())
			{
				x.getline(idk, 250);
				count++;

				if (idk[0] != '^' && idk[0] != '\0')
				{
					y << idk << endl;
				}
			}
		}

		x.close();
		y.close();

		rowCount = 0;
		int Units_R = 0;
		int Units_P = 0;
		bool flag = 1;

		x.open("CustomersInfo.txt", ios::in);

		while (!x.eof() && flag)
		{
			x.getline(idk, 250);

			if (ID[0] == idk[0] && ID[1] == idk[1] && ID[2] == idk[2] && ID[3] == idk[3])
			{
				flag = 0;
				commaCount = 0;

				for (int i = 0; idk[i] != '\0'; i++)
				{
					if (idk[i] == ',')
					{
						commaCount++;
					}

					if (commaCount == 7 && idk[i] != ',')
					{
						int j = 0;

						for (; idk[j + i] != ','; j++)
						{
							Units_R = (Units_R * 10) + (idk[j + i] - 48);
						}

						i += j - 1;
					}

					if (commaCount == 8 && idk[i] != ',')
					{
						int j = 0;

						for (; idk[j + i] != ','; j++)
						{
							Units_P = (Units_P * 10) + (idk[j + i] - 48);
						}

						i += j - 1;
					}
				}
			}
		}

		x.close();

		char UnitsR_ch[10];

		int temp = 0;
		int countDigit = 0;

		temp = unitsR + Units_R;

		while (temp > 0)
		{
			temp /= 10;
			countDigit++;
		}

		temp = unitsR + Units_R;

		if (temp == 0)
		{
			UnitsR_ch[0] = '0';
			UnitsR_ch[1] = 0;
		}
		else
		{
			for (int i = 0; i < countDigit; i++)
			{
				UnitsR_ch[countDigit - i - 1] = (temp % 10) + 48;
				temp /= 10;
			}

			UnitsR_ch[countDigit] = '\0';
		}

		char UnitsP_ch[10];

		temp = 0;
		countDigit = 0;

		temp = unitsP + Units_P;

		while (temp > 0)
		{
			temp /= 10;
			countDigit++;
		}

		temp = unitsP + Units_P;

		if (temp == 0)
		{
			UnitsP_ch[0] = '0';
			UnitsP_ch[1] = 0;
		}
		else
		{
			for (int i = 0; i < countDigit; i++)
			{
				UnitsP_ch[countDigit - i - 1] = (temp % 10) + 48;
				temp /= 10;
			}

			UnitsP_ch[countDigit] = '\0';
		}

		char tempCH = 'a';

		for (int i = 0; idk[i] != '\0'; i++)
		{

			if (idk[i] == '^')
			{
				tempCH = idk[i - 1];
			}
		}

		bool flagStopCount = 1;

		flag = 0;
		commaCount = 0;

		char copy_idk[300];
		int countTextG = 0;

		for (int i = 0; idk[i] != '\0' && flagStopCount; i++)
		{
			if (idk[i] == ',')
			{
				commaCount++;
			}

			if (commaCount != 7 && commaCount != 8)
			{
				copy_idk[countTextG++] = idk[i];
			}

			if (commaCount == 7 && idk[i] != ',')
			{
				int j = 0;

				copy_idk[countTextG++] = ',';

				for (; UnitsR_ch[j] != '\0'; j++)
				{
					copy_idk[countTextG++] = UnitsR_ch[j];
				}


				while (idk[i++] != ',')
				{

				}

				i--;

				commaCount++;
			}

			if (commaCount == 8 && idk[i] != ',')
			{
				int j = 0;

				copy_idk[countTextG++] = ',';

				for (; UnitsP_ch[j] != '\0'; j++)
				{
					copy_idk[countTextG++] = UnitsP_ch[j];
				}

				while (idk[i++] != ',')
				{

				}

				i--;
				copy_idk[countTextG++] = ',';

				flagStopCount = 0;
			}
		}

		copy_idk[countTextG++] = tempCH;
		copy_idk[countTextG++] = '^';
		copy_idk[countTextG++] = '\0';

		cout << endl << endl << "Bill edited successfully" << endl << endl << endl;

		x.open("CustomersInfo.txt", ios::in);
		y.open("CustomerCopy.txt", ios::out);


		while (!x.eof())
		{
			x.getline(data, 250);


			if (ID[0] == data[0] && ID[1] == data[1] && ID[2] == data[2] && ID[3] == data[3])
			{
				y << copy_idk << endl;
			}
			else
			{
				if (idk[0] != '^' && idk[0] != '\0')
					y << data << endl;
			}
		}

		x.close();
		y.close();

		y.open("CustomersInfo.txt", ios::out);
		x.open("CustomerCopy.txt", ios::in);

		while (!x.eof())
		{
			x.getline(data, 250);

			if (data[0] != '^' && data[0] != '\0')
			{
				y << data << endl;
			}
		}

		x.close();
		y.close();

	}

	if (stop == 1)
	{
		return 1;
	}

	if (stop == 0)
	{
		return 0;
	}

}

void viewBill()
{
	fstream fin;

	fin.open("BillingInfo.txt", ios::in);
	char chh = 'a';
	int commaCount = 0;
	char data[300];
	int countText = 0;
	char customerID[5];
	char customerIDuser[5];
	char RegularUnits[10];
	char PeakUnits[10];
	char costE[10];
	char taxE[10];
	char FixedChargeE[10];
	char totalAmount[10];
	char dueDate[11];
	bool flag = 0;
	char name[50];
	char address[100];
	char phoneNumber[20];
	int customerType = 0;
	int meterType = 0;
	int FixedCharges = 0;
	int percentageTax = 0;
	int countRow = 0;
	int priceRUnits = 0;
	int pricePUnits = 0;
	char TaxFile[100];

	cout << "---------------------------------------- View Bill Mode ----------------------------------------" << endl << endl;

	cout << "Enter Customer ID : ";
	cin.getline(customerIDuser, 5);

	while (!fin.eof())
	{
		fin.getline(data, 300);


		if (data[0] == '^')
		{
			break;
		}
		else
		{



			if (data[0] == customerIDuser[0] && data[1] == customerIDuser[1] && data[2] == customerIDuser[2] && data[3] == customerIDuser[3])
			{
				int countTextLoop = 0;

				for (int i = 0; data[i] != '\0'; i++)
				{
					if (data[i] == ',')
					{
						commaCount++;

						if (commaCount == 1)
						{
							customerID[countTextLoop] = '\0';
						}

						if (commaCount == 3)
						{
							RegularUnits[countTextLoop] = '\0';
						}

						if (commaCount == 4)
						{
							PeakUnits[countTextLoop] = '\0';
						}

						if (commaCount == 10)
						{
							dueDate[countTextLoop] = '\0';
						}

						if (commaCount == 6)
						{
							costE[countTextLoop] = '\0';
						}

						if (commaCount == 7)
						{
							taxE[countTextLoop] = '\0';
						}

						if (commaCount == 8)
						{
							FixedChargeE[countTextLoop] = '\0';
						}

						if (commaCount == 9)
						{
							totalAmount[countTextLoop] = '\0';
						}

						countTextLoop = 0;
					}

					if (commaCount == 0 && data[i] != ',')
					{
						customerID[countTextLoop++] = data[i];
					}

					if (commaCount == 2 && data[i] != ',')
					{
						RegularUnits[countTextLoop++] = data[i];
					}

					if (commaCount == 3 && data[i] != ',')
					{
						PeakUnits[countTextLoop++] = data[i];
					}

					if (commaCount == 9 && data[i] != ',')
					{
						dueDate[countTextLoop++] = data[i];
					}

					if (commaCount == 5 && data[i] != ',')
					{
						costE[countTextLoop++] = data[i];
					}

					if (commaCount == 6 && data[i] != ',')
					{
						taxE[countTextLoop++] = data[i];
					}

					if (commaCount == 7 && data[i] != ',')
					{
						FixedChargeE[countTextLoop++] = data[i];
					}

					if (commaCount == 8 && data[i] != ',')
					{
						totalAmount[countTextLoop++] = data[i];
					}
				}

				flag = 1;
			}

			countText = 0;
			commaCount = 0;

		}
	}

	if (flag)
		//cout << customerID << "  " << RegularUnits << "  " << PeakUnits << "  " << costE << "  " << taxE << "  " << FixedChargeE << "  " << totalAmount << "  " << dueDate << endl;

		fin.close();

	for (int i = 0; i < 300; i++)
	{
		data[i] = 'a';
	}

	// now customer info file

	bool stopCheckC = 1;
	countText = 0;

	if (flag == 1)
	{
		fin.open("CustomersInfo.txt", ios::in);

		while (!fin.eof())
		{
			fin.getline(data, 300);


			if (data[0] == '^')
			{
				break;
			}
			else
			{

				if (data[0] == customerIDuser[0] && data[1] == customerIDuser[1] && data[2] == customerIDuser[2] && data[3] == customerIDuser[3])
				{

					int countTextLoop = 0;
					stopCheckC = 0;

					for (int i = 0; data[i] != '\0'; i++)
					{
						if (data[i] == ',')
						{
							commaCount++;

							if (commaCount == 3)
							{
								name[countTextLoop] = '\0';
							}

							if (commaCount == 4)
							{
								address[countTextLoop] = '\0';
							}

							if (commaCount == 5)
							{
								phoneNumber[countTextLoop] = '\0';
							}

							countTextLoop = 0;
						}

						if (commaCount == 2 && data[i] != ',')
						{
							name[countTextLoop++] = data[i];
						}

						if (commaCount == 3 && data[i] != ',')
						{
							address[countTextLoop++] = data[i];
						}


						if (commaCount == 4 && data[i] != ',')
						{
							phoneNumber[countTextLoop++] = data[i];
						}

						if (commaCount == 9 && data[i] != ',' && data[i] != '^')
						{
							customerType = data[i] - 48;
						}

						if (commaCount == 5 && data[i] != ',')
						{
							meterType = data[i] - 48;
						}
					}
				}

				countText = 0;
				commaCount = 0;
			}
		}

		for (int i = 0; name[i] != '\0'; i++)
		{
			if (name[i] == '?')
			{
				name[i] = 32;
			}
		}

		for (int i = 0; address[i] != '\0'; i++)
		{
			if (address[i] == '?')
			{
				address[i] = 32;
			}

			if (address[i] == '%')
			{
				address[i] = ',';
			}
		}

		fin.close();

		//cout << endl << endl << name << "  " << address << "  " << phoneNumber << "  " << customerType << "  " << meterType << endl;

		fin.open("TariffTaxInfo.txt", ios::in);

		int rowcountTax = 0;
		int rowToCheck = 0;

		if (meterType == 1 && customerType == 1)
		{
			rowToCheck = 1;
		}
		else if (meterType == 1 && customerType == 2)
		{
			rowToCheck = 2;
		}
		else if (meterType == 3 && customerType == 1)
		{
			rowToCheck = 3;
		}
		else if (meterType == 3 && customerType == 2)
		{
			rowToCheck = 4;
		}

		countRow = 0;
		commaCount = 0;


		while (!fin.eof())
		{
			fin >> chh;

			TaxFile[countRow++] = chh;

			if (chh == '^')
			{
				rowcountTax++;
				TaxFile[countRow] = '\0';
				countRow = 0;

				if (rowToCheck == rowcountTax)
				{
					for (int i = 0; TaxFile[i] != '^'; i++)
					{
						if (TaxFile[i] == ',')
						{
							commaCount++;
						}

						if (commaCount == 1 && TaxFile[i] != ',' && TaxFile[i] != '^')
						{
							if (TaxFile[i - 1] != ',')
							{
								priceRUnits = priceRUnits * 10;
								priceRUnits = priceRUnits + (TaxFile[i] - 48);
							}
							else if (TaxFile[i - 1] == ',')
							{
								priceRUnits = TaxFile[i] - 48;
							}
						}

						if (commaCount == 2 && meterType == 3 && TaxFile[i] != ',' && TaxFile[i] != '^')
						{

							if (TaxFile[i - 1] != ',')
							{
								pricePUnits = pricePUnits * 10;
								pricePUnits = pricePUnits + (TaxFile[i] - 48);
							}
							else if (TaxFile[i - 1] == ',')
							{
								pricePUnits = TaxFile[i] - 48;
							}
						}

						if (commaCount == 3 && TaxFile[i] != ',' && TaxFile[i] != '^')
						{

							if (TaxFile[i - 1] != ',')
							{
								percentageTax = percentageTax * 10;
								percentageTax = percentageTax + (TaxFile[i] - 48);
							}
							else if (TaxFile[i - 1] == ',')
							{
								percentageTax = TaxFile[i] - 48;
							}
						}

						if (commaCount == 4 && TaxFile[i] != ',' && TaxFile[i] != '^')
						{

							if (TaxFile[i - 1] != ',')
							{
								FixedCharges = FixedCharges * 10;
								FixedCharges = FixedCharges + (TaxFile[i] - 48);
							}
							else if (TaxFile[i - 1] == ',')
							{
								FixedCharges = TaxFile[i] - 48;
							}
						}
					}
				}

			}


		}

		//cout << endl << endl << priceRUnits << "  " << pricePUnits << "  " << FixedCharges << "  " << percentageTax << endl;

		fin.close();
	}

	if (flag == 1)
	{
		system("cls");

		cout << "---------------------------------------- View Bill Mode ----------------------------------------" << endl << endl;

		cout << "------------------------------------------------------------------------------------------------" << endl;

		cout << "|                                                                                              |" << endl;

		cout << "|                                        Customer Info                                         |" << endl;

		cout << "|                                                                                              |" << endl;

		cout << "------------------------------------------------------------------------------------------------" << endl << endl;

		cout << "Customer ID : " << customerID << "\t\t\t" << "Customer Name : " << name << endl << endl;

		cout << "Customer Adress : " << address << endl << endl;

		cout << "Phone Number : " << phoneNumber << endl << endl;

		cout << "Meter Type : ";

		if (meterType == 1)
		{
			cout << "1 Phase";
		}
		else if (meterType == 3)
		{
			cout << "3 Phase";
		}

		cout << "\t\t\t" << "Customer Type : ";

		if (customerType == 1)
		{
			cout << "Domestic";
		}
		else if (customerType == 2)
		{
			cout << "Commercial";
		}

		cout << endl << endl;


		cout << "-----------------------------------------------------------------------------------------------" << endl;

		cout << "|                                                                                              |" << endl;

		cout << "|                                         Tarrif Info                                          |" << endl;

		cout << "|                                                                                              |" << endl;

		cout << "------------------------------------------------------------------------------------------------" << endl << endl;


		cout << "Regular Unit Price : " << priceRUnits << "\t\t\t";

		if (meterType == 3)
		{
			cout << "Peak Unit Price : " << pricePUnits;
		}

		cout << endl << endl;

		cout << "Fixed Charges : " << FixedCharges << "\t\t\t" << "Tax Percentage : " << percentageTax << endl << endl;



		cout << "------------------------------------------------------------------------------------------------" << endl;

		cout << "|                                                                                              |" << endl;

		cout << "|                                      Current Bill Info                                       |" << endl;

		cout << "|                                                                                              |" << endl;

		cout << "------------------------------------------------------------------------------------------------" << endl << endl;


		cout << "Cost of Electricity : " << costE << "\t\t" << "Tax Applied : " << taxE << "\t\t" << "Fixed Charges : " << FixedChargeE << endl << endl;

		cout << "Total Bill Amount : " << totalAmount << "\t\t";

		cout << "Total Regular Units Used : " << RegularUnits << "\t   ";

		if (meterType == 3)
		{
			cout << "Total Peak Units Used : " << PeakUnits;
		}

		cout << endl << endl;

		cout << "Due Date : " << dueDate << endl << endl;
	}

	if (flag == 0)
	{
		cout << endl << endl << "Customer does not Exist";
	}

	cout << endl << endl;

	cout << "Press any key to continue";

	_getch();

	cout << endl << endl;

	cout << "Exiting in ";

	for (int i = 3; i > 0; i--)
	{
		cout << i << "  ";

		Sleep(1000);
	}
}

void editCustomerInfoFile()
{

char customerIDuser[20];
bool flag = 1;
char ch;

do
{
	flag = 1;

	for (int i = 0; i < 20; i++)
	{
		customerIDuser[i] = 'a';
	}

	cout << "Enter customer ID you want to edit : ";
	cin.getline(customerIDuser, 20);
	



	if (customerIDuser[0] == 'a' || customerIDuser[1] == 'a' || customerIDuser[2] == 'a' || customerIDuser[3] == 'a')
	{
		flag = 0;
	}

	if (flag && customerIDuser[4] != '\0')
	{
		flag = 0;
	}

} while (flag == 0);

//convert customer ID to num for row check

int IDinNum = 0;

for (int i = 0; i < 4; i++)
{
	IDinNum = (customerIDuser[i] - 48) + (IDinNum * 10);
}

// done

// get data of required line

	fstream edit;
	char data[200];
	edit.open("CustomersInfo.txt", ios::in);
	int rowCount = 0;
	int countText = 0;
	flag = 1;

	for (int i = 0; i < 200; i++)
	{
		data[i] = '=';
	}

	while (!edit.eof() && flag)
	{
		edit >> ch;

		if (rowCount == IDinNum - 1)
		{
			data[countText++] = ch;
		}

		if (ch == '^')
		{
			data[countText] = '\0';

			if (rowCount == IDinNum - 1)
			{
				flag = 0;
			}

			rowCount++;
		}


	}



	// done

	// ask what to edit

	if (data[3] != '=')
	{

		int choice = 0;

		do
		{
			cout << "Enter 1 to edit Name " << endl;
			cout << "Enter 2 to edit Address " << endl;
			cout << "Enter 3 to edit Phone Number " << endl;
			cout << "Enter 4 to edit Connection Date " << endl;

			cout << "Enter any of the Above : ";
			cin >> choice;

		} while (choice < 1 && choice > 4);

		char copy_data[150];

		switch (choice)
		{
		case 1:
		{

			//Name Input

			char name[50]; // no numbers

			cout << "Enter Name : ";

			cin.ignore();

			cin.getline(name, 50);
			

			for (int i = 0; name[i] != '\0'; i++)
			{
				if (name[i] == 32)
				{
					name[i] = '?';
				}
			}

			//Name input end

			int commaCount = 0;
			countText = 0;
			bool flagStopCopyLoop = 1;

			for (int i = 0; data[i] != '\0'; i++)
			{
				if (commaCount != 2)
				{
					copy_data[countText++] = data[i];
				}

				if (commaCount == 2 && flagStopCopyLoop)
				{
					for (int k = 0; name[k] != '\0'; k++)
					{
						copy_data[countText++] = name[k];
					}

					copy_data[countText++] = ',';

					flagStopCopyLoop = 0;
				}

				if (data[i] == ',')
				{
					commaCount++;
				}

			}

			copy_data[countText] = '\0';
		}
		break;
		case 2:
		{
			//Address Input

			char address[100];	// no comma in address // if(address[i] == ',') { cout << "no comma to be used" })

			cout << "Enter Address : ";
			
			cin.getline(address, 100);
			

			flag = 1;

			for (int i = 0; address[i] != '\0'; i++)
			{
				if (address[i] == ',')
				{
					address[i] = '%';
				}

				if (address[i] == 32)
				{
					address[i] = '?';
				}
			}


			//Adreess input end

			int commaCount = 0;
			countText = 0;
			bool flagStopCopyLoop = 1;

			for (int i = 0; data[i] != '\0'; i++)
			{
				if (commaCount != 3)
				{
					copy_data[countText++] = data[i];
				}

				if (commaCount == 3 && flagStopCopyLoop)
				{
					for (int k = 0; address[k] != '\0'; k++)
					{
						copy_data[countText++] = address[k];
					}

					copy_data[countText++] = ',';

					flagStopCopyLoop = 0;
				}

				if (data[i] == ',')
				{
					commaCount++;
				}

			}

			copy_data[countText] = '\0';
		}
		break;
		case 3:
		{
			//number Input

			char number[15]; // no alphabets letter

			cout << "Enter Contact Number : ";
			
			cin.getline(number, 15);
			

			flag = 1;

			do {
				flag = 1;

				for (int i = 0; number[i] != '\0' && flag; i++)
				{
					if (i == 0)
					{
						if (number[i] < 48 || number[i] > 57)
						{
							flag = 0;
						}

						if (number[i] == '+')
						{
							flag = 1;
						}
					}
					else
					{
						if (number[i] < 48 || number[i] > 57)
						{
							flag = 0;
						}
					}
				}

				if (flag == 0)
				{
					cout << "Enter Contact Number : ";
					cin.getline(number, 15);
					
				}

			} while (flag == 0);

			//number input end

			int commaCount = 0;
			countText = 0;
			bool flagStopCopyLoop = 1;

			for (int i = 0; data[i] != '\0'; i++)
			{
				if (commaCount != 4)
				{
					copy_data[countText++] = data[i];
				}

				if (commaCount == 4 && flagStopCopyLoop)
				{
					for (int k = 0; number[k] != '\0'; k++)
					{
						copy_data[countText++] = number[k];
					}

					copy_data[countText++] = ',';

					flagStopCopyLoop = 0;
				}

				if (data[i] == ',')
				{
					commaCount++;
				}

			}

			copy_data[countText] = '\0';
		}
		break;
		case 4:
		{
			//Connection date input

			char connectionDate[11];

			connectionDate[2] = connectionDate[5] = '/';
			connectionDate[10] = '\0';

			int num = 0;

			cout << "Enter Year of Connection : ";
			cin >> num;
			int temp = num;
			int countDigit = 0;

			while (temp > 0)
			{
				temp = temp / 10;
				countDigit++;
			}

			if (countDigit != 4)
			{
				do {

					cout << "Enter Year of Connection : ";
					cin >> num;
					temp = num;
					countDigit = 0;

					while (temp > 0)
					{
						temp /= 10;
						countDigit++;
					}

				} while (countDigit != 4);
			}


			bool leapYear = 1;

			if (!LeapCheck(num))
			{
				leapYear = 0;
			}

			for (int i = 0; i < 4; i++)
			{
				connectionDate[9 - i] = (num % 10) + 48;
				num /= 10;
			}

			//year done

			num = 0;

			cout << "Enter Month of Connection : ";
			cin >> num;

			flag = 1;

			do {
				flag = 1;

				if (num < 1 || num > 12)
				{
					flag = 0;
				}

				if (flag == 0)
				{
					cout << "Enter Month of Connection : ";
					cin >> num;
				}
			} while (flag == 0);

			int laterCheck = num;
			temp = num;

			if (num < 10)
			{
				connectionDate[3] = '0';
				connectionDate[4] = (num + 48);
			}
			else
			{
				connectionDate[4] = (num % 10) + 48;
				num /= 10;
				connectionDate[3] = num + 48;
			}

			//month done

			num = 0;

			cout << "Enter Date of Connection : ";
			cin >> num;

			flag = 1;

			if (leapYear && laterCheck == 2)
			{
				do {
					flag = 1;

					if (num < 1 || num > 29)
					{
						flag = 0;
						cout << "Enter Date of Connection : ";
						cin >> num;
					}
				} while (flag == 0);
			}
			else if (!leapYear && laterCheck == 2)
			{
				do {
					flag = 1;

					if (num < 1 || num > 28)
					{
						flag = 0;
						cout << "Enter Date of Connection : ";
						cin >> num;
					}
				} while (flag == 0);
			}
			else if (laterCheck == 4 || laterCheck == 6 || laterCheck == 9 || laterCheck == 11)
			{
				do {
					flag = 1;

					if (num < 1 || num > 30)
					{
						flag = 0;
						cout << "Enter Date of Connection : ";
						cin >> num;
					}
				} while (flag == 0);
			}
			else
			{
				do
				{
					flag = 1;

					if (num < 0 || num > 31)
					{
						flag = 0;
						cout << "Enter Date of Connection : ";
						cin >> num;
					}

				} while (flag == 0);
			}

			if (num < 10)
			{
				connectionDate[0] = '0';
				connectionDate[1] = (num + 48);
			}
			else
			{
				connectionDate[1] = (num % 10) + 48;
				num /= 10;
				connectionDate[0] = (num + 48);
			}

			//date done

			//date month year done with exception handling

			int commaCount = 0;
			countText = 0;
			bool flagStopCopyLoop = 1;

			for (int i = 0; data[i] != '\0'; i++)
			{
				if (commaCount != 6)
				{
					copy_data[countText++] = data[i];
				}

				if (commaCount == 6 && flagStopCopyLoop)
				{
					for (int k = 0; connectionDate[k] != '\0'; k++)
					{
						copy_data[countText++] = connectionDate[k];
					}

					copy_data[countText++] = ',';

					flagStopCopyLoop = 0;
				}

				if (data[i] == ',')
				{
					commaCount++;
				}

			}

			copy_data[countText] = '\0';

		}
		break;
		}


		edit.close();

		fstream f1;
		fstream f2;

		f1.open("CustomersInfo.txt", ios::in);
		f2.open("CopyCustomerInfo.txt", ios::out);
		countText = 0;
		rowCount = 0;


		while (!f1.eof())
		{
			f1 >> ch;

			data[countText++] = ch;

			if (ch == '^' && data[0] != '^')
			{
				rowCount++;

				data[countText] = '\0';

				countText = 0;

				if (rowCount == IDinNum)
				{
					f2 << copy_data << endl;
				}
				else
				{
					f2 << data << endl;
				}
			}
		}

		f1.close();
		f2.close();

		f2.open("CustomersInfo.txt", ios::out);
		f1.open("CopyCustomerInfo.txt", ios::in);

		while (!f1.eof())
		{
			f1.getline(data, 200, '\n');

			if (data[0] != '^')
			{
				f2 << data << endl;
			}
		}
	}
	else
	{

		cout << endl << endl << "Customer not found with such Customer ID" << endl;
	}

}

