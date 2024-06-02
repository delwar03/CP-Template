#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;



void solve() {
    int n; cin>>n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    seg.resize(4 * n + 1);
    build(0, 0, n - 1);

    int q; cin>>q;
    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int l, r; cin>>l>>r;
            cout<<query(0, 0, n - 1, l, r)<<endl;
        } else {
            int i, val; cin>>i>>val;
            update(0, 0, n - 1, i, val);
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 7
     1 2 0 3 4 1 2
     5
     1 0 3
     2 2 4
     1 0 3
     2 5 10
     1 4 6
o/p: 0
     1
     2
*/