#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Đếm số lượng xâu con phân biệt có độ dài k trong xâu s (Count Distinct Substrings of Length K):
    - Sử dụng Rolling Hash để tính giá trị Hash của từng xâu con độ dài k: `getHash(i, i + k - 1)`.
    - Thêm mã Hash của tất cả xâu con vào `unordered_set<ll> mark`.
    - Kích thước của `mark` (`mark.size()`) chính là số xâu con phân biệt độ dài k.
*/

ll hashS[1000006], power[1000006], mod = 2e9 + 11, base = 29;

// Lấy mã Hash của đoạn s[l..r]
inline ll getHash(int l, int r){
    return (hashS[r] - hashS[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
}

inline void solve(){
    unordered_set<ll> mark;    
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    // Tiền xử lý Hash cho xâu s
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i - 1] * base) % mod;
        hashS[i] = (hashS[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod;
    }
    
    // Đẩy Hash của mọi cửa sổ độ dài k vào unordered_set
    for (int i = 1; i + k - 1 <= n; i++) {
        ll h = getHash(i, i + k - 1);
        mark.insert(h);
    }
    cout << mark.size() << endl;
}

signed main(){
    nguyentukien
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}