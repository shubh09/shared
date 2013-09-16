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

class GreatFairyWar{ 
public: 
    
  int minHP(vector <int> dps,vector <int> hp)
  {
      int n=hp.size();
      int i,j;
      int ans=0;
      FOR(i,0,n)
      {
          int s=0;
          FOR(j,i,n)
          {
              s+=dps[j];
          }
          ans+=(s*hp[i]);
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
