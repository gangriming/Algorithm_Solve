#include <iostream>

using namespace std;

struct node
{
	int num = -1;	// -1 = ����
	node* parent = nullptr;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Ʈ�� ��Ʈ 1
	int count = 0;
	cin >> count;


	// �Ǳ� �ϴµ�, ���ϴ� ���� �ƴ�.
	/*
	node tree[100001];
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
		cout << tree[i + 2].parent->num << endl;
	*/
}