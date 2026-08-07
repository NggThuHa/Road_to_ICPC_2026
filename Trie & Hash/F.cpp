#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

ll dp[1000006], power[1000006], mod = 1e9 + 7, base = 29;

inline ll getHash(int l, int r) {
    return (dp[r] - dp[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
}

inline void solve(){
    string s, p; cin >> s >> p;
    ll hashP = 0;
    int ns = s.size();
    int np = p.size();
    s = " " + s; p = " " + p;
    power[0] = 1;
    for (int i = 1; i <= ns; ++i) 
        power[i] = (power[i - 1] * base) % mod;
    for (int i = 1; i <= np; ++i) 
        hashP = (hashP * base + (p[i] - 'a' + 1)) % mod;
    for (int i = 1; i <= ns; ++i)
        dp[i] = (dp[i - 1] * base + (s[i] - 'a' + 1)) % mod;
    for (int i = 1; i + np - 1 <= ns; ++i) {
        if (getHash(i, i + np - 1) == hashP) cout << i << " ";
    }
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
    int t = 1; // cin >> t;
    while (t--) solve();
    // clock_t end = clock();
    // get_time_n_mem(start, end);
    return 0;
}