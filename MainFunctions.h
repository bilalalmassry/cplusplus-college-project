#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
using namespace std;
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include <ctime>
#include<sstream>
#include<stdio.h>
#include "doctorheader.h"
#include "patientheader.h"
linked_list doctor_linkedlist;
patient_linkedlist patient_list;

int Intger_input() {
	string a;
	int Intgervar;
	stringstream Intger;
	//cin.clear();
	bool check = 0;
	do
	{
		getline(cin, a);
		int len = a.length();
		check = 0;
		for (int i = 0; i<len; i++)
		{
			if (!isdigit(a[i]) || a[i] == '\n')
			{
				if (a[i] == '.' || a[i] == ',')
					cout << "\nYou Entered invalid character like '.' or ',' " << endl;
				check = 1;
				break;
			}
		}
		if (check == 0)
		{
			Intger << a;
			Intger >> Intgervar;
			return Intgervar;
		}
	} while (check, cout << "Error Input: Make sure That your Input is an Integer" << endl);
	return NULL;
}

bool checkdate(int x, int nowyear, int *d, int *m, int *y)
{
	if (x == 1)
	{if (((nowyear - 90) >= *y) || (*y >= (nowyear - 23)))//comment these 2 lines out if it bothers you
			return false;
		}
	else
		if (((nowyear - 110) >= *y) || (*y >= (nowyear - 0)))//comment these 2 lines out if it bothers you
			return false;
	if (!(1 <= *m && *m <= 12))
		return false;
	if (!(1 <= *d && *d <= 31))
		return false;
	if ((*d == 31) && (*m == 2 || *m == 4 || *m == 6 || *m == 9 || *m == 11))
		return false;
	if ((*d == 30) && (*m == 2))
		return false;
	if ((*m == 2) && (*d == 29) && (*y % 4 != 0))
		return false;
	if ((*m == 2) && (*d == 29) && (*y % 400 == 0))
		return true;
	if ((*m == 2) && (*d == 29) && (*y % 100 == 0))
		return false;
	if ((*m == 2) && (*d == 29) && (*y % 4 == 0))
		return true;

	return true;
}

void getdate(int x,int *d, int *m, int *y) {
	time_t now;
	struct tm nowlocal;
	now = time(NULL);
	nowlocal = *localtime(&now);
	do {
		fflush(stdin);
		cout << "day:  ";
		 *d = Intger_input();
		cout << "Month:  ";
			*m = Intger_input();
		cout << "Year:  ";
		 *y = Intger_input();
		 if(checkdate(x,nowlocal.tm_year + 1900, d, m, y) == 0)
			 cout << "Error: Something Wrong with your date ^_^ try Again:  ";
	} while (checkdate(x,nowlocal.tm_year + 1900, d, m, y) == 0);
}



string Input_Name()
{
	string a;
	bool check = 0;
	do
	{
		do
		{
			getline(cin, a);
		} while (a.length() > 40 && a.length() <4);
		check = 0;
		for (int i = 0; i < (a.length()); i++)
		{
			if (isdigit(a[i]) || ispunct(a[i]))
			{
				check = 1;
				break;
			}
		}
		if (!check)
			return a;
	} while (check == 1, cout << "Input Error: Name should have Only alpha characters ^_^\n");
	return NULL;
}


