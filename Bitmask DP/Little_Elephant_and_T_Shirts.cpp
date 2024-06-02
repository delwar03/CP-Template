// problem link: https://www.codechef.com/problems/TSHIRTS

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 11;

bool can_take[N][10 * N];
int dp[10 * N][(1LL << N)];
int n;

int calc(int shirt, int mask) {
    if(mask == 0)
        return 1;
    if(shirt >= 100)
        return 0;

    int &ans = dp[shirt][mask];
    if(~ans)
        return ans;
    
    ans = 0;

    for(int i = 0; i < n; i++) {
        if((mask & (1LL << i))) {
            if(can_take[i][shirt]) {
                int new_mask = mask ^ (1LL << i);
                ans = (ans + calc(shirt + 1, new_mask)) % M;
            }
        }
    }
    ans = (ans + calc(shirt + 1, mask)) % M;
    return ans;
}

void solve() {
    cin>>n;
    memset(can_take, 0, sizeof can_take);
    memset(dp, -1, sizeof dp);
    string s;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream in(s);
        int a;
        while(in>>a) {
            a--;
            can_take[i][a] = true;
        }
    }
    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j < 100; j++) {
    //         cout<<can_take[i][j]<<" \n"[j == 99];
    //     }
    // }
    int mask = (1LL << n) - 1;
    cout<<calc(0, mask)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 