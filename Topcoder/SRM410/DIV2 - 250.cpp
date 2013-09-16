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

class ContiguousCacheEasy{ 
public: 
    
  int bytesRead(int n,int k,vector <int> arr)
  {
      int s=arr.size();
      int b=0;
      int ans=0;
      int i;
      FOR(i,0,s)
      {
          if (!(arr[i]-b<=k-1&&arr[i]>=b))
          {
              int bt=b;
              if (arr[i]>b)
              {
                  b=arr[i]-k+1;
              }
              else
              {
                  b=arr[i];
              }
              ans+=min(abs(bt-b),k);
              //p(abs(bt-b));
          }
      }
      return ans;
  }
};

//for testing
int main()
{
    ContiguousCacheEasy cls;
    int t=100;
    int i,j;
    vector <int> arr;
    FOR(i,0,t)
    {
        arr.clear();
        sd(n);sd(k);
        sd(tt);
        FOR(j,0,tt)
        {
            sd(temp);
            arr.push_back(temp);
        }
        p(cls.bytesRead(n,k,arr));
    }
}
