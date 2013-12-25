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

class Point
{
public:
    int x;
    int y;
    
    Point()
    {
        
    }
    Point(int xx,int yy) 
    {
        x=xx;
        y=yy;
    }
    
    Point operator+(const Point& rhs) const
    {
        Point temp=*this;       //Copy 'this' which is not to be modified
        temp.x+=rhs.x;
        temp.y+=rhs.y;
        return temp;
    }
    
    Point operator-(const Point& rhs) const
    {
        Point temp=*this;       //Copy 'this' which is not to be modified
        temp.x-=rhs.x;
        temp.y-=rhs.y;
        return temp;
    }
    
    //the dot product
    ll operator*(const Point& rhs) const
    {
        //Point temp=*this;       //Copy 'this' which is not to be modified
        ll temp=(ll)(this->x)*(ll)(rhs.x)+(ll)(this->y)*(ll)(rhs.y);
        return temp;
    }
    
    //the cross product
    ll operator^(const Point& rhs) const
    {
        ll temp=(ll)(this->x)*(ll)(rhs.y)-(ll)(this->y)*(ll)(rhs.x);
        return temp;
    }
    
    //computes the square of the distance between this and A
    ll dist2(Point A)
    {
        int x2=A.x,y2=A.y;
        ll dx=x2-x;
        ll dy=y2-y;
        return dx*dx+dy*dy;
    }
    
    //computes the distance between this and A
    double dist(Point A)
    {
        ll d2=dist2(A);
        return sqrt(d2);
    }
    
    static double dist(Point A,Point B)
    {
        return A.dist(B);
    }
    
    static double dist(pair<double,double> A,pair<double,double> B)
    {
        double dx=A.first-B.first;
        double dy=A.second-B.second;
        return sqrt(dx*dx+dy*dy);
    }
    
    static ll dist2(Point A,Point B)
    {
        return A.dist2(B);
    }
    
    //computes the dot product AB.BC
    static ll dot(Point A,Point B,Point C)
    {
        return (B-A)*(C-B);
    }
    
    //computes the cross product ABxAC
    static ll cross(Point A,Point B,Point C)
    {
        return (B-A)^(C-A);
    }
    
    //computes the distance between AB and C
    static double linePointDist(Point A, Point B, Point C,bool isSegment)
    {
        double distt=(double)(cross(A,B,C))/(A.dist(B));
        if (isSegment)
        {
            if ((B-A)*(C-B)>0) return dist(B,C);
            if ((A-B)*(C-A)>0) return dist(A,C);
        }
        return abs(distt);
    }
    
    static double slope(Point &A,Point &B)
    {
        int dx=A.x-B.x;
        int dy=A.y-B.y;
        if (dx==0) return 1e9;
        return (double)dy/(double)dx;
    }
    
    static ll polygonArea2(vector<Point> &arr)   //returns the double of the polygon area
    {
        int n=sz(arr),i;
        ll ans=0;
        FOR(i,2,n)
        {
            ans+=((arr[i-1]-arr[0])^(arr[i]-arr[0]));
        }
        return ans;
    }
    
    void print()
    {
        printf("%d %d\n",x,y);
    }
};

double eps=1e-9;

bool eq(double a,double b)
{
    if (a>b-eps&&a<b+eps) return true;
    return false;
}

class Line
{
    //ax+by+c=0
public:
    int a;
    int b;
    int c;
    Line()
    {
        
    }
    Line(int aa,int bb,int cc)
    {
        a=aa;b=bb;c=cc;
    }
    Line(Point A,Point B)
    {
        int x1=A.x,y1=A.y,x2=B.x,y2=B.y;
        ll a_l=y2-y1;
        ll b_l=x1-x2;
//        ll c_l=(ll)y1*(x1-x1)-x1*(y2-y1);
        ll c_l=-(a_l*x1+b_l*y1);
        ll g=__gcd(a_l,__gcd(b_l,c_l));
        a_l/=g;b_l/=g;c_l/=g;
        a=(int)a_l;b=(int)b_l;c=(int)c_l;
    }
    
    int calc(Point P)
    {
        return a*P.x+b*P.y+c;
    }
    
    double calc(pair<double,double> P)
    {
        return a*P.first+b*P.second+c;
    }
    
    pair<double,double> lineIntersection(Line l1)
    {
        Line l2=*this;
        int a1=l1.a,b1=l1.b,c1=-l1.c;
        int a2=l2.a,b2=l2.b,c2=-l2.c;
        double det=(a1*b2-a2*b1);
        if (det==0)
        {
            //lines are parallel
        }
        else
        {
            double x=b2*c1-b1*c2;
            double y=a1*c2-a2*c1;
            x/=det;y/=det;
            return mp(x,y);
        }
    }
    
    static pair<double,double> lineIntersection(Line l1,Line l2)
    {
        int a1=l1.a,b1=l1.b,c1=-l1.c;
        int a2=l2.a,b2=l2.b,c2=-l2.c;
        double det=(a1*b2-a2*b1);
        if (det==0)
        {
            //lines are parallel
        }
        else
        {
            double x=b2*c1-b1*c2;
            double y=a1*c2-a2*c1;
            x/=det;y/=det;
            return mp(x,y);
        }
    }
    
    static pair<double,double> lineIntersection(double a1,double b1,double c1,double a2,double b2,double c2)
    {
        c1*=-1;c2*=-1;
        double det=(a1*b2-a2*b1);
        if (det==0)
        {
            //lines are parallel
        }
        else
        {
            double x=b2*c1-b1*c2;
            double y=a1*c2-a2*c1;
            x/=det;y/=det;
            return mp(x,y);
        }
    }
};

bool isin(Point P,pair<double,double> c,double r)
{
    double x1=P.x,y1=P.y;
    double x2=c.first,y2=c.second;
    double dx=x1-x2,dy=y1-y2;
    double d=sqrt(dx*dx+dy*dy);
    if (d<r+eps) return true;
    return false;
}


class Surveyor {
	public:
	int area(string direction, vector <int> length)
	{
		int i,j;
                vector<Point> arr;
                arr.pb(Point(0,0));
                int n=sz(direction);
                int x=0,y=0;
                FOR(i,0,n)
                {
                    char c=direction[i];
                    int len=length[i];
                    if (c=='N') y-=len;
                    else if (c=='S') y+=len;
                    else if (c=='E') x+=len;
                    else if (c=='W') x-=len;
                    arr.pb(Point(x,y));
                }
                int ans=(int)Point::polygonArea2(arr);
                ans=abs(ans);
                return ans/2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "NWWSE"; int Arr1[] = {10,3,7,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; verify_case(0, Arg2, area(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "NESWNWSW"; int Arr1[] = {20,200,30,100,20,30,10,70}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4700; verify_case(1, Arg2, area(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Surveyor ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
