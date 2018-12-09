#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2 ;
    getline(cin,s1);
    getline(cin,s2);
    int a[26]={0};
    int A[26]={0};
    for(int i=0;i<s1.size();i++){
        if ( s1[i] >= 'a' && s1[i] <= 'z' ){
            a[s1[i]-'a']++;
        }
        else if ( s1[i] >= 'A' && s1[i] <= 'Z' ){
            A[s1[i]-'A']++;
        }
    }
    for(int i=0;i<s2.size();i++){
        if ( s2[i] >= 'a' && s2[i] <= 'z' ){
            if ( a[s2[i]-'a'] ) a[s2[i]-'a']--;
            else{
                cout << "NO" << endl;
                return 0 ;
            }
        }
        else if ( s2[i] >= 'A' && s2[i] <= 'Z' ){
            if ( A[s2[i]-'A'] ) A[s2[i]-'A']--;
            else{
                cout << "NO" << endl;
                return 0 ;
            }
        }
    }
    cout << "YES" << endl;
    return 0 ;
}
