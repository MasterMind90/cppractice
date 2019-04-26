#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<char> c ;
    int cur = 0 ;
    while(true){
        if ( v.size() ){
            int left = v[0] ;
            int right = v[v.size()-1] ;
            int nax = min(left,right);
            if ( left > cur && right > cur ){
                if ( left == nax ){
                    c.push_back('L');
                    v.erase(v.begin());
                    cur = left;
                }
                else {
                    c.push_back('R');
                    v.pop_back();
                    cur = right ;
                }
            }
            else if ( left > cur ){
                c.push_back('L');
                v.erase(v.begin());
                cur = left ;
            }
            else if ( right > cur ){
                c.push_back('R');
                v.pop_back();
                cur = right ;
            }
            else break;
        }
        else break;
    }
    cout << c.size() << endl;
    for(char x : c){
        cout << x ;
    }
    cout << endl;
    return 0 ;
}
