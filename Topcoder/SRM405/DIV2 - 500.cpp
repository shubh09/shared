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

vector <string> split(string a,char c) //splits a string wrt the delimiter c. returns only the non empty tokens in the vector.
{
    int i;
    int l=a.length();
    int pos=0,count=0;
    //if (a[0]==c) start=1;
    vector <string> ret;
    FOR(i,0,l)
    {
        if (a[i]==c)
        {
            string str=a.substr(pos,count);
            if (!str.empty()) ret.push_back(str);
            pos=i+1;
            count=0;
        }
        else count++;
    }
    string str=a.substr(pos,count);
    if (!str.empty()) ret.push_back(str);
    return ret;
}

class RelativePath{ 
public: 
    
  string makeRelative(string a,string b)
  {
      vector <string> av=split(a,'/');
      vector <string> bv=split(b,'/');
      int i;
      int u=min(av.size(),bv.size());

      FOR(i,0,u)
      {
          if (av[i]!=bv[i]) break;
      }
      int it=i;
      int dd=bv.size()-i;
      string str;
      //p(dd);
      FOR(i,0,dd)
      {
          str.append("../");
      }
      FOR(i,it,av.size())
      {
          str.append(av[i]);
          str.append("/");
      }
      return str.substr(0,str.length()-1);
      //str.append(av[av.size()-1]);
  }
};

//for testing
int main()
{
    RelativePath cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        string a,b;
        cin>>a>>b;
        //printf("heer");
        cout<<cls.makeRelative(a,b)<<endl;
    }
}
