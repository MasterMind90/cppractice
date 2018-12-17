#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int start = 0 ;
    int end = n-1;
    for(int i=1;i<n;i++){
        if ( v[i] < v[i-1] ){
            start = i - 1 ;
            break;
        }
    }
    for(int i=1;i<n;i++){
        if ( v[i] > v[start] ) {
            end = i - 1 ;
            break;
        }
    }
    reverse(v.begin()+start,v.begin()+end+1);
    for(int i=1;i<n;i++){
        if ( v[i] < v[i-1] ){
            cout << "no" << endl;
            return 0 ;
        }
    }
    cout << "yes" << endl;
    cout << start+1 << " " << end+1 << endl;



    return 0 ;
}
