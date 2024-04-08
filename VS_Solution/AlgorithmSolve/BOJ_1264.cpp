#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        string str;
        getline(cin, str);

        if (str == "#")
            return 0;

        istringstream ss(str);
        string stringBuffer;
        vector<string> x;

        int cnt = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                cnt++;
        }

        cout << cnt << endl;
    }
}