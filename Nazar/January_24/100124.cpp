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

// Есть строка, состоящая из символов алфавита. Найти длину минимальной подстроки, содержащей в себе буквы 'a', 'b', и 'c'

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    int dif = 0;
    // aaabcdeabac
    // !![ptr1, ptr2]!! / [ptr1, ptr2)
    ++cnt[s[0]];
    if(s[0] <= 'c') ++dif;
    int ans = 1e9;
    for(int l = 0, r = 0; l < n && r < n; )
    {
        if(dif == 3)
        {
            ans = min(ans, r - l + 1);
            if(s[l] <= 'c')
            {
                --cnt[s[l]];
                if(cnt[s[l]] == 0) --dif;
            }
            ++l;

            continue;
        }
        ++r;
        for(; r < n; )
        {
            if(s[r] <= 'c')
            {
                ++cnt[s[r]];
                if(cnt[s[r]] == 1) ++dif;
            }
            if(dif == 3) break;
            ++r;
        }
    }
    cout << ans << endl;
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