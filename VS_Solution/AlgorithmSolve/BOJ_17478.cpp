#include <iostream>

using namespace std;

void chatbot(int count, int initCount, int addCount)
{
	if (count == 0)
	{
		for (int i = 0; i < initCount; ++i)
			cout << "____";
		cout << "\"����Լ��� ������?\"" << endl;
		for (int i = 0; i < initCount; ++i)
			cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		for (int i = 0; i < initCount; ++i)
			cout << "____";
		cout << "��� �亯�Ͽ���." << endl;
		return;
	}
	else
	{
		addCount++;
		for (int i = 0; i < initCount - count; ++i)
			cout << "____";
		cout << "\"����Լ��� ������?\"" << endl;
		for (int i = 0; i < initCount - count; ++i)
			cout << "____";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
		for (int i = 0; i < initCount - count; ++i)
			cout << "____";
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���."		   << endl;
		for (int i = 0; i < initCount - count; ++i)
			cout << "____";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""  << endl;

	
		chatbot(count - 1, initCount, addCount);

		for (int i = 0; i < initCount - count; ++i)
			cout << "____";
		cout << "��� �亯�Ͽ���." << endl;
	}
}

int main()
{
	int count;
	cin >> count;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	chatbot(count, count, 0);
}