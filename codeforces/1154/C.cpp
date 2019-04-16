#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a , b , c ;
    cin >> a >> b >> c ;

    long long fishWeek = a/3LL;
    long long rabbitWeek = b/2LL;
    long long chickenWeek = c/2LL;
    long long week = min(fishWeek,rabbitWeek);
    week = min(week,chickenWeek);
    a-=week*3;
    b-=week*2;
    c-=week*2;
    // 0 1 2 3 4 5 6
    int maxDay = 0 ;
    for(int j=0;j<7;j++){
        int ta = a ;
        int tb = b ;
        int tc = c ;
        int days = 0 ;
        for(int i=j;;i++){
            if ( (i%7 == 0 || i%7 == 1 || i%7 == 4) ){
                if ( ta ) {
                    ta--;
                    days++;
                }
                else break;
            }
            if ( (i%7 == 2 || i%7 == 6 ) ){
                if ( tb ) {
                    tb--;
                    days++;
                }
                else break;
            }
            if ( (i%7 == 3 || i%7 == 4 ) ){
                if ( tc ) {
                    tc--;
                    days++;
                }
                else break;
            }
        }
        maxDay = max(days,maxDay);
    }
    cout << week*7+maxDay << endl;

    return 0 ;
}
