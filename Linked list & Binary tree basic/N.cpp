#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Cây tìm kiếm nhị phân (BST):
    - Chèn lần lượt các phần tử vào cây BST.
    - Duyệt Tiền thứ (Pre-order Traversal): Gốc -> Trái -> Phải.
*/

struct Node{
    int data;
    Node *left, *right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
    
    // Thao tác chèn vào cây BST
    void insert(int val){
        if(val < data){
            if(!left) left = new Node(val);
            else left->insert(val);
        }
        else {
            if(!right) right = new Node(val);
            else right->insert(val);
        }
    }

    // Duyệt Pre-order (Gốc -> Trái -> Phải)
    void printPreOrder(){
        cout << data << " ";
        if(left) left->printPreOrder();
        if(right) right->printPreOrder();
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
    root->printPreOrder();
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}