#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

struct Node {
    Node *child[2];
    int cnt = 0;

    Node () {
        for (int i = 0; i < 2; i++) {
            child[i] = nullptr;
        }
        cnt = 0;
    }
}; typedef Node* trie;
trie root = new Node();

inline void insert(trie T, int a, int cnt = 1){
    for (int i = 31; i >= 0; i--) {
        int idx = (a >> i) & 1;
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
        T->cnt += cnt;
    }
}

inline int getMaxXor(trie T, int bx, int by) {
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        if (!T) break;
        int bit_x = (bx >> i) & 1;
        int bit_y = (by >> i) & 1;
        if (bit_y == 1) {
            if (T->child[bit_x]) {
                ans += T->child[bit_x]->cnt;
            }
            T = T->child[bit_x ^ 1];
        } else {
            T = T->child[bit_x];
        }
    }
    // if (T) {
    //     ans += T->cnt;
    // }
    return ans;
}

inline void solve(){
    int c; cin >> c;
    if (c == 1) {
        int a; cin >> a;
        insert(root, a);
    } else if (c == 2) {
        int a; cin >> a;
        insert(root, a, -1);
    } else {
        int bx, by; cin >> bx >> by;
        cout << getMaxXor(root, bx, by) << endl;
    }
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
    int t = 1; cin >> t;
    while (t--) solve();
    // clock_t end = clock();
    // get_time_n_mem(start, end);
    return 0;
}