#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

struct Node {
    Node *child[26];
    int max = 0;
    string record = "";

    Node () {
        max = 0;
        record = "";
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
}; typedef Node* trie;
trie root = new Node();

void insert(trie T, string &s, int cnt){
    for (char ch : s) {
        int idx = ch - 'a';
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
        if (cnt > T->max) {
            T->max = cnt;
            T->record = s;
        }
    }
}

string query(trie T, string &s) {
    for (char ch : s) {
        int idx = ch - 'a';
        if (!T->child[idx]) return "No suggestion!";
        T = T->child[idx];
    }
    return T->record;
}

inline void solve(){
    int n, q; cin >> n >> q;
    while (n--) {
        string s; int cnt; cin >> s >> cnt;
        insert(root, s, cnt);
    }
    while (q--) {
        string s; cin >> s;
        cout << query(root, s) << endl;
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
    int t = 1; // cin >> t;
    while (t--) solve();
    // clock_t end = clock();
    // get_time_n_mem(start, end);
    return 0;
}