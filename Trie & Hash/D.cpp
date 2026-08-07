#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

struct Node {
    Node *child[2];

    Node () {
        for (int i = 0; i < 2; i++) {
            child[i] = nullptr;
        }
    }
}; typedef Node* trie;
trie root = new Node();

void insert(trie T, int &s){
    for (int i = 31; i >= 0; i--) {
        int idx = (s >> i) & 1;
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
    }
}

int getMaxXor(trie T, int &s) {
    int ans = 0;
    for (int i = 31; i >= 0; --i){
        int idx = (s >> i) & 1;
        if (T->child[1 - idx]) {
            ans |= (1 << i);
            T = T->child[1 - idx];
        } else if (T->child[idx]) {
            T = T->child[idx];
        } else {
            break;
        }
    }
    return ans;
}

inline void solve(){
    int n, maxXor = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        maxXor = max(maxXor, getMaxXor(root, s));
        insert(root, s);
    }
    cout << maxXor << endl;
}

// inline void get_time_n_mem(clock_t start, clock_t end){
//     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
//     cerr << "\n-----------------------------------\n";
//     cerr << "Time:   " << fixed << setprecision(6) << time_taken << " sec\n";
//     cerr << "-----------------------------------\n";
// }

signed main(){
    nguyentukien
    // clock_t start = clock();
    int t = 1; // cin >> t;
    while (t--) solve();
    // clock_t end = clock();
    // get_time_n_mem(start, end);
    return 0;
}