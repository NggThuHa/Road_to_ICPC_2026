#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

/*
Bước 1: Biểu diễn dữ liệu
Mỗi Node lưu giá trị và hai con trỏ left, right. Dùng unordered_map để
ánh xạ giá trị node tới con trỏ tương ứng, giúp nối cha-con trong O(1).

Bước 2: Khởi tạo
Ở mỗi test, xóa map cũ. Node cha của quan hệ đầu tiên được dùng làm root,
sau đó tạo node con và lưu các node vào map.

Bước 3: Xây dựng cây
Với mỗi quan hệ (par, child, side), gắn child vào left hoặc right của par
tùy theo side là 'L' hay 'R'.

Bước 4: Duyệt cây
Dùng queue cho BFS. Đưa root vào queue; mỗi lần lấy một node ra thì in nó,
sau đó lần lượt đưa các node con trái và phải vào queue.

Bước 5: Tính đúng đắn
Queue luôn chứa các node theo thứ tự không giảm về độ sâu. Vì vậy mỗi node
được in trước các node ở tầng sâu hơn, và trong cùng một node thì con trái
được xử lý trước con phải: đó là thứ tự duyệt theo mức.

Bước 6: Độ phức tạp
Xây cây và duyệt cây đều O(n) với n quan hệ; bộ nhớ O(n).

Bước 7: Trường hợp biên
Input cần mô tả một cây hợp lệ và node cha cần tồn tại trong map trước khi
được nối. Nếu cây rỗng thì không được đưa root null vào queue.
*/

struct Node{
    int data;
    Node *left, *right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
}; typedef Node* tree;
unordered_map <int, tree> mp;

// Duyệt cây theo mức (Level-order / BFS)
inline void inOrder(tree root){
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree cur = q.front(); q.pop();
        cout << cur->data << " ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}

inline void solve(){
    int n; cin >> n;
    tree root = NULL;
    mp.clear();
    for (int i = 0; i < n; i++) {
        int par, child;
        char side;
        cin >> par >> child >> side;
        if (!root) {
            root = new Node(par);
            mp[par] = root;
        }
        mp[child] = new Node(child);
        if(side == 'L') mp[par]->left = mp[child];
        else mp[par]->right = mp[child];
    }
    inOrder(root);
    cout << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
}