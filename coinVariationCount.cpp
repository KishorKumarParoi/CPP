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

const int N   = 1e4 + 5;
const int MOD = 1e9 + 7;
int n, W, dp[310][10010];

int fun(int idx, int amount, vector<int>&coins){
       if(amount == 0) return 1;
       if(idx < 0) return 0;
       
       if(dp[idx][amount] != -1) return dp[idx][amount];
       
       int ways = 0;

         for(int coin_amount = 0; coin_amount <= amount; coin_amount += coins[idx ]){
           if(amount-coin_amount >= 0) {
              ways += fun(idx-1, amount-coin_amount, coins);
           }
       }
    
    return dp[idx][amount] = ways;
}

int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        int ans = fun(coins.size()-1,amount,coins);
        return ans;
}

void solve(){
      
       cin >> n >> W;
       vector<int>v(n);
       for(int i = 0; i < n ; ++i) cin >> v[i];
       cout << coinChange(v,W);
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  //TEST
  solve();

  return 0;
}