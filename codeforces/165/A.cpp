#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<pair<int,int> > v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i].first ;
        cin >> v[i].second ;
    }
    int ans = 0 ;
    for(int i=0;i<n;i++){
        int x = v[i].first ;
        int y = v[i].second ;
        int a = 0 , b = 0 , c = 0 , d = 0;
        for(int j=0;j<n;j++){

            int xx = v[j].first ;
            int yy = v[j].second ;
            if ( y == yy && xx > x ){
                a++ ;
            }
            else if ( y == yy && xx < x ){
                b++;
            }
            else if ( x == xx && yy > y ){
                c++;
            }
            else if ( x == xx && yy < y ){
                d++;
            }

        }
        if ( a && b && c && d ) ans++;
    }
    cout << ans << endl;

    return 0 ;
}
