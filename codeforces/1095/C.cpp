#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n , k ;
    cin >> n >> k ;
    if ( k > n ) {
        cout << "NO" << endl;
        return 0 ;
    }
    stack<long long> s ;
    for(long long i=0;i<30;i++){
        if ( (n&(1<<i)) ){
            s.push((1<<i));
        }
    }
    if ( s.size() > k ){
        cout << "NO" << endl;
        return 0 ;
    }
    vector<long long> v ;
    while(!s.empty()){
        if ( v.size() + s.size() == k ) break;
        long long t = s.top();s.pop();
        if ( t == 1 ) v.push_back(t);
        else {
            s.push(t/2);
            s.push(t/2);
        }
    }
    if ( v.size() + s.size() < k ) {
        cout << "NO" << endl;
        return 0 ;
    }
    cout << "YES" << endl;
    for(long long &x : v){
        cout << x << " " ;
    }
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << endl;
    return 0 ;
}
