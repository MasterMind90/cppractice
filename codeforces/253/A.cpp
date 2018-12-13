#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin ;
    cin.open("input.txt");
    ofstream cout;
    cout.open("output.txt");
    int n , m ;
    cin >> n >> m ;
    if ( m >= n ){
        int len = n + m ;
        for(int i=0;i<len;i++){
            if ( i % 2 == 0 && m ) {
                cout << 'G';
                m--;
            }
            else if ( i % 2 == 0 && !m ){
                cout << 'B' ;
            }
            else if ( i % 2 == 1 && n ) {
                cout << 'B' ;
                n--;
            }
            else if ( i % 2 == 1 && !n ){
                cout << 'G';
            }
        }
        cout << endl;
    }
    else{
        int len = n + m ;
        for(int i=0;i<len;i++){
            if ( i % 2 == 1 && m ) {
                cout << 'G';
                m--;
            }
            else if ( i % 2 == 1 && !m ){
                cout << 'B' ;
            }
            else if ( i % 2 == 0 && n ) {
                cout << 'B' ;
                n--;
            }
            else if ( i % 2 == 0 && !n ){
                cout << 'G';
            }
        }
        cout << endl;
    }


    return 0 ;
}
