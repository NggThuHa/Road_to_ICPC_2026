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
    int n, c, x; cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; ++i){
        Node *tmp;
        cin >> c;
        if(c < 3) {
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
        } else if(c == 3){
            if(!root) continue;
            Node *cur = root->next;
            root = cur;
        } else if(c == 4){
            if(root == NULL) continue;
            Node *cur = root;
            if(!cur->next) root = NULL;
            else {
                while(cur->next->next) cur = cur->next;
                cur->next = NULL;
            }

        } else {
            if(!root) continue;
            Node *cur = root;
            while(cur->next){
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