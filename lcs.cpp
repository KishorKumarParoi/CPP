/*
One Day You will become RED Coder ;
Just Keep breathing & Practicing in your own way;

Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/

//11-05-22
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
int dp[1010][1010];

int fun(int i, int j, string &s1, string &s2){
     if(i < 0 || j < 0) return 0;
     if(dp[i][j] != -1) return dp[i][j];
     
     int ans = fun(i-1,j,s1,s2);
     ans = max(ans, fun(i,j-1,s1,s2));
     ans = max(ans, fun(i-1,j-1,s1,s2) + (s1[i]==s2[j]));
     return dp[i][j] = ans; 
}

int longestCommonSubsequence(string text1, string text2) {
     memset(dp,-1,sizeof dp);
     return fun(text.size()-1, text2.size()-1, text1, text2);
}
    
void solve(){
     string s1,s2; cin >> s1 >> s2;
     cout << longestCommonSubsequence(s1,s2);      
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  //TEST
  solve();

  return 0;
}