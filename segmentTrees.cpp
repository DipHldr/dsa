#include <bits/stdc++.h>
using namespace std;

class segmentTrees
{
public:
    vector<int> seg;
    segmentTrees(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        if (high < l || r < low)
            return INT_MAX;

        if (low >= l && r >= high)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve()
{
    int n;
    cin >> n;
    segmentTrees sg(n);
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // int seg[4 * n];
    sg.build(0, 0, n - 1, arr);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << "min element in the range of index " << l << "<--->" << r << " is " << sg.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            sg.update(0, 0, n - 1, i, val);
        }
    }
}

void solve2()
{
    int n1;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    int n2;
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    segmentTrees s1(n1), s2(n2);

    s1.build(0, 0, n1 - 1, arr1);
    s2.build(0, 0, n2 - 1, arr2);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            cout << min(s1.query(0, 0, n1 - 1, l1, r1), s2.query(0, 0, n2 - 1, l2, r2));
        }
        else
        {
            int arrNo, i, val;
            cin >> arrNo >> i >> val;
            if (arrNo == 1)
                s1.update(0, 0, n1 - 1, i, val);
            else
                s2.update(0, 0, n2 - 1, i, val);
        }
    }
}
int main()
{
    solve();
    return 0;
}
// 6
// 1 3 2 0 4 5
// 3
// 0 3
// 1 4
// 4 6