#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#ifndef HELPER_H
#define HELPER_H

class date
{
protected:
	int day;
	int month;
	int year;
public:
	date()
	{
		day = month = year = 0;
	}
	date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void set_date(int day, int month, int year) {
			this->day = day;
			this->month = month;
			this->year = year;
		
	}
	void printdate()
	{
		cout<<"  Date:  " << day << "/" << month << "/" << year << "   ";
	}
	int get_day(){
		return day;
	}
	int get_month() {
		return month;
	}
	int get_year() {
		return year;
	}
};

#endif