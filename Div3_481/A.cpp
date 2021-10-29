#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int seq[55];
set<int> seen;

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    for(int i = n-1; i >=0; --i) {
        if(seen.count(seq[i]) == 0) {
            seen.insert(seq[i]);
        } else {
            seq[i] = -1;
        }
    }

    cout << seen.size() << '\n';
    for(int i = 0; i < n; ++i) {
        if(seq[i] != -1) {
            cout << seq[i] << " ";
        }
    }
    cout << '\n';
}