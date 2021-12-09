#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*

*/

int ones[50];
int zeroes[50];
int len;

string bits[1005];

int findOxygen() {
    vector<string> keep(bits, bits+1000);
    vector<string> a;
    vector<string> b;
    int depth = 0;    
    for(int i = 0; i < len; ++i) {
        a.clear();
        b.clear();

        for(auto k : keep) {
            if(k[i] == '0') a.push_back(k);

            if(k[i] == '1') b.push_back(k);
        }

        if(a.size() > b.size()) keep = a;
        else keep = b;
    }

    cout << keep[0] << '\n';
    int val = 0;
    for(int i = 0; i < len; ++i) {
        val *= 2;

        if(keep[0][i] == '1') ++val;
    }

    return val;
}

int findCarbon() {
    vector<string> keep(bits, bits+1000);
    vector<string> a;
    vector<string> b;
    int depth = 0;    
    for(int i = 0; i < len; ++i) {
        a.clear();
        b.clear();

        for(auto k : keep) {
            if(k[i] == '0') a.push_back(k);

            if(k[i] == '1') b.push_back(k);
        }

        if(a.size() > b.size()) keep = b;
        else keep = a;
    }

    cout << keep[0] << '\n';
    int val = 0;
    for(int i = 0; i < len; ++i) {
        val *= 2;

        if(keep[0][i] == '1') ++val;
    }

    return val;
}

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    string in;

    for(int i = 0; i < 1000; ++i) {
        cin >> bits[i];
    }

    sort(bits, bits + 1000);

    /*
    for(int i = 0; i < 1000; ++i) {
        cout << bits[i] << '\n';
    }
    */

    len = bits[0].size();

    cout << findOxygen() << '\n';
    cout << findCarbon() << '\n';

    cout << findOxygen() * findCarbon() << '\n';

}


/*

Part A

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    string in;
    int len;
    for(int i = 0; i < 1000; ++i) {
        cin >> in;
        len = in.size();

        for(int j=  0; j < in.size(); ++j) {
            if(in[j] == '0') {
                ++zeroes[j];
            } else {
                ++ones[j];
            }
        }
    }

    ll g = 0;
    ll e = 0;

    for(int i = 0; i < len; ++i) {
        g *= 2;
        e *= 2;

        if(zeroes[i] > ones[i]) {
            ++g;
        } else {
            ++e;
        }
    }

    cout << e * g << '\n';
}
*/