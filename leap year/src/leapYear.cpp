#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif

bool is_leap_year(int yearIn);

#ifndef MARMOSET_TESTING
int main()
{
	std::cout << "Please enter a year." << std::endl;
	int yearIn = 0;
	std::cin >> yearIn;
	if(is_leap_year(yearIn))
	{
		std::cout << yearIn << " is a leap year!" << std::endl;
	}
	else
	{
		std::cout << yearIn << " is not a leap year!" << std::endl;
	}
}
#endif

/*if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)
*/

bool is_leap_year(int yearIn)
{
	if(yearIn <= 1584) return false;
    else if (yearIn % 4 != 0) return false;
	else if (yearIn % 100 != 0) return true;
	else if (yearIn % 400 != 0) return false;
	else return true;
}
