#include <iostream>
#include <math.h>
#include <map>

using namespace std;

//vector<long> save;
// ������ �ұ�
map<int, long> save;

// top-down�̾ ��ǥ ���ں��� �����״ϱ�
long pibonachi(int n)
{
	// 0, 1�� �н�
	if (n < 2)
		return save[n] = n;


	if (save[n] > 0)	// �̸� ���ؼ� ������ ���� �ִٸ�
		return save[n];	// �ٷ� ��ȯ�Ѵ�.
	else
	{
		// �ƴ϶�� ��͸� ����ؼ� ���� ���Ѵ�.
		save[n] = pibonachi(n - 1) + pibonachi(n - 2);
	}
	return save[n];
}


int main()
{
	int n;
	cin >> n;

	// top-down
	pibonachi(n);

	cout << save[n] << endl;
}