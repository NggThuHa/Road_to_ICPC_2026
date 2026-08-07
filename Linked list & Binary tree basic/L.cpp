#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Tính tổng tất cả các nút lá là con bên phải (Right Leaf Nodes):
    - Đánh dấu `side` ('L' hoặc 'R') cho mỗi node khi nối với cha.
    - Duyệt qua tất cả các node bằng BFS:
      Nếu node là lá (`!cur->left && !cur->right`) và là con phải (`cur->side == 'R'`) thì cộng `cur->data` vào tổng.
*/

struct Node{
    int data;
    char side;
    Node *left, *right;
    Node (int val) {
        data = val;
        side = 'N'; 
        left = right = NULL;
    }
}; typedef Node* tree;
unordered_map <int, tree> mp;

inline int compute(tree root){   
    if (!root) return 0;
    int total = 0;
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        // Kiểm tra điều kiện node lá và là con phía bên phải
        if(!cur->left && !cur->right) {
            if(cur->side == 'R') total += cur->data;
        }
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return total;
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
            mp[child]->side = 'L';
        }
        else {
            mp[par]->right = mp[child];
            mp[child]->side = 'R';
        }
    }
    cout << compute(root) << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}