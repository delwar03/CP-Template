#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n;
int table[30][N];

void buildTable(vector<int> par) {
    memset(table, 0, sizeof table);
    for(int i = 0; i < n; i++) {
        table[0][i] = par[i];
    }

    for(int i = 1; i < 30; i++) {
        for(int j = 0; j < n; j++) {
            table[i][j] = table[i - 1][table[i-1][j]];
        }
    }
}

int query(int u, int k) {
    for(int i = 0; i < 30; i++) {
        if(k & (1LL << i)) u = table[i][u];
    }
    return u;
}

void solve() {
    cin>>n;
    vector<int> par(n);
    for(auto &x : par) cin>>x;
    
    buildTable(par);
    int q; cin>>q;
    while(q--) {
        int u, k; cin>>u>>k;
        cout<<query(u, k)<<endl;
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