#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Kiểm tra cây nhị phân có phải là Cây nhị phân đầy đủ (Full Binary Tree) hay không:
    - Cây nhị phân đầy đủ là cây mà mỗi node trung gian/nội bộ đều có chính xác 2 node con (left và right).
    - Không tồn tại node nào chỉ có duy nhất 1 node con (chỉ có left hoặc chỉ có right).
    - Nếu có node lẻ 1 con -> return 0. Nếu tất cả thỏa mãn -> return 1.
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
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        // Có đủ 2 con -> tiếp tục duyệt
        if(cur->left && cur->right) {
            q.push(cur->left);
            q.push(cur->right);
        }
        // Không có con nào (node lá) -> tiếp tục
        else if(!cur->left && !cur->right) continue;
        // Có duy nhất 1 con -> Không phải Full Binary Tree
        else return 0;
    }
    return 1;
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