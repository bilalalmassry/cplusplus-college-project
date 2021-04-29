#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include "patientheader.h"
#include "treatment.h"
#include"Helper.h"
#ifndef DOCTORHEADER_H
#define DOCTORHEADER_H




class doctor
{
protected:
	int doctorid;
	string doctorname;
	string doctoraddress;
	date doctorbirthday;
	int type;
	
	
public:
	doctor *next;
	doctor() :doctorbirthday()
	{
		doctorid = 0;
		doctoraddress = doctorname = "";
		type = -1;
		next = NULL;
	}
	doctor(int id, string name, string address, int type, date &d0) :doctorbirthday(d0)
	{
		doctorid = id;
		doctoraddress = address;
		doctorname = name;
		this->type = type;
	}
	~doctor() {}
	virtual   void  doctor_print_info()
	{
		cout << "Doctor: " << doctorname << "  |  ";
		cout <<"Id:  "<< doctorid << "  |  Address:  " << doctoraddress << "  |  ";
		doctorbirthday.printdate();
	}
	int get_doctor_id()
	{
		return doctorid;
	}
	int get_type()
	{
		return type;
	}
};



class doctorinside :public doctor
{
public:
	int sectionnumber;
	int  salary;
public:
	doctorinside() :doctor()
	{
		sectionnumber = 0;
		salary = 0;
	}
	doctorinside(int id, string  name, string address, date &d0, int  sectionnumber, int  salary, int type)
		: doctor(id, name, address, type, d0)
	{
/*		doctorid = id;
		doctorname = name;
		doctoraddress = address;*/
		this->sectionnumber = sectionnumber;
		this->salary = salary;
		this->type = type;

	}
	~doctorinside()
	{

	}
 void doctor_print_info()
	{
		doctor::doctor_print_info();
		cout <<"Salary:  "<< salary << "  |  Section Number:  " << sectionnumber << " type:  Internal Doctor  | ";
	}

};


class doctortraining :public doctor
{
protected:
	int  salary;
	date starttraining;
	date endtraining;
public:
	doctortraining() :doctor(), starttraining(), endtraining()
	{
		salary = 0;
	}
	~doctortraining()
	{

	}
	doctortraining(int id, string name, string address, int type, int  salary1, date &d0, date &d1, date &d2)
		:doctor(id, name, address, type, d0), starttraining(d1), endtraining(d2)
	{
		salary = salary1;
	}
	void doctor_print_info()
	{
		doctor::doctor_print_info();
		cout <<"  |  "<< salary << "\t";
		cout << "  Training Doctor  ";
		cout << "|   Start training ";
		starttraining.printdate();
		if (endtraining.get_day() == 0)
			cout << "He is still training.";
		else {
			cout << "End training ";
			endtraining.printdate();
		}
			
	}
};

class doctorcontracting :public doctor
{
protected:
	int  salary;
	date startcontacting;
public:
	doctorcontracting() :doctor(), startcontacting()
	{
		salary = 0;
	}
	~doctorcontracting()
	{

	}
	doctorcontracting(int id, string name, string address, int type, int salary, date &d0, date &d3)
		:doctor(id, name, address, type, d0), startcontacting(d3)
	{
		this->salary = salary;
	}
	void doctor_print_info() {
	
		doctor::doctor_print_info();
		cout << "	|  Total Salary  " << salary <<  " type:  Contracting Doctor  | ";
		startcontacting.printdate();
	}
};

//struct node
//{
//	doctor *head;
//};
class linked_list
{
private:	
	doctor *head;
public:
	linked_list()
	{
		head = NULL;
	}
	~linked_list() {}							
								//Inserst In Linked List
	void insert(doctor *d1)
	{
		if (d1 != NULL) {
			if (searchlinkedlist(d1->get_doctor_id()))
			{
				system("cls");
				cout << "This Doctor Id is already in our File." << endl;
			}
			else
			{
				doctor *temp;
				/*if (d1->get_type() == 1)
				temp = new doctorinside;
				else if (d1->get_type() == 2)
				temp = new doctortraining;
				else if (d1->get_type() == 3)
				temp = new doctortraining;*/
				temp = d1;
				temp->next = NULL;
				if (head == NULL)
				{
					head = temp;
					//head->next = temp->next;
					//head->value = temp->value;
				}
				/*	else
				{
				temp->next = head;
				head = temp;
				}*/
				else
				{
					if (temp->get_doctor_id() <= head->get_doctor_id())
					{
						temp->next = head;
						head = temp;
					}
					else
					{		//temp new
							//sort i 
						doctor *sort;
						sort = head;
						while (sort != NULL)
						{
							if ((temp->get_doctor_id() > sort->get_doctor_id()))
							{
								if (sort->next == NULL) {
									sort->next = temp;
									break;
								}
								else if (temp->get_doctor_id() < (sort->next)->get_doctor_id()) {
									temp->next = (sort->next);
									sort->next = temp;
									break;
								}
							}
							/*else if (sort->next == NULL && (temp->get_doctor_id()) >= (sort->get_doctor_id()))
							{
								sort->next = temp;
								break;
							}*/
							sort = sort->next;
						}
					}
				}
			}

		}
		
		
	}
	//Print Of Doctor Linked List
	void printlinkedlist() 
	{
		
		doctor *temp;
		temp = head;
		cout << "Doctors\n";
		while (temp != NULL)
		{
				temp->doctor_print_info();
				temp = temp->next;
			cout << endl;
		}
	}

	void print_spacific_linkedlist(int y)
	{
		doctor *temp;
		temp = head;
		if (head == NULL)
			cout << "Empty" << endl;
		else
		{
			cout << "Doctors\n";
			while (temp != NULL)
			{
				if (temp->get_type() == y) {
					temp->doctor_print_info();
				}
				temp = temp->next;
				cout << endl;
			}
		}
	}


	//Search in Doctor Linked List
	 bool searchlinkedlist(int idsearch)
	{
		 doctor *temp;
		 temp = head;
	int count=0;
		while (temp != NULL)
		{
			if (temp->get_doctor_id() == idsearch)
			count++;
		temp = temp->next;
		}
		if (count > 0)
			return 1;
		else return 0;
	 }
	 void delete_linked_list(int iddelete) {
		 doctor *temp = head;
		 doctor *sort = head->next;
		 if (head->get_doctor_id() == iddelete)
		 {
			 temp = temp->next;
			 head = temp;
			 return;
		 }
		 else {
			 while ((sort->next != NULL) && ((sort->get_doctor_id()) != iddelete)) {
			//	 cout << sort->get_doctor_id();
				 temp = sort;
				 sort = sort->next;
			 }
			 if (sort->next == NULL && sort->get_doctor_id() != iddelete)
			 {
				 cout << "\nThis id not found\n";
			 }
			 else if (sort->next != NULL && sort->get_doctor_id() == iddelete)
			 {
				 temp->next = sort->next;
				 free(sort);
			 }
			 else if (sort->next == NULL && sort->get_doctor_id() == iddelete)
			 {
				 temp->next = NULL;
				 free(sort);
			 }
		 }
	 }
};



#endif // !HEADER_H
