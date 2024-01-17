#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define eb emplace_back
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ss second
#define ff first
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x); for(auto& val : x){cout << val << ' ';}cout << endl;
#define input(x); for(auto& val : x){cin >> val;}
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define endl '\n'   
int n, k;
bool ok(const vector<int>& vec, int mid)
{
    int cnt = k;
    int prevX = -mid - 10;
    // vec.front() >= 1; vec.front() - prevX >= mid; prevX <= 1 - mid <= -mid - 10 
    for(int i = 0; i < n && cnt; ++i)
    {
        if(vec[i] - prevX >= mid)
        {
            prevX = vec[i];
            --cnt;
        }
    }

    return cnt == 0;
}
void solve()
{
    cin >> n >> k;
    vector<int> vec(n);
    input(vec);

    int l = 1, r = vec.back() - vec.front() + 1;
    // (l, r) [l, r]
    while(l + 1 < r)
    {
        int mid = (l + r) / 2;

        if(ok(vec, mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    if(ok(vec, r)) cout << r << endl;
    else cout << l << endl;
}
int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int ttest = 1; 
    // cin >> ttest;
    while(ttest--) solve();
    return 0;
}