#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Cây Cấu trúc Dữ liệu Trie cơ bản (Prefix Tree) cho bảng chữ cái Tiếng Anh ('a' - 'z'):
    - `insert`: Thêm một xâu vào cây Trie bằng cách duyệt từng ký tự và tạo node mới nếu chưa tồn tại.
    - `query`: Truy vấn kiểm tra xem tiền tố/chuỗi s có tồn tại trong Trie hay không.
*/

struct Node {
    Node *child[26];

    Node () {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
}; typedef Node* trie;
trie root = new Node();

// Chèn chuỗi s vào cây Trie
void insert(trie T, string &s){
    for (char ch : s) {
        int idx = ch - 'a';
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
    }
}

// Kiểm tra tiền tố s có thuộc cây Trie không
bool query(trie T, string &s) {
    for (char ch : s) {
        int idx = ch - 'a';
        if (!T->child[idx]) return false;
        T = T->child[idx];
    }
    return true;
}

inline void solve(){
    int c; cin >> c;
    string s; cin >> s;
    if (c == 1) {
        insert(root, s);
    } else if (c == 2) {
        cout << (query(root, s) ? "YES" : "NO") << endl;
    }
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}