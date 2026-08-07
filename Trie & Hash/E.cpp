#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Quản lý tập hợp số động và đếm các số a sao cho $a \oplus b_x < b_y$:
    - Thao tác 1 (c = 1): Thêm số a vào Binary Trie (`cnt += 1`).
    - Thao tác 2 (c = 2): Xóa số a khỏi Binary Trie (`cnt += -1`).
    - Thao tác 3 (c = 3): Đếm số phần tử a sao cho $a \oplus b_x < b_y$.
      + Duyệt bit i từ 31 về 0.
      + Xét bit thứ i của $b_x$ (`bit_x`) và $b_y$ (`bit_y`).
      + Nếu `bit_y == 1`: Tất cả các số đi theo nhánh `bit_x` sẽ tạo ra bit thứ i của $a \oplus b_x$ bằng 0 (nhỏ hơn `bit_y` bằng 1). Do đó, ta cộng tất cả số phần tử trong cây con `T->child[bit_x]->cnt` vào đáp án, sau đó tiếp tục xét nhánh `bit_x ^ 1` (để bit XOR bằng 1).
      + Nếu `bit_y == 0`: Để $a \oplus b_x$ không vượt quá $b_y$, ta bắt buộc phải chọn nhánh sao cho bit thứ i của $a \oplus b_x$ bằng 0, tức là nhánh `bit_x`.
*/

struct Node {
    Node *child[2];
    int cnt = 0; // Đếm số lượng phần tử thuộc cây con này

    Node () {
        for (int i = 0; i < 2; i++) {
            child[i] = nullptr;
        }
        cnt = 0;
    }
}; typedef Node* trie;
trie root = new Node();

// Chèn (hoặc xóa) số a khỏi Trie với số lượng cnt (+1 hoặc -1)
inline void insert(trie T, int a, int cnt = 1){
    for (int i = 31; i >= 0; i--) {
        int idx = (a >> i) & 1;
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
        T->cnt += cnt;
    }
}

// Đếm số lượng phần tử a sao cho a XOR bx < by
inline int getMaxXor(trie T, int bx, int by) {
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        if (!T) break;
        int bit_x = (bx >> i) & 1;
        int bit_y = (by >> i) & 1;
        if (bit_y == 1) {
            // Nếu bit của by là 1, toàn bộ các số đi theo nhánh bit_x sẽ có bit XOR = 0 < 1
            if (T->child[bit_x]) {
                ans += T->child[bit_x]->cnt;
            }
            T = T->child[bit_x ^ 1]; // Tiếp tục tìm các số có bit XOR = 1 để so sánh các bit sau
        } else {
            // Nếu bit của by là 0, bắt buộc phải đi theo nhánh bit_x để bit XOR bằng 0
            T = T->child[bit_x];
        }
    }
    return ans;
}

inline void solve(){
    int c; cin >> c;
    if (c == 1) {
        int a; cin >> a;
        insert(root, a);
    } else if (c == 2) {
        int a; cin >> a;
        insert(root, a, -1);
    } else {
        int bx, by; cin >> bx >> by;
        cout << getMaxXor(root, bx, by) << endl;
    }
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}