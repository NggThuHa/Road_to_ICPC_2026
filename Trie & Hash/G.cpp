#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'

/* Ý tưởng:
    Kiểm tra đoạn con S[L..R] có phải là Palindrome (xâu đối xứng) bằng Rolling Hash:
    - Xây dựng mảng Hash xuôi `hashS` trên xâu ban đầu S.
    - Xây dựng mảng Hash ngược `hashRS` trên xâu đảo ngược RS = reverse(S).
    - Đoạn $S[l..r]$ trên xâu xuôi tương ứng với đoạn $RS[n - r + 1..n - l + 1]$ trên xâu ngược.
    - Nếu Hash đoạn xuôi bằng Hash đoạn ngược tương ứng -> S[L..R] là Palindrome (YES).

Bước 1: Xây dựng trạng thái
hashS[i] là hash của tiền tố S[1..i], còn hashRS[i] là hash của tiền tố
xâu đảo RS[1..i]. power[i] lưu base^i modulo mod.

Bước 2: Khởi tạo
hashS[0] = hashRS[0] = 0 và power[0] = 1. Mỗi ký tự được đổi thành
một số dương (a -> 1, ..., z -> 26) trước khi cập nhật hash.

Bước 3: Công thức tiền xử lý
hashS[i] = hashS[i - 1] * base + value(S[i]) (mod mod),
tương tự cho hashRS. Từ hash tiền tố, hash của mọi đoạn được lấy trong O(1).

Bước 4: Trả lời truy vấn
Đoạn S[l..r] tương ứng với đoạn RS[n-r+1..n-l+1]. Hai đoạn là palindrome
khi và chỉ khi hai hash tương ứng bằng nhau.

Bước 5: Tính đúng đắn
Đảo ngược S biến thứ tự ký tự của S[l..r] thành thứ tự ngược lại.
Vì vậy hai hash bằng nhau khi đoạn đang xét đối xứng, với xác suất rất cao
(theo giả thiết không xảy ra va chạm hash).

Bước 6: Độ phức tạp
Tiền xử lý O(n), mỗi truy vấn O(1), bộ nhớ O(n). Đây là hash xác suất;
muốn giảm nguy cơ va chạm có thể dùng hai modulo hoặc một hash 64-bit.

Bước 7: Trường hợp biên
Cần bảo đảm 1 <= l <= r <= n. Đoạn một ký tự luôn là palindrome vì nó
được so sánh với chính nó.
*/

ll hashS[1000006], hashRS[1000006], power[1000006], mod = 1e9 + 7, base = 29;

// Lấy mã Hash đoạn l..r trên xâu xuôi hoặc xâu ngược
inline ll getHash(int l, int r, bool isReverse = false){
    if (isReverse) return (hashRS[r] - hashRS[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
    else return (hashS[r] - hashS[l - 1] * power[r - l + 1] + 1ll * mod * mod) % mod;
}

inline void solve(){
    string s; cin >> s;
    string rs = s; reverse(rs.begin(), rs.end());
    int n = s.size();
    
    // Tiền xử lý Hash xuôi và Hash ngược
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i - 1] * base) % mod;
        hashS[i] = (hashS[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod;
        hashRS[i] = (hashRS[i - 1] * base + (rs[i - 1] - 'a' + 1)) % mod;
    }
    
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        // So sánh Hash xuôi S[l..r] với Hash ngược RS[n - r + 1 .. n - l + 1]
        if (getHash(l, r) == getHash(n - r + 1, n - l + 1, true)) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main(){
    nguyentukien
    int t = 1; // cin >> t;
    while (t--) solve();
    return 0;
}