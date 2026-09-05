#include <bits/stdc++.h>
using namespace std;

#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

struct Edge {
    int u, v, w;
    bool in_tree = false;
};

struct DSU {
    vector<int> parent, size;

    explicit DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return true;
    }
};

/*
Bước 1: Nhận xét về giá trị cần đạt
Gọi best(u, v) là thông lượng lớn nhất có thể của một đường truyền từ u
đến v, tức là giá trị lớn nhất của cạnh nhỏ nhất trên đường truyền đó.
Với cạnh (u, v, w), thông lượng sau nâng cấp bắt buộc phải ít nhất bằng
best(u, v), nên chi phí nhỏ nhất của cạnh này là best(u, v) - w.

Bước 2: Xây maximum spanning tree
Dùng Kruskal nhưng xét các cạnh theo trọng số giảm dần. Với mọi hai đỉnh
u, v, giá trị nhỏ nhất trên đường đi duy nhất giữa chúng trong maximum
spanning tree chính là best(u, v). Đây là tính chất minimax của maximum
spanning tree.

Bước 3: Định nghĩa trạng thái nâng nhị phân
Gốc cây tại đỉnh 1. Gọi up[i][u] là tổ tiên của u sau 2^i bước đi lên,
và mn[i][u] là cạnh nhỏ nhất trên đoạn từ u đến up[i][u].

Bước 4: Bài toán cơ sở
Với mỗi đỉnh u khác gốc:
- up[0][u] là cha trực tiếp của u;
- mn[0][u] là trọng số cạnh nối u với cha.
Đặt up[i][1] = 1 và mn[i][1] = INF để việc truy vấn ở gốc an toàn.

Bước 5: Công thức truy hồi
Đoạn dài 2^i được chia thành hai đoạn dài 2^(i - 1), do đó:
up[i][u] = up[i - 1][up[i - 1][u]],
mn[i][u] = min(mn[i - 1][u], mn[i - 1][up[i - 1][u]]).

Bước 6: Trả lời truy vấn trên cây
Để tìm cạnh nhỏ nhất trên đường đi u-v:
1. Nâng đỉnh sâu hơn lên cùng độ sâu với đỉnh còn lại.
2. Nếu hai đỉnh đã trùng nhau, trả về giá trị nhỏ nhất đã gặp.
3. Từ mức lớn xuống nhỏ, nâng đồng thời hai đỉnh khi tổ tiên của chúng
   còn khác nhau, đồng thời cập nhật các cạnh đi qua.
4. Cuối cùng xét hai cạnh nối trực tiếp hai đỉnh hiện tại với LCA.

Bước 7: Tính đúng đắn
Theo tính chất maximum spanning tree, minimum trên đường đi trong cây
là đúng best(u, v). Bảng nâng nhị phân lưu đúng tổ tiên và minimum của
mỗi đoạn lũy thừa của 2; các bước truy vấn ghép các đoạn đó thành toàn bộ
đường đi u-v, nên trả về đúng best(u, v).

Bước 8: Tính đáp án và chứng minh tối ưu
Với mỗi cạnh, đặt thông lượng mới bằng best(u, v). Mọi phương án hợp lệ
đều phải trả ít nhất best(u, v) - w cho cạnh đó. Đồng thời, việc gán các
cạnh theo các giá trị best không làm thay đổi các thành phần liên thông ở
mọi ngưỡng thông lượng, nên vẫn thỏa điều kiện đề bài. Vì vậy tổng chi phí
sau đây là nhỏ nhất:
answer = sum(best(u, v) - w) với mọi cạnh (u, v, w).

Bước 9: Độ phức tạp và trường hợp biên
Sắp xếp và các truy vấn đều trong O((n + m) log n), bộ nhớ O(n log n + m).
Dùng long long cho đáp án. Đồ thị được đảm bảo liên thông nên Kruskal tạo
được n - 1 cạnh; các cạnh trong cây có best(u, v) = w và đóng góp bằng 0.
*/

int main() {
    nguyentukien;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (Edge &edge : edges) {
        cin >> edge.u >> edge.v >> edge.w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w > b.w;
    });

    vector<vector<pair<int, int>>> tree(n + 1);
    DSU dsu(n);
    for (Edge &edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            edge.in_tree = true;
            tree[edge.u].push_back({edge.v, edge.w});
            tree[edge.v].push_back({edge.u, edge.w});
        }
    }

    int log_n = 1;
    while ((1 << log_n) <= n) ++log_n;

    const int INF = 1e9;
    vector<vector<int>> up(log_n, vector<int>(n + 1));
    vector<vector<int>> mn(log_n, vector<int>(n + 1, INF));
    vector<int> depth(n + 1, -1);

    queue<int> q;
    depth[1] = 0;
    up[0][1] = 1;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : tree[u]) {
            if (v == up[0][u]) continue;
            depth[v] = depth[u] + 1;
            up[0][v] = u;
            mn[0][v] = w;
            q.push(v);
        }
    }

    for (int i = 1; i < log_n; ++i) {
        for (int u = 1; u <= n; ++u) {
            up[i][u] = up[i - 1][up[i - 1][u]];
            mn[i][u] = min(mn[i - 1][u], mn[i - 1][up[i - 1][u]]);
        }
    }

    auto query = [&](int u, int v) {
        int result = INF;

        if (depth[u] < depth[v]) swap(u, v);
        int difference = depth[u] - depth[v];
        for (int i = 0; i < log_n; ++i) {
            if (difference & (1 << i)) {
                result = min(result, mn[i][u]);
                u = up[i][u];
            }
        }

        if (u == v) return result;

        for (int i = log_n - 1; i >= 0; --i) {
            if (up[i][u] != up[i][v]) {
                result = min(result, mn[i][u]);
                result = min(result, mn[i][v]);
                u = up[i][u];
                v = up[i][v];
            }
        }

        result = min(result, mn[0][u]);
        result = min(result, mn[0][v]);
        return result;
    };

    ll answer = 0;
    for (const Edge &edge : edges) {
        if (!edge.in_tree) {
            answer += query(edge.u, edge.v) - edge.w;
        }
    }

    cout << answer << '\n';
    return 0;
}
