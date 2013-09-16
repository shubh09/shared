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

bool isIn(int xo,int yo,int r,int x,int y)
{
    double dist=sqrt((x-xo)*(x-xo)+(y-yo)*(y-yo));
    return dist<=(double)r;
}

class CirclesCountry{ 
public: 
    
  int leastBorders(row xx,row yy,row rad,int x1,int y1,int x2,int y2)
  {
      int s=xx.size();
      row arr1(s,0),arr2(s,0);
      int i;
      FOR(i,0,s) if (isIn(xx[i],yy[i],rad[i],x1,y1)) arr1[i]++;
      FOR(i,0,s) if (isIn(xx[i],yy[i],rad[i],x2,y2)) arr2[i]++;
      FOR(i,0,s)
      {
          if (arr1[i]==arr2[i])
          {
              arr1[i]=arr2[i]=0;
          }
      }
      int ans=0;
      FOR(i,0,s) ans+=arr1[i];
      FOR(i,0,s) ans+=arr2[i];
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
