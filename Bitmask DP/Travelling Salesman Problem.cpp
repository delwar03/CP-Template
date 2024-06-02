
// problem link: https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

/*

Problem statement:

Given a matrix dist of size n 
where dist[i][j] denotes the cost 
of moving from city i to city j. 

Your task is to complete a tour 
from the city 0 (0 based index) 
to all other cities such that you 
visit each city exactly once and 
then at the end come back to 
city 0 in min cost.

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
int dist[N][N];

int calc(int i, int mask) {
    if(mask == 0) return dist[i][0];

    if(dp[i][mask] != -1) return dp[i][mask];

    int min_dist = INF;

    for(int j = 0; j < n; j++) {
        if(mask & (1LL << j)) {
            min_dist = min(min_dist, dist[i][j] + calc(j, mask ^ (1LL << j)));
        }
    }
    
    assert(min_dist != INF);
    return dp[i][mask] = min_dist;
}

void solve() {

    cin>>n;
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>dist[i][j];
        }
    }

    int mask = (1LL << n) - 2; // all guys are available **except the first guy**

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