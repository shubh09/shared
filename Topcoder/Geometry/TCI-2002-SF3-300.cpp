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
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;

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

class Point
{
public:
    double x,y,z;
    Point(double x,double y,double z):x(x),y(y),z(z){}
    double operator *(const Point &rhs) const
    {
        Point lhs=*this;
        return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z;
    }
    bool operator <(const Point &rhs) const
    {
        Point lhs=*this;
        return lhs.x==rhs.x?(lhs.y==rhs.y?lhs.z<rhs.z:lhs.y<rhs.y):lhs.x<rhs.x;
    }
    void print()
    {
    }
};

int str2int(string s)
{
    istringstream buffer(s);
    int ans;
    buffer>>ans;
    return ans;
}

#define PI 3.14159265359

class Travel {
	public:
	int shortest(vector <string> cities, int r)
	{
		int i,j;
                int n=sz(cities);
                vector<pii> vp;
                FOR(i,0,n)
                {
                    vstr vs=split(cities[i],' ');
                    vp.pb(mp(str2int(vs[0]),str2int(vs[1])));
                }
                vector<Point> arr;
                FOR(i,0,n)
                {
                    double lat=vp[i].first,lon=vp[i].second;
                    lat*=(PI/180.0);lon*=(PI/180.0);
                    double x=(double)r*cos(lat)*cos(lon);
                    double y=(double)r*cos(lat)*sin(lon);
                    double z=(double)r*sin(lat);
                    arr.pb(Point(x,y,z));
                }
//                vp.erase(vp.begin());
                double dans=1e9;
                sort(arr.begin()+1,arr.end());
                do
                {
                    double tans=0;
                    FOR(i,0,n)
                    {
                        Point A=arr[i],B=arr[(i+1)%n];
                        double ang=A*B;
                        ang/=(r*r);
                        ang=acos(ang);
                        double dist=(ang)*r;
                        tans+=dist;
                    }
                    dans=min(dans,tans);
                }while (next_permutation(arr.begin()+1,arr.end()));
                dans+=0.5;
                int ans=(int)dans;
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0","0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 35; verify_case(0, Arg2, shortest(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0 0","0 1","0 -1","-1 0","1 0","-1 -1","1 1","1 -1","-1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, shortest(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"40 -82","-27 -59","-40 48"
,"26 -12","-31 -37","-30 42"
,"-36 -23","-26 71","-19 83","8 63"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 698; int Arg2 = 4505; verify_case(2, Arg2, shortest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Travel ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
