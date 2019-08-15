//CodeF Common Divisors 1203C
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
 
#define ll long long
 
using namespace std;
 
 
int main()
{
 cin.tie(0);ios_base::sync_with_stdio(0);
 
 int n;
 cin>>n;
 ll g=0;
 while(n--){
     ll k;
     cin>>k;
     g=__gcd(g,k);
 }
 ll ans=0;
 for(int i=1;i*1ll*i<=g;i++){
     if(g%i==0){
         ans++;
         if((i*1ll*i)!=g){ans++;}
     }
 }
 cout<<ans<<"\n";
 
 return 0;
}