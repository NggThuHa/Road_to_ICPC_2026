#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

ll hashS[1000006], hashRS[1000006], power[1000006], mod = 1e9 + 7, base = 29;

inline ll getHash(int l, int r, bool isReverse = false){
    if (isReverse) return (hashRS[r] - hashRS[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
    else return (hashS[r] - hashS[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
}

inline void solve(){
    string s; cin >> s;
    string rs = s; reverse(rs.begin(), rs.end());
    int n = s.size();
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i - 1] * base) % mod;
        hashS[i] = (hashS[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod;
        hashRS[i] = (hashRS[i - 1] * base + (rs[i - 1] - 'a' + 1)) % mod;
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        if (getHash(l, r) == getHash(n - r + 1, n - l + 1, true)) cout << "YES\n";
        else cout << "NO\n";
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