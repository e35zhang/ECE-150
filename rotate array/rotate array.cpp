#include<iostream>
int main();
void rotate(int data[], int capacity);
int main()
{
    int capacity = 5;
    int rotate_by = 12;
    int data[5] = {1,2,3,4,5};
    for(int i =rotate_by % capacity; i > 0; i--)
    {
    	rotate(data, capacity);
    }
	for(int j = 0; j < capacity; j++)
	{
        std::cout << data[j] <<" ";
	}
	return 0;
}

void rotate(int data[], int capacity)
{
	int temp = data[capacity - 1];
	for (int i = capacity - 1; i > 0; i--)
	{
        data[i] = data[i - 1];
	}
	data[0] = temp;
}
