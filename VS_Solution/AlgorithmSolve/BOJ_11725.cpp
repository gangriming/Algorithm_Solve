#include <iostream>

using namespace std;

struct node
{
	int num = -1;	// -1 = 없음
	node* parent = nullptr;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 트리 루트 1
	int count = 0;
	cin >> count;


	// 되긴 하는데, 원하는 답이 아님.
	/*
	node tree[100001];
	tree[1].num = 1;

	for (int i = 0; i < count-1; ++i)
	{
		int a, b = 0;
		cin >> a >> b;

		if (a == 1 || b == 1)	// 1의(루트 노드의) 자식인 경우
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
		cout << tree[i + 2].parent->num << endl;
	*/
}