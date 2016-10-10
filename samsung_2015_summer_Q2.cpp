#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int testcase = 0, index = 0;
	int **numbers = new int*[10];
	int minus = 0, minimal = 0;
	
	// input the number of datasets
	cin >> testcase;

	// allocate array & input each integer
	for (int i = 0; i < testcase; i++){
		numbers[i] = new int[2];
		cin >> numbers[i][0] >> numbers[i][1];
	}
	
	// process
	while (index < testcase){
		minus = abs(numbers[index][0] - numbers[index][1]);
		minimal = min(numbers[index][0], numbers[index][1]);

		if (minus == minimal){
			cout << "#testcase" << index + 1 << endl;
			cout << minus;
			cout << endl;
			index++;
		}
		else {
			numbers[index][0] = minus;
			numbers[index][1] = minimal;
		}
	}

	// return the dynamically allocated array
	for (int i = 0; i < testcase; i++){
		delete[] numbers[i];
	}
	delete[] numbers;
	return 0;
}