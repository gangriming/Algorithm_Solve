#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// ���׸�Ʈ Ʈ���� �ʱ�ȭ
long long init(vector<long long>& a, vector<long long>& tree,
	int node, int start, int end)
{
	// �迭 a
	// ���׸�Ʈ Ʈ�� tree
	// ���׸�Ʈ Ʈ�� ��� ��ȣ node
	// node�� ����ϴ� ���� ������ start ~ end
	if (start == end)	// ��尡 ���� ����� ���.
		return tree[node] = a[start];	// ���� ���� �迭�� �� ���Ҹ� ������ �ϱ� ������
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


// �� ���ϴ� ��.
long long sum(vector<long long>& tree, int node, int start, int end,
	int left, int right)
{
	if (left > end || right < start)		// left, right�� start, end�� ��ġ�� ����. = Ʈ���� Ž���� �ʿ� X
		return 0;
	if (left <= start && right >= end)	// left, right�� start, end������ �� �����Ҷ�
		return tree[node];	// �� �θ��� �ʰ� ��� ���Ѱ��� �����Ѵ�.

	// �� �̿��� ���.
	// start�� end�ȿ� �츮�� ã�� left, right�� ��� ���Ե� ���.
	int mid = (start + end) / 2;

	return sum(tree, node * 2,		// ����
		start,
		mid,
		left,
		right)
		+
		sum(tree, node * 2 + 1,		// ������
			mid + 1,
			end,
			left,
			right);

}

// ���� ����ȴٸ�, ���� ���س��� Ʈ���� ��� ������ �־�� �Ѵ�.
void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end)
		return;		// �ٲٰ���� ��尡 Ʈ�� �ȿ� ���Ե��� ���� ���� �Ұ����ϴ�.
	
	if (start != end)	// ���� ������� �˻��Ѵ�.
	{
		int mid = (start + end) / 2;
		// diff�� ������ ������ ���� ����.
		update(tree, node * 2, start, mid, index, diff);			// ��
		update(tree, node * 2 + 1, mid + 1, end, index, diff);	// ��
	}
}

int main()
{
	/*
	����, N�� 2�� �������� ��쿡�� Full Binary Tree
	��, �� �� ���̴� lgN �Դϴ�. 
	���� ��尡 N���� Full Binary Tree�� �ʿ��� ����� ������ 2*N-1�� �Դϴ�.

	N�� 2�� �������� �ƴ� ��쿡�� ���̰� H = lgN
	�� ���׸�Ʈ Ʈ���� ����µ� �ʿ��� �迭�� ũ��� 2^(H+1) - 1��
	*/

	vector<long long> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int height = ceil(log2(a.size()));		// ����
	cout << height << endl;
	cout << pow(2, height + 1) << endl;		// ũ��

	vector<long long> tree;
	tree.assign(pow(2, height + 1), 0);

	init(a, tree, 0, 0, a.size()-1);
	
	for (int i = 0; i < a.size(); ++i)
		cout << tree[i] << " ";
}