doctor *Input_Doctor_Info() {
	int type = 0 ,id = 0 ,day =0 ,month =0 ,year = 0,salary = 0;
	date d0;
	string name, address;
	cout << "1- Inside Doctor \n2-Training Doctor \n3-Contracting Doctor\n4-Print A Specific Doctor/Doctors\n5-Back\n6-eixt\n" << endl;
	cin.ignore(100, '\n');
	while (type != 5) {
		type = Intger_input();
		switch (type)
		{
		case 1: {
			cout << "\nid = ";
			id = Intger_input();
			cout << "\nName: ";
			name = Input_Name();
			cout << "\nAddress: ";
			getline(cin, address);
			getdate(1,&day, &month, &year);
			d0.set_date(day, month, year);
			cout << "His section: ";
			int sectionnumber;
			sectionnumber = Intger_input();
			cout << "\nHis month salary";
			salary = Intger_input();
			doctor *doctorinside1 = new doctorinside(id, name, address, d0, sectionnumber, salary, type);
			//		doctorinside1->doctor_print_info();
			return doctorinside1;
			break;
		}
		case 2: {
			cout << "\nid = ";
			id = Intger_input();
			cout << "\nName: ";
			name = Input_Name();
			cout << "\nAddress: ";
			getline(cin, address);
			getdate(1,&day, &month, &year);
			d0.set_date(day, month, year);
			cout << "\nHis month salary";
			salary = Intger_input();
			date d1, d2;
			cout << "1-is he still training\n2-he is not";
			int isstilltraining;
			do {
				isstilltraining = Intger_input();
				switch (isstilltraining)
				{
				case 1: {
					getdate(2,&day, &month, &year);
					d1.set_date(day, month, year);
					getdate(2,&day, &month, &year);
					d2.set_date(day, month, year);
					break; }
				case 2: {
					getdate(2,&day, &month, &year);
					d1.set_date(day, month, year);
					break;
				}
				default: {
					cout << "Invalid input.  Try again:";
					break; }
				}
			} while (isstilltraining != 1 && isstilltraining != 2);
			doctor *doctortraining1 = new doctortraining(id, name, address, type, salary, d0, d1, d2);
			//doctor_linkedlist.insert(doctortraining1);
			return doctortraining1;
			break;
		}
		case 3: {
			cout << "\nid = ";
			id = Intger_input();
			cout << "\nName: ";
			name = Input_Name();
			cout << "\nAddress: ";
			getline(cin, address);
			getdate(1,&day, &month, &year);
			d0.set_date(day, month, year);
			cout << "\nHis total salary";
			salary = Intger_input();
			cout << "\ndate of start contracting\t ";
			getdate(2,&day, &month, &year);
			date d3(day, month, year);
			doctor *doctorcontracting1 = new doctorcontracting(id, name, address, type, salary, d0, d3);
			return doctorcontracting1;
			break;
		}
	
		
		case 4: {
			int x = 0;
			cout << "1-Print All types of Docotr\n2-Print internal Doctors\n3-Print training Doctors\n4-Print Contracted Doctors\n5-Back" << endl;
			while (x != 5)
			{
				x = Intger_input();
				switch (x)
				{
				case 1:
					doctor_linkedlist.printlinkedlist();
					return nullptr;
					break;
				case 2:
					cout << "Enternal Doctors\n";
					doctor_linkedlist.print_spacific_linkedlist(x-1);
					return nullptr;
					break;
				case 3:
					cout << "training Doctors\n";
					doctor_linkedlist.print_spacific_linkedlist(x-1);
					return nullptr;
					break;
				case 4:
					cout << "Contracted Doctors\n";
					doctor_linkedlist.print_spacific_linkedlist(x-1);
					return nullptr;
					break;
				case 5:
					return nullptr;
					break;
				default:
					cout << "Error in Input, try again\n";
					break;
				}
			}

			break;
		}
		case 5: {
			return nullptr;
			break;
		}
		case 6: {
			exit(-1);
			break;
		}
		default: {
			system("cls");
			cout << "\nEnter the statment number: ";
			break;
		}

		}//switch

	}//While


	return nullptr;


}


/****************************************************************************
*****************************************************************************
*****************************************************************************
*****************in/ex Treatment and Input Patient Info *********************
*****************************************************************************
*****************************************************************************
*****************************************************************************
*****************************************************************************
*****************************************************************************/
// ÈÊÑÌÚ ÓÌá ãÚÇáÌÉ ÎÇÑÌíÉ ÎÇáÕ
externaltreatment* extre() {
	cout << "treatment id  ";
	int treatmentid = Intger_input();
	cout << "cost  ";
	int cost = Intger_input();
	int day, month, year;
	cout << "Date of Treatment: ";
	getdate(2,&day, &month, &year);
	date d1(day, month, year);
	cout << "Clinic Number:  ";
	int clinicnumber = Intger_input();
	cout << "His Doctor Id:  ";
	int treatment_doctorid;
	do {
		treatment_doctorid = Intger_input();
		} while (!doctor_linkedlist.searchlinkedlist(treatment_doctorid));
	externaltreatment externaltreatment1(treatmentid, cost, clinicnumber, treatment_doctorid, d1);
	externaltreatment *e = new externaltreatment;
	*e = externaltreatment1;
	return e;
}

