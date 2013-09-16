#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <sstream>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                                   push_back(n)

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;
typedef vector <string> vstr;

int p10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

string int2str(int n)
{
    stringstream ss;
    string ans;
    ss<<n;
    ss>>ans;
    return ans;
}

int solve(int n,int m)
{
    string str=int2str(n);
    int l=str.length();
    if (m<l) return p10[m]-p10[m-1];
    if (m==l) return n-(p10[m-1]-1);
    return 0;
}

class SoldierLabeling{ 
public: 
    
  int count(int n,int l,int u)
  {
      int ans=0,i;
      FOR(i,l,u+1)
      {
          ans+=solve(n,i);
      }
      return ans;
  }
};

//for testing
int main()
{
    className cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
