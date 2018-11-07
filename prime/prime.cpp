#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdlib>
typedef std::chrono::high_resolution_clock Clock;

bool IsPrime(int num)
{
	for (int i = 3; i <= sqrt(num); i+=2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	auto t1 = Clock::now();
	for(int i = 3; i <=100; i+=2)
	{
		if(IsPrime(i))
		{
			std::cout << i << std::endl;
		}
	}
	auto t2 = Clock::now();
	std::cout << "the time it runs is : " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
			<< " nanoseconds.";
}

