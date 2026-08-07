#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node (int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
typedef Node* node;

inline void solve(){
    int n, c, x; cin >> n;
    node root = NULL;
    for (int i = 0; i < n; ++i){
        cin >> c; 
        node tmp = NULL;
        if(c != 4){
            cin >> x;
            tmp = new Node(x);
        }
        if(c == 1){
            if(!root) root = tmp;
            else {
                node cur = root;
                while(cur->next) cur = cur->next;
                cur->next = tmp;
                tmp->prev = cur;
            }
        } else if(c == 2){
            if(!root) root = tmp;
            else {
                tmp->next = root;
                root->prev = tmp;
                root = tmp;
            }
        } else if(c == 3){
            if(!root) continue;
            node cur = root;
            do {
                if(root->data == x){
                    if(root->next) root->next->prev = NULL;
                    root = root->next;
                    break;
                }
                if(cur->data == x){
                    if(cur->prev) cur->prev->next = cur->next;
                    if(cur->next) cur->next->prev = cur->prev;
                    delete cur;
                    break;
                }
                cur = cur->next;
            }
            while(cur);
        } else {
            if(!root) continue;
            node cur = root;
            while(cur->next) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << cur->data << endl;
        }
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}