/*
One Day You will become RED Coder ;
Just Keep breathing & Practicing in your own way;

Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/

//06-05-22
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
#define fr(i,a,b)                         for(int i=a;i<=b;++i)
#define all(v)                            v.begin(),v.end()
#define TEST                              int tc;cin>>tc; while(tc--)
// Debug
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout << #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

using namespace std;

const int N   = 1e3 + 5;
const int MOD = 1e9 + 7;

int binCr(int i, int n, int k, int res){
    if(i == k) return res;
    res *= (n-i);
    res/=(i+1);
    binCr(i+1,n,k,res);
}

int dp[66][33];
int nCr(int n, int r){
    if(r == 0) dp[n][r] = 1;
    if(r == 1) dp[n][r] = n;
    if(r == n) dp[n][r] = 1;
    
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int kkp[1001][1001];
void combi(int n){
     fr(i,0,n){
        kkp[i][0] = kkp[i][i] = 1;
        fr(j,1,i-1){
           kkp[i][j] = kkp[i-1][j] + kkp[i-1][j-1];
        }
     }
}
void solve(){
    int n, k; cin >> n >> k;
    if(k > n-k) k = n - k;
    
    //cout << binCr(0,n,k,1) << endl;
    cout << nCr(n,k) << endl;
    //combi(n); cout << kkp[n][k] << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  //TEST
  solve();

  return 0;
}