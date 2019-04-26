#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin >> n ;
    vector<int> a(n);
    multiset<int> s ;
    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        s.insert(x);
    }
    for(int i=0;i<n;i++){
        if ( a[i] == 0 ){
            auto it = s.begin() ;
            cout << (a[i]+*it)%n << " " ;
            s.erase(it);
        }
        else{
            auto it = s.lower_bound(n-a[i]);
            if ( it == s.end() ){
                it = s.begin() ;
            }
            cout << (a[i]+*it)%n << " " ;
            s.erase(it);
        }
    }
    return 0 ;
}
