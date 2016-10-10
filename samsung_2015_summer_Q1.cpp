#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int testcase, count = 0, index;
	char ** string = new char*[10];
	vector<char> res_string;
	char before, current;
	
	//------------------input start-------------------
	cin >> testcase;	
	
	// allocate the space that is used for saving each sentence
	for (int i = 0; i < testcase; i++){
		string[i] = new char[20];
		cin >> string[i];
	}
	//------------------input end----------------------
	
	index = 0;
	while (index < testcase){
		
		current = string[index][0];
		
		// the idea of for loop is Linked-List that
		// compares before node to current node
		for (char* cp = string[index]; *cp != '\0'; cp++)
		{
			before = current;
			current = *cp;

			if (current == before)
			{
				count++;
			}
			else
			{
				if (count < 10)
				{
					count += '0';
					res_string.push_back(before);
					res_string.push_back(count);
				}
				else 	// when count is more than 10, we must split that number
					// and than save to vector space
				{
					res_string.push_back(current);
					int quo = count / 10;
					int spare = count % 10;
					quo += '0'; spare += '0';
					res_string.push_back(quo);
					res_string.push_back(spare);
				}

				count = 1;
			}

		}
			count += '0';				// change integer to char
			res_string.push_back(current);
			res_string.push_back(count);
		

		//----------- output start------------------
		cout << "#testcase" << index+1 << endl;
		cout << string[index] << " " << strlen(string[index]) << endl;

		if (strlen(string[index]) > res_string.size())
		{
			for (int i = 0; i < res_string.size(); i++)
				cout << res_string[i];
			cout << " " << res_string.size();
		}
		else
			cout << string[index] << " " << strlen(string[index]);

		//------------ output end--------------------
		cout << endl;
		count = 0;
		res_string.clear();
		index++;
	}
	
	// return the spaces allocated dynamically
	for (int i = 0; i < testcase; i++)
		delete[] string[i];
	delete[] string;
	return 0;
}
