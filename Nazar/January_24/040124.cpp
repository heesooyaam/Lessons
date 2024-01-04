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

// Kadano's algorythm

void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    ll curSum = 0;
    // max_element(container.begin(), container.end()) --> returns itertator on max element
    auto it = max_element(vec.begin(), vec.begin()); // if all elemnts are negative, then it will be ok
    ll mx = *it;
    int mxL = it - vec.begin(), mxR = mxL;
    int l = 0, r = -1;

    for(int i = 0; i < n; ++i)
    {
        if(curSum + vec[i] >= 0)
        {
            curSum += 1ll * vec[i];
            ++r;
            if(curSum > mx)
            {
                mxL = l;
                mxR = r;
                mx = curSum;
            }
        }
        else
        {
            curSum = 0;
            l = i + 1;
            r = i;
            // a b c d
        }
    }

    cout << "value of maxSum on subArray = " << mx << endl;
    cout << "size = " << mxR - mxL + 1 << endl;
    cout << "elements: ";

    for(int i = mxL; i <= mxR; ++i)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
    


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