#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/*
Có 2 bài toán cần xử lý:
1. Tìm giá trị lớn nhất trong đoạn [l, r] và giá trị nhỏ nhất trong đoạn [l, r].
2. Tìm giá trị lớn nhất trong đoạn [1, l - 1] và giá trị lớn nhất trong đoạn [r + 1, n].
Sau đó, ta tính giá trị cần tìm bằng công thức:
max(max(mxL, mxR) + mnLR, mnLR + (mxLR - mnLR) / 2)

Bài toán 1:
Bước 1: Định nghĩa trạng thái
Gọi mn[i][u] là giá trị nhỏ nhất trong đoạn từ u đến u + 2^i - 1.

Bươc 2: Bài toán cơ sở
Giá trị nhỏ nhất trong đoạn từ u đến u + 2^0 - 1 là chính a[u], do đó ta có:
mn[0][u] = a[u] với mọi u từ 1 đến n.

Bước 3: Công thức truy hồi
Giá trị nhỏ nhất trong đoạn từ u đến u + 2^i - 1 có thể được tính bằng cách lấy giá trị nhỏ nhất của hai đoạn con:
- Đoạn từ u đến u + 2^(i - 1) - 1
- Đoạn từ u + 2^(i - 1) đến u + 2^i - 1
Do đó, ta có công thức truy hồi:
mn[i][u] = min(mn[i - 1][u], mn[i - 1][u + (1 << (i - 1))]) với mọi i từ 1 đến log2(n) và mọi u từ 1 đến n - 2^i + 1.

Bài toán 2:
Bước 1: Định nghĩa trạng thái
Gọi mx[i][u] là giá trị lớn nhất trong đoạn từ u đến u + 2^i - 1.   


*/

ll mn[21][200005];
ll mx[21][200005];
int n; 

inline void mn_build(){
    for (int i = 1; i <= 20; ++i){
        for (int u = 1; u + (1 << (i - 1)) - 1 <= n; ++u){
            mn[i][u] = min(mn[i - 1][u], mn[i - 1][u + (1 << (i - 1))]);
        }
    }   
}

inline void mx_build(){
    for (int i = 1; i <= 20; ++i){
        for (int u = 1; u + (1 << (i - 1)) - 1 <= n; ++u){
            mx[i][u] = max(mx[i - 1][u], mx[i - 1][u + (1 << (i - 1))]);
        }
    }   
}

inline ll mn_query(int l, int r){
    int len = __lg(r - l + 1);
    return min(mn[len][l], mn[len][r - (1 << len) + 1]);
}

inline ll mx_query(int l, int r){
    int len = __lg(r - l + 1);
    return max(mx[len][l], mx[len][r - (1 << len) + 1]);
}

inline void solve(){
    int k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> mx[0][i];
        mn[0][i] = mx[0][i];
    }
    mn_build();
    mx_build();
    while(k--){
        int l, r; cin >> l >> r;
        ll mxL = 0, mxR = 0, mnLR = mn_query(l, r), mxLR = mx_query(l, r);
        if(l != 1) mxL = max(mxL, mx_query(1, l - 1));
        if(r != n) mxR = max(mxR, mx_query(r + 1, n));
        printf("%.1f\n", max(1.0 * (max(mxL, mxR) + mnLR), 1.0 * mnLR + 1.0 * (mxLR - mnLR) / 2));
    }
}

signed main(){
    nguyentukien
    solve();
}