#include <bits/stdc++.h>
using namespace std;

typedef long long llint;

struct Position {
    llint x;
    llint y;

    Position() {};
    Position(llint x_, llint y_) : x(x_), y(y_) {};
    bool operator< (const Position& o) const {
        if(x != o.x) return x < o.x;
        return y < o.y;
    }

};

void move(Position& pos, char c) {
    pos.x += (c == '>') - (c == '<');
    pos.y += (c == 'v') - (c == '^');
}

int main() {
    set<Position> houses;
    Position pos(0,0);
    houses.insert(pos);


    string line; cin >> line;
    for(char c : line) {
        move(pos, c);
        houses.insert(pos);
    }

    cout << houses.size() << endl;
    return 0;

}

