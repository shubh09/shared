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
//WRONG ANSWER
typedef long long ll;

bool lex(string a,string b)     //returns true if a comes before b lexicographically
{
    int l1=a.length();
    int l2=b.length();
    int l=min(l1,l2);
    int i;
    FOR(i,0,l)
    {
        if (a[i]!=b[i]) return a[i]<b[i];
    }
    return (l1<=l2);
}

bool pmatch(string str,string p,int n)
{
    string t1=str.substr(0,n);
    string t2=p.substr(p.length()-n);
    return (t1.compare(t2)==0);
}

bool smatch(string str,string s,int n)
{
    string t1=str.substr(str.length()-n);
    string t2=s.substr(0,n);
    return (t1.compare(t2)==0);
}

int pscore(string str,string p)
{
    int l1=str.length();
    int l2=p.length();
    int m=min(l1,l2);
    int i;
    for (i=m;i>0;i--)
    {
        if (pmatch(str,p,i)) break;
    }
    return i;
}

int sscore(string str,string s)
{
    int l1=str.length();
    int l2=s.length();
    int m=min(l1,l2);
    int i;
    for (i=m;i>0;i--)
    {
        if (smatch(str,s,i)) break;
    }
    return i;
}

class TemplateMatching{ 
public: 
    
  string bestMatch(string str,string pre,string suf)
  {
      int l=str.length();
      int i,j;
      int score=0;
      int ps=0;
      string ans;
      char ifempty=str[0];
      FOR(i,1,l)
      {
          ifempty=min(ifempty,str[i]);
      }
      FOR(i,0,l)
      {
          int jm=l-i;
          FOR(j,1,jm+1)
          {
              string temp=str.substr(i,j);
              int tps=pscore(temp,pre);
              int tscore=tps+sscore(temp,suf);
              if (tscore>score)
              {
                  score=tscore;
                  ans=temp;
              }
              else
              {
                  if (tscore==score)
                  {
                      if (tps>ps)
                      {
                          ps=tps;
                          ans=temp;
                      }
                      else
                      {
                          if(tps==ps)
                          {
                              if (lex(temp,ans)) ans=temp;
                          }
                      }
                  }
              }
          }
      }
      if (ans.compare("")==0)
      {
          stringstream ss;
          ss<<ifempty;
          ss>>ans;
      }
      return ans;
  }
};

//for testing
int main()
{
    TemplateMatching cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        string str,p,s;
        p=" wapl yl s kq";
        s="abw rv";
        cin>>str;//>>p>>s;
        p(pscore(str,p));
        p(sscore(str,s));
        //p(lex("qu","q"));
    }
}
