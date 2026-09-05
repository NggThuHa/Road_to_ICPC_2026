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

Bước 4: Trả lời truy vấn
Phân tích k theo biểu diễn nhị phân. Với mỗi bit i bật trong k,
nhảy u lên root[i][u], tức là đi lên 2^i mức. Các bước nhảy được
thực hiện từ bit nhỏ đến bit lớn và dừng nếu đã đi qua nút gốc.

Bước 5: Tính đúng đắn
Theo định nghĩa, root[i][u] là tổ tiên cách u đúng 2^i bước.
Tổng các bước nhảy ứng với các bit bật bằng k, nên nút cuối cùng
chính là tổ tiên thứ k của u.

Bước 6: Độ phức tạp
Tiền xử lý mất O(n log n), mỗi truy vấn mất O(log n), bộ nhớ O(n log n).

Bước 7: Trường hợp biên
Nút gốc có tổ tiên là -1. Nếu đang ở -1 trước khi hoàn thành k bước,
kết quả là -1. Số mức của bảng phải đủ để biểu diễn k lớn nhất.
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