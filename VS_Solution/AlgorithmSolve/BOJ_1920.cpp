#include <iostream>
#include <map>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ����Ʈ�� ����.
	// Ʈ��.. �׷���.. �׷��� ������ �����̳� map, set
	// set�� operator[]�� �ȵǾ map���� �ٲ㺽.
	// �ݾ� ������ �˻��غ��� �����̾����� ������.

	int n;
	cin >> n;

	map<int, int> m;
	
	for(int i = 0 ; i < n ; ++i)
	{
		int temp;
		cin >> temp;
		m.insert(make_pair(n, temp));
	}
}