#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

struct Node {
    Node *child[2];
    int count; // Đếm số phần tử trong cây con của nút hiện tại

    Node () {
        for (int i = 0; i < 2; i++) {
            child[i] = nullptr;
        }
        count = 0;
    }
}; typedef Node* trie;
trie root = new Node();

void insert(trie T, int &s){
    ++T->count;
    for (int i = 31; i >= 0; i--) {
        int idx = (s >> i) & 1;
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
        ++T->count;
    }
}

int query(trie T, int &k) {
    int ans = 0;
    for (int i = 31; i >= 0; --i){
        if (T->child[0] && T->child[0]->count >= k) {
            T = T->child[0];
        } else {
            if (T->child[0]) k -= T->child[0]->count;
            ans |= (1 << i);
            T = T->child[1];
        }
    }
    return ans;
}

inline void solve(){
    int c; cin >> c;
    if (c == 1) {
        int s; cin >> s;
        insert(root, s);
    } else if (c == 2) {
        int k; cin >> k;
        cout << query(root, k) << endl;
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