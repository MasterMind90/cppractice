#include <iostream>

using namespace std;
int k,l,m,n,d;
int k1,l1,m1,n1,d1;
int a[100001];

int main(){
    cin >> k >> l >> m >> n >> d;
    for(int i=0;i<100001;i++) a[i]=0;

    k1=k;l1=l;m1=m;n1=n;
    for(int i=0;i<d;i++){
        if ( k <= d ){
            a[k-1]=1;
            k+=k1;
        }
        if ( l <= d ){
            a[l-1]=1;
            l+=l1;
        }
        if ( m <= d){
            a[m-1]=1;
            m+=m1;
        }
        if ( n <= d ){
            a[n-1]=1;
            n+=n1;
        }
    }
    int count=0;
    for(int i=0;i<d;i++){
        if (a[i]==0) count++;
    }
    cout << d-count << endl;


    return 0;
}
