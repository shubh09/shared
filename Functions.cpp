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
typedef vector <ll> row;
typedef vector <row> matrix;

ll MOD=(ll) 1e9+7;

int addmod(int a,int b)
{
	ll t=(ll)a+b;
	if (t>=MOD) t=t%MOD;
	return t;
}

int submod(int a,int b)
{
    //assuming both a and b are positive and <MOD
    int t=a-b;
    t=t<0?t+MOD:t;
    return t;
}

int mulmod(int a,int b)
{
	ll t=(ll)a*b;
	if (t>=MOD) t=t%MOD;
	return t;
}


int epowmod(int a,int p)
{
	if (p==0) return 1;
	int t=epowmod(a,p/2);
	t=mulmod(t,t);
	if (p&1) t=mulmod(t,a);
	return t;
}

int epow(int a,int p)
{
	if (p==0) return 1;
	int t=epow(a,p/2);
	t*=t;
	if (p&1) t*=a;
	return t;
}


void clear(matrix &a)
{
	size_t i,j;
	FOR(i,0,a.size())
	{
		FOR(j,0,a[i].size())
		{
			a[i][j]=0;
		}
	}
}
	
matrix mul(matrix &a,matrix &b)		//for multiplying square matrices
{
	size_t i,j,k;
	matrix c=a;
	clear(c);
	size_t s=c.size();
	FOR(i,0,s)
	{
		FOR(j,0,s)
		{
			FOR(k,0,s)
			{
				c[i][j]=addmod(c[i][j],mulmod(a[i][k],b[k][j]));
			}
		}
	}
	return c;
}

matrix pow(matrix &a,ll n)
{
	matrix c=a;
	if (n==0)
	{
		clear(c);
		size_t i;
		FOR(i,0,a.size()) c[i][i]=1;
		return c;
	}
	c=pow(a,n/2);
	c=mul(c,c);
	if (n&1) c=mul(c,a);
	return c;
}

void display_row(row &a)
{
    int i;
    int s=a.size();
    FOR(i,0,s)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void display_matrix(matrix &a)
{
    int i;
    int s=a.size();
    FOR(i,0,s)
    {
        display_row(a[i]);
    }
}

int m2r(int r,int c,int s)
{
    return (s*r+c);
}

pair <int,int> r2m(int k,int s)
{
    int d=k/s;
    int r=k%s;
    return make_pair(d,r);
}

int row_m_size(int s_row)
{
    int s=(int)(sqrt(s_row)+0.5);
    return s;
}

void display_row_m(row &a)
{
    int i,j;
    int s=row_m_size(a.size());
    FOR(i,0,s)
    {
        FOR(j,0,s)
        {
            printf("%d ",a[m2r(i,j,s)]);
        }
        printf("\n");
    }
}

row fw(row &a,int k)
{
    int s=row_m_size(a.size());
    row ans=a;
    int i,j;
    
    FOR(i,0,s)
    {
        FOR(j,0,s)
        {
            int ind=m2r(i,j,s);
            //ans[ind]=a[ind];
            ans[ind]=min(a[ind],a[m2r(i,k,s)]+a[m2r(k,j,s)]);
        }
    }
    return ans;
}

int ndigits(int n) //assumes '0' has 1 digit
{
    if (n==0) return 1;
    int count=0;
    while(n>0)
    {
        n/=10;
        count++;
    }
    return count;
}

int bin_srch(vector <int> a,int l,int r,int x)
{
    if (l>=r)
    {
        if (a[l]<=x) return l;
        return l-1;
    }
    int mid=(l+r)>>1;
    if (a[mid]==x) return mid;
    if (a[mid]>x) return bin_srch(a,l,mid-1,x);
    return bin_srch(a,mid+1,r,x);
}

void insertion_sort(vector <int> &a)
{
    int i,j,v;
    int s=a.size();
    FOR(i,1,s)
    {
        v=a[i];j=i;
        while(j>0&&a[j-1]>v)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=v;
    }
}


//the next two functions can be used to split a string using a given delimiter in C++
//Doesn't skip empty tokens
vector<string> &split(string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(string &s, char delim) {
    vector<string> elems;
    return split(s, delim, elems);
}


//trim function in C++
inline std::string trim_right_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}

inline std::string trim_left_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( s.find_first_not_of( delimiters ) );
}

inline std::string trim_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return trim_left_copy( trim_right_copy( s, delimiters ), delimiters );
}


int ndivisors(int n)		//O(sqrt(n))
{
    int ans=0;
    int i;
    double s2=sqrt(n);
    int s=(int) (s2);
    FOR(i,1,s+1)
    {
        if (n%i==0)
        {
            if (i!=n/i) ans++;
            ans++;
        }
    }
    return ans;
}

int gcd(int a,int b)		//works for all cases - a>b,a=b,a<b
{
    if (b==0) return a;
    return gcd(b,a%b);
}

ll lcm(int a,int b)
{
    int g=gcd(a,b);
    ll ans=(ll)a/g;
    ans*=(ll)b;
    return ans;
}

void upminheap(vector <int> h,int k)    //assuming h[0] is a sentinel
{
    int v=h[k];
    while (v<h[k/2])
    {
        h[k]=h[k/2];
        k/=2;
    }
    h[k]=v;
}

