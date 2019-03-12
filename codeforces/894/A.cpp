#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    vector<int> sum(s.size()+1,0);
    int cnt = 0 ;
    for(int i=0;i<s.size();i++){
        sum[i+1] += sum[i];
        if ( s[i] == 'Q' ) sum[i+1]++;
    }
    int ans = 0 ;
    int n = s.size() ;
    for(int i=1;i<s.size();i++){
        if ( s[i] == 'A' ){
            int after = sum[n] - sum[i+1] ;
            int before = sum[i] ;
            ans += after*before;
        }
    }
    cout << ans << endl;
    return 0 ;
}
