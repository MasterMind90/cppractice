#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> v(n);
    set<int> s ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        s.insert(v[i]);
    }
    if ( s.size() >= m ) {
        cout << "YES" << endl;
        set<int> ss ;
        int c = 0 ;
        for(int i=0;i<n;i++){
            if ( c >= m ) break;
            auto it = ss.find(v[i]);
            if ( it == ss.end() ) {
                cout << i+1 << " ";
                ss.insert(v[i]);
                c++;
            }
        }
    }
    else cout << "NO" << endl;
    return 0 ;
}
