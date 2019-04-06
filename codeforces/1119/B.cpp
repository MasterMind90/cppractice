#include <bits/stdc++.h>
using namespace std;
int n , h ;
bool check(priority_queue<int> q){
    long long ans = 0 ;
    while(q.size()){
        if ( q.size() == 1 ) {
            ans += q.top() ;
            q.pop();
        }
        else{
            ans += q.top() ;
            q.pop();
            q.pop();
        }
    }
    if ( ans <= h ) return true ;
    return false ;
}
int main(){
    cin >> n >> h ;
    vector<int> v(n);
    for(int &x : v){
        cin >> x ;
    }
    priority_queue<int> q ;
    q.push(v[0]);
    int ans = 1 ;
    for(int i=1;i<n;i++){
        q.push(v[i]);
        if ( check(q) ){
            ans = max(ans,i+1);
        }
        else break;
    }
    cout << ans << endl;
    return 0 ;
}
