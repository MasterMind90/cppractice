#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(X) (((X)<0)?(-(X)):(X))

int main(){
    int n,m,d,a[10001],mid,moves=0;
    cin>>n>>m>>d;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    sort(a,a+n*m);
    mid=a[(n*m)/2];

    for(int i=0;i<n*m;i++){
        a[i]=ABS(a[i]-mid);
        //cout<<a[i]<<endl;
        if(a[i]%d!=0){
            cout<<-1<<endl;
            return 0;
        }
        moves+=a[i]/d;
    }
    cout<<moves<<endl;
    return 0;
    }
/*
2 2 2
2 4
6 8


*/
