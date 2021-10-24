#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

map<string, int> freq;

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 1; i < n; ++i) {
        string ss = s.substr(i-1,2);
        freq[ss] += 1;
    }

    string maxS;
    int maxFreq = 0;
    for(auto it = freq.begin(); it != freq.end(); ++it) {
        if(it->second > maxFreq) {
            maxFreq = it->second;
            maxS = it->first;
        }
    }

    cout << maxS << '\n';
}