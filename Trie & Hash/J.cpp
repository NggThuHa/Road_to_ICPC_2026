#include <bits/stdc++.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tường:
    Giả sử A + B = C, với độ dài của A là len1, độ dài của A + B là len12, độ dài của C là len3.
    Ta có len3 = n - len12. Do đó, len1 có thể là len3 hoặc len3 - 1.
    Ngoài ra, ta cũng có thể thử các trường hợp len1 = len12 - len3 hoặc len1 = len12 - len3 + 1.
*/

ll hashS[1000006], power[1000006], mod = 1e9 + 7, base = 10; // BẮT BUỘC phải là 10

inline ll getHash(int l, int r){
    if (l > r) return 0;
    return (hashS[r] - hashS[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
}

// len1 là độ dài A, len12 là tổng độ dài A + B
inline bool check (int len1, int len12, const string& s, int n) {
    if (len1 <= 0 || len12 <= len1 || len12 >= n) return false;
    if (len1 != 1 && s[1] == '0') return false; 
    if (len12 - len1 != 1 && s[len1 + 1] == '0') return false;
    if (n - len12 != 1 && s[len12 + 1] == '0') return false;
    
    return true;
}

inline void solve(){
    string s; cin >> s;
    int n = s.size();
    
    // Thêm khoảng trắng để đẩy index của s bắt đầu từ 1
    s = " " + s; 
    
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i - 1] * base) % mod;
        // Phải trừ đi '0' để lấy giá trị số học chuẩn
        hashS[i] = (hashS[i - 1] * base + (s[i] - '0')) % mod; 
    }
    
    // Gọi len12 là điểm chia giữa B và C. Nghĩa là A+B nằm từ 1 đến len12.
    // C nằm từ len12 + 1 đến n. Do đó độ dài C (len3) = n - len12.
    for (int len12 = n - 1; len12 >= 2; --len12) {
        int len3 = n - len12;
        ll hashC = getHash(len12 + 1, n);
        
        // Vì A + B = C, nên độ dài của C phải >= độ dài lớn nhất của A và B.
        // Mảng len1 (độ dài của A) có thể là len3 hoặc len3 - 1.
        int possible_len1[] = {len3 - 1, len3, len12 - len3, len12 - len3 + 1};
        
        for (int len1 : possible_len1) {
            if (check(len1, len12, s, n)) {
                ll hashA = getHash(1, len1);
                ll hashB = getHash(len1 + 1, len12);
                
                if ((hashA + hashB) % mod == hashC) {
                    cout << s.substr(1, len1) << "+" 
                         << s.substr(len1 + 1, len12 - len1) << "=" 
                         << s.substr(len12 + 1, len3) << endl;
                    return; // Tìm thấy thì dừng luôn
                }
            }
        }
    }
}

signed main(){
    nguyentukien
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    return 0;
}