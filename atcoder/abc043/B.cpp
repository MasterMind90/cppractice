#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    vector<int> v ;
    for(char c : s){
        if ( c == '1' ){
            v.push_back(1);
        }
        else if ( c == '0' ){
            v.push_back(0);
        }
        else{
            if ( v.size() )
                v.pop_back();
        }
    }
    for(int x : v){
        cout << x ;
    }
    cout << endl;
    return 0 ;
}
