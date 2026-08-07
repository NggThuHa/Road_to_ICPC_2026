#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

ll hashS[1000006], power[1000006], mod = 2e9 + 11, base = 29;

inline ll getHash(int l, int r){
    return (hashS[r] - hashS[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
}

inline void solve(){
    unordered_set<ll> mark;    
    int n, k; cin >> n >> k;
    string s; cin >> s;
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i - 1] * base) % mod;
        hashS[i] = (hashS[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod;
    }
    for (int i = 1; i <= n - k + 1; i++) {
        ll h = getHash(i, i + k - 1);
        mark.insert(h);
    }
    cout << mark.size() << endl;
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
    while (t--) solve();
    // clock_t end = clock();
    // get_time_n_mem(start, end);
    return 0;
}