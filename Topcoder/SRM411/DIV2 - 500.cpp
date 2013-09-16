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

//failing for indeterminate inputs. (tle)
//the code IS taking too much time for the test case("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",{"a","ab","aaa","ac"})
//even after optimizing for this particular input, still failing one test case (which SHOULD have happened!)
//(There should be a better algo for this question)
//MEMOIZE!!
//cache - of size 51 (not 50)!!
//passed!!

vector <int> cache(51,-2);

class SentenceDecomposition{ 
public: 
    

    
    //assumes that s1,s2 are made up of lowercase alphabets only
    int anag(string s1,string s2)
    {
        int l1=s1.length();
        int l2=s2.length();
        if (l1!=l2) return -1;
        vector <int> a1(26,0);
        vector <int> a2(26,0);
        int i;
        FOR(i,0,l1)
        {
            a1[s1[i]-97]++;
        }
        FOR(i,0,l2)
        {
            a2[s2[i]-97]++;
        }
        FOR(i,0,26)
        {
            if (a1[i]!=a2[i]) return -1;
        }
        int cost=0;
        FOR(i,0,l1)
        {
            if (s1[i]!=s2[i]) cost++;
        }
        return cost;
    }
    
  int decompose(string sent,vector <string> v)
  {
      int ans=51,l=sent.length(),i,s=v.size();
      
      if (l==0) return 0;
      //printf("here\n");
      if (cache[l]!=-2) return cache[l];
      FOR(i,0,s)
      {
          //cout<<sent<<endl;
          int l2=v[i].length();
          int t1=anag(v[i],sent.substr(0,l2));
          if (t1>=0)
          {
              int t2=decompose(sent.substr(l2),v);
              if (t2>=0)
              {
                  ans=min(ans,t2+t1);
              }
          }
      }
      if (ans==51) ans=-1;
      cache[l]=ans;
      return ans;
  }
};

//for testing
int main()
{
    SentenceDecomposition cls;
    int t=100;
    int i,j;
    vector <string> v;
    string sent;
    FOR(i,0,t)
    {
        v.clear();
        cin>>sent;
        sd(n);
        FOR(j,0,n)
        {
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        p(cls.decompose(sent,v));
    }
}
