#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Hydrothermal Venture
*/

int grid[1005][1005];


int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    for(int i = 0; i < 500; ++i) {
        string start, div, end;
        cin >> start >> div >> end;

        int sX, sY, eX, eY;

        sX = stoi(start.substr(0, start.find(",")));
        sY = stoi(start.substr(start.find(",") + 1, start.size()));

        eX = stoi(end.substr(0, end.find(",")));
        eY = stoi(end.substr(end.find(",") + 1, end.size()));

        //if(sX != eX && sY != eY) continue;
        //cout << sX << " " << sY << " " << eX << " " << eY << '\n';
        if(sX == eX) {
            for(int j = min(sY, eY); j <= max(sY, eY); ++j) {
                grid[sX][j] += 1;
            }
        } else if (sY == eY) {
            for(int j = min(sX, eX); j <= max(sX, eX); ++j) {
                grid[j][sY] += 1;
            }
        } else if (abs(sY - eY) == abs(sX - eX)) {
            if(sX < eX) {
                if(sY < eY) {
                    for(int i = 0; sX + i <= eX; ++i) {
                        grid[sX + i][sY + i] += 1;
                    }
                } else {
                    for(int i = 0; sX + i <= eX; ++i) {
                        grid[sX + i][sY - i] += 1;
                    }
                }
            } else if (eX < sX) {
                if(eY < sY) {
                    for(int i = 0; eX + i <= sX; ++i) {
                        grid[eX + i][eY + i] += 1;
                    }
                } else {
                    for(int i = 0; eX + i <= sX; ++i) {
                        grid[eX + i][eY - i] += 1;
                    }
                }
            }
        }
    }
    int total = 0;
    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            if(grid[i][j] > 1) ++total;
        }
    }
    cout << total << '\n';
}