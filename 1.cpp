#include <bits/stdc++.h>
using namespace std;


int main() {
    string line; cin >> line;
    bool first = true;

    int ans = 0;

    for(int i = 0; i < line.size(); ++i) {
        char c = line[i];
        ans += (c == '(') - (c == ')');

        if(first && ans < 0) {
            cout << "First time: " << i + 1 << endl;
            first = false;
        }
    }

    cout << ans << endl;
    return 0;

}
