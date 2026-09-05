#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
#define MOD 1000000007

/*
Bước 1: Định nghĩa trạng thái

Gọi sparse_table[i][u] là giá trị nhỏ nhất trong đoạn từ u đến u + 2^i - 1.

Bước 2: Bài toán cơ sở

Giá trị nhỏ nhất trong đoạn từ u đến u + 2^0 - 1 là chính a[u], do đó ta có:
sparse_table[0][u] = a[u] với mọi u từ 1 đến n.

Bước 3: Công thức truy hồi

Giá trị nhỏ nhất trong đoạn từ u đến u + 2^i - 1 có thể được tính bằng cách lấy giá trị nhỏ nhất của hai đoạn con:
- Đoạn từ u đến u + 2^(i - 1) - 1
- Đoạn từ u + 2^(i - 1) đến u + 2^i - 1
Do đó, ta có công thức truy hồi:
sparse_table[i][u] = min(sparse_table[i - 1][u], sparse_table[i - 1][u + (1 << (i - 1))]) với mọi i từ 1 đến log2(n) và mọi u từ 1 đến n - 2^i + 1.
*/


int sparse_table[21][1000005];

inline void build(int a[], int n){
    for (int u = 1; u <= n; ++u) sparse_table[0][u] = a[u];
    for (int i = 1; (1 << i) <= n; ++i){
        for (int u = 1; u + (1 << i) - 1 <= n; ++u){
            sparse_table[i][u] = min(sparse_table[i - 1][u], sparse_table[i - 1][u + (1 << (i - 1))]);
        }
    }
}

inline int query(int L, int R){
    int k = log2(R - L + 1);
    return min(sparse_table[k][L], sparse_table[k][R - (1 << k) + 1]);
}

inline void solve(){
    int n, q; cin >> n >> q;
    int a[n + 1];
    for (int u = 1; u <= n; u++) cin >> a[u];
    build(a, n);
    while (q--){
        int L, R; cin >> L >> R;
        cout << query(L, R) << endl;  
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}