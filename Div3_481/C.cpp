#include <iostream>

using namespace std;

typedef long long ll;

ll rooms[200005];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> rooms[i];
    }

    ll room = 0;
    ll dorm = 1;

    ll prevB = 0;
    ll b;
    for(int i = 0; i < m; ++i) {
        cin >> b;

        ll dif = b - prevB;
        while(dif >= 0) {
            if(rooms[dorm] - room >= dif) {
                room += dif;
                break;
            } else {
                dif -= rooms[dorm] - room;
                ++dorm;
                room = 0;
            }
        }

        prevB = b;
        cout << dorm << " " << room << '\n';
    }
}