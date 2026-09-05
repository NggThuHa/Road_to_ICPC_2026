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
*/

int root[21][100005];

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

inline void solve(){
    int n, q; cin >> n >> q;
    int a[n + 1];
    for (int i = 2; i <= n; ++i) cin >> a[i];
    build(a, n);
    while (q--){
        int u, k; cin >> u >> k;
        cout << query(u, k) << endl;
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}