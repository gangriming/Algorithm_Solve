#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long treeInit(vector<long long>& numVec, vector<long long> seg,
	int node, int start, int end)
{
	if (start == end)	// 리프 노드
		return seg[node] = numVec[start];
	else
	{
		int mid = (start + end) / 2;
		return seg[node] = treeInit(numVec, seg,
			node * 2,
			start,
			mid + treeInit(numVec, seg, node * 2 + 1, mid + 1, end));
	}
}

int main()
{
	int num = 0;
	cin >> num;
	int numchange, sumCount = 0;
	cin >> numchange >> sumCount;

	int height = ceil(log2(num));		// 높이
	vector<long long> seg(pow(2, height + 1) , 0);

	vector<long long> numVec;
	numVec.reserve(num);

	for (int i = 0; i < num; ++i)
	{
		long long temp;
		cin >> temp;
		numVec.push_back(temp);
	}

	treeInit(numVec, seg, 0, 0, numVec.size() - 1);

	cout << endl;
}