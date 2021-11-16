#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

bool paintRed[100005];
bool paintYellow[100005];
bool paintBlue[100005];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int c = 1; c <= t; ++c) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        fill(paintRed, paintRed + 100005, false);
        fill(paintBlue, paintBlue + 100005, false);
        fill(paintYellow, paintYellow + 100005, false);

        for(int i = 0; i < n; ++i) {
            if(s[i] == 'U') continue;
            else if(s[i] == 'R') {
                paintRed[i] = true;
            } else if(s[i] == 'Y') {
                paintYellow[i] = true;
            } else if(s[i] == 'B') {
                paintBlue[i] = true;    
            } else if(s[i] == 'O') {
                paintRed[i] = true;
                paintYellow[i] = true;
            } else if(s[i] == 'P') {
                paintRed[i] = true;
                paintBlue[i] = true;
            } else if (s[i] == 'G') {
                paintBlue[i] = true;
                paintYellow[i] = true;
            } else {
                paintBlue[i] = true;
                paintYellow[i] = true;
                paintRed[i] = true; 
            }
            
        }
        ll ans = 0;

        ll tempAns = 0;
        bool painting = false;

        // Red paint
        tempAns = 0;
        painting = paintRed[0];
        for(int i = 1; i < n; ++i) {
            if(!paintRed[i] && painting) {
                painting = false;
                ++tempAns;
            } else if(paintRed[i]) {
                painting = true;
            } else if(!paintRed[i]) {
                painting = false;
            }
        }
        if(painting) ++tempAns;
        ans += tempAns;
        // Blue paint
        tempAns = 0;
        painting = paintBlue[0];
        for(int i = 1; i < n; ++i) {
            if(!paintBlue[i] && painting) {
                painting = false;
                ++tempAns;
            } else if(paintBlue[i]) {
                painting = true;
            } else if(!paintBlue[i]) {
                painting = false;
            }
        }
        if(painting) ++tempAns;
        ans += tempAns;
        // Yellow paint
        tempAns = 0;
        painting = paintYellow[0];
        for(int i = 1; i < n; ++i) {
            if(!paintYellow[i] && painting) {
                painting = false;
                ++tempAns;
            } else if(paintYellow[i]) {
                painting = true;
            } else if(!paintYellow[i]) {
                painting = false;
            }
        }
        if(painting) ++tempAns;
        ans += tempAns;

        cout << "Case #" << c << ": " << ans << '\n';
    }
}