#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    // **���� Ǯ��**
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

    // **�ؼ� ���� Ǭ Ǯ��**
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] % 2 == 0)     // ¦��
        {
            /*
            auto bit = bitset<20>(numbers[i]);

            for (int i = 0; i < bit.size(); ++i)
            {
                if (!bit.test(i)) // ���� ������ 0 �� ���´ٸ�
                {
                    bit.set(i, true);
                    break;
                }
            }
            answer.push_back(bit.to_ullong());
            */

            // �� �����غ���, ¦���� ��쿡�� ������ �� ������ ��Ʈ(1����Ÿ��)�� 0���״�,
            // 1�� ���ؼ� ������ ������ ��Ʈ�� �ٲپ��شٸ�, ������ �����Ѵ�.
            answer.push_back(numbers[i] + 1);
        }
        else                         // Ȧ��
        {
            // https://withhamit.tistory.com/564 ����
            // �����ʿ������� �˻���, ���� ���� 0�� 1�� �ٲٰ�
            // �� ������ ������ 1�� �ٲ۴�.(���� ����)
            auto bit = bitset<20>(numbers[i]);

            bool flag = false;
            for (int i = 0; i < bit.size(); ++i)
            {
                if (!bit.test(i)) // ���� ������ 0 �� ���´ٸ�
                {
                    bit.set(i, true);
                    for (int j = i-1; j >= 0; --j)
                    {
                        if (bit.test(j)) // �״��� ���� 1��
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