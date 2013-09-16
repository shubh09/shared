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

class SoccerLeagues{ 
public: 
    
  vector <int> points(vector <string> v)
  {
      int s=v.size();
      int i,j;
      vector <int> ans(s,0);
      FOR(i,0,s)
      {
          FOR(j,0,s)
          {
              char c=v[i][j];
              if (c=='W')
              {
                  ans[i]+=3;
              }
              if (c=='L')
              {
                  ans[j]+=3;
              }
              if (c=='D')
              {
                  ans[i]+=1;
                  ans[j]+=1;
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
