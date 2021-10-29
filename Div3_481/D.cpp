#include <iostream>

using namespace std;

typedef long long ll;

ll seq[100005];
int change[9][2] = {
    {0,0}, {0,1}, {0,-1}, {1,0}, {1,-1}, {1,1}, {-1,-1}, {-1,0}, {-1,1}
};

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    if(n <= 2) {
        cout << "0\n";
        return 0;
    }

    int minChanges = 100005;

    for(int i = 0; i < 9; ++i) {
        ll b1 = seq[0] + change[i][0];
        ll b2 = seq[1] + change[i][1];

        ll dif = b1 - b2;
        int changes = 0;
        bool arithmetic = true;

        if(change[i][0] != 0) {
            ++changes;
        }
        if(change[i][1] != 0) {
            ++ changes;
        }

        for(int i = 2; i < n; ++i) {
            ll value = b2 - (i-1) * dif;
            if(value == seq[i]) {
                continue;
            } else if (value == seq[i] + 1 || value == seq[i] - 1) {
                ++changes;
            } else {
                arithmetic = false;
                break;
            }
        }

        if(arithmetic) {
            minChanges = min(minChanges, changes);
        } 
    }
    
    if(minChanges == 100005) {
        cout << "-1\n";
    } else {
        cout << minChanges << '\n';
    }

}