void downminheap(vector <int> h,int k)
{
    int N=h.size()-1;
    int v=h[k];
    int j;
    while (k<=(N/2))
    {
        j=k+k;
        if (j<N)
        {
            if (h[j+1]<h[j])
            {
                j++;
            }
        }
        if (v<=h[j]) break;
        h[k]=h[j];k=j;
    }
    h[k]=v;
}

void insertmin(vector <int> h,int x)
{
    int s=h.size()-1;
    h.push_back(x);
    upminheap(h,s+1);
}

void removemin(vector <int> h,int k)    //here k is the index
{
    int s=h.size()-1;
    h[1]=h[s];
    h.pop_back();
    downminheap(h,1);
}


//a.compare(b) works well too - returns >0 if b comes before a lexicographically
int comp(string a,string b)			//lexicographically compare a and b; return 1 if a comes before b lexicographically, -1 if b comes before a and 0 if a and b are equal
{
    int l1=a.length();
    int l2=b.length();
    int l=min(l1,l2);
    int i;
    FOR(i,0,l)
    {
        if (a[i]>b[i])
        {
            return -1;
        }
        if (a[i]<b[i])
        {
            return 1;
        }
    }
    if (l1==l2) return 0;
    if (l1<l2) return 1;
    return -1;
}

//code to generate all the possible permutations of a string in lexicographic order

vector <string> genPerm2(int a[])
{
    int i,j;
    vector <string> ans;
    FOR(i,0,26)
    {
        if (a[i]>0)
        {
            a[i]--;
            vector <string> ans2=genPerm2(a);
            a[i]++;     //imp
            char c=(char)(i+97);
            string sc;
            stringstream ss;
            ss<<c;
            ss>>sc;
            int s=ans2.size();
            FOR(j,0,s)
            {
                string temp=sc;
                ans.push_back(temp.append(ans2[j]));
            }
            
        }
    }
    if (ans.size()==0)
    {
        string stemp="";
        ans.push_back(stemp);
    }
    return ans;
}

vector <string> genPerm(string s)		//assumes that s contains only lowercase letters
{
    int l=s.length();
    int i;
    int arr[26];
    memset(arr,0,sizeof(arr));
    FOR(i,0,l)
    {
        arr[s[i]-97]++;
    }
    return genPerm2(arr);
}

bool isPalindrome(string a)
{
    int l=a.length();
    string str1=a.substr(0,l/2);
    string str2=a.substr((l+1)/2,l/2);
    return (str1.compare(str2)==0);    
}

int str2int(string s)
{
    istringstream buffer(s);
    int ans;
    buffer>>ans;
    return ans;
}

string int2str(int n)
{
    stringstream ss;
    string ans;
    ss<<n;
    ss>>ans;
    return ans;
}

string char2str(char c)
{
    stringstream ss;
    string ans;
    ss<<c;
    ss>>ans;
    return ans;
}

vector <int> sieve(int n)
{
    vector <int> ans(n+1,0);
    int i=2,j;
    while(1)
    {
        while (ans[i]!=0 && i<=n) i++;
        if (i>n) break;
        //ans[i]=1;
        for (j=i;j<=n;j+=i) ans[j]++;
    }
    return ans;
}

string stradd(string a,string b)	//requires char2str
{
    int l1=a.length(),l2=b.length();
    int l=max(l1,l2);
    if (l1<l2)
    {
        //pad a with zeros
        int i;
        string pad;
        FOR(i,0,l2-l1)
        {
            pad=pad.append(char2str('0'));
        }
        a=pad.append(a);
    }

    if (l1>l2)
    {
        //pad b with zeros
        int i;
        string pad;
        FOR(i,0,l1-l2)
        {
            pad=pad.append(char2str('0'));
        }
        b=pad.append(b);
    }

    //cout<<a<<" "<<b<<endl;
    string ans;
    int c=0,i;
    FOR(i,0,l)
    {
        string ans1=ans;
        int temp=a[l-i-1]+b[l-i-1]-96+c;
        c=temp/10;
        ans=char2str((temp%10)+48);
        ans=ans.append(ans1);
    }
    if (c)
    {
        string ans1=ans;
        ans=char2str(c+48);
        ans=ans.append(ans1);
    }
    return ans;
}

vector<bool> sieve(int n)		//O(nloglogn)
{
    //ans[i]=true if i is prime
    vector<bool> ans(n+1,true);
    ans[0]=ans[1]=false;
    int i;
    int hi=(int)sqrt(n);
    FOR(i,2,hi+1)
    {
        if (ans[i]==true)
        {
            //i is prime
            int t=i*i;
            while (t<=n)
            {
                ans[t]=false;
                t+=i;
            }
        }
    }
    return ans;
}

//invfact and fact; modular calculations
FOR(i,1,MX) fact[i]=mulmod(fact[i-1],i);
ifact[MX-1]=epowmod(fact[MX-1],MOD-2);
for (i=MX-2;i>=0;i--) ifact[i]=mulmod(ifact[i+1],i+1);

//Removing duplicates from a vector (and sort the vector in the process)
//Tested - TC_571_1_250
template <class T>
void removeDuplicates(vector <T> &v)
{
	set<T> temp_set(all(v));
	vector<T> v2(all(s));
	v=v2;
}