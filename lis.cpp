/*
One Day You will become RED Coder ;
Just Keep breathing & Practicing in your own way;

Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/

//08-05-22
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
int a[N], dp[N];

int lis(int i){
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j = 1; j < i; ++j){
        if(a[j] < a[i])
           ans = max(ans, lis(j) + 1);
    }
    return dp[i] = ans;
}

void solve(){
   memset(dp,-1,sizeof dp);
   int n; cin >> n;
   fr(i,1,n) cin >> a[i];
   int ans = 1;
   
   fr(i,1,n){
      ans = max(ans,lis(i));
   }
   
   cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  //TEST
  solve();

  return 0;
}