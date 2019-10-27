#include<bits/stdc++.h>
using namespace std;
#define           ll                 long long int

int main()
{
    ll  w , s , c , k ;
    cin >> w >> s >> c >> k ;
    if(( s < k || w+c < k ) || ( s == k && w+c <= 2*k) || ( w+c == k && s <= 2*k )) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0 ;
}
//https://open.kattis.com/problems/otherside
