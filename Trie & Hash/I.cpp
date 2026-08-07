#include <bits/stdc++.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define endl '\n'

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