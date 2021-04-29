#ifndef PATIENTHEADER_H
#define PATIENTHEADER_H
#include "doctorheader.h" 
#include "treatment.h"

class patient {
protected:
	int patientid;
	string patientname;
	string patientaddress;
	date patientbirhtday;
	external_treatment_lists etl;
	int type ;
public:
	patient *next;
	patient() : patientbirhtday() , etl() {
		patientid = 0;
		patientname = patientaddress = "";
		next = NULL;
		type = 0;
	}
	patient(int patientid, string patientname, string patientaddress, date &d1, external_treatment_lists etll,  int x)
		:patientbirhtday(d1)
	{

		this->patientid = patientid;
		this->patientname = patientname;
		this->patientaddress = patientaddress;
		//this->etl = etl;						//ÛáØ ÛáØ ÛáØ
		etl = etll;
		type = x;
		this->next = NULL;
		
	}
	~patient() {}
	virtual void print_patient_info() {
		cout << "patientid  " << patientid << "	patient name  " << patientname << "		patient address  " << patientaddress << "  ";
		patientbirhtday.printdate();
		etl.print_external_list();
	}
	virtual int get_patient_id() {
		return patientid;
	}
	virtual int get_patient_type() {
		return type;
	}
	virtual string get_name() {
		return patientname;
	}
	virtual string get_address() {
		return patientaddress;
	}

	virtual external_treatment_lists get_list() {
		return etl;
	}
	virtual date get_date() {
		return patientbirhtday;
	}
	// for inhertanc
	virtual void add_in_tretment(internaltreatment *it) {

	}
	virtual void add_ex_tretment(externaltreatment *et) {
		etl.insert_external(et);
	}
	virtual void set_exitstutes() {
	}

	virtual void get_ite_date() {

	}
	virtual internal_treatment_lists *get_inter_list() {
		return nullptr;
	}
};


class internal_patient : public patient {
protected:
	internal_treatment_lists itl;
	bool exitstutes = 0;
public:
	internal_patient():patient() ,itl(){
		exitstutes = 0;
	}
	~internal_patient() {}
	internal_patient(int patientid, string patientname, string patientaddress, date &d1, bool exitstutes, external_treatment_lists etl, internal_treatment_lists itl)
		:patient(patientid, patientname, patientaddress, d1, etl , 1){
		this->exitstutes = exitstutes;
		this->itl = itl;
	}
	int get_patient_type() {
		return type;
	}
	void print_patient_info() {
		patient::print_patient_info();
		if (exitstutes == 0)
			cout << "  lsato 3na  ";
		else
			cout << "  6l3 ";
		itl.print_internal_list();
	}
	 int get_patient_id() {
		return patientid;
	}


	  void add_in_tretment(internaltreatment *it) {
		 itl.insert_internal(it);
	 }

	  void set_exitstutes() {
		  exitstutes = 1;
		}

	  internal_treatment_lists *get_inter_list() {
		  return &itl;
	  }
	  
};


class external_patient : public patient {
private:
	bool accepted;
public:
	external_patient() : patient() {
		accepted = 0;		
	}

	~external_patient() {}
	external_patient(int patientid, string patientname, string patientaddress, date &d1,bool accepted, external_treatment_lists etll)
		:patient(patientid, patientname, patientaddress, d1, etll,2) {
		this->accepted = accepted;
	}
	int get_patient_type() {
		return type;
	}
	void print_patient_info() {
		patient::print_patient_info();
		if (accepted == 0)
			cout << "  not accepted  ";
		else
			cout << "   accepted  ";
	}
	external_treatment_lists get_list() {
		return etl;
	}
	string get_name() {
		return patientname;
	}
	string get_address() {
		return patientaddress;
	}
	 int get_patient_id() {
		return patientid;
	}
	 date get_date() {
		 return patientbirhtday;
	 }

};


