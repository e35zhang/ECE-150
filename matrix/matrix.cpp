#include <iostream>
#include "fraction.h"
using namespace std;

int main();

int main()
{
	fraction a[10][10]={}, b[10][10]={},mult[10][10]={};
	int r1;

	cout << "rows for the square matrix: ";
	cin >> r1;
    int r2 = r1;
    int c1 = r1;
    int c2 = r2;

	cout << endl << "Enter elements of matrix:" << endl;
	for(int i = 0; i < r1; i++)
	{
		for(int j = 0; j < c1; j++)
	    {
	        int x1;
	        int x2;
			cout << "Enter element a[" << i + 1 <<"]"<< "["<<j + 1 << "]'s numerator : ";
	        cin >> x1;
	        cout << "Enter element a[" << i + 1 <<"]"<< "["<<j + 1 << "]'s denominator : ";
	        cin >> x2;
	        a[i][j] = fraction(x1,x2);
	    }
	}

	for(int i = 0; i < r1; i++)
	{
	    for(int j = 0; j < c2; j++)
	    {
	        mult[i][j] = fraction();
	    }
	}

	cout << "the 2 th power of A is: "<<endl;
    for(int i = 0; i < r1; i++)
	{
	    for(int j = 0; j < c2; j++)
	    {
	        for(int k = 0; k < c1; k++)
	        {
	            mult[i][j] = mult[i][j].AddedTo(a[i][k].MultipliedBy(a[k][j]));
	        }
	        mult[i][j].print();
	        cout << " ";
	    }
	    cout << endl;
	}
    cout << endl;


    //start
    for (int s = 3; s <=15; s++)
    {
        for(int i = 0; i < r1; i++)
            	    {
            	        for(int j = 0; j < c2; j++)
            	        {
            	        	b[i][j] = mult[i][j];
            	        	mult[i][j] = fraction();
            	        }
            	    }

        cout << "the " << s << "th power of A is: "<<endl;
        for(int i = 0; i < r1; i++)
    	    {
    	        for(int j = 0; j < c2; j++)
    	        {
    	            for(int k = 0; k < c1; k++)
    	            {
    	            	mult[i][j] = mult[i][j].AddedTo(a[i][k].MultipliedBy(b[k][j]));
    	            }
    	        }
    	    }
        for(int i = 0; i < r1; i++)
        	    {
        	        for(int j = 0; j < c2; j++)
        	        {
        	        	 mult[i][j].print();
        	             cout << " ";
        	        }
        		    cout << endl;
        	    }
        cout << endl;
    }///end
}


