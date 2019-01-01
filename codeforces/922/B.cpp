#include <bits/stdc++.h>
using namespace std;
bool area(int a,int b,int c){
    double p = (a+b+c)/2.0;
    double area = sqrt(p*(p-a)*(p-b)*(p-c)) ;
    if ( area > 0.00001 ) return true ;
    return false;
}
int main(){
    int n ;
    cin >> n ;
    int ans = 0 ;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j;k<=n;k++){
                if ( ((i ^ j ^ k) == 0) && area(i,j,k) ) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
