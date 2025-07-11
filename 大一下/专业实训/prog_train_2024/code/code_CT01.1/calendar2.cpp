#include <iostream>

using namespace std;

const char wstr[][20] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

bool isleap(unsigned year)
{
	if (  ( year%100!=0 && year%4==0 ) || ( year%400==0 )  )
	{
		return true;
	}
	return false;
}

unsigned days_of_year(unsigned year)
{
	if (isleap(year))
	{
		return 366;
	}
	else
	{
		return 365;
	}
}

unsigned days_of_month(unsigned month, unsigned year)
{
	switch (month)
	{
	case 4: case 6: case 9: case 11:
		return 30;
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 2:	
		if ( isleap(year) )
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
}

class YMDay
{
	unsigned year;
	unsigned month;
	unsigned day;
	unsigned week;
public:
	void print();
	void reset(int query_days);
	void calc(int query_days);
};

void YMDay::reset(int query_days)
{
	year = 2000;
	month = 1;
	day = 1;
	week = query_days%7;
}

void YMDay::calc(int query_days)
{
	reset(query_days);

	while ( query_days )
	{
		if ( query_days>=days_of_year(year) )
		{
			query_days -= days_of_year(year);
			year++;
		}
		else if ( query_days>=days_of_month(month,year) )
		{
			query_days -= days_of_month(month,year);
			month++;
		}
		else
		{
			day += query_days;
			query_days = 0;
		}
	}// while ( query_days )
}

void YMDay::print()
{
	cout << year << '-';
	if ( month <10 )
	{
		cout << "0";
	}
	cout << month << '-';
	if ( day<10 )
	{
		cout << "0";
	}
	cout << day << " ";
	cout << wstr[week] << endl;
}



int main(void)
{
	YMDay ymd;
	int query_days;  // can be -1

	cin >> query_days;

	while ( query_days>=0 )
	{
		ymd.calc(query_days);
		ymd.print();
		cin >> query_days;
	}

	return 0;
}
