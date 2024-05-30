#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

pair<int, int> check_pos(const string& str) 
{
    return { str[0] - 'A', str[1] - '1' };
}

// 다시 문자열로 변환
string pos_to_str(pair<int, int> pos) 
{
    return string(1, 'A' + pos.first) + to_string(pos.second + 1);
}

// 움직임을 정의
const unordered_map<string, pair<int, int>> moves = 
{
    {"R", {1, 0}}, {"L", {-1, 0}}, {"B", {0, -1}}, {"T", {0, 1}},
    {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1, -1}}, {"LB", {-1, -1}}
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string king, stone;
    int move_count;
    cin >> king >> stone >> move_count;

    auto king_pos = check_pos(king);
    auto stone_pos = check_pos(stone);

    for (int i = 0; i < move_count; ++i) 
    {
        string cmd;
        cin >> cmd;

        auto move = moves.at(cmd);
        pair<int, int> new_king_pos = { king_pos.first + move.first, king_pos.second + move.second };

        // 킹이 체스판 밖으로 나가는지 확인
        if (new_king_pos.first < 0 || new_king_pos.first >= 8 ||
            new_king_pos.second < 0 || new_king_pos.second >= 8) 
            continue;

        // 킹이 움직인 위치에 돌이 있는 경우
        if (new_king_pos == stone_pos) 
        {
            pair<int, int> new_stone_pos = { stone_pos.first + move.first, stone_pos.second + move.second };

            // 돌이 체스판 밖으로 나가는지 확인
            if (new_stone_pos.first < 0 || new_stone_pos.first >= 8 ||
                new_stone_pos.second < 0 || new_stone_pos.second >= 8) 
                continue;

            stone_pos = new_stone_pos;
        }

        king_pos = new_king_pos;
    }

    cout << pos_to_str(king_pos) << "\n" << pos_to_str(stone_pos) << "\n";
}