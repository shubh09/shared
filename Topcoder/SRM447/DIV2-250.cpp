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

class ImportantTasks{ 
public: 
    
  int maximalCost(row cx,row comp)
  {
      //sort(cx.begin(),cx.end());
      sort(comp.begin(),comp.end());
      row arr(comp.size(),0);
      int ans=0,i,j;
      FOR(i,0,cx.size())
      {
          FOR(j,0,comp.size())
          {
              if (arr[j]==0&&cx[i]<=comp[j])
              {
                  arr[j]++;
                  ans++;
                  break;
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
