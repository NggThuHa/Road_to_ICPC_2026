#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Sử dụng Trie bit (Binary Trie / Bitwise Trie) để tìm phần tử nhỏ thứ k (k-th smallest element):
    - Mới mỗi số nguyên 32-bit: Chèn từng bit từ bit 31 đến bit 0 vào Trie.
    - Mỗi node lưu biến `count` là số lượng phần tử thuộc nhánh/cây con đó.
    - Khi truy vấn phần tử nhỏ thứ `k`:
      + Xét bit ở nhánh trái (`child[0]`). Nếu số lượng phần tử nhánh trái `>= k`, ta chỉ cần đi tiếp xuống nhánh trái.
      + Ngược lại (nhánh trái có ít hơn `k` phần tử), ta phải đi xuống nhánh phải (`child[1]`), đồng thời giảm `k` đi một lượng bằng `child[0]->count` và bật bit thứ i của kết quả lên 1 (`ans |= (1 << i)`).
*/

struct Node {
    Node *child[2];
    int count; // Đếm số phần tử trong cây con của nút hiện tại

    Node () {
        for (int i = 0; i < 2; i++) {
            child[i] = nullptr;
        }
        count = 0;
    }
}; typedef Node* trie;
trie root = new Node();

// Chèn số s dạng 32 bit vào Binary Trie
void insert(trie T, int &s){
    ++T->count;
    for (int i = 31; i >= 0; i--) {
        int idx = (s >> i) & 1;
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
        ++T->count;
    }
}

// Tìm số nhỏ thứ k trong tập hợp hiện tại
int query(trie T, int &k) {
    int ans = 0;
    for (int i = 31; i >= 0; --i){
        // Nếu số lượng phần tử ở nhánh bit 0 đủ chứa phần tử thứ k
        if (T->child[0] && T->child[0]->count >= k) {
            T = T->child[0];
        } else {
            // Ngược lại, trừ đi số lượng phần tử ở nhánh bit 0 và đi sang nhánh bit 1
            if (T->child[0]) k -= T->child[0]->count;
            ans |= (1 << i);
            T = T->child[1];
        }
    }
    return ans;
}

inline void solve(){
    int c; cin >> c;
    if (c == 1) {
        int s; cin >> s;
        insert(root, s);
    } else if (c == 2) {
        int k; cin >> k;
        cout << query(root, k) << endl;
    }
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}