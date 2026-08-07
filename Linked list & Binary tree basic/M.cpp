#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Cây tìm kiếm nhị phân (Binary Search Tree - BST):
    - Chèn phần tử: Nếu `val <= data` chèn vào cây con trái, ngược lại chèn vào cây con phải.
    - Duyệt Hậu thứ (Post-order Traversal): Trái -> Phải -> Gốc.
*/

struct Node{
    int data;
    Node *left, *right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
    
    // Thao tác chèn phần tử vào cây BST
    void insert(int val){
        if(val <= data){
            if(!left) left = new Node(val);
            else left->insert(val);
        }
        else {
            if(!right) right = new Node(val);
            else right->insert(val);
        }
    }

    // Duyệt Post-order (Trái -> Phải -> Gốc)
    void printPostOrder(){
        if(left) left->printPostOrder();
        if(right) right->printPostOrder();
        cout << data << " ";
    }
}; typedef Node* tree;

inline void solve(){
    int n; cin >> n;
    tree root = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(!root) root = new Node(x);
        else root->insert(x);
    }
    root->printPostOrder();
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}