class patient_linkedlist {
private:
	patient *head;
public:
	patient_linkedlist()
	{
		head = NULL;
	}
	~patient_linkedlist() {}
	//Inserst patient In Linked List
	void insert(patient *p1)
	{
		if (p1 != NULL) {
			if (searchlinkedlist(p1->get_patient_id()))
			{
				system("cls");
				cout << "This patient Id is already in our File." << endl;
			}
			else
			{
				patient *temp;
				temp = p1;
				temp->next = NULL;
				if (head == NULL)
				{
					head = temp;
				}
				else
				{
					if (temp->get_patient_id() <= head->get_patient_id())
					{
						temp->next = head;
						head = temp;
					}
					else
					{		//temp new
							//sort i 
						patient *sort;
						sort = head;
						while (sort != NULL)
						{
							if ((temp->get_patient_id() > sort->get_patient_id()))
							{
								if (sort->next == NULL) {
									sort->next = temp;
									break;
								}
								else if (temp->get_patient_id() < (sort->next)->get_patient_id()) {
									temp->next = (sort->next);
									sort->next = temp;
									break;
								}
							}
							else if (sort->next == NULL && (temp->get_patient_id()) >= (sort->get_patient_id()))
							{
								sort->next = temp;
								break;
							}
							sort = sort->next;
						}
					}
				}
			}

		}


	}
	//Print Of patient Linked List
	void printlinkedlist()
	{

		patient *temp;
		temp = head;
		cout << "\nPatient\n";
		while (temp != NULL)
		{
			temp->print_patient_info();
			temp = temp->next;
			cout << endl;
		}
	}
	//Search in patient Linked List
	bool searchlinkedlist(int idsearch)
	{
		patient *temp;
		temp = head;
		int count = 0;
		while (temp != NULL)
		{
			if (temp->get_patient_id() == idsearch)
				count++;
			temp = temp->next;
		}
		if (count > 0)
			return 1;
		else return 0;
	}
	//Delete in patient Linked List
	void delete_linked_list(int iddelete) {
		patient *temp = head;
		patient *sort = head->next;
		if (head->get_patient_id() == iddelete)
		{
			temp = temp->next;
			head = temp;
			return;
		}
		else {
			while ((sort->next != NULL) && ((sort->get_patient_id()) != iddelete)) {
				temp = sort;
				sort = sort->next;
			}
			if (sort->next == NULL && sort->get_patient_id() != iddelete)
			{
				cout << "\nThis id not found\n";
			}
			else if (sort->next != NULL && sort->get_patient_id() == iddelete)
			{
				temp->next = sort->next;
				free(sort);
			}
			else if (sort->next == NULL && sort->get_patient_id() == iddelete)
			{
				temp->next = NULL;
				free(sort);
			}
		}
	}


	patient *get_external_by_id(int idsearch)
	{
		patient *temp;
		temp = head;
		int count = 0;
		while (temp != NULL)
		{
			if (temp->get_patient_id() == idsearch)
			{
				count++;
				if ((temp->get_patient_type()) == 2){
					return temp;
				}
				else
					return nullptr;
			}
			temp = temp->next;
		}
		return nullptr;

	}

	

	patient *get_patient_by_id(int idsearch)
	{
		patient *temp;
		temp = head;
		while (temp != NULL)
		{
			if (temp->get_patient_id() == idsearch)
			{

					return temp;
				}
			temp = temp->next;
			}
		return nullptr;

	}


	void get_betwwn_dates(int x,date d1,date d2) {
		patient *temp;
		temp = head;
		int count = 0;
		while (temp != NULL)
		{
			//ÍØ Ãäæ ãÑíÖ ÏÇÎáí
			if(temp->get_patient_type() == 1)
			if (((temp->get_inter_list())->get_count_in_date(x,d1, d2)) > 0)
			{
				count++;
			}
			temp = temp->next;
			
		}
		cout << "\nCount =  " << count << endl;
	}
};



#endif 