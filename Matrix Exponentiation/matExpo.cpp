#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e9 + 10;

void matMult(int** mat1, int** mat2, int** res, int x, int y, int z, int mod) {
    int (*A)[y] = (int (*)[y]) mat1;
    int (*B)[z] = (int (*)[z]) mat2;
    int (*C)[z] = (int (*)[z]) res;

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < z; j++) {
            C[i][j] = 0;
            for(int k = 0; k < y; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
}

void matIden(int** mat, int n) {
    int (*x)[n] = (int (*)[n]) mat;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            x[i][j] = 0;
        }
        x[i][i] = 1;
    } 
}

void matPow(int** mat, int** ans, int n, int y, int mod) {
    if(y == 0) {
        matIden(ans, n);
        return;
    }
    int temp[n][n];
    matPow(mat, (int**) temp, n, y / 2, mod);

    int temp_square[n][n];
    matMult((int**) temp, (int**) temp, (int**) temp_square, n, n, n, mod);

    if(y & 1) {
        matMult((int**) temp_square, mat, ans, n, n, n, mod);
    } else {
        matIden((int**) temp, n);
        matMult((int**) temp_square,(int**) temp, ans, n, n, n, mod);
    }
}
 
void solve() {
    int n; cin>>n;
    int mat[2][2] = {
        {1, 1},
        {1, 0}
    };

    int res[2][2];
    matPow((int **) mat, (int **) res, 2, n, M);
    cout<<res[0][1]<<endl;
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