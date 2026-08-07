#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

struct Node{
    int data;
    char side;
    Node *left, *right;
    Node (int val) {
        data = val;
        side = 'N'; 
        left = right = NULL;
    }
}; typedef Node* tree;
unordered_map <int, tree> mp;

inline int compute(tree root){   
    if (!root) return 0;
    int total = 0;
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        if(!cur->left && !cur->right) {
            if(cur->side == 'R') total += cur->data;
        }
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return total;
}

inline void solve(){
    int n; cin >> n;
    tree root = NULL;
    for (int i = 0; i < n; i++) {
        int par, child;
        char side;
        cin >> par >> child >> side;
        if (!root) {
            root = new Node(par);
            mp[par] = root;
        }
        mp[child] = new Node(child);
        if(side == 'L') {
            mp[par]->left = mp[child];
            mp[child]->side = 'L';
        }
        else {
            mp[par]->right = mp[child];
            mp[child]->side = 'R';
        }
    }
    cout << compute(root) << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}