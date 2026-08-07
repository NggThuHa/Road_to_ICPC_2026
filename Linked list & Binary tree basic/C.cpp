#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/* Ý tưởng:
    Sử dụng Danh sách liên kết đôi (Doubly Linked List): Mỗi node duy trì 2 con trỏ `prev` và `next`.
    - 1 x: Thêm phần tử x vào cuối.
    - 2 x: Thêm phần tử x vào đầu.
    - 3 x: Xóa phần tử đầu tiên xuất hiện có giá trị x.
    - 4: In toàn bộ danh sách.
*/

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node (int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
typedef Node* node;

inline void solve(){
    int n, c, x; cin >> n;
    node root = NULL;
    for (int i = 0; i < n; ++i){
        cin >> c; 
        node tmp = NULL;
        if(c != 4){
            cin >> x;
            tmp = new Node(x);
        }
        // Thao tác 1: Thêm vào cuối danh sách liên kết đôi
        if(c == 1){
            if(!root) root = tmp;
            else {
                node cur = root;
                while(cur->next) cur = cur->next;
                cur->next = tmp;
                tmp->prev = cur;
            }
        } 
        // Thao tác 2: Thêm vào đầu danh sách liên kết đôi
        else if(c == 2){
            if(!root) root = tmp;
            else {
                tmp->next = root;
                root->prev = tmp;
                root = tmp;
            }
        } 
        // Thao tác 3: Tìm và xóa phần tử đầu tiên có giá trị x
        else if(c == 3){
            if(!root) continue;
            node cur = root;
            do {
                // Nếu node cần xóa là node đầu tiên (root)
                if(root->data == x){
                    node toDelete = root;
                    if(root->next) root->next->prev = NULL;
                    root = root->next;
                    delete toDelete;
                    break;
                }
                // Nếu node cần xóa nằm ở giữa hoặc cuối
                if(cur->data == x){
                    if(cur->prev) cur->prev->next = cur->next;
                    if(cur->next) cur->next->prev = cur->prev;
                    delete cur;
                    break;
                }
                cur = cur->next;
            }
            while(cur);
        } 
        // Thao tác 4: In danh sách
        else {
            if(!root) continue;
            node cur = root;
            while(cur->next) {
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