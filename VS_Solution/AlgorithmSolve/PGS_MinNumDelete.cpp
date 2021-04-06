#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(min_element(arr.begin(), arr.end()));
    if (arr.empty())
        arr.push_back(-1);

    return arr;
}

int main()
{
    solution(vector<int>{4, 3, 2, 1});
}