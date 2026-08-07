#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    - Đọc n phần tử và sắp xếp mảng theo thứ tự tăng dần.
    - Duyệt qua mảng đã sắp xếp và lần lượt chèn các phần tử vào Danh sách liên kết đơn.
    - Duyệt danh sách liên kết và in ra các phần tử đã được sắp xếp.
*/

struct Node{
    int data;
    Node *next;
    Node (int val) {
        data = val;
        next = NULL;
    }
}; typedef Node* node;

inline void solve(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // Sắp xếp mảng tăng dần
    sort(a, a + n);
    
    // Xây dựng danh sách liên kết từ mảng đã sắp xếp
    node root = new Node(a[0]);
    for (int i = 1; i < n; ++i) {
        node cur = root;
        while (cur->next) cur = cur->next;
        cur->next = new Node(a[i]);
    }
    
    // Duyệt danh sách và in ra màn hình
    node cur = root;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}