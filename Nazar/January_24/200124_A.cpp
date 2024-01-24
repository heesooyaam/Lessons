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

void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    input(vec);
    if(n <= 2)
    {
        cout << 0 << endl;
        print(vec);
        return;
    }
    sort(all(vec));
    vector<int> ans;
    int l = 0, r = n - 1;
    // 0001010101 & 00000001
    for(int i = 0; i < n; ++i)
    {
        if(i & 1)
        {
            ans.eb(vec[l++]);
        }
        else ans.eb(vec[r--]);
    }
    cout << ((n % 2) ? (n / 2) : (n / 2 - 1)) << endl;
    print(ans);
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