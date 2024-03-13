#include <iostream>
#include <vector>

using namespace std;


pair<int,int> fibonacci(int n, vector<pair<long, long>>& v)
{
    for (int i = 2; i <= n; ++i)
    {
        if (v[i].first == 0 && v[i].second == 0)
        {
            //v[i].first = fibonacci(n - 1, v).first + fibonacci(n - 2, v).first;
            //v[i].second = fibonacci(n - 1, v).second + fibonacci(n - 2, v).second;
            v[i].first = v[i - 1].first + v[i - 2].first;
            v[i].second = v[i - 1].second + v[i-2].second;
        }
    }

    return v[n];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin >> t;

    vector<pair<long, long>> v(41);

    v[0] = make_pair(1, 0);
    v[1] = make_pair(0, 1);

    while (t--)
    {
        int solve;
        cin >> solve;

        auto fibo = fibonacci(solve, v);
        cout << fibo.first << " " << fibo.second << "\n";
    }
}