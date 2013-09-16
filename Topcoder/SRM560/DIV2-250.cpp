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

class TypingDistance{ 
public: 
    
  int minDistance(string str1,string str2)
  {
      int s1=str1.size();
      int s2=str2.size();
      int arr[26],i;
      memset(arr,0,sizeof(arr));
      
      FOR(i,0,s1)
      {
          arr[str1[i]-97]=i;
      }
      int ans=0;
      FOR(i,1,s2)
      {
          ans+=abs(arr[str2[i]-97]-arr[str2[i-1]-97]);
          
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
