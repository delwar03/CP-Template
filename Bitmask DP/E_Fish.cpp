// problem link: https://codeforces.com/contest/16/problem/E

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 19;

double prob[N][N];
double dp[(1LL << N)];
int n;

double next_step_prob(int mask, int fish_no) {
    int k = __builtin_popcount(mask);
    int denom = k * (k - 1) / 2;

    double probab_of_next_step = 0.0;

    for(int i = 0; i < n; i++) {
        if(mask & (1LL << i))
            probab_of_next_step += prob[i][fish_no];
    }
    return probab_of_next_step / (1.0 * denom);
}

double calc(int mask) {
    int alive = __builtin_popcount(mask);
    if(alive == n) 
        return 1.0;
    if(dp[mask] > -0.9)
        return dp[mask];

    double ans = 0.0;

    for(int i = 0; i < n; i++) {
        if(!(mask & (1LL << i))) { // the i`th guy not set
            int prev_mask = mask | (1LL << i);
            double prev_day_prob = calc(prev_mask);
            ans += prev_day_prob * next_step_prob(prev_mask, i);
        }
    }
    return dp[mask] = ans;
}

void solve() {
    cin>>n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>prob[i][j];
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout<<prob[i][j]<<" \n"[j == n - 1];
    //     }
    // }

    for(int i = 0; i < n; i++) {
        cout<<fixed<<setprecision(6)<<calc((1LL << i))<<" \n"[i == n - 1];
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