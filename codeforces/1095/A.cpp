#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    for(int i=1;s.size()>0;i++){
        cout << s[0];
        s.erase(0,i);
    }
    cout << endl;

    return 0 ;
}
