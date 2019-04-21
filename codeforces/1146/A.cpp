#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    sort(s.rbegin(),s.rend());

    while(true){
        int a = 0 ;
        for(char x : s){
            if ( x == 'a' ) a++;
        }
        if ( s.size() % 2 == 0 ){
            if ( a > s.size() / 2 ){
                cout << s.size() << endl;
                return 0 ;
            }
        }
        else{
            if ( a >= (s.size() / 2)+1 ){
                cout << s.size() << endl;
                return 0;
            }
        }
        s.erase(0,1);
    }

    return 0 ;
}
