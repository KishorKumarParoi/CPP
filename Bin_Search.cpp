/*
One Day You will become RED Coder ;
Just Keep breathing & Practice without self-preception;
2 hour CF, 2 hour atcoder, 1 hour typing, 1 hour japa, 1 hour PK, 1 hour timepass
8 hour Marathon 8 hour sleep

Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/

//01-06-22
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
int arr[N];
int n, k;

int bin_Search(int l, int r, int x){
    while(l < r){
        int mid = l + (r-l)/2 ;
        if(arr[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    
    return l;
}
int upper_bound(int l, int r, int x){
    while(l < r){
        int mid = l + (r - l)/2;
        if(x >= arr[mid])
            l = mid + 1;
        else
            r = mid;
    }
    
    if(arr[l] <= x && l == n+1) l++;
    // cout << "up : " << l << " ";
    return l;
}

int lower_bound(int l, int r, int x){
    while(l < r){
        int mid = l + (r - l)/2;
        if(x <= arr[mid])
            r = mid;
        else
            l = mid + 1;
    }
    
    if(l == n+1 && arr[l] < x) l++; 
    // cout << "lower : " << l << endl;
    return l;
}

int up(int l, int r, int x){
   int ans = 0;
   while((r-l) > 1){
      int mid = l + (r-l)/2;
      if(arr[mid] >= x) {
          ans = mid;
          r = mid ;
       }
       else l = mid ;
   }
   
   if(ans == 0) ans = n + 1;
   return ans;
}

int lo(int l, int r, int x){
   int ans = 0;
   while((r-l) > 1){
      int mid = l + (r-l)/2;
      if(arr[mid] <= x) {
          ans = mid;
          l = mid ;
       }
       else r = mid ;
   }

   return ans;
}

void solve(){
   cin >> n ;
   for(int i = 1; i <= n; ++i) cin >> arr[i];
   arr[0] = -1e18; arr[n+1] = 1e18;
   
   sort(arr+1,arr+n+1);
   printArr(0,n+1,arr);
   
   // First Occurence 
   cout << bin_Search(0,n+1,10) << endl;
      
   int k; cin >> k;
   while(k--){
       int l, r; cin >> l >> r;
       cout << upper_bound(0,n+1,r) - lower_bound(0,n+1,l) << " ";
   }
   cout << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  // TEST
  solve();

  return 0;
}