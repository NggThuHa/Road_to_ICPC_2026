#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/*
Bước 1: Định nghĩa trạng thái
Gọi table[i][u] là giá trị lớn nhất trong đoạn từ u đến u + 2^i - 1.

Bước 2: Bài toán cơ sở
Với i = 0, table[0][u] = a[u] với mọi u từ 1 đến n.

Bước 3: Công thức truy hồi
Với i > 0, table[i][u] = max(table[i - 1][u], table[i - 1][u + (1 << (i - 1))]) với mọi u từ 1 đến n - (1 << i) + 1.

Bước 4: Trả lời truy vấn
Chuẩn hóa để u <= v. Với u = v hoặc hai vị trí kề nhau,
đoạn ở giữa là rỗng nên xử lý trực tiếp. Các trường hợp còn lại
cần kiểm tra max(a[u + 1 .. v - 1]) <= a[u].

Bước 5: Tính đúng đắn
Hàm query trả về đúng giá trị lớn nhất trên đoạn ở giữa nhờ hai block
có độ dài lũy thừa của 2. Vì vậy phép so sánh với a[u] tương đương
chính xác với điều kiện của truy vấn.

Bước 6: Độ phức tạp
Tiền xử lý mất O(n log n), mỗi truy vấn mất O(1), bộ nhớ O(n log n).

Bước 7: Trường hợp biên
Không được gọi query trên đoạn rỗng; u = v và v = u + 1 phải được
xử lý riêng. Khi xây bảng, chỉ tạo block thỏa mãn u + 2^i - 1 <= n.
*/

ll table[21][50004];

inline void build(ll a[], int n){
    for (int u = 1; u <= n; ++u) table[0][u] = a[u];
    for (int i = 1; i <= 20; ++i){
        for (int u = 1; u + (1 << i) - 1 <= n; ++u){
            table[i][u] = max(table[i - 1][u], table[i - 1][u + (1 << (i - 1))]);
        }
    }   
}

inline ll query(int l, int r){
    int len = log2(r - l + 1);
    return max(table[len][l], table[len][r - (1 << len) + 1]);
}


inline void solve(){
    int n, k, cnt = 0; cin >> n >> k;
    ll a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(a, n);
    while(k--){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        if (u == v || u == v - 1) {
            ++cnt;
        }
        else if (query(u + 1, v - 1) <= a[u]) {
            ++cnt;
        }
    }
    cout << cnt;
}

signed main(){
    nguyentukien
    solve();
}