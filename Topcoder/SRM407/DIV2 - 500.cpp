#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;

vector <ll> salary(100,-1);

ll solve(int i,vector <string> v)
{
    if (salary[i]>0) return salary[i];
    int s=v[i].length();
    int j;
    ll ans=0;
    FOR(j,0,s)
    {
        if (v[i][j]=='Y')
        {
            ans+=solve(j,v);
        }
    }
    if (ans==0) ans=1;
    salary[i]=ans;
    return ans;
}

class CorporationSalary{ 
public: 
    
  ll totalSalary(vector <string> v)
  {
      int s=v.size();
      int i;
      ll ans=0;
      FOR(i,0,s)
      {
          ans+=solve(i,v);
      }
      return ans;
  }
};

//for testing
int main()
{
    CorporationSalary cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
