#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll sum, prefix, suffix, maxSum;
    Node(ll v = 0) {
        sum = prefix = suffix = maxSum = v;
    }
};

class SegmentTree {
    int n;
    vector<Node> tree;

    Node combine(Node left, Node right) {
        Node parent;
        parent.sum = left.sum + right.sum;
        parent.prefix = max(left.prefix, left.sum + right.prefix);
        parent.suffix = max(right.suffix, right.sum + left.suffix);
        parent.maxSum = max({left.maxSum, right.maxSum, left.suffix + right.prefix});
        return parent;
    }

    void build(vector<ll>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = Node(a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        tree[v] = combine(tree[2*v], tree[2*v+1]);
    }

    void update(int v, int tl, int tr, int pos, ll newVal) {
        if (tl == tr) {
            tree[v] = Node(newVal);
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(2*v, tl, tm, pos, newVal);
        else update(2*v+1, tm+1, tr, pos, newVal);
        tree[v] = combine(tree[2*v], tree[2*v+1]);
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return Node(LLONG_MIN); // very negative
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(2*v, tl, tm, l, min(r, tm));
        Node right = query(2*v+1, tm+1, tr, max(l, tm+1), r);
        if (left.maxSum == LLONG_MIN) return right;
        if (right.maxSum == LLONG_MIN) return left;
        return combine(left, right);
    }

public:
    SegmentTree(vector<ll>& a) {
        n = a.size();
        tree.resize(4*n);
        build(a, 1, 0, n-1);
    }

    void pointUpdate(int idx, ll val) {
        update(1, 0, n-1, idx, val);
    }

    ll getMaxSubarraySum(int l, int r) {
        return query(1, 0, n-1, l, r).maxSum;
    }
};
int main() {
    vector<ll> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    SegmentTree st(a);

    cout << "Max subarray sum in [0, 8] = " << st.getMaxSubarraySum(0, 8) << "\n"; // Should be 6
    st.pointUpdate(3, 10);
    cout << "After update: Max subarray sum in [0, 8] = " << st.getMaxSubarraySum(0, 8) << "\n";
}
