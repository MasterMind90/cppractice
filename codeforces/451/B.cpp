#include <bits/stdc++.h>
using namespace std;
bool sorted(vector<int> &v){
    for(int i=1;i<v.size();i++){
        if ( v[i] >= v[i-1] ) continue ;
        else return false ;
    }
    return true ;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }
    int start = 0 ;
    int dest = 0 ;
    for(int i=0;i<n;i++){
        start = i ;
        int j ;
        for(j=i+1;j<n;j++){
            if ( v[j] < v[j-1] ){
                dest = j ;
            }
            else break;
        }
        if ( dest != 0 ){
            reverse(v.begin()+start,v.begin()+dest+1);
            if ( sorted(v) ){
                cout << "yes" << endl;
                cout << start+1 << ' ' << dest+1 << endl;
                return 0 ;
            }
            else{
                cout << "no" << endl;
                return 0 ;
            }
        }
        i = j-1;
    }
    if ( sorted(v) ){
        cout << "yes" << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0 ;
    }

    return 0 ;
}
