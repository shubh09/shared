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
#define pb(n)                                   push_back(n)

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;
typedef vector <string> vstr;

class NumericalPerfectionLevel{ 
public: 
    
  int getLevel(long long n)
  {
      int s=(int)sqrt(n),i,count=0;
      FOR(i,2,s+1)
      {
            while (n%i==0)
            {
                n/=i;
                count++;
            }
      }
      if (n>1) count++;
      int r=count/4;
      if (r==0) return 0;
      if (r<4) return 1;
      return 2;
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
