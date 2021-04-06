#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//bool compare(string a, string b, int n)
//{
//    return a[n] > b[n];
//}

vector<string> solution(vector<string> strings, int n) {

    //sort(strings.begin(), strings.end(), [&](string& a, string& b, int n)->bool {return a[n] > b[n]; });
    vector<string> answer(strings.begin(), strings.end());

    return answer;
}

int main()
{
    solution(vector<string>{"sun", "bed", "car"}, 1);
}