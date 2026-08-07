#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Tìm cặp số có giá trị XOR lớn nhất (Maximum XOR Pair):
    - Sử dụng Binary Trie lưu biểu diễn nhị phân 32-bit của các số đã duyệt qua.
    - Để XOR thu được kết quả lớn nhất tại bit thứ i: Nếu bit hiện tại của s là `idx` (0 hoặc 1), ta tham lam ưu tiên đi sang nhánh bit đối lập `1 - idx` (để bit XOR tương ứng bằng 1, làm giá trị XOR tăng thêm $2^i$).
    - Nếu có nhánh `1 - idx`, bật bit thứ i trong kết quả `ans |= (1 << i)` và đi theo nhánh `1 - idx`. Nếu không có, đành phải đi theo nhánh `idx`.
*/

struct Node {
    Node *child[2];

    Node () {
        for (int i = 0; i < 2; i++) {
            child[i] = nullptr;
        }
    }
}; typedef Node* trie;
trie root = new Node();

// Chèn số s dạng 32 bit vào Binary Trie
void insert(trie T, int &s){
    for (int i = 31; i >= 0; i--) {
        int idx = (s >> i) & 1;
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
    }
}

// Tìm giá trị XOR lớn nhất khi XOR một số s đã có trong Trie với số s hiện tại
int getMaxXor(trie T, int &s) {
    int ans = 0;
    for (int i = 31; i >= 0; --i){
        int idx = (s >> i) & 1;
        // Ưu tiên tham lam chọn bit đối lập để thu được kết quả bit XOR là 1
        if (T->child[1 - idx]) {
            ans |= (1 << i);
            T = T->child[1 - idx];
        } else if (T->child[idx]) {
            T = T->child[idx];
        } else {
            break;
        }
    }
    return ans;
}

inline void solve(){
    int n, maxXor = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        maxXor = max(maxXor, getMaxXor(root, s));
        insert(root, s);
    }
    cout << maxXor << endl;
}

signed main(){
    nguyentukien
    int t = 1; // cin >> t;
    while (t--) solve();
    return 0;
}