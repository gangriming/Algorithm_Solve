#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>


using namespace std;
int main()
{
	auto clock = time(nullptr) + 32400; // ���� ���� �ð��� UTC + 0��.
	auto local_clock = localtime(&clock);
	
	
	//cout << local_clock->tm_year + 1900 << "-" << local_clock->tm_mon + 1<< "-" << local_clock->tm_mday;	// �̰� setw, setfill�� �����.
	std::printf("%d-%02d-%02d", local_clock->tm_year + 1900, local_clock->tm_mon + 1, local_clock->tm_mday); // ���������� ���°� �� �� ����..
}