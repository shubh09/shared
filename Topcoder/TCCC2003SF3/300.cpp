#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                   push_back(n)

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;
typedef vector <string> vstr;

class ZigZag{ 
public: 
    
  int longestZigZag(row arr)
  {
      int s=arr.size();
      row a1(s,0),a2(s,0);
      row ind1(s,-1),ind2(s,-1);
      a1[0]=a2[0]=1;
      int i,j;
      FOR(i,1,s)
      {
          FOR(j,0,i)
          {
              if (arr[i]>arr[j])
              {
                  if (a1[i]<a2[j]+1)
                  {
                      a1[i]=a2[j]+1;
                      ind1[i]=j;
                  }
              }
              if (arr[i]<arr[j])
              {
                  if (a2[i]<a1[j]+1)
                  {
                      a2[i]=a1[j]+1;
                      ind2[i]=j;
                  }
              }
          }
      }
      int ans=0;
      FOR(i,0,s)
      {
          ans=max(ans,a1[i]);
          ans=max(ans,a2[i]);
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
