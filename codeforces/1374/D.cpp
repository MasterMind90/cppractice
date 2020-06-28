#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
int main()
{
    fast
    int q;
    cin>>q;
    while(q--)
    {
        ll n,k;
        cin>>n>>k;
        ll z;
        ll mx=0;
        unordered_map<ll,ll, custom_hash>m;
        for(int i=0; i<n; i++)
        {
            cin>>z;
            if(z%k!=0)
            {
                ll x=k-(z%k);
                m[x]++;
                mx=max(mx,(m[x]-1)*k+x);
            }
        }
 
        cout<<mx+(mx!=0)<<endl;
    }
 
    return 0;
 
}