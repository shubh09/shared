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

class CreateGroups{ 
public: 
    
  int minChanges(vector <int> arr,int mn,int mx)
  {
      int s=arr.size(),sum=0,i;
      FOR(i,0,s) sum+=arr[i];
      double avg=(double)sum/s;
      if (floor(avg)<mn||ceil(avg)>mx) return -1;
      int ans1=0,ans2=0;
      FOR(i,0,s)
      {
          if (arr[i]<mn) ans1+=(mn-arr[i]);
          else if (arr[i]>mx) ans2+=(arr[i]-mx);
      }
      return max(ans1,ans2);
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
