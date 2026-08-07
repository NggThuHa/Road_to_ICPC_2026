#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }

    void insert(int val){
        if (val < data){
            if (left == NULL) left = new Node(val);
            else left->insert(val);
        }
        else {
            if (right == NULL) right = new Node(val);
            else right->insert(val);
        }
    }

    void printLeaf(){
        if (left == NULL && right == NULL){
            cout << data << ' ';
            return;
        }
        if (left) left->printLeaf();
        if (right) right->printLeaf();
    }
}; typedef Node* Tree;



inline void solve(){
    int n; cin >> n;
    Tree root = NULL;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (root == NULL) {
            root = new Node(x);
        }
        else root->insert(x);
    }
    root->printLeaf();
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}