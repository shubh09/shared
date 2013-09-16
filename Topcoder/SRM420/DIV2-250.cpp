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

class DeckRearranging{ 
public: 
    
  string rearrange(string str,vector <int> arr)
  {
      int s=str.size();
      string ans=str;
      int i,j;
      FOR(i,0,s)
      {
          for (j=s-1;j>=arr[i];j--)
          {
              ans[j+1]=ans[j];
          }
          ans[arr[i]]=str[i];
          //cout<<ans<<endl;
      }
      return ans;
  }
};

//for testing
int main()
{
    DeckRearranging cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        string str;
        cin>>str;
        int l=str.length();
        int i;
        vector <int> arr;
        FOR(i,0,l)
        {
            sd(temp);
            arr.push_back(temp);
        }
        cout<<cls.rearrange(str,arr)<<endl;
    }
}
