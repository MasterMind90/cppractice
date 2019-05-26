#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int ma=0;
	for(int i=0;i<s.size();i++){
        int cnt = 0 ;
        int cur = i;
		while(s[cur]=='A'||s[cur]=='T'||s[cur]=='C'||s[cur]=='G'){
            cnt++ ;
            cur++;
		}
        ma = max(ma,cnt) ;
	}
	cout<<ma<<endl;
  return 0 ; 
}
