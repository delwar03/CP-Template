#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int f(multiset<int> &ms) {
    if(ms.empty()) return 0;
    return (*ms.rbegin()) - (*ms.begin());
}

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n + 1);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    v[n++] = INF;

    while(q--) {
        int l, r; cin>>l>>r;
        multiset<int> ms1, ms2;
        int p = 0, q = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            while(p < n && f(ms1) < l) {
                ms1.insert(v[p++]);
            }
            while(q < n && f(ms2) <= r) {
                ms2.insert(v[q++]);
            }
            ans += q - p;
            ms1.erase(ms1.find(v[i]));
            ms2.erase(ms2.find(v[i]));
        }
        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 