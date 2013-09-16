#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <sstream>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;

vector <string> split(string str)
{
    int l=str.length();
    int i;
    int prev=0;
    vector <string> ans;
    FOR(i,0,l)
    {
        
        if (str[i]==' ')
        {
            int len=i-prev;
            ans.push_back(str.substr(prev,len));
            prev=i+1;
        }
    }
    
    ans.push_back(str.substr(prev,i-prev));
    return ans;
}

class Undo{ 
public: 
    
  string getText(vector <string> v,vector <int> a)
  {
      int s=v.size();
      int i,j;
      vector <string> res;
      FOR(i,0,s)
      {
          vector <string> temp=split(v[i]);
          if (temp[0].compare("type")==0)
          {
              string tmp=i>0?res[i-1]:"";
              tmp.append(temp[1]);
              res.push_back(tmp);
          }
          else
          {
              int sec;
              stringstream ss;
              ss<<temp[1];
              ss>>sec;
              j=0;
              sec=a[i]-sec-1;
              while (a[j]<sec&&j<i)
              {
                  j++;
              }
              if (j==i) j--;
              else
              {
                if (a[j]!=sec) j--;
              }
              string tmp2;
              if (j<0) tmp2="";
              else tmp2=res[j];
              res.push_back(tmp2);
          }
      }
      return res[s-1];
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
