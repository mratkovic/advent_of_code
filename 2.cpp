#include <bits/stdc++.h>

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

using namespace std;


inline int getArea(int l, int w, int h) {
    return 2*(l*w + w*h + h*l) + min3(l*w, w*h, h*l);
}

inline int getRibbon(int l, int w, int h) {
    return l*w*h + 2*(l + w + h - max3(l, w, h));
}
int main() {
    int l, w, h;
    int paper = 0, ribbon = 0;

    while(scanf("%dx%dx%d", &l, &w, &h) == 3) {
        paper += getArea(l, w, h);
        ribbon += getRibbon(l, w, h);
    }

    cout << paper << endl;
    cout << ribbon << endl;
    return 0;

}

