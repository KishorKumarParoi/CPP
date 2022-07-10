/*
One Day You will become RED Coder ;
Just Keep breathing & Practicing in your own way;

Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/

//09-05-22
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

const int N   = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, W, dp[105][N], w[N], v[N];

int fun(int ind, int wt_lft){
      if(wt_lft == 0) return 0;
      if(ind < 0) return 0;
      
      if(dp[ind][wt_lft] != -1) return dp[ind][wt_lft];
      
      int ans = fun(ind-1,wt_lft);
      if(wt_lft-w[ind] >= 0)
        ans = max(ans, fun(ind-1,wt_lft - w[ind]) + v[ind]);
     return dp[ind][wt_lft] = ans;
}

void solve(){
      memset(dp,-1,sizeof dp);
      cin >> n >> W;
      fr(i,0,n-1) cin >> w[i] >> v[i];
      cout << fun(n-1,W) << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  //TEST
  solve();

  return 0;
}