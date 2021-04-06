#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // ÇØ½Ã?
    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        for (int j = i+1; j < phone_book.size(); ++j)
        {
            if (phone_book[i].length() <= phone_book[j].length() &&
                phone_book[i]
                == phone_book[j].substr(0, phone_book[i].length()))
                return false;
            else if (phone_book[i].length() > phone_book[j].length() &&
                phone_book[i].substr(0, phone_book[j].length())
                == phone_book[j])
                return false;
            
        }
    }

    return answer;
}

int main()
{
    cout << solution(vector<string>{"97213", "1195524421", "119"}) << endl;
    cout << solution(vector<string>{"123", "456", "789"}) << endl;
    cout << solution(vector<string>{"12", "123", "1235", "567", "88"}) << endl;
}