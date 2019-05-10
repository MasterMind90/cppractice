#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q[3] ;
    for(int i=0;i<3;i++){
        string x ;
        cin >> x ;
        for(char c : x){
            q[i].push(c-'a');
        }
    }
    queue<int> qq ;
    qq.push(q[0].front());
    while(qq.size()){
        int f = qq.front() ; qq.pop();
        if ( q[f].size() == 0 ){
            cout << char(f+'a'-32) << endl;
            return 0 ;
        }
        qq.push(q[f].front());
        q[f].pop();

    }



    return 0 ;
}
