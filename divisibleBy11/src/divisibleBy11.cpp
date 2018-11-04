#include <iostream>
using namespace std;

int main();
int main()
{
	int numIn;
	cout << "enter num:";
	cin >> numIn;
	int keepNum = numIn;

	numIn = abs(numIn);
	int Num[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};       //array to store
	int i = 0;
	while (numIn > 0)
	{
        Num[i] = numIn % 10;          //store from back to front
	    numIn = numIn / 10;
	    i++;
	}

	for(int i = 0; i < 16; i++)   //test
	{
		cout << Num[i];
	}
	cout << endl;


	int tau = 0;
	for (int j = 0; j <= 15; j+=2)
	{
	    tau += Num[j];
	}
	for (int j = 1; j <= 15; j+=2)
	{
	    tau -= Num[j];
	}

	if((tau%11 == 0) && keepNum != 0)
		cout << keepNum << " is divisible by 11." <<endl;
	else
		cout << keepNum << " is not divisible by 11." <<endl;
	return 0;
}

