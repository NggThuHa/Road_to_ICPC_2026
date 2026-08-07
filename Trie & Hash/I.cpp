#include <bits/stdc++.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define endl '\n'

/* Ý tưởng:
    Nối các chuỗi tiếp theo vào kết quả sao cho phần đè lên (overlap) là lớn nhất:
    - Xâu `ans` lưu kết quả tích lũy.
    - Với xâu mới `s`, ta thử độ dài giao nhau `len` giảm dần từ `min(n, m)` về 0.
    - Nếu phần hậu tố của `ans` độ dài `len` (`ans.substr(m - len)`) trùng với tiền tố của `s` độ dài `len` (`s.substr(0, len)`), ta nối phần còn dư `s.substr(len)` vào `ans` và kết thúc bước hiện tại.
*/

string ans = "";

inline void solve(){
    string s; 
    cin >> s;
    if (ans == "") {
        ans = s;
        return;
    }
    int n = s.size();
    int m = ans.size();
    
    // Tìm độ dài giao nhau lớn nhất giữa đuôi của ans và đầu của s
    for (int len = min(n, m); len >= 0; --len) {
        if (ans.substr(m - len) == s.substr(0, len)) {
            ans += s.substr(len);
            return;
        }
    }
}

signed main(){
    nguyentukien
    int t = 1; 
    cin >> t;
    while (t--) solve();
    cout << ans << endl;
    return 0;
}