#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    string x ;
    cin >> x ;
    int cnt[26] ;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<x.size();i++){
        cnt[x[i]-'a']++;
    }
    while(k>0){
        for(int i=0;i<26;i++){
            if ( k >= cnt[i] ){
                k-=cnt[i];
                cnt[i] = 0 ;
            }
            else{
                cnt[i]-=k;
                k=0;
                break;
            }
        }
    }
    stack<char> ss ;
    for(int i=x.size()-1;i>=0;i--){
        if ( cnt[x[i]-'a'] ){
            ss.push(x[i]);
            cnt[x[i]-'a']--;
        }
    }
    while(!ss.empty()){
        cout << ss.top() ;
        ss.pop();
    }
    cout << endl;

    return 0 ;
}
