#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include <ctime>
 
#include "doctorheader.h"
#include "patientheader.h"
#include"MainFunctions.h"
using namespace std;


int main()
{

	char x = '0';

	while (x != '4')
	{

		cout << "\n\n\n\n\t\t\t\t\t*****************************************************************************\n"
			"\t\t\t\t\t*****************************************************************************\n"
			"\t\t\t\t\t****************************************************************************\n"
			"\t\t\t\t\t************************************     ************************************\n"
			"\t\t\t\t\t*******************************               *******************************\n"
			"\t\t\t\t\t*************************                           *************************\n"
			"\t\t\t\t\t******************* Coded by Bilal AL-Massry && Hamodeh *********************\n"
			"\t\t\t\t\t*************************                           *************************\n"
			"\t\t\t\t\t*******************************               *******************************\n"
			"\t\t\t\t\t************************************     ************************************\n"
			"\t\t\t\t\t*****************************************************************************\n"
			"\t\t\t\t\t*****************************************************************************\n"
			"\t\t\t\t\t*****************************************************************************\n" << endl;
			//system("cls");
		cout << "What type you want to add:\n1-Doctor\n2-Edit/Add Patient\n3-Close\t";
		cin >> x;
		switch (x)
		{
		case '1':
			system("cls");
			doctor_linkedlist.insert(Input_Doctor_Info());
				break;
		case '2':
		{
			patient_list.insert(Input_patient_Info());
			system("cls");
			patient_list.printlinkedlist();
				break;
			}
		case '3': {
			system("cls");
			system("pause");
			return 0;
			break; }
		default:
			cout << "\nWrong choice, select one of the statments above:  ";
			break;
		}
		}
	
	return  0;
}

