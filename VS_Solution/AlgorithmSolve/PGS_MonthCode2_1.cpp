#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; ++i)
    {
        int temp = i;
        int count = 0;
        while (temp >= 1)
        {
            if (i % temp == 0) // 나누어 떨어진다면
                count++;
            temp--;
        }
        
        if (count % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}