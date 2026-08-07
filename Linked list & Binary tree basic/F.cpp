#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Dựng Cây nhị phân từ các bộ (cha, con, phía 'L'/'R'):
    - Hàm `insertNode`: Tìm đệ quy node cha `par` trong cây, sau đó tạo node con mới `child` ở bên trái ('L') hoặc bên phải ('R').
    - Duyệt Trung thứ (In-order Traversal): Duyệt Trái -> Gốc -> Phải để in thứ tự các nút.
*/

struct Node{
    int data;
    Node *left, *right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
}; typedef Node* tree;

// Tìm node par đệ quy và chèn node child vào bên side ('L' hoặc 'R')
inline void insertNode(tree root, int par, int child, char side){
    if(!root) return;
    if(root->data == par){
        if(side == 'L') root->left = new Node(child);
        else root->right = new Node(child);
        return;
    }
    if(root->left) insertNode(root->left, par, child, side);
    if(root->right) insertNode(root->right, par, child, side);
}

// Duyệt cây theo thứ tự In-order (Trái -> Gốc -> Phải)
inline void inOrder(tree root){
    if(!root) return;
    if(root->left) inOrder(root->left);
    cout << root->data << " ";
    if(root->right) inOrder(root->right);
}

inline void solve(){
    int n; cin >> n;
    tree root = NULL;
    for (int i = 0; i < n; i++) {
        int par, child;
        char side;
        cin >> par >> child >> side;
        if (!root) root = new Node(par);
        insertNode(root, par, child, side);
    }
    inOrder(root);
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}