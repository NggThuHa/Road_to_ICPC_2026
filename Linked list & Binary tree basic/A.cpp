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
};

inline void solve(){
    int t; cin >> t;
    Node *root = NULL;
    while (t--){
        int c, x; cin >> c;
        Node *tmp = NULL;
        if(c != 3) {
            cin >> x;
            tmp = new Node(x);
        }
        if(c == 1){
            if(!root) root = tmp;
            else {
                Node *cur = root;
                while(cur->next) cur = cur->next;
                cur->next = tmp;
            }
        } else if(c == 2){
            if(!root) root = tmp;
            else {
                tmp->next = root;
                root = tmp;
            }
        } else {
            Node* cur = root;
            if(cur) {
                while(cur->next){
                    cout << cur->data << " ";
                    cur = cur->next;
                }
                cout << cur->data << endl;
            }
            
        }
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}