#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    - Sử dụng `unordered_map<int, tree>` để lưu vị trí con trỏ của mỗi node theo giá trị của nó, giúp truy cập $O(1)$ khi nối cha-con mà không cần tìm kiếm đệ quy.
    - Duyệt cây theo mức (Level-order Traversal) bằng Hàng đợi (Queue / BFS).
*/

struct Node{
    int data;
    Node *left, *right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
}; typedef Node* tree;
unordered_map <int, tree> mp;

// Duyệt cây theo mức (Level-order / BFS)
inline void inOrder(tree root){
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        cout << cur->data << " ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}

inline void solve(){
    int n; cin >> n;
    tree root = NULL;
    mp.clear();
    for (int i = 0; i < n; i++) {
        int par, child;
        char side;
        cin >> par >> child >> side;
        if (!root) {
            root = new Node(par);
            mp[par] = root;
        }
        mp[child] = new Node(child);
        if(side == 'L') mp[par]->left = mp[child];
        else mp[par]->right = mp[child];
    }
    inOrder(root);
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}