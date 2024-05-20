#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, l;
    cin >> k >> l;

    list<string> waitlist;
    unordered_map<string, list<string>::iterator> student_map;

    for (int i = 0; i < l; ++i) 
    {
        string temp;
        cin >> temp;

        auto it = student_map.find(temp);
        if (it != student_map.end()) {
            waitlist.erase(it->second);
        }

        waitlist.push_back(temp);
        student_map[temp] = --waitlist.end();
    }

    auto it = waitlist.begin();
    int count = 0;

    while (it != waitlist.end() && count < k) {
        cout << *it << "\n";
        ++it;
        ++count;
    }

    return 0;
}