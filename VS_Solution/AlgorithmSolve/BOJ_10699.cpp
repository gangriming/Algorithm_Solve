#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>


using namespace std;
int main()
{
	auto clock = time(nullptr) + 32400; // 백준 서버 시간이 UTC + 0임.
	auto local_clock = localtime(&clock);
	
	
	//cout << local_clock->tm_year + 1900 << "-" << local_clock->tm_mon + 1<< "-" << local_clock->tm_mday;	// 이건 setw, setfill을 써야함.
	std::printf("%d-%02d-%02d", local_clock->tm_year + 1900, local_clock->tm_mon + 1, local_clock->tm_mday); // 형식지정자 쓰는게 좀 더 편함..
}