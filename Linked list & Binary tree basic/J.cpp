#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Kiểm tra cây nhị phân thỏa mãn:
    1. Tất cả các nút lá nằm ở cùng một độ sâu (level).
    2. Tổng số lượng nút lá là một số chẵn.
    Sử dụng BFS để thống kê tần suất các mức của nút lá qua `unordered_map<int, int> leafs`.
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
    unordered_map<int, int> leafs;
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        if(!cur->left && !cur->right) ++leafs[cur->level]; // Đếm số nút lá ở từng level
        if(cur->right) q.push(cur->right);
        if(cur->left) q.push(cur->left);
    }
    // Thỏa mãn nếu chỉ có 1 mức duy nhất và số nút lá là số chẵn (% 2 == 0)
    if(leafs.size() == 1 and leafs.begin()->second % 2 == 0) return 1;
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
