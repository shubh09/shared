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

class UnluckyNumbers{ 
public: 
    
  int getCount(vector <int> arr,int n)
  {
      int s=arr.size(),i;
      sort(arr.begin(),arr.end());
      FOR(i,0,s)
      {
          if (n<arr[i]) break;
      }
      int hi=arr[i];
      int lo=i>0?arr[i-1]:0;
      if (n==hi || n==lo) return 0;
      return (n-lo)*(hi-n)-1;
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
