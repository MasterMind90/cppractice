#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    set<int> s ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        s.insert(x);
    }
    if ( s.size() > 3 ){
        cout << -1 << endl;
        return 0 ;
    }
    if ( s.size() == 1 ) {
        cout << 0 << endl;
        return 0 ;
    }
    else if ( s.size() == 2 ){
        auto it = s.begin() ;
        int x = *it ;
        it++;
        int y = *it;
        if ( (y + x) % 2 == 0 )
            cout << (y + x)/2 - x << endl;
        else cout << y - x << endl;
    }
    else if ( s.size() == 3 ){
        auto it = s.begin() ;
        int x = *it ;
        it++;
        int y = *it;
        int diff1 = y - x ;
        it++;
        int diff2 = *it - y ;
        if ( diff1 != diff2 ){
            cout << -1 << endl;
            return 0 ;
        }
        cout << diff1 << endl;
    }


    return 0 ;
}
