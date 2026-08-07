#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Đếm số lượng nút không phải nút lá (Nút nội bộ / Internal Nodes):
    - Đếm tổng số nút lá `cnt` bằng cách đệ quy kiểm tra `left == NULL && right == NULL`.
    - Số lượng nút nội bộ = Tổng số nút (n) - Số nút lá (cnt).
*/

int cnt = 0;
struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }

    void insert(int val){
        if (val < data){
            if (left == NULL) left = new Node(val);
            else left->insert(val);
        }
        else {
            if (right == NULL) right = new Node(val);
            else right->insert(val);
        }
    }

    // Đếm số lượng nút lá
    void checkLeaf(){
        if (left == NULL && right == NULL){
            ++cnt;
            return;
        }
        if (left) left->checkLeaf();
        if (right) right->checkLeaf();
    }
}; typedef Node* Tree;

inline void solve(){
    int n; cin >> n;
    cnt = 0;
    Tree root = NULL;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (root == NULL) {
            root = new Node(x);
        }
        else root->insert(x);
    }
    root->checkLeaf();
    // Kết quả là tổng số nút trừ số nút lá
    cout << n - cnt << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}