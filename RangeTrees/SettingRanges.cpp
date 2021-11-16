#include <iostream>

using namespace std;

const int MAXN = 100000;
const int UNSET = -1;

int lazyset[MAXN * 3];
int maxrt[MAXN * 3];

void recalculate(int id) {
    if(lazyset[id] != UNSET) {
        maxrt[id] = lazyset[id];
    } else {
        maxrt[id] = max(maxrt[id*2], maxrt[id*2+1]);
    }
}

void propagate(int id) {
    if (lazyset[id] == UNSET) return;
    lazyset[id*2] = lazyset[id];
    lazyset[id*2+1] = lazyset[id];

    maxrt[id*2] = lazyset[id];
    maxrt[id*2+1] = lazyset[id];

    lazyset[id] = UNSET;
}

void update(int uL, int uR, int l, int r, int id, int v) {
    if(uL > r || uR < l) return;

    if(uL <= l && uR >= r) {
        lazyset[id] = maxrt[id] = v;
        return;
    }
    propagate(id);

    int mid = (l + r) / 2;
    if(uL < mid) update(uL, uR, l, mid, id*2, v);
    if(uR > mid) update(uL, uR, mid+1, r, id*2+1, v);
    recalculate(id);
}

int query(int qL, int qR, int l, int r, int id) {
    if(qL > r || qR < l) {
        return -1;
    }
    if(qL <= l && qR >= r) {
        return maxrt[id];
    }
    propagate(id);
    int mid = (l + r) / 2;
    int ans = -1;
    if(qL < mid) ans = max(ans, query(qL, qR, l, mid, id*2));
    if(qR > mid) ans = max(ans, query(qL, qR, mid+1, r, id*2+1));
    return ans;
}


int main() {



}