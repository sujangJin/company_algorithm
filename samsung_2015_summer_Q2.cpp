#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int testcase = 0, index = 0, allnegative = 1;
	int **numbers = new int*[10];
	int minus = 0, minimal = 0;
	
	// input the number of datasets
	cin >> testcase;

	// allocate array
	for (int i = 0; i < testcase; i++){
		numbers[i] = new int[2];
		cin >> numbers[i][0] >> numbers[i][1];
	}
	
	// process
	while (index < testcase){
		if (numbers[index][0] < 0 && numbers[index][1] < 0){
			numbers[index][0] *= -1; 
			numbers[index][1] *= -1;
			allnegative = -1;
		}
		else if (numbers[index][0] < 0){
			numbers[index][0] *= -1;
		}
		else if (numbers[index][1] < 0){
			numbers[index][1] *= -1;
		}

		
		
		minus = abs(numbers[index][0] - numbers[index][1]);
		minimal = min(numbers[index][0], numbers[index][1]);

		if (minus == minimal){
			cout << "#testcase" << index + 1 << endl;
			cout << minus*allnegative;
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