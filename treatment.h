#ifndef treatment_H
#define treatment_H
#include "doctorheader.h" 
#include "patientheader.h" 


class treatment {
protected:
	int treatmentid, cost;
	date treatmentdate;

public:
	treatment() : treatmentdate() {
		treatmentid = cost = 0;
	}
	~treatment() {}
	treatment(int treatmentid, int cost, date &d1) :treatmentdate(d1) {
		this->treatmentid = treatmentid;
		this->cost = cost;
	}
	int get_treatment_id() {
		return treatmentid;
	}
	virtual void print_treatment() {
		cout << "treatmentid  " << treatmentid << "   cost:  " << cost;
		treatmentdate.printdate();
	}
};

/* Internal treatmernt */
struct treatment_node {
	int doctor_supervisor;
	treatment_node *next;
};

class treatment_internal_list_id {
private:
	treatment_node *head;
public:
	treatment_internal_list_id() {
		head = NULL;
	}
	void insert(int value)
	{
		struct treatment_node *temp = new treatment_node;
		struct treatment_node *sort = new treatment_node;
		sort = head;
		temp->doctor_supervisor = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			//head->next_ptr = temp->next_ptr;
			//head->value = temp->value;
		}
		else
		{
			if (temp->doctor_supervisor <= head->doctor_supervisor)
			{
				temp->next = head;
				head = temp;
			}
			else
			{		//temp new
					//sort i
				while (sort != NULL)
				{
					if ((temp->doctor_supervisor > sort->doctor_supervisor))
					{
						if (sort->next == NULL) {
							sort->next = temp;
							break;
						}
						else if (temp->doctor_supervisor < (sort->next)->doctor_supervisor) {
							temp->next = (sort->next);
							sort->next = temp;
							break;
						}
					}
					else if (sort->next == NULL && (temp->doctor_supervisor) >= (sort->doctor_supervisor))
					{
						sort->next = temp;
						break;
					}
					sort = sort->next;
				}
			}
		}
	}
	void printlinkedlist()
	{
		treatment_node *temp = new treatment_node;
		temp = head;
		cout << "The linked list is :\t";
		while (temp != NULL)
		{
			cout << temp->doctor_supervisor << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
	int  searchlinkedlist(int search)
	{
		int count = 0;
		treatment_node *temp = new treatment_node;
		temp = head;
		while (temp != NULL)
		{
			if (temp->doctor_supervisor == search)
				count++;
			temp = temp->next;
		}
		cout << endl;
		if (count > 0)
			return 1;
		else return 0;
	}
};

class internaltreatment :public treatment {
protected:
	int sectionnum;
	date exitdate;
	treatment_internal_list_id internaltreatment_linklist1;
public:
	internaltreatment *next;
	internaltreatment() :treatment(), exitdate(), internaltreatment_linklist1() {
		sectionnum = -1;
	}
	~internaltreatment() {

	}
	internaltreatment(int treatmentid, int cost, int sectionnum, date &d1, date &d2, int numberofdoctors, treatment_internal_list_id l1)
		:treatment(treatmentid, cost, d1), exitdate(d2) {
		this->sectionnum = sectionnum;
		internaltreatment_linklist1 = l1;
	}
	void print_treatment() {
		treatment::print_treatment();
		cout << "Section Number: " << sectionnum;
		if (exitdate.get_day() == 0)
			cout << "	lsa ma t7'raj    ";
		else
		exitdate.printdate();
		internaltreatment_linklist1.printlinkedlist();
	}
	int get_section_num() {
		return sectionnum;
	}
	date *get_treatment_date () {
		return &treatmentdate;
	}
};
			


class externaltreatment :public treatment {
protected:
	int clinicnumber;
	int treatment_doctorid;
public:
	externaltreatment *next;
	externaltreatment() : treatment() {
		clinicnumber = treatment_doctorid = 0;
		next = NULL;
	}
	~externaltreatment() {}

	externaltreatment(int treatmentid, int cost, int clinicnumber, int treatment_doctorid, date &d1)
		:treatment(treatmentid, cost, d1) {
		this->clinicnumber = clinicnumber;
		this->treatment_doctorid = treatment_doctorid;

	}
	void print_treatment() {
		treatment::print_treatment();
		cout << "clinic Number: " << clinicnumber;
		cout << "treatment doctorid " << treatment_doctorid;
	}
};

class internal_treatment_lists {
private:
	internaltreatment *internal_head;
public:
	internal_treatment_lists() {
		internal_head = NULL;
	}
	~internal_treatment_lists() {}

	void insert_internal(internaltreatment *Object) {
		internaltreatment *temp;
		temp = Object;
		temp->next = NULL;
		if (internal_head == NULL)
		{
			internal_head = temp;
		}
		else
		{
			if (temp->get_treatment_id() <= internal_head->get_treatment_id())
			{
				temp->next = internal_head;
				internal_head = temp;
			}
			else
			{		//temp new
					//sort i 
				internaltreatment *sort;
				sort = internal_head;
				while (sort != NULL)
				{
					if ((temp->get_treatment_id()) > (sort->get_treatment_id()))
					{
						if (sort->next == NULL) {
							sort->next = temp;
							break;
						}
						else if (temp->get_treatment_id() < (sort->next)->get_treatment_id()) {
							temp->next = (sort->next);
							sort->next = temp;
							break;
						}
					}
					else if (sort->next == NULL && (temp->get_treatment_id()) >= (sort->get_treatment_id()))
					{
						sort->next = temp;
						break;
					}
					sort = sort->next;
				}
			}
		}
	}

	//Print Of internal treatment Linked List
	void print_internal_list()
	{

		internaltreatment *temp;
		temp = internal_head;
		cout << "internal treatments\n";
		while (temp != NULL)
		{
			temp->print_treatment();
			temp = temp->next;
			cout << endl;
		}
	}

	//Search in internal treatment  Linked List
	bool search_internal_list(int idsearch)
	{
		internaltreatment *temp;
		temp = internal_head;
		int count = 0;
		while (temp != NULL)
		{
			if (temp->get_treatment_id() == idsearch)
				count++;
			temp = temp->next;
		}
		if (count > 0)
			return 1;
		else return 0;
	}


	void delete_linked_list(int iddelete) {
		internaltreatment *temp = internal_head;
		internaltreatment *sort = internal_head->next;
		if (internal_head->get_treatment_id() == iddelete)
		{
			temp = temp->next;
			internal_head = temp;
			return;
		}
		else {
			while ((sort->next != NULL) && ((sort->get_treatment_id()) != iddelete)) {
				cout << sort->get_treatment_id();
				temp = sort;
				sort = sort->next;
			}
			if (sort->next == NULL && sort->get_treatment_id() != iddelete)
			{
				cout << "\nThis id not found\n";
			}
			else if (sort->next != NULL && sort->get_treatment_id() == iddelete)
			{
				temp->next = sort->next;
				free(sort);
			}
			else if (sort->next == NULL && sort->get_treatment_id() == iddelete)
			{
				temp->next = NULL;
				free(sort);
			}
		}
	}

	int get_count_in_date(int x,date d1,date d2) {
		internaltreatment *temp;
		if (internal_head == NULL)
			return 0;
		
		else
		{
			temp = internal_head;
			int count = 0;
			while (temp != NULL)
			{
				if (temp->get_section_num() == x)
					if (d1.get_year() <= (temp->get_treatment_date()->get_year()) && d2.get_year() >= (temp->get_treatment_date()->get_year()))
						if (d1.get_month() <= (temp->get_treatment_date()->get_month()) && d2.get_month() >= (temp->get_treatment_date()->get_month()))
							if (d1.get_day() <= (temp->get_treatment_date()->get_day()) && d2.get_day() >= (temp->get_treatment_date()->get_day()))
								count++;
				temp = temp->next;
			}
			return count;
		}
	}

};

class external_treatment_lists {
private:
	externaltreatment *external_head;
public:


	external_treatment_lists() {
		external_head = NULL;
	}
	~external_treatment_lists() {}
	void set(const external_treatment_lists &object) {
		external_head = object.external_head;
	}

	/*External treatment Linked List*/
	void insert_external(externaltreatment *Object) {
		if (Object != NULL) {
			if (search_external_list(Object->get_treatment_id()))
			{
				system("cls");
				cout << "This Treatment is already in our File." << endl;
			}
			else {
				externaltreatment *temp;
				temp = Object;
				temp->next = NULL;
				if (external_head == NULL)
				{

					external_head = temp;
				}
				else
				{
					if (temp->get_treatment_id() <= external_head->get_treatment_id())
					{
						temp->next = external_head;
						external_head = temp;
					}
					else
					{		//temp new
							//sort i 
						externaltreatment *sort;
						sort = external_head;
						while (sort != NULL)
						{
							if ((temp->get_treatment_id()) > (sort->get_treatment_id()))
							{
								if (sort->next == NULL) {
									sort->next = temp;
									break;
								}
								else if (temp->get_treatment_id() < (sort->next)->get_treatment_id()) {
									temp->next = (sort->next);
									sort->next = temp;
									break;
								}
							}
							else if (sort->next == NULL && (temp->get_treatment_id()) >= (sort->get_treatment_id()))
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

	//Print Of internal treatment Linked List
	void print_external_list()
	{

		externaltreatment *temp;
		temp = external_head;
		cout << "external treatments\n";
		while (temp != NULL)
		{
			temp->print_treatment();
			temp = temp->next;
			cout << endl;
		}
	}

	//Search in internal treatment  Linked List
	bool search_external_list(int idsearch)
	{
		externaltreatment *temp;
		temp = external_head;
		int count = 0;
		while (temp != NULL)
		{
			if (temp->get_treatment_id() == idsearch)
				count++;
			temp = temp->next;
		}
		if (count > 0)
			return 1;
		else return 0;
	}
	externaltreatment get_external_head() {
		return *external_head;
	}

};

#endif