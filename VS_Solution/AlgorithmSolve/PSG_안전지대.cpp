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
                // �ֺ� ���� ǥ��.
                // �ϸ鼭, �̹� ���ڰ� �ż��Ȱ��� �ٲٸ� �ȵȴ�.
                // ���ڰ� �� ����� ����..
                if (i > 0 && board[i - 1][j] != 1) board[i - 1][j] = 2; // ��
                if (i < board.size() - 1 && board[i + 1][j] != 1) board[i + 1][j] = 2;  // �Ʒ�
                if (j > 0 && board[i][j - 1] != 1) board[i][j - 1] = 2; // ��
                if (j < board.size() - 1 && board[i][j + 1] != 1) board[i][j + 1] = 2; // ��
                if (i > 0 && j > 0 && board[i - 1][j - 1] != 1) board[i - 1][j - 1] = 2; // ����
                if (i < board.size() - 1 && j > 0 && board[i + 1][j - 1] != 1) board[i + 1][j - 1] = 2; // �޾Ʒ�
                if (i > 0 && j < board.size() - 1 && board[i - 1][j + 1] != 1) board[i - 1][j + 1] = 2; // ������
                if (i < board.size() - 1 && j < board.size() - 1 && board[i + 1][j + 1] != 1) board[i + 1][j + 1] = 2; // �����Ʒ�
            }
        }
    }

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
           // cout << board[i][j] << " "; // ������
            if (board[i][j] == 0) answer++;
        }
       //cout << endl;  // ������
    }

    return answer;
}

int main()
{
    vector<vector<int>> v{ { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 0 } };

    solution(v);
}