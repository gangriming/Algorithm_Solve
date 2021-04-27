#include <iostream>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

struct node
{
	char name = ' ';
	node* left = nullptr;
	node* right = nullptr;
};

void preorder(node* node)
{
	if (!node)
		return;
	cout << node->name;
	preorder(node->left);
	preorder(node->right);
}

void inorder(node* node)
{
	if (!node)
		return;
	inorder(node->left);
	cout << node->name;
	inorder(node->right);
}

void postorder(node* node)
{
	if (!node)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->name;
}

int main()
{
	int count = 0;
	cin >> count;

	map<char, node> tree;

	for (int i = 0; i < count; ++i)
	{
		char a, b, c;
		cin >> a >> b >> c;


		auto iter = tree.find(a);
		if (iter == tree.end())	// 없는 노드라면
		{
			tree[a] = node();
			tree[a].name = a;
			if (b != '.')	// 왼쪽 노드 존재
			{
				auto left = tree.find(b);
				if (left == tree.end())
				{
					tree[b] = node();
					tree[b].name = b;
					tree[a].left = &tree[b];
				}
				else
					tree[a].left = &tree[b];
			}
			if (c != '.')
			{
				auto right = tree.find(c);
				if (right == tree.end())
				{
					tree[c] = node();
					tree[c].name = c;
					tree[a].right = &tree[c];
				}
				else
					tree[a].right = &tree[c];
			}
		}
		else		//존재하는 노드라면
		{
			// 따로 안만들어줌.
			if (b != '.')	// 왼쪽 노드 존재
			{
				auto left = tree.find(b);
				if (left == tree.end())
				{
					tree[b] = node();
					tree[b].name = b;
					tree[a].left = &tree[b];
				}
				else
					tree[a].left = &tree[b];
			}
			if (c != '.')
			{
				auto right = tree.find(c);
				if (right == tree.end())
				{
					tree[c] = node();
					tree[c].name = c;
					tree[a].right = &tree[c];
				}
				else
					tree[a].right = &tree[c];
			}
		}
	}

	// 재귀 이용해서 호출만 하면 될듯.
	// 혹시 맵을 이용하면 안되는 이유가 있는지 짜면서 생각해보자아

	preorder(&tree['A']); cout << endl;
	inorder(&tree['A']); cout << endl;
	postorder(&tree['A']);
}