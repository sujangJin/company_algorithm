#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int T, N;
long long res[100];

int fac(int n){
	int sum = 1;
	
	if (n == 0)
		return 1;
	else{
		for (int i = n; i >= 1; i--)
			sum *= i;
		return sum;
	}
}

int vecPathIndex(vector<char> vec, char c){
	for (int i = 0; i < vec.size(); i++){
		if (vec.at(i) == c) return i;
	}
}

int FindRank(vector<char> input){
	int res = 1;
	char curr, min, max;
	int diff = 0;
	vector<char> tmp;

	if (input.size() == 2){
		if (input.front() < input.back()) return res;
		else return res + 1;
	}
	else {
		curr = input.front();
		tmp = input;
		input.erase(input.begin());

		sort(tmp.begin(), tmp.end());
		if (curr > tmp.front()){
			diff = vecPathIndex(tmp,curr) - vecPathIndex(tmp,tmp.front());
			return diff * fac(input.size()) + FindRank(input);
		}
		else{
			return FindRank(input);
		}
	}
}

vector<char> stringToVec(char * p){
	vector<char> res;
	
	for (char * tmp = p; *tmp != '\0'; tmp++){
		res.push_back(tmp[0]);
	}

	return res;
}

int main()
{
	char * tmp1 = new char[18];
	char * tmp2 = new char[18];
	int rank1, rank2;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%d %s %s", &N, tmp1, tmp2);
		if (strlen(tmp1) < 4 || strlen(tmp2) < 4) return -1;

		rank1 = FindRank(stringToVec(tmp1));
		rank2 = FindRank(stringToVec(tmp2));

		res[i] = abs(rank2 - rank1);
	}

	for (int i = 0; i < T; i++){
		printf("#%d %lld\n", i+1, res[i]-1);
	}
}
