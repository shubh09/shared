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

class CollectingUsualPostmarks{ 
public: 
    
  int numberOfPostmarks(vector <int> arr,vector <int> have)
  {
      int s=have.size();
      int i;
      int sum=0;
      FOR(i,0,s)
      {
          sum+=arr[have[i]];
      }
      s=arr.size();
      sort(arr.begin(),arr.end());
      FOR(i,0,s)
      {
          sum-=arr[i];
          if (sum<0) break;
      }
      return i;
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
