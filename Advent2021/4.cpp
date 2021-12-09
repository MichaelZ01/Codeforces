#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Giant Squid

5 * 5 Grid
*/

int nums[1005];

int rows[5];
int cols[5];

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
        nums[index] = stoi(val);

        start = end + 1;
        end = input.find(",", start);
        ++index;
    }
    val = input.substr(start, end - start);
    nums[index] = stoi(val);   


    ll globalMax = -1;
    int globalFirst = 10000;
    ll globalLastMax = -1;
    int globalLast = -1;
    for(int b = 0; b < 100; ++ b) {
        ll localMax = 0;
        int localFirst = 10001;

        map<int,pair<int,int>> lookup;
        fill(rows, rows + 5, 0);
        fill(cols, cols + 5, 0);

        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) {
                int num;
                cin >> num;

                lookup.emplace(num, pair<int,int>(i,j));
            }
        }

        for(int i = 0; i <= index; ++i) {
            if(lookup.count(nums[i]) != 0) {
                rows[lookup[nums[i]].first] += 1;
                cols[lookup[nums[i]].second] += 1;
            }

            if(rows[lookup[nums[i]].first] == 5 || 
                cols[lookup[nums[i]].second] == 5 ) {

                //cout << "found at: " << nums[i] << '\n';

                localFirst = i + 1;
                //cout << "local:" << localMax << '\n';
                for(int j = i + 1; j <= index; ++j) {
                    if(lookup.count(nums[j]) != 0) localMax += nums[j];
                    
                }

                localMax *= nums[i];
                break;
            }
        }

        if(localFirst < globalFirst) {
            globalMax = localMax;
            globalFirst = localFirst;
        }

        if(localFirst > globalLast) {
            globalLastMax = localMax;
            globalLast = localFirst;         
        }

    }

    cout << globalMax << '\n';
    cout << globalLastMax << '\n';

}