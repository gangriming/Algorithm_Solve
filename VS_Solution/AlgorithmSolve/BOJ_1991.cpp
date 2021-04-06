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
//
//bool find_node(const node& data, char c) {
//	return data.name == c;
//}

int main()
{
	int count = 0;
	cin >> count;

	//list<node> tree;
	map<char, node> tree;

	for (int i = 0; i < count; ++i)
	{
		char a, b, c;
		cin >> a >> b >> c;

		// list�� �ƴ϶� map���� map<string, node>�� �Ѵٸ�?

		auto iter = tree.find(a);
		if (iter == tree.end())	// ���� �����
		{
			tree[a] = node();
			tree[a].name = a;
			if (b != '.')	// ���� ��� ����
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
		else		//�����ϴ� �����
		{
			// ���� �ȸ������.
			if (b != '.')	// ���� ��� ����
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

	//for (const auto& data : tree)
	//{
	//	cout << "���� ��� " << data.first << endl;
	//	if(data.second.left)
	//		cout << "�� ������" << (data.second.left)->name << endl;
	//	if (data.second.right)
	//		cout << "�� ��������" << (data.second.right)->name << endl;
	//}
	//cout << endl;

	// ��� �̿��ؼ� ȣ�⸸ �ϸ� �ɵ�.
	// Ȥ�� ���� �̿��ϸ� �ȵǴ� ������ �ִ��� ¥�鼭 �����غ��ھ�

}