//ÈÊÑÌÚ ÓÌá ãÚÇáÌÉ ÏÇÎáíÉ ÎÇáÕ
internaltreatment* intre() {
	cout << "treatment id  ";
	int treatmentid = Intger_input();
	cout << "cost  ";
	int cost = Intger_input();
	int day, month, year;
	cout << "Date of Treatment: ";
	getdate(2,&day, &month, &year);
	date d1(day, month, year);
	cout << "Enter The section Number \n1-Es3af\n2-eye\n3-sadree\n4-gera7a" << endl;
	int sectionnum = Intger_input();
	cout << "1-he exited\t2-he is not\t";
	int exitstutes;
	int d, y, m;
	date d2;
	
	do {
		exitstutes = Intger_input();
		switch (exitstutes)
		{
		case 1: {
			getdate(2,&d, &m, &y);
			d2.set_date(d, m, y);
			exitstutes = 1;
			break; }
		case 2: {
			exitstutes = 0;
			break;
		}
		default: {
			cout << "Invalid input.  Try again:";
			break; }
		}
	} while (exitstutes != 0 && exitstutes != 1);
	cout << "Number of Doctors: ";
	int numberofdoctors = Intger_input();
	int x;
	treatment_internal_list_id id_list;
	for (int i = 0; i < numberofdoctors; i++) {
		cout << "Doctor number" << i + 1 << "  ";
		cin >> x;
		if (doctor_linkedlist.searchlinkedlist(x))
			id_list.insert(x);
		else { cout << "We Don't Know this Doctor ... You Should Selecte one of our Doctors  "; i--; }
	}
	internaltreatment internaltreatment1(treatmentid, cost, sectionnum, d1, d2, numberofdoctors, id_list);
	internaltreatment *e = new internaltreatment;
	*e = internaltreatment1;
	return e;
}

//ÈÊÚÈÆÉ ãÑíÖ ÎÇÑÌí ÎÇáÕ
external_patient *Input_external_patient(int *patientid, string patientname, string patientaddress, date *patientbirhtday) {
	cout << "Enter patient id  ";
	*patientid = Intger_input();
	cout << "Enter patient Name  ";
	patientname = Input_Name();
	cout << "Enter patient address ";
	getline(cin, patientaddress);
	int d, y, m;
	getdate(2,&d, &m, &y);
	patientbirhtday->set_date(d, m, y);
	external_treatment_lists etl;
	etl.insert_external(extre());
	bool accepted = 0;
	external_patient external_patient1(*patientid, patientname, patientaddress, *patientbirhtday, accepted, etl);
	external_patient *ep = new external_patient;
	*ep = external_patient1;
	return ep;
}

//ÈÊÚÈí ãÑíÖ ÏÇÎáí ÎÇáÕ
internal_patient *Input_internal_patient(int *patientid, string patientname, string patientaddress, date *patientbirhtday) {
	cout << "Enter patient id  ";
	*patientid = Intger_input();
	cout << "Enter patient Name  ";
	patientname = Input_Name();
	cout << "Enter patient address ";
	getline(cin, patientaddress);
	int d, y, m;
	getdate(2,&d, &m, &y);
	patientbirhtday->set_date(d, m, y);
	date d2;
	cout << "1-he exit stutes\t2-he is not\t";
	int exitstutes = 0;
	do {
		exitstutes = Intger_input();
		switch (exitstutes)
		{
		case 1: {
			exitstutes = true;
			break; }
		case 2: {
			exitstutes = false;
			break;
		}
		default: {
			cout << "Invalid input.  Try again:";
			break; }
		}
	} while (exitstutes != true && exitstutes != false);
	external_treatment_lists etl;
	internal_treatment_lists itl;
	itl.insert_internal(intre());
	internal_patient internalpatient1(*patientid, patientname, patientaddress, *patientbirhtday, exitstutes, etl, itl);
	internal_patient *p = new internal_patient;
	*p = internalpatient1;
	return p;
}


//ÈÊÚÈí ãÑíÖ  ÈÔßá ßÇãáÈíÊã ÇÓÊÏÚÇåÇ ãÈÇÔÑÉğ
patient *Input_patient_Info() {
	int type = 0, patientid = 0 ;
	string patientname, patientaddress;
	date patientbirhtday;

	
	while (type != 8)
	{

		cout << "1-Internal Patient\n2-External Patient\n3-Move External Patient to Internal\n4-Input a Treatment to patient\n5-print patient\n6-exit an internal patient\n7-Find the number of patient between tow date\n8-Back\n";
		cin.ignore(100, '\n');
		type = Intger_input();
		switch (type)
		{
		case 1:
		{
			system("cls");
			internal_patient internal_patient1 = *Input_internal_patient(&patientid, patientname, patientaddress, &patientbirhtday);
			internal_patient *ip = new internal_patient;
			*ip = internal_patient1;
			ip->print_patient_info();
			return ip;
			break;
		}
		case 2:
		{
			system("cls");
			external_patient external_patient1 = *Input_external_patient(&patientid, patientname, patientaddress, &patientbirhtday);
			external_patient *ep = new external_patient;
			*ep = external_patient1;
			//ep->print_patient_info();
			return ep;
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Enter the patient Id:  ";
			int search = Intger_input();
			if (patient *get = (patient_list.get_external_by_id(search)))
			{
				patient *swap = new patient;
				swap = get;
				bool exitstutes = 0;
				internal_treatment_lists itl;
				itl.insert_internal(intre());
				internal_patient *newp = new internal_patient(swap->get_patient_id(), swap->get_name(), swap->get_address(), swap->get_date(),exitstutes, swap->get_list() , itl);
				patient_list.delete_linked_list(search);
				return newp;
			}
			


			break;
		}
		case 4:
		{
			system("cls");
			cout << "Enter the Patient Id to add  a treatment\n";
			patientid = Intger_input();
			patient *p = nullptr;
			if ((p = patient_list.get_patient_by_id(patientid)) != nullptr)
			{
				if (p->get_patient_type() == 1)
				{
					cout << "1-Add internal tratment\n2-external treatment\n";
					int l = 0;
					while (l != 3)
					{
						switch (l)
						{
						case 1:
							p->add_in_tretment(intre());
							break;
						case 2:
							p->add_ex_tretment(extre());
							break;
						case 3:
							break;
						default:
							cout << "Error Input";
							break;
						}
					}
				
					
				}

				else if (p->get_patient_type() == 2) {
					cout << "you are going to Add external treatment\n";
					p->add_ex_tretment(extre());
				}
				break;
			}

			

		}
		case 5: {
			system("cls");
			patient_list.printlinkedlist();
			break;
		}
		case 6:{
			system("cls");
			cout << "Enter the Patient Id to exit him\n";
			patientid = Intger_input();
			patient *p = nullptr;
			if ((p = patient_list.get_patient_by_id(patientid)) != nullptr)
			{
				if (p->get_patient_type() == 1)
					p->set_exitstutes();
				else
				cout << "this is a external patient\n";
			}
			break;
		}
		case 7: {
			date d1, d2;
			int day, year, month;
			bool c = true;
			int section;
			do
			{
				
				cout << "Section Number" << endl;
				
					section = Intger_input();
				cout << "First Date:\n";
				getdate(2, &day, &month, &year);
				d1.set_date(day, month, year);
				cout << "Second Date:\n";
				getdate(2, &day, &month, &year);
				d2.set_date(day, month, year);
				if (d2.get_year() < d1.get_year())
					c = false;
				else if (d2.get_year() == d1.get_year())
				{
					if (d2.get_month() < d1.get_month())
						c = false;
					else if (d2.get_month() == d1.get_month())
					{
						if (d2.get_day() < d1.get_day())
							c = false;
						else if (d2.get_day() == d1.get_day())
							c = false;
					}
				}
			} while (c == false);
			patient_list.get_betwwn_dates(section,d1, d2);
			
			break;
		}
		case 8:
		{
			return nullptr;
			break;
		}
		default:
			break;
		}
	}
	return nullptr;
}





#endif