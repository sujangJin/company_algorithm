#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int N, M, T, index;
int threat[50][50];
int dp[50][50];
queue<int> res;

const int MAX = 10000;

int IsEnable(int x, int y, int N, int M){
	if (x < 0 || x > N || y < 0 || y > N)
		return MAX;
	else
		return dp[x][y];
}

int main()
{
	int tmp, formerUp, formerLeft;
	
	scanf("%d",&T);
	for (int i= 0; i < T; i++){


		scanf("%d %d", &N, &M);
		if (N >= 3 && N <= 50 && M >= 3 && M <= 50){
			for (int x = 0; x < N; x++){
				for (int y = 0; y < M; y++){
					scanf("%d", &tmp);
					if (tmp >= 0 && tmp <= 1000)
						threat[x][y] = tmp;
					else{
						printf("error");
						return -1;
					}
				}
			}

			dp[0][0] = threat[0][0];
			for (int x = 0; x <= N; x++){
				for (int y = 0; y <= M; y++){
					if (x == 0 && y == 0){}
					else {
						formerUp = IsEnable(x - 1, y, N, M);
						formerLeft = IsEnable(x, y - 1, N, M);
						dp[x][y] = min(formerLeft, formerUp) + threat[x][y];
					}
				}
			}
		}
		res.push(dp[N-1][M-1]);
	}
	index = 1;
	while (!res.empty()){
		printf("#%d %d", index, res.front());
		res.pop();
	}
	
}