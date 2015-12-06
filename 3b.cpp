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
    Position santa(0,0), robo(0,0);
    houses.insert(santa);


    string line; cin >> line;

    for(int i = 0; i < line.size(); ++i) {
        Position* pos = i % 2 ? &santa : &robo;

        move(*pos, line[i]);
        houses.insert(*pos);
    }

    cout << houses.size() << endl;
    return 0;

}

