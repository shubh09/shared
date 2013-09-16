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



int iseq(vector <int> x,vector <int> m,double c,int ind)
{
    int s=x.size();
    double left=0,right=0;
    int i;
    FOR(i,0,ind+1)
    {
        double dist=(double)x[i]-c;
        left+=(double)m[i]/(dist*dist);
    }
    FOR(i,ind+1,s)
    {
        double dist=(double)x[i]-c;
        right+=(double)m[i]/(dist*dist);
    }
    if (left>right) return -1;
    if (left<right) return 1;
    return 0;
}

double solve(vector <int> x,vector<int> m,double c,int ind)
{
    printf("here");
    int t=iseq(x,m,c,ind);
    if (t==0) return c;
    if (t>0) c=(c+(double)x[ind])/2;
    else c=(c+(double)x[ind+1])/2;
    return solve(x,m,c,ind);
}

double f(double m,double d)
{
    return m/d/d;
}
class EquilibriumPoints{ 
public: 
    
  vector <double> getPoints(vector <int> x,vector <int> m)
  {
      vector <double> ans;
      int i,j,k;
      int s=x.size();
      FOR(i,1,s)
      {
          //printf("here");
          int ind=i-1;
          double hi=(double)x[ind];
          double lo=(double)x[ind+1];
          FOR(j,0,500)
          {
              double mid=(hi+lo)/2;
              double left=0,right=0;
              FOR(k,0,i) left+=f(m[k],mid-x[k]);
              FOR(k,i,s) right+=f(m[k],mid-x[k]);
              if (left<right) hi=mid;
              else lo=mid;
          }
          ans.push_back(hi);
      }
      return ans;
  }
};

//for testing
int main()
{
    EquilibriumPoints cls;
    int t=100;
    int i,j;
    vector <int> x,m;
    FOR(i,0,t)
    {
        sd(n);
        x.clear();m.clear();
        FOR(j,0,n)
        {
            sd(t1);x.push_back(t1);
        }
        FOR(j,0,n)
        {
            sd(t2);m.push_back(t2);
        }
        vector <double> ans=cls.getPoints(x,m);
        FOR(j,0,n-1)
        {
            printf("%f\n",ans[j]);
        }
    }
}
