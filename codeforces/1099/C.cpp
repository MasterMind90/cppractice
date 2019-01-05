#include <bits/stdc++.h>
using namespace std;
string s ;
string remove(int x,int len){

}
int main(){

    cin >> s ;
    int k ;
    cin >> k ;
    int can = 0 ;
    int snow = 0 ;
    string clean = "" ;
    for(int i=0;i<s.size();i++){
        if ( s[i] == '?' ) can++;
        else if ( s[i] == '*' ) snow++;
        else clean += s.substr(i,1);
    }
    int len = s.size()-(can+snow);
    if ( len == k ) {
        for(int i=0;i<s.size();i++){
            if ( s[i] == '?' || s[i] == '*' )continue ;
            cout << s[i];
        }
        cout << endl;
        return 0 ;
    }
    else if ( len > k ){
        int diff = len - k ;
        if ( (can+snow) >= diff ) {
            int c = 0 ;
            bool flag = true ;
            stack<char> x ;
            for(int i=0;i<s.size();i++){
                if ( c == diff ) {
                    flag = false ;
                }
                if ( flag && (s[i] == '?' || s[i] == '*') ){
                    x.pop();
                    c++;
                }
                if ( s[i] >= 'a' && s[i] <= 'z' ) x.push(s[i]);
            }
            vector<char> vv ;
            while(!x.empty()){
                vv.push_back(x.top()) ;
                x.pop();
            }
            for(int i=vv.size()-1;i>=0;i--){
                cout << vv[i] ;
            }
            cout << endl;
        }
        else{
            cout << "Impossible" << endl;
            return 0 ;
        }
    }
    else if ( k > len && snow == 0 ) {
        cout << "Impossible" << endl;
        return 0 ;
    }
    else if ( k > len && snow > 0 ) {
        int diff = k - len ;
        bool f = true ;
        for(int i=0;i<s.size();i++){
            if ( s[i] == '*' && f ){
                f = false ;
                for(int j=0;j<diff;j++){
                    cout << s[i-1] ;
                }
            }
            else if ( s[i] == '*' || s[i] == '?' ) continue ;
            else cout << s[i];
        }
        cout << endl;
    }
    return 0 ;
}
