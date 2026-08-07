#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

struct Node {
    int co, pw;
    Node* prev;
    Node* next;
    Node (int co, int pw) : co(co), pw(pw), prev(nullptr), next(nullptr) {}
}; typedef Node* node;

inline void input(string &s, node &root){
    stringstream ss(s);
    string token;
    
    while (ss >> token) {
        if (token == "+") continue;
        
        int pos = token.find("*x^");
        int co = stoi(token.substr(0, pos));
        int pw = stoi(token.substr(pos + 3));
        
        node newNode = new Node(co, pw);
        
        // Nếu danh sách rỗng
        if (!root) {
            root = newNode;
            continue;
        }
        
        node cur = root;
        node prev = nullptr;
        
        // Trôi con trỏ tìm vị trí (danh sách giảm dần theo số mũ)
        while (cur && cur->pw > newNode->pw) {
            prev = cur;
            cur = cur->next;
        }
        
        // Trạng thái 1: Số mũ bằng nhau -> Cộng dồn hệ số, hủy node vừa tạo
        if (cur && cur->pw == newNode->pw) {
            cur->co += newNode->co;
            delete newNode;
        } 
        // Trạng thái 2: Không trùng số mũ -> Chèn newNode vào giữa prev và cur
        else {
            newNode->next = cur;
            newNode->prev = prev;
            
            if (prev) {
                prev->next = newNode;
            } else {
                root = newNode; // Nếu prev là nullptr nghĩa là chèn vào đầu
            }
            
            if (cur) {
                cur->prev = newNode;
            }
        }
    }
}

inline void solve(){
    string s1, s2; 
    getline(cin, s1);
    getline(cin, s2);
    node root = nullptr;
    input(s1, root);
    input(s2, root);
    while (root && root->next) {
        cout << root->co << "*x^" << root->pw << " + ";
        root = root->next;
    }
    if (root) cout << root->co << "*x^" << root->pw << endl;
}

// inline void get_time_n_mem(clock_t start, clock_t end){
//     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
//     cerr << "\n-----------------------------------\n";
//     cerr << "Time:   " << fixed << setprecision(6) << time_taken << " sec\n";
//     cerr << "-----------------------------------\n";
// }

signed main(){
    nguyentukien
    // clock_t start = clock();
    int t = 1; cin >> t;
    cin.ignore(); 
    while (t--) solve();
    // clock_t end = clock();
    // get_time_n_mem(start, end);
    return 0;
}