#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Tìm vị trí xuất hiện của xâu mẫu p trong xâu s bằng Hash chuỗi (String Hashing / Rolling Hash):
    - Tính mã Hash cho toàn bộ xâu p (`hashP`).
    - Tiền xử lý mảng Hash tiền tố `dp[i]` cho xâu s và mảng lũy thừa `power[i]`.
    - Tính Hash đoạn con `getHash(l, r)` trong $O(1)$: `(dp[r] - dp[l-1]*power[r-l+1] + mod*mod) % mod`.
    - Duyệt mọi cửa sổ độ sâu `np` trong xâu s, so sánh `getHash(i, i + np - 1)` với `hashP`.
*/

ll dp[1000006], power[1000006], mod = 1e9 + 7, base = 29;

// Lấy mã Hash của đoạn s[l..r] trong O(1)
inline ll getHash(int l, int r) {
    return (dp[r] - dp[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
}

inline void solve(){
    string s, p; cin >> s >> p;
    ll hashP = 0;
    int ns = s.size();
    int np = p.size();
    s = " " + s; p = " " + p;
    
    // Tính các lũy thừa của base
    power[0] = 1;
    for (int i = 1; i <= ns; ++i) 
        power[i] = (power[i - 1] * base) % mod;
        
    // Tính mã Hash cho xâu mẫu P
    for (int i = 1; i <= np; ++i) 
        hashP = (hashP * base + (p[i] - 'a' + 1)) % mod;
        
    // Tính Hash tiền tố cho xâu S
    for (int i = 1; i <= ns; ++i)
        dp[i] = (dp[i - 1] * base + (s[i] - 'a' + 1)) % mod;
        
    // Tìm các vị trí khớp Hash
    for (int i = 1; i + np - 1 <= ns; ++i) {
        if (getHash(i, i + np - 1) == hashP) cout << i << " ";
    }
}

signed main(){
    nguyentukien
    int t = 1; // cin >> t;
    while (t--) solve();
    return 0;
}