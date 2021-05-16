#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i)
    {
        string bit = bitset<20>(numbers[i]).to_string();

        long long num = numbers[i];

        while (true)
        {
            num++;
            string combit = bitset<20>(num).to_string();

            int count = 0;
            for (int i = combit.length() - 1; i >= 0; --i)
            {
                if (combit[i] != bit[i])
                    count++;

                if (count > 2)
                    break;
            }

            if (count > 2)
                continue;
            else
            {
                answer.push_back(num);
                break;
            }
        }
    }

    // 2개 테케가 시간초과뜸;
    return answer;
}

int main()
{
    solution(vector<long long>{2, 7, 10<<15});
}