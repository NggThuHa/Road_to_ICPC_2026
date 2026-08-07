#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Dựng Cây tìm kiếm nhị phân cân bằng (Balanced BST) từ mảng và duyệt Tiền thứ (Pre-order):
    - Sắp xếp mảng tăng dần.
    - Đệ quy chọn phần tử ở giữa `mid = (l + r) / 2` làm nút gốc.
    - Cây con trái được tạo từ đoạn `[l, mid - 1]`, cây con phải được tạo từ đoạn `[mid + 1, r]`.
    - Duyệt Pre-order (Gốc -> Trái -> Phải) để in kết quả.
*/

struct Node{
    int data;
    Node *left, *right;
    Node(vector <int> &arr, int l, int r){
        int mid = (l + r) / 2;
        data = arr[mid];
        left = right = NULL;
        if(l <= mid - 1) left = new Node(arr, l, mid - 1);
        if(r >= mid + 1) right = new Node(arr, mid + 1, r);
    }

    // Duyệt Pre-order (Gốc -> Trái -> Phải)
    void preOrder(){
        cout << data << ' ';
        if(left) left->preOrder();
        if(right) right->preOrder();
    }
    
}; typedef Node* Tree;

inline void solve(){
    int n; cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    Tree root = new Node(arr, 0, n - 1);
    root->preOrder();
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}