#include <iostream>
using namespace std;

int main()
{
	int i = 69, number = 72;
	i = i + number;
	int arr[3] = {0, 0, 0};
	int* iPointer = &i;
	number = *iPointer;
	*iPointer = 15;
	iPointer = &arr[0];
	iPointer += 2;
	arr[0] = 5;
	*iPointer = 6;

	cout << "i " << i << endl;
	cout << "number " << number << endl;
	cout << "array " << arr[0] << ", " << arr[1] << ", " << arr[2] << "" << endl;	

	return 0;
}