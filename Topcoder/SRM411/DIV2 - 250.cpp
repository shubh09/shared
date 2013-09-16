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

#define MAXM 10000

typedef long long ll;




class MaximumScoredNumber{ 
public: 
    
  int getNumber(int l,int u)
  {
      int i,j;
      int mx=0;
      int ans=u;

      vector <int> arr(MAXM+1,0);
    FOR(i,0,101)
    {
        FOR(j,i,101)
        {
            int temp=(i*i)+(j*j);
            if (temp<=MAXM) arr[temp]++;
        }
    }
      
      for (i=u;i>=l;i--)
      {
          if (arr[i]>mx)
          {
              mx=arr[i];
              ans=i;
          }
      }
      return ans;
  }
};

//for testing
int main()
{
    MaximumScoredNumber cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
