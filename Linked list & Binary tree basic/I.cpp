#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Kiểm tra xem tất cả các nút lá của Cây nhị phân có cùng độ sâu (level) hay không:
    - Trong quá trình xây dựng cây, ghi nhận level của từng node (`level = par->level + 1`).
    - Duyệt cây qua Queue (BFS), mỗi khi gặp node lá (`!cur->left && !cur->right`), thêm `level` của lá đó vào `unordered_set <int> leafs`.
    - Nếu kích thước của `leafs` đúng bằng 1 thì tất cả nút lá cùng độ sâu (in ra 1), ngược lại in ra 0.
*/

struct Node{
    int data;
    int level;
    Node *left, *right;
    Node (int val) {
        data = val;
        level = 1;
        left = right = NULL;
    }
}; typedef Node* tree;
unordered_map <int, tree> mp;

inline int LevelOrder(tree root){
    if (!root) return 0;
    unordered_set <int> leafs;
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        if(!cur->left && !cur->right) leafs.insert(cur->level); // Thu thập độ sâu của các node lá
        if(cur->right) q.push(cur->right);
        if(cur->left) q.push(cur->left);
    }
    // Nếu tất cả lá đều ở cùng một mức -> leafs.size() == 1
    if(leafs.size() == 1) return 1;
    else return 0;
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
        if(side == 'L') {
            mp[par]->left = mp[child];
            mp[child]->level = mp[par]->level + 1;
        }
        else {
            mp[par]->right = mp[child];
            mp[child]->level = mp[par]->level + 1;
        }
    }
    cout << LevelOrder(root) << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}