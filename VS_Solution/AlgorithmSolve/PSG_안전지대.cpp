#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int solution(vector<vector<int>> board) {
    int answer = 0;

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
            if (board[i][j] == 1)
            {
                // 주변 위험 표시.
                // 하면서, 이미 지뢰가 매설된곳을 바꾸면 안된다.
                // 예쁘게 쓸 방법이 없나..
                if (i > 0 && board[i - 1][j] != 1) board[i - 1][j] = 2; // 위
                if (i < board.size() - 1 && board[i + 1][j] != 1) board[i + 1][j] = 2;  // 아래
                if (j > 0 && board[i][j - 1] != 1) board[i][j - 1] = 2; // 왼
                if (j < board.size() - 1 && board[i][j + 1] != 1) board[i][j + 1] = 2; // 우
                if (i > 0 && j > 0 && board[i - 1][j - 1] != 1) board[i - 1][j - 1] = 2; // 왼위
                if (i < board.size() - 1 && j > 0 && board[i + 1][j - 1] != 1) board[i + 1][j - 1] = 2; // 왼아래
                if (i > 0 && j < board.size() - 1 && board[i - 1][j + 1] != 1) board[i - 1][j + 1] = 2; // 오른위
                if (i < board.size() - 1 && j < board.size() - 1 && board[i + 1][j + 1] != 1) board[i + 1][j + 1] = 2; // 오른아래
            }
        }
    }

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
           // cout << board[i][j] << " "; // 디버깅용
            if (board[i][j] == 0) answer++;
        }
       //cout << endl;  // 디버깅용
    }

    return answer;
}

int main()
{
    vector<vector<int>> v{ { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 } };

    solution(v);
}