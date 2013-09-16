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

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}

class TomekPhone{ 
public: 
    
  int minKeystrokes(vector <int> freq,vector <int> key)
  {
      int s1=freq.size(),s2=key.size();
      int letters=0,i,j;
      FOR(i,0,s2)
      {
          letters+=key[i];
      }
      if (letters<s1) return -1;
      //legitimate layout
      int ans=0;
      
      
      vector < pair<int,int> > arr(s2);
      FOR(i,0,s2)
      {
          arr[i].first=0;
          arr[i].second=i;
      }
      sort(freq.begin(),freq.end());
      
      for (i=s1-1;i>=0;i--)
      {
          j=0;
          while(arr[j].first>=key[arr[j].second]) j++;
          arr[j].first++;
          ans+=((arr[j].first)*freq[i]);
//         p((arr[j].first)*freq[i]);
          sort(arr.begin(),arr.end(),compare);
//          FOR(j,0,s2) printf("%d ",arr[j].first);
//          printf("\n");
          
      }
      return ans;
  }
};

//for testing
int main()
{
    TomekPhone cls;
    int t=100;
    int i,j;
    FOR(i,0,t)
    {
        sd(n1);
        vector <int> arr1,arr2;
        FOR(j,0,n1)
        {
            sd(temp);
            arr1.push_back(temp);
        }
        sd(n2);
        FOR(j,0,n2)
        {
            sd(temp);
            arr2.push_back(temp);
        }
        p(cls.minKeystrokes(arr1,arr2));
    }
}
