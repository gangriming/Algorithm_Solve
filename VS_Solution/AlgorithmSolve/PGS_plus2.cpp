#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> a;

    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
            a.insert(numbers[i] + numbers[j]);
    }
    vector<int> answer(a.begin(), a.end());

    return answer;
}

int main()
{
    solution(vector<int>{2, 1, 3, 4, 1});
    solution(vector<int>{5,0,2,7});
}