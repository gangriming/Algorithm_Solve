#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// 세그먼트 트리의 초기화
long long init(vector<long long>& a, vector<long long>& tree,
	int node, int start, int end)
{
	// 배열 a
	// 세그먼트 트리 tree
	// 세그먼트 트리 노드 번호 node
	// node가 담당하는 합의 범위가 start ~ end
	if (start == end)	// 노드가 리프 노드인 경우.
		return tree[node] = a[start];	// 리프 노드는 배열의 그 원소를 가져야 하기 떄문에
	else
	{
		int mid = (start + end) / 2;
		return tree[node]
			= init(a, tree
				, node * 2
				, start
				, mid + init(a, tree, node * 2 + 1, mid + 1, end));
	}
}


// 합 구하는 법.
long long sum(vector<long long>& tree, int node, int start, int end,
	int left, int right)
{
	if (left > end || right < start)		// left, right가 start, end와 겹치지 않음. = 트리를 탐색할 필요 X
		return 0;
	if (left <= start && right >= end)	// left, right가 start, end범위를 다 포함할때
		return tree[node];	// 더 부르지 않고 모두 더한값을 리턴한다.

	// 그 이외의 경우.
	// start와 end안에 우리가 찾는 left, right가 모두 포함될 경우.
	int mid = (start + end) / 2;

	return sum(tree, node * 2,		// 왼쪽
		start,
		mid,
		left,
		right)
		+
		sum(tree, node * 2 + 1,		// 오른쪽
			mid + 1,
			end,
			left,
			right);

}

// 수가 변경된다면, 합을 구해놓은 트리도 모두 변경해 주어야 한다.
void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end)
		return;		// 바꾸고싶은 노드가 트리 안에 포함되지 않을 경우는 불가능하다.
	
	if (start != end)	// 리프 노드인지 검사한다.
	{
		int mid = (start + end) / 2;
		// diff는 원래의 값에서 변한 정도.
		update(tree, node * 2, start, mid, index, diff);			// 왼
		update(tree, node * 2 + 1, mid + 1, end, index, diff);	// 오
	}
}

int main()
{
	/*
	만약, N이 2의 제곱꼴인 경우에는 Full Binary Tree
	또, 그 때 높이는 lgN 입니다. 
	리프 노드가 N개인 Full Binary Tree는 필요한 노드의 개수가 2*N-1개 입니다.

	N이 2의 제곱꼴이 아닌 경우에는 높이가 H = lgN
	총 세그먼트 트리를 만드는데 필요한 배열의 크기는 2^(H+1) - 1개
	*/

	vector<long long> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int height = ceil(log2(a.size()));		// 높이
	cout << height << endl;
	cout << pow(2, height + 1) << endl;		// 크기

	vector<long long> tree;
	tree.assign(pow(2, height + 1), 0);

	init(a, tree, 0, 0, a.size()-1);
	
	for (int i = 0; i < a.size(); ++i)
		cout << tree[i] << " ";
}

