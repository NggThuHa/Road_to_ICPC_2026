#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

struct Node{
    int data;
    Node *next;
    Node (int val) {
        data = val;
        next = NULL;
    }
}; typedef Node* node;

inline void solve(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    node root = new Node(a[0]);
    for (int i = 1; i < n; ++i) {
        node cur = root;
        while (cur->next) cur = cur->next;
        cur->next = new Node(a[i]);
    }
    node cur = root;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}