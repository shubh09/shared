#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                   push_back(n)

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;
typedef vector <string> vstr;

class PastingPaintingDivTwo{ 
public: 
    
  ll countColors(vstr cb,int t)
  {
      vstr canv(200,string(200,'.'));
      int i,j,k;
      int s1=cb.size(),s2=cb[0].size();
      ll ans=0;
      FOR(i,0,s1)
      {
          FOR(j,0,s2)
          {
              canv[i][j]=cb[i][j];
              ans+=(cb[i][j]=='B');
          }
      }
      ans*=(ll)t;
      //now find the overlap
      int s=min(s1,s2);
      s=min(s,t);
      ll ovr=0,ovriter=0;
      FOR(k,1,s)
      {
          ovriter=0;
          FOR(i,0,s1)
          {
              FOR(j,0,s2)
              {
                  if (cb[i][j]=='B')
                  {
                      if (canv[k+i][k+j]=='B')
                      {
                          ovriter++;
                      }
                      else
                      {
                          canv[k+i][k+j]='B';
                      }
                  }
              }
          }
          ovr+=ovriter;
      }
      ans-=(ll)ovr;
      ans-=(ll)(t-s)*ovriter;

      //pl(ovr);
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
