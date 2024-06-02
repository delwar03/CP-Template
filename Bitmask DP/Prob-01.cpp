
// problem link: https://docs.google.com/document/d/1zuw8hBXHsiTYTH8u986fQhn8TWfpOk9BQBIRH3lo_W8/edit
/*

Problem statement:

Let there be N workers and N jobs. 
Any worker can be assigned to perform any job, 
incurring some cost that may vary depending on 
the work-job assignment. 

It is required to perform all jobs by assigning 
exactly one worker to each job and exactly one 
job to each agent in such a way that the total 
cost of the assignment is minimized.

    **N <= 20**
*/

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int INF = 1e15 + 10;
const int N = 21;

int n;
int dp[N][(1LL << N)];
int cost[N][N];

int calc(int i, int mask) {
    if(i == n) return 0;

    if(dp[i][mask] != -1) return dp[i][mask];

    int mn = INF;

    for(int j = 0; j < n; j++) {
        if(mask & (1LL << j)) {
            mn = min(mn, cost[j][i] + calc(i + 1, mask ^ (1LL << j)));
        }
    }
    
    return dp[i][mask] = mn;
}

void solve() {

    cin>>n;
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>cost[i][j];
        }
    }

    int mask = (1LL << n) - 1; // all guys are available

    cout<<calc(0, mask)<<endl;
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