#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Lanternfish
*/

//vector<int> fishes;

ll fishes[10];
ll newFishes[10];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    string input;
    cin >> input;

    int start = 0;
    int end = input.find(",");
    int index = 0;
    string val;
    //cout << input << " " << "end: " << end << '\n';
    while(end != -1) {
        val = input.substr(start, end - start);
        //fishes.push_back(stoi(val));
        fishes[stoi(val)] += 1;

        start = end + 1;
        end = input.find(",", start);
        ++index;
    }
    val = input.substr(start, end - start);
    //fishes.push_back(stoi(val)); 
    fishes[stoi(val)] += 1;

    for(int d = 0; d < 256; ++d) {
        fill(newFishes, newFishes + 8, 0);
        newFishes[8] = fishes[0];
        newFishes[6] += fishes[0];
        for(int i = 1; i < 9; ++i) {
            newFishes[i-1] += fishes[i];
        }

        for(int i = 0; i < 9; ++i) {
            fishes[i] = newFishes[i];
        }
    }

    ll total = 0;
    for(int i = 0; i < 9; ++i) {
        total += fishes[i];
    }

    cout << total << '\n';

    //for(auto f : fishes) cout << f << '\n';
    /*
    for(int d = 0; d < 256; ++d) {
        int newFishes = 0;

        for(auto& f : fishes) {
            if(f == 0) {
                ++newFishes;
                f = 6;
            } else {
                --f;
            }
        }

        fishes.insert(fishes.end(), newFishes, 8);
    }

    cout << fishes.size() << '\n';
    */
}