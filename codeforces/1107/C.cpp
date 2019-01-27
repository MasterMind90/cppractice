#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , k ;
    cin >> n >> k ;
    vector<long long> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    string x ;
    cin >> x ;
    priority_queue<long long> q ;
    q.push(v[0]);
    long long res = 0 ;
    for(int i=1;i<=x.size();i++){
        if ( x[i] != x[i-1] ){
            long long cnt = (long long)q.size() ;
            for(int i=0;i<min(k,cnt);i++){
                res += q.top() ; q.pop();
            }
            q = priority_queue<long long>() ;
            if ( i == x.size() ) continue ;
            q.push(v[i]);
        }
        else{
            q.push(v[i]);
        }
    }
    cout << res << endl;
    return 0 ;
}
