#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <sstream>
#include <map>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;

vector <string> split(string str,char delim)
{
    int l=str.length();
    int i;
    int prev=0;
    vector <string> ans;
    string tmp;
    FOR(i,0,l)
    {
        if (str[i]==delim)
        {
            int len=i-prev;
            tmp=str.substr(prev,len);
            if (tmp.compare("")!=0) ans.push_back(tmp);
            prev=i+1;
        }
    }
    tmp=str.substr(prev,i-prev);
    if (tmp.compare("")!=0) ans.push_back(tmp);
    return ans;
}

int strtoi(string str)
{
    stringstream ss;
    int ans;
    ss<<str;
    ss>>ans;
    return ans;
}

bool isLeap(int y)
{
    if (y%100!=0)
    {
        if (y%4==0) return true;
        return false;
    }
    else
    {
        if (y%400==0) return true;
        return false;
    }
}

class YearProgressbar{ 
public: 
    
  double percentage(string str)
  {
      map<string,int> month;
      int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
      month["January"]=0;
      month["February"]=1;
      month["March"]=2;
      month["April"]=3;
      month["May"]=4;
      month["June"]=5;
      month["July"]=6;
      month["August"]=7;
      month["September"]=8;
      month["October"]=9;
      month["November"]=10;
      month["December"]=11;
      vector <string> v1=split(str,',');
      vector <string> v2=split(v1[0],' ');
      vector <string> v3=split(v1[1],' ');
      stringstream ss;
      int year=strtoi(v3[0]);
      int day=strtoi(v2[1]);
      if (isLeap(year)) days[1]++;
      int i;
      FOR(i,1,12)
      {
          days[i]=days[i-1]+days[i];
      }
      string mnth=v2[0];
      int m=month[mnth];
      int nr=m>0?days[m-1]:0;
      nr+=day-1;
      nr*=1440;
      vector <string> v4=split(v3[1],':');
      int h=strtoi(v4[0]);
      int m2=strtoi(v4[1]);
      nr+=(h*60)+m2;
      nr*=100;
      int dr=days[11]*1440;
      return (double)nr/dr;
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
