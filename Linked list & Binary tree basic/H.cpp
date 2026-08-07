#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Duyệt cây theo mức từ dưới lên (Reverse Level-order Traversal):
    - Dùng BFS với Queue đẩy các nút vào `vector <int> ans` (lưu ý ưu tiên đẩy con Phải trước rồi đến con Trái).
    - Sau khi BFS xong, đảo ngược vector `ans` để thu được thứ tự các nút từ dưới lên trên, từ trái sang phải.
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

inline void LevelOrder(tree root){
    queue <tree> q;
    vector <int> ans;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        ans.push_back(cur->data);
        if(cur->right) q.push(cur->right);
        if(cur->left) q.push(cur->left);
    }
    // Đảo ngược thứ tự để có kết quả từ lá lên gốc
    reverse(ans.begin(), ans.end());
    for (int it : ans) cout << it << " ";
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
    LevelOrder(root);
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}