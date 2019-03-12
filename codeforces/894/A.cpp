#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    vector<int> sum(s.size()+1,0);
    int cnt = 0 ;
    for(int i=0;i<s.size();i++){
        if ( s[i] == 'Q' ) cnt++ ;
        if ( s[i] == 'A' ) sum[i] = cnt;
    }
    int ans = 0 ;
    for(int i=0;i<s.size();i++){
        if ( s[i] == 'Q' ){
            for(int j=i-1;j>=0;j--){
                if ( s[j] == 'A' ) ans += sum[j];
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
