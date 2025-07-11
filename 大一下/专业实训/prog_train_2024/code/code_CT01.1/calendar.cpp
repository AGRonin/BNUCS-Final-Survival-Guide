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
	if ( month==2 )
	{
		if ( isleap(year) )
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}

	switch ( month )
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	}

	return 30;

}

int main(void)
{
	int query_days;  // may be -1

	cin >> query_days;

	while ( query_days>=0 )
	{
		unsigned year = 2000;
		unsigned month = 1;
		unsigned day = 1;
		unsigned week = query_days%7;

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

		cin >> query_days;
	}// while ( query_days >= 0)


	return 0;
}
