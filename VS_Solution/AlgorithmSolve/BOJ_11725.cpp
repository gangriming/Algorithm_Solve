#include <iostream>
#include <vector>

using namespace std;

struct node
{
	//bool visit = false;
	//int connet = -1;
	int num = -1;
	node* parent = nullptr;
};

void find_parent(int index, vector<bool>* visit, vector<int>** tree, vector<int>* parent)
{
	(*visit)[index] = true;
	
	for (int i = 0; i < (*tree)[index].size(); ++i)
	{
		int next = (*tree)[index][i];

		if (!(*visit)[next])	// �湮 ��������
		{
			(*parent)[next] = index;
			find_parent(next, visit, tree, parent);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Ʈ�� ��Ʈ 1
	int count = 0;
	cin >> count;

	vector<int> *tree = new vector<int>[count + 1];	// Ʈ��
	vector<int> parent(count + 1);	// �θ�
	vector<bool> visit(count + 1, false);

	for (int i = 0; i < count - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	find_parent(1, &visit, &tree, &parent);

	for (int i = 2; i <= count; ++i)
		cout << parent[i] << "\n";


	delete[] tree;

	// �Ǳ� �ϴµ�, ���ϴ� ���� �ƴ�.
	
	/*
	node tree[100005];
	tree[1].num = 1;
	
	for (int i = 0; i < count-1; ++i)
	{
		int a, b = 0;
		cin >> a >> b;
	
		if (a == 1 || b == 1)	// 1��(��Ʈ �����) �ڽ��� ���
		{
			if (a != 1)
			{
				tree[a].num = a;
				tree[a].parent = &tree[1];
			}
			else
			{
				tree[b].num = b;
				tree[b].parent = &tree[1];
			}
		}
		else
		{
			if (tree[a].num == -1)
			{
				tree[a].num = a;
				tree[a].parent = &tree[b];
			}
			else
			{
				tree[b].num = b;
				tree[b].parent = &tree[a];
			}
		}
	}
	
	for (int i = 0; i < count - 1; ++i)
		if (!tree[i+2].parent)
			cout << tree[i + 2].parent->num << "\n";
	*/
}