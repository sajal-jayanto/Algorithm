#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>

using namespace std;

#define _pair(x,y) make_pair(x,y)
#define INF (1<<30)
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double eps = 1e-11;
const int save[10][4] = {{0},{0},{6,2,4,8},{1,3,9,7},{6,4},{0},{0},{1,7,9,3},{6,8,4,2},{1,9}};
int todigit(char c) { return ( isdigit(c) ) ?( c - 48 ) : c ; }
int toint(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }
ll tolong(string s) {  ll r = 0; istringstream sin(s); sin >> r; return r; }
double todouble(string s) { double r = 0.0 ; istringstream sin(s); sin >> r; return r; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > T Abs(T x) { return x > 0 ? x : -x;}
template < class T > T power(T N , T P) { return (P == 0) ?  1 : N * power(N , P - 1); }
template < class T > void max(T &a, T b) { if(a < b) a = b; }
template < class T > void min(T &a, T b) { if(b < a) a = b; }
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
template < class T > inline T lcm(T a,T b) {if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b));}
ll big_mod(ll n , ll  p , ll m)
{
	ll sum;
	if(!p) return 1;
	if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
	else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
}
///int one[]={1,0,-1,0}; //4 Direction
///int two[]={0,1,0,-1}; //4 Direction
///int one[]={1,1,0,-1,-1,-1,0,1}; //8 direction
///int two[]={0,1,1,1,0,-1,-1,-1}; //8 direction
///int one[]={2,1,-1,-2,-2,-1,1,2}; //Knight Direction
///int two[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction


int main()
{
    map < string , pair < vector < string > , int > > mymap;
    map < string , pair < vector < string > , int > >::iterator it, x;
    string kye, name;
    int _max;
    getline(cin , kye);
    while( kye != "0" )
    {
        if(isupper(kye[0]))
        {
            mymap[kye];
            getline(cin , name);
            while(islower(name[0]))
            {
                mymap[kye].first.push_back(name);
                getline(cin , name);
            }
            kye = name;
        }
        if(kye == "1")
        {
            _max = 0;
            for( it = mymap.begin() ; it != mymap.end() ; ++it)
            {
                int k = 0;
                set < string > myset;
                set < string > ::iterator itt;
                for(int i = 0 ; i < it->second.first.size() ; ++i) myset.insert(it->second.first[i]);
                for(itt = myset.begin() ; itt != myset.end() ; ++itt)
                {
                    bool flag = true;
                    for(x = mymap.begin() ; x != mymap.end() ; ++x)
                    {
                        if(x != it) for(int i = 0 ; i < x->second.first.size() ; ++i) if((*itt) == x->second.first[i]){flag = false; break; }
                    }
                    if(flag) ++k;
                }
                it->second.second = k;
                max(_max , k);
            }
            for(int i = _max ; i >= 0 ; i--)
            {
                for( it = mymap.begin() ; it != mymap.end() ; ++it) if(it->second.second == i) printf("%s %d\n",it->first.c_str(),  i);
            }
            mymap.clear();
            getline(cin , kye);
        }
    }
    return 0;
}
