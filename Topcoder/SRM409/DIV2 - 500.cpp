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

int overlap(string a,string b)
{
    int s1=a.length();
    int s2=b.length();
    int s=min(s1,s2);
    int i;
    for (i=s;i>0;i--)
    {
        string str1=a.substr(s1-i);
        cout<<"str1 "<<str1<<endl;
        string str2=b.substr(0,i);
        cout<<"str2 "<<str2<<endl;
        if (str1.compare(str2)==0) break;
    }
    return i;
}

class OrderedSuperString{ 
public: 
    
  int getLength(vector <string> v)
  {
      int s=v.size();
      string ss=v[0];
      int i;
      FOR(i,1,s)
      {
          //int k=overlap(ss,v[i]);
          int found=ss.find(v[i-1]);
          if (ss.find(v[i],found)==string::npos)
          {
              string temp=ss.substr(found);
              cout<<"temp"<<temp<<endl;
              int k=overlap(temp,v[i]);
              temp=v[i].substr(k);
              p(k);
              ss.append(temp);
              cout<<ss<<endl;
          }
      }
      return ss.length();
  }
};

//for testing
int main()
{
    OrderedSuperString cls;
    int t=100;
    int i,j;
    vector <string> v;
    FOR(i,0,t)
    {
        sd(n);
        v.clear();
        FOR(j,0,n)
        {
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        p(cls.getLength(v));
    }
}
