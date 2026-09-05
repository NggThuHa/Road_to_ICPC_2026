#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/*
Bước 1: Định nghĩa trạng thái
Gọi table[i][u] là giá trị nhỏ nhất trong đoạn từ u đến u + 2^i - 1.

Bước 2: Bài toán cơ sở
Với i = 0, table[0][u] = a[u] với mọi u từ 1 đến n.

Bước 3: Công thức truy hồi
Với i > 0, table[i][u] = min(table[i - 1][u], table[i - 1][u + (1 << (i - 1))]) với mọi u từ 1 đến n - (1 << i) + 1.

Bước 4: Tìm vị trí đầu tiên
Nếu min trên [l, r] lớn hơn p thì không tồn tại vị trí phù hợp.
Ngược lại, duyệt các block từ lớn đến nhỏ để bỏ qua những block
mà mọi phần tử đều lớn hơn p. Vị trí còn lại là id đầu tiên có a[id] <= p.

Bước 5: Tính đúng đắn
Một block chỉ được bỏ qua khi giá trị nhỏ nhất của nó lớn hơn p,
nghĩa là toàn bộ phần tử trong block đều không phù hợp. Do đó không
bỏ qua vị trí phù hợp đầu tiên. Sau khi chọn id, cập nhật p %= a[id]
và tiếp tục từ id + 1 theo đúng thứ tự của dãy.

Bước 6: Độ phức tạp
Tiền xử lý mất O(n log n). Mỗi lần tìm id mất O(log n); số lần lặp
phụ thuộc vào số lần p giảm (với a[i] > 0, p giảm nghiêm ngặt sau mỗi lần).

Bước 7: Trường hợp biên
Chỉ gọi first_id khi l <= r. Nếu không tìm thấy vị trí phù hợp thì trả về -1.
Bài toán cần giả thiết a[i] > 0 để phép modulo hợp lệ và p giảm.
*/

ll table[21][200005];

inline void build(ll a[], int n){
    for (int u = 1; u <= n; ++u) table[0][u] = a[u];
    for (int i = 1; i <= 20; ++i){
        for (int u = 1; u + (1 << i) - 1 <= n; ++u){
            table[i][u] = min(table[i - 1][u], table[i - 1][u + (1 << (i - 1))]);
        }
    }   
}

inline ll query(int l, int r){
    int len = __lg(r - l + 1);
    return min(table[len][l], table[len][r - (1 << len) + 1]);
}

inline int first_id(int l, int r, ll p){
    if(query(l, r) > p) return -1;
    int pos = l;
    for (int i = 20; i >= 0; --i){
        if (pos + (1 << i) - 1 <= r and table[i][pos] > p){
            pos += (1 << i);
        }
    }
    return pos;
}

inline void solve(){
    int n, k; cin >> n >> k;
    ll a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(a, n);
    while(k--){
        ll p; int l, r; 
        cin >> p >> l >> r;
        while(l <= r and p > 0){
            int id = first_id(l, r, p);
            if (id == -1) break;
            p %= a[id];
            l = id + 1;
        }
        cout << p << endl;
    }
}

signed main(){
    nguyentukien
    solve();
}