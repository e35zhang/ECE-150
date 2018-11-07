#include <iostream>
#include <cmath>
using namespace std;

int getFnum(int a);
int main()
{
    int numIn=0;
	cout << "enter a number you want to test: ";
    cin >> numIn;
    cout << "the friendliness of a given number " << numIn << " is: " << getFnum(numIn);
}
//analyse: (ai + afin) * (afin - ai + 1)/2 = num
//afin - ai + 1 is n numbers of concecutives
// (2*num/n + 1 - n) /2 = ai must be int  and this idea is the while loop!!! cool!!!

int getFnum(int a)
{
    int fn=0;
    double ai = 0;
	for(int i = 2; i < (sqrt(2*a)+1); i++)    //there must be a better solution than i < a !!
	{
		ai = (2.0*a/i+1-i)/2.0;
		if(((ai-int(ai)) == 0) && (ai>0))
		{
			fn++;
			cout << "i = "<< i <<" ai ="<< ai <<endl;
		}
	}
	return fn;
}
