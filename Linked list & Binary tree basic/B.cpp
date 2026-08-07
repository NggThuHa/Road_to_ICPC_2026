#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Quản lý Danh sách liên kết đơn với đầy đủ các thao tác cơ bản:
    - 1 x: Thêm x vào cuối danh sách.
    - 2 x: Thêm x vào đầu danh sách.
    - 3: Xóa phần tử ở đầu danh sách.
    - 4: Xóa phần tử ở cuối danh sách.
    - 5: In toàn bộ danh sách liên kết.
*/

struct Node{
    int data;
    Node *next;
    Node (int val) {
        data = val;
        next = NULL;
    }
};

inline void solve(){
    int n, c, x; cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; ++i){
        Node *tmp;
        cin >> c;
        if(c < 3) {
            cin >> x;
            tmp = new Node(x);
        }
        // Thao tác 1: Thêm vào cuối
        if(c == 1){
            if(!root) root = tmp;
            else {
                Node *cur = root;
                while(cur->next) cur = cur->next;
                cur->next = tmp;
            }
        } 
        // Thao tác 2: Thêm vào đầu
        else if(c == 2){
            if(!root) root = tmp;
            else {
                tmp->next = root;
                root = tmp;
            }
        } 
        // Thao tác 3: Xóa đầu danh sách
        else if(c == 3){
            if(!root) continue;
            Node *cur = root->next;
            delete root; // Giải phóng bộ nhớ của node đầu
            root = cur;
        } 
        // Thao tác 4: Xóa cuối danh sách
        else if(c == 4){
            if(root == NULL) continue;
            Node *cur = root;
            if(!cur->next) {
                delete root;
                root = NULL;
            }
            else {
                while(cur->next->next) cur = cur->next; // Duyệt đến node áp cuối
                delete cur->next; // Giải phóng node cuối
                cur->next = NULL;
            }
        } 
        // Thao tác 5: In danh sách
        else {
            if(!root) continue;
            Node *cur = root;
            while(cur->next){
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << cur->data << endl;
        }

    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}