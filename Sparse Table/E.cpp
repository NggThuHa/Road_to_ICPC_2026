#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/*
Bước 1: Định nghĩa trạng thái
Gọi table[i][u] là ước chung lớn nhất của đoạn từ u đến u + 2^i - 1.

Bước 2: Bài toán cơ sở
Với i = 0, table[0][u] = a[u] với mọi u từ 1 đến n.

Bước 3: Công thức truy hồi
Với i > 0, table[i][u] = gcd(table[i - 1][u], table[i - 1][u + (1 << (i - 1))]) với mọi u từ 1 đến n - (1 << i) + 1.
*/

int table[21][100005];

inline void build(int a[], int n){
    for (int u = 1; u <= n; ++u) table[0][u] = a[u];
    for (int i = 1; i <= 20; ++i){
        for (int u = 1; u + (1 << (i - 1)) - 1 <= n; ++u){
            table[i][u] = __gcd(table[i - 1][u], table[i - 1][u + (1 << (i - 1))]);
        }
    }   
}

inline int query(int l, int r){
    int k = log2(r - l + 1);
    return __gcd(table[k][l], table[k][r - (1 << k) + 1]);
}

inline void solve(){
    int n; cin >> n;
    int a[n + 1];
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(a, n);
    for (int l = 1; l <= n; ++l){
        int r = l ;
        while(r <= n and query(l, r) != 1) ++r;
        cnt += n - r + 1;
    }
    cout << cnt << endl;
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}