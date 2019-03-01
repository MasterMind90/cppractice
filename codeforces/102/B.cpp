#include <bits/stdc++.h>
using namespace std;
string sum(string a,string b){
    int diff = abs((int)a.size()-(int)b.size());
    if ( a.size() <= b.size() ) { 
        for(int i=0;i<diff;i++){
            a = "0" + a ;
        }
    }
    else{
        for(int i=0;i<diff;i++){
            b = "0" + b ;
        }
    }
    int c = 0 ; 
    string ans = "" ;
    for(int i=a.size()-1;i>=0;i--){
        int x = a[i] - '0' ; 
        int y = b[i] - '0' ; 
        int z = x+y+c ; 
        if ( z >= 10 ){
            char cc = (z%10)+'0';
            ans+=cc;
            c = z/10;
        }
        else{
            char cc = (z%10)+'0';
            ans+=cc;
            c = 0 ;
        }
    }
    if ( c != 0 ){
        ans += (c + '0') ; 
    }
    reverse(ans.begin(),ans.end());
    return ans ; 
}
int main(){
    string s ;
    cin >> s ; 
    int cnt = 0 ;
    while(s.size()>1){
        cnt++;
        string tmp = "0" ; 
        for(int i=0;i<s.size();i++){
            tmp = sum(s.substr(i,1),tmp);
        }
        s = tmp ;
    }
    cout << cnt << endl;
    return 0;
}
