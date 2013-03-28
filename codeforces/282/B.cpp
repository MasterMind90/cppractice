#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int a,b;
long long sumA,sumG;
int main(){
    string str="";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if (n==1 && a <= 500 ) {
            sumA+=a;
            str+="A";
            break;
        }
        else if (n==1 && b<= 500){
            sumG+=b;
            str+="G";
            break;
        }
        if (i==0){
            sumA+=a;
            str+="A";
            continue;
        }
        if ( (abs(sumA-sumG) > 500) && (sumA > sumG) ){
            sumG+=b;
            str+="G";
        }
        else if ( (abs(sumA-sumG) > 500) && (sumG > sumA) ){
            sumA+=a;
            str+="A";
        }
        /*else if ( sumA > sumG ){
            sumG+=b;
            str+="G";
            cout << su
        }*/
        else{
            if (  abs((sumA+a)-sumG) > 500  ){
                sumG+=b;
                str+="G";
                //cout << "hi" << endl;
            }
            else {
                sumA+=a;
                str+="A";
                //cout << "hi" << endl;
            }
        }
    }
    //cout << sumA  << "    " << sumG << endl;
    if (abs(sumA-sumG)>500) cout << -1 << endl;
    else cout << str << endl;
    return 0;
}
/*
3
400 600
400 600
400 600
*/
