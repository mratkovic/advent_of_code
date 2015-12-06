#include <bits/stdc++.h>
#define _ << " " <<

#define R first
#define C second

using namespace std;
typedef long long llint;
typedef pair<int, int> Cell;


int grid[1024][1024];

auto on = [](Cell c) {grid[c.R][c.C] += 1;};
auto off = [](Cell c) {grid[c.R][c.C] = max(0, grid[c.R][c.C]-1);};
auto toggle = [](Cell c) {grid[c.R][c.C] += 2;};

void apply(Cell lo, Cell hi, function<void(Cell)> f) {
    for(int i = lo.R; i <= hi.R; ++i)
        for(int j = lo.C; j <= hi.C; ++j)
            f({i, j});
}

int cntOn() {
    int cnt = 0;
    for(int i = 0; i < 1000; ++i)
        for(int j = 0; j < 1000; ++j)
            cnt += grid[i][j];
    return cnt;

}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

Cell parseCell(string line) {
    int index = line.find(',');

    int r = stoi(line.substr(0, index));
    int c = stoi(line.substr(index+1, line.size()));
    return {r, c};
}

int main() {
    string line;

    while(getline(cin, line)) {
        vector<string> parts = split(line, ' ');

        int id1 = 2, id2 = 4; //toggle 461,550 through 564,900 or turn off 370,39 through 425,839
        function<void(Cell)> f;

        if(parts.size() == 4) {
            id1 = 1, id2 = 3;
            f = toggle;
        } else {
            f = (parts[1] == "on") ? on : off;
        }

        Cell lo = parseCell(parts[id1]);
        Cell hi = parseCell(parts[id2]);
        apply(lo, hi, f);
    }

    cout << cntOn() << endl;
    return 0;
}


