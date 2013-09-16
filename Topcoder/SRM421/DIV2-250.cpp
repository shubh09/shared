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

class GymTraining{ 
public: 
    
  int trainingTime(int nt,int mn,int mx,int tc,int rc)
  {
      //finding the max number of training minutes
      int pulse=mn;
      int time=0;
      int ttime=0;
      while (1)
      {
          //Training
          int train=(mx-pulse)/tc;
          pulse+=(train*tc);
          
          if (ttime+train>=nt)
          {
              return time+(nt-ttime);
          }
          time+=train;
          ttime+=train;
          if (train==0) return -1;
          //Rest
          double t=(double)(pulse-(mx-tc))/rc;
          int rest=(int)ceil(t);
          pulse-=(rest*rc);
          pulse=max(mn,pulse);
          time+=rest;
          //printf("%d %d %d %d %d\n",train,rest,pulse,time,ttime);
      }
  }
};

//for testing
int main()
{
    GymTraining cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        sd(nt);sd(mn);sd(mx);sd(tc);sd(rc);
        p(cls.trainingTime(nt,mn,mx,tc,rc));
    }
}
