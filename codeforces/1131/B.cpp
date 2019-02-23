#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 
pair<ll,ll> intersect(ll a, ll b, ll x, ll y){
    if ( x > b || a > y ) return {-1,-1};
    ll n = max(a,x);
    ll m = min(b,y);
    return {n,m};
}
int main(){
    ll n ;
    cin >> n ;
    ll x = 0 , y = 0 ; 
    ll cnt = 0 ;
    vector<pair<ll,ll> > s ;
    for(int i=0;i<n;i++){
        ll xx , yy ; 
        cin >> xx >> yy ; 
        auto p = intersect(x,xx,y,yy) ;
        if ( p.first != -1 ) 
            s.push_back(intersect(x,xx,y,yy));
        x = xx ;
        y = yy ;
    }
    stack<pair<ll,ll> > ss ;
    ss.push({0,0});
    for(int i=0;i<s.size();i++){
        auto cur = s[i];
        auto top = ss.top();
        if ( cur.first > top.second ) ss.push(cur);
        else{
            ss.pop();
            ss.push({top.first,cur.second});
        }
    }
    while(!ss.empty()){
        cnt += (ss.top().second - ss.top().first + 1 );
        ss.pop();
    }
    cout << cnt << endl;
    return 0 ;
}
