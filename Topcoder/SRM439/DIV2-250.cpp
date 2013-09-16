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

class SquareOfDigits{ 
public: 
    
  int getMax(vector <string> v)
  {
      int s1=v.size(),s2=v[0].size();
      int i,j,ans=1,k;
      FOR(i,0,s1)
      {
          FOR(j,0,s2)
          {
              int u=min(s1-i,s2-j)+1;
              char c=v[i][j];
              FOR(k,2,u)        //size of the square
              {
                  if (c==v[i+k-1][j]&&c==v[i][j+k-1]&&c==v[i+k-1][j+k-1])
                  {
                      ans=max(ans,k*k);
                  }
              }
          }
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
