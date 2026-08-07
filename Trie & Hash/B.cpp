#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Gợi ý từ tự động (Search Autocomplete / Suggestion system) bằng Trie:
    - Khi chèn từ `s` kèm tần suất `cnt`: Duyệt từng ký tự, nếu `cnt` lớn hơn tần suất lớn nhất `max` đang lưu ở node hiện tại thì cập nhật `T->max = cnt` và ghi nhớ từ `T->record = s`.
    - Khi truy vấn tiền tố `s`: Đi theo đường đi của `s` trong Trie. Nếu đi hết được `s`, kết quả chính là từ gợi ý `T->record` lưu ở nút cuối cùng của tiền tố đó. Nếu không đi hết -> in "No suggestion!".
*/

struct Node {
    Node *child[26];
    int max = 0;       // Tần suất lớn nhất của từ đi qua node này
    string record = ""; // Từ có tần suất lớn nhất tương ứng

    Node () {
        max = 0;
        record = "";
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
}; typedef Node* trie;
trie root = new Node();

// Chèn từ s với số lần xuất hiện/tần suất cnt vào Trie
void insert(trie T, string &s, int cnt){
    for (char ch : s) {
        int idx = ch - 'a';
        if (!T->child[idx]) {
            T->child[idx] = new Node();
        }
        T = T->child[idx];
        // Cập nhật từ gợi ý có tần suất cao nhất đi qua node này
        if (cnt > T->max) {
            T->max = cnt;
            T->record = s;
        }
    }
}

// Truy vấn từ gợi ý tương ứng với tiền tố s
string query(trie T, string &s) {
    for (char ch : s) {
        int idx = ch - 'a';
        if (!T->child[idx]) return "No suggestion!";
        T = T->child[idx];
    }
    return T->record;
}

inline void solve(){
    int n, q; cin >> n >> q;
    while (n--) {
        string s; int cnt; cin >> s >> cnt;
        insert(root, s, cnt);
    }
    while (q--) {
        string s; cin >> s;
        cout << query(root, s) << endl;
    }
}

signed main(){
    nguyentukien
    int t = 1; // cin >> t;
    while (t--) solve();
    return 0;
}