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

#define INF 1000000000

typedef long long ll;

int steps(int x1,int y1,int x2,int y2)
{
    return (abs(x1-x2)+abs(y1-y2));
}

class GrabbingTaxi{ 
public: 
    
  int minTime(vector <int> tx,vector <int> ty,int gx,int gy,int wt,int tt)
  {
      int s=tx.size();
      int i;
      int ans=wt*(steps(0,0,gx,gy));
      FOR(i,0,s)
      {
          int temp=steps(0,0,tx[i],ty[i]);
          temp*=wt;
          temp+=(tt*steps(tx[i],ty[i],gx,gy));
          ans=min(ans,temp);
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
