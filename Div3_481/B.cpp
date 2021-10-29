#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int con = 0;
    int changes = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'x') {
            ++con;
        } else {
            if(con >= 3) {
                changes += con - 2;
            }
            con = 0;
        }
    }
    if(con >= 3) {
        changes += con - 2;
    }

    cout << changes << '\n';
}   