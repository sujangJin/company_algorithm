//트리의 전위 순회, 후위 순회 결과가 주어졌을 때 이를 중위 순회한 결과를 출력하는 프로그램을 작성하시오. 

//입력
//입력은 표준 입력으로 주어진다. (scanf로 읽을 수 있다는 뜻)
//입력의 첫 줄에는 트리의 노드 수 n이 주어진다.n은 1부터 1, 000 이하이다.
//트리의 각 노드는 1부터 n까지 숫자로 이름이 붙여져 있으며, 서로 다른 노드는 서로 이름이 다르다.
//입력의 두 번째 줄에는 이 트리를 전위 순회한 결과가 차례로 주어진다.숫자들은 사이에 공백을 두고 주어진다.
//입력의 세 번째 줄에는 이 트리를 후위 순회한 결과가 차례로 주어진다.숫자들은 사이에 공백을 두고 주어진다.

//출력
//출력은 트리의 중위 순회 결과를 나타내는 n개의 숫자를 사이에 공백 하나를 두고 한 줄에 출력한다.

//입력 예제
//7
//1 2 4 5 3 6 7
//4 5 2 6 7 3 1

//출력 예제
//4 2 5 1 6 3 7


//전위순회와 후위순회의 결과에서 얻을 수 있는 트리가 유일하지 않은 경우는 입력으로 주어지지 않는다고 가정해도 좋습니다. 
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> pre_order, post_order;
int isExist(int num, vector<int> arr);
void make_inorder(vector<int> pre, vector<int> post);
int Root;

int main()
{
	int tmp;
	scanf("%d", &Root);
	for (int i = 0; i < Root; i++){
		scanf("%d ", &tmp);
		if( tmp >=1 && tmp<= 1000 && !isExist(tmp, pre_order) )	pre_order.push_back(tmp);
	}

	for (int i = 0; i < Root; i++){
		scanf("%d ", &tmp);
		if ( tmp >= 1 && tmp <= 1000 && !isExist(tmp, post_order) )	post_order.push_back(tmp);
	}
	
	make_inorder(pre_order, post_order);

	return 0;
}

// if a number exists in that node than return arr's index
int isExist(int num, vector<int> arr)
{
	if (find(arr.begin(), arr.end(), num) != arr.end())
		return true;
	else
		return false;
}

void make_inorder(vector<int> pre, vector<int> post)
{
	int root = 0;
	root = pre.at(0);
	vector<int> L_pre, L_post, R_pre, R_post;

	vector<int>::iterator end_point = find(post.begin(), post.end(), pre.at(1));
	vector<int>::iterator start = post.begin();

	int index = (end_point - start) + 1;	// 1부터 indexing 시작했으므로 연산 결과에서 1 더함
	
	//////////////// Retrieve L ///////////////////
	for (int i = 1; i < 1 + index; i++)
	{
		L_pre.push_back(pre.at(i));
	}
	
	for (int i = 0; i < index; i++)
	{
		L_post.push_back(post.at(i));
	}
	//////////////// Retrieve R ///////////////////
	for (int i = index + 1; i < pre.size(); i++)
	{
		R_pre.push_back(pre.at(i));
	}

	for (int i = index; i < post.size() - 1; i++)
	{
		R_post.push_back(post.at(i));
	}

	///////////////////output part///////////////////

	if (L_pre.size() == 1 && L_post.size() == 1){
		printf("%d ", L_pre.at(0));
	}
	else
		make_inorder(L_pre, L_post);

	printf("%d ", root);

	if (R_pre.size() == 1 && R_pre.size() == 1)
		printf("%d ", R_pre.at(0));
	else{
		if (R_pre.size() != 0 && R_post.size() != 0)
			make_inorder(R_pre, R_post);
	}
}