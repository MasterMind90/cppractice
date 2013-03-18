#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N;
int s1,s2,s3;

int main(){
    int a,b,c;
    cin >> N;
    s1=0;
    s2=0;
    s3=0;
    for(int i=0;i<N;i++){
        cin >> a >> b >> c;
        s1+=a;s2+=b;s3+=c;
    } 
    if (!s1 && !s2 && !s3) cout << "YES" << endl;
    else cout << "NO" << endl;
     
    return 0;
}