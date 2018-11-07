#include <iostream>
using namespace std;

#ifndef MARMOSET_TESTING
int main();
#endif

float rolling_average(float a, float b, float c);

#ifndef MARMOSET_TESTING
int main()
{
    float array[3] = {0,0,0};
    cout << "Enter a number." << endl;
    cin >> array[0];
    cout << "Enter a number." << endl;
    cin >> array[1];
    cout << "Enter a number." << endl;
    cin >> array[2];
    cout << "rolling average is: " << rolling_average(array[0], array[1], array[2]) <<endl;
    float numIn = 0;
    cout << "Enter a number." << endl;

	while(true)
	{
		cin >> numIn;
		if(numIn < 0) break;
		array[0] = array[1];
		array[1] = array[2];
		array[2] = numIn;
		cout << "rolling average is: " << rolling_average(array[0], array[1], array[2]) <<endl;
	}
	return 0;
}
#endif

float rolling_average(float a, float b, float c)
{
    return (a+b+c)/3.0;
}
