#include <iostream>

using namespace std;

// Min cur + initial > 0
// Max cur + inital <=w

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n, w;
    cin >> n >> w;

    int minCur = 1e9+5;
    int maxCur = -minCur;
    int cur = 0;
    int a;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        cur += a;

        maxCur = max(maxCur, cur);
        minCur = min(minCur, cur);
    }

    // min: + max: +
    if(maxCur >= 0 and minCur >= 0) {
        if(maxCur > w) {
            cout << "0\n";
        } else {
            cout << w - maxCur + 1 << '\n';
        }
    }
    // min: - max +
    else if(maxCur >= 0 and minCur < 0) {
        if(maxCur > w) {
            cout << "0\n";
        } else {
            int a = w - maxCur;
            if(a + minCur < 0) {
                cout << "0\n";
            } else {
                cout << a + minCur + 1 << '\n';
            }
        }
    }
    // min: - max: -
    else if(minCur < 0 and maxCur < 0) {
        if(w + minCur < 0) {
            cout << "0\n";
        } else {
            cout << w + minCur + 1 << '\n';
        }
    }
}