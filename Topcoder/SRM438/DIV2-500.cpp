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
typedef vector<int> row;
typedef vector<row> matrix;

class FeudaliasBattle{ 
public: 
    
  double getMinimumTime(row bxi,row byi,row sxi,row syi,int tt,int rt,int ms)
  {
      double tot=(double)tt/60;
      vector<double> bx,by,sx,sy;
      bx.push_back(bxi[0]);
      bx.push_back(bxi[1]);
      by.push_back(byi[0]);
      by.push_back(byi[1]);
      sx.push_back(sxi[0]);
      sx.push_back(sxi[1]);
      sy.push_back(syi[0]);
      sy.push_back(syi[1]);
      double dist0=sqrt(((bx[0]-sx[0])*(bx[0]-sx[0]))+((by[0]-sy[0]))*(by[0]-sy[0]));
      double dist1=sqrt(((bx[0]-sx[1])*(bx[0]-sx[1]))+((by[0]-sy[1]))*(by[0]-sy[1]));
      double dist2=sqrt(((bx[1]-sx[0])*(bx[1]-sx[0]))+((by[1]-sy[0]))*(by[1]-sy[0]));
      double dist3=sqrt(((bx[1]-sx[1])*(bx[1]-sx[1]))+((by[1]-sy[1]))*(by[1]-sy[1]));
      
      double ans0=max((double)tot+(dist0/ms),tot+rt+tot+(dist2/ms));
      ans0=min(ans0,max((double)tot+(dist2/ms),tot+rt+tot+(dist0/ms)));
      double ans1=tot+max((dist0/ms),(dist3/ms));
      double ans2=tot+max((dist1/ms),(dist2/ms));
      double ans3=max((double)tot+(dist1/ms),tot+rt+tot+(dist3/ms));
      ans3=min(ans3,max((double)tot+(dist3/ms),tot+rt+tot+(dist1/ms)));
      
      return min(ans0,min(ans1,min(ans2,ans3)));
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
