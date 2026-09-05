#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* 
Bước 1: Định nghĩa trạng thái
Gọi root[i][u] là nút cha của nút u sau 2^i bước đi lên cây.

Bước 2: Bài toán cơ sở
Nút cha của nút u sau 2^0 bước đi lên cây là chính nút cha của nút u, do đó ta có:
root[0][u] = a[u] với mọi u từ 2 đến n.
Nếu nút u là nút gốc thì root[0][u] = -1.

Bước 3: Công thức truy hồi
Nút cha của nút u sau 2^i bước đi lên cây có thể được tính bằng cách lấy nút cha của nút cha của nút u sau 2^(i - 1) bước đi lên cây:
root[i][u] = root[i - 1][root[i - 1][u]] với mọi i từ 1 đến log2(n) và mọi u từ 1 đến n.

==> Cha chung của hai nút a và b là nút cha chung của hai nút a và b sau min(depth[a], depth[b]) bước đi lên cây.
*/

vector <int> adj[100005];
int root[21][100005];
int depth[100005];

void dfs(int u, int d){
    depth[u] = d;
    for (int v : adj[u]){
        dfs(v, d + 1);
    }
}

void build(int a[], int n){
    root[0][1] = -1;
    for (int u = 2; u <= n; ++u) root[0][u] = a[u];
    for (int i = 1; i <= 20; ++i){
        for (int u = 1; u <= n; ++u){
            if (root[i - 1][u] == -1) root[i][u] = -1;
            else root[i][u] = root[i - 1][root[i - 1][u]];
        }
    }   
}

inline int query(int u, int k){
    for (int i = 0; i <= 20; ++i){
        if (k & (1 << i)){
            u = root[i][u];
            if (u == -1) return -1;
        }
    }
    return u;
}

inline int bin_search(int a, int b, int d){
    int l = 0, r = d;
    while (l < r){
        int mid = (l + r) >> 1;
        if (query(a, mid) == query(b, mid)) r = mid;
        else l = mid + 1;
    }
    return query(a, l);
}

inline void solve(){
    int n, q; cin >> n >> q;
    int a[n + 1];
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    dfs(1, 0);
    build(a, n);
    while (q--){
        int a, b; cin >> a >> b;
        if(depth[a] < depth[b]) b = query(b, depth[b] - depth[a]);
        else if(depth[b] < depth[a]) a = query(a, depth[a] - depth[b]);
        if (a == b) cout << a << endl;
        else cout << bin_search(a, b, min(depth[a], depth[b])) << endl;
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}