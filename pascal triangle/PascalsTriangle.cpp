#include <iostream>
using namespace std;

#ifndef MARMOSET_TESTING
int main();
#endif

int pascal_triangle(int n);
int pascal_triangle_recursive(int n);
int getNum(int i, int j);

#ifndef MARMOSET_TESTING

int main()
{
    int numIn = 0;
	cin >> numIn;              //numIn + 1 is how many rows we want
	pascal_triangle(numIn);
	pascal_triangle_recursive(numIn);
	//cout << pascal_triangle(numIn) <<pascal_triangle_recursive(numIn);//    could use this to test return is right or not.
}
#endif

int pascal_triangle( int n )
{
	int arr[n+1][n];         // we have rows and columns so 2D so [][] array
	for (int line = 0; line < n+1; line++)
	{
	    for (int i = 0; i <= line; i++)
	    {
	        if (line == i || i == 0)
	        {
	        	arr[line][i] = 1;    // start and end is 1
	        }
	        else
	        {
	        	arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
	        }
	        cout << arr[line][i] << " ";
	    }
	    cout << endl;
	}
	return (n*n+3*n+2)/2;
}

int pascal_triangle_recursive(int n)
{
	if(n>=1)
		pascal_triangle_recursive(n-1);
	int element = 0;
	for (int i = 0; i <= n; i++)
    {
         if(i == 0 || n == 0)
              element = 1;
         else
        	 element = element*(n-i+1)/i;
         cout << element << " ";
	}
	cout << endl;
	return (n*n+3*n+2)/2;
}
