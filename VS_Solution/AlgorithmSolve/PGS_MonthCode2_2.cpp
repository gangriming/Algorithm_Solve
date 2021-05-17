#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    // **기존 풀이**
    /*
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
    */

    // **해설 보고 푼 풀이**
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] % 2 == 0)     // 짝수
        {
            /*
            auto bit = bitset<20>(numbers[i]);

            for (int i = 0; i < bit.size(); ++i)
            {
                if (!bit.test(i)) // 작은 수에서 0 이 나온다면
                {
                    bit.set(i, true);
                    break;
                }
            }
            answer.push_back(bit.to_ullong());
            */

            // 잘 생각해보면, 짝수의 경우에는 무조건 맨 오른쪽 비트(1을나타냄)가 0일테니,
            // 1을 더해서 마지막 오른쪽 비트만 바꾸어준다면, 조건을 충족한다.
            answer.push_back(numbers[i] + 1);
        }
        else                         // 홀수
        {
            // https://withhamit.tistory.com/564 참고
            // 오른쪽에서부터 검색해, 제일 작은 0을 1로 바꾸고
            // 그 다음에 나오는 1을 바꾼다.(없음 말고)
            auto bit = bitset<20>(numbers[i]);

            bool flag = false;
            for (int i = 0; i < bit.size(); ++i)
            {
                if (!bit.test(i)) // 작은 수에서 0 이 나온다면
                {
                    bit.set(i, true);
                    for (int j = i-1; j >= 0; --j)
                    {
                        if (bit.test(j)) // 그다음 작은 1을
                        {
                            bit.set(j, false);
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
            }
            answer.push_back(bit.to_ullong());
        }
    }


    return answer;
}

int main()
{
    solution(vector<long long>{2, 7, 10<<15});
}