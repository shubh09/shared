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

int str2int(string s)
{
    istringstream buffer(s);
    int ans;
    buffer>>ans;
    return ans;
}

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
    
    static ll polygonArea2(vector<Point> arr)   //returns the double of the polygon area
    {
        int n=sz(arr),i;
        ll ans=0;
        FOR(i,2,n)
        {
            ans+=((arr[i-1]-arr[0])*(arr[i]-arr[0]));
        }
        return ans;
    }
    
    void print()
    {
        printf("%d %d\n",x,y);
    }
};

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
};

double eps=1e-9;

bool eq(double a,double b)
{
    if (a>b-eps&&a<b+eps) return true;
    return false;
}

bool betw(int a,int b,int c)
{
    if (a<=b&&b<=c) return true;
    return false;
}

bool betw(double a,double b,double c)
{
    if (a<=b&&b<=c) return true;
    return false;
}


class PointInPolygon {
	public:
	string testPoint(vector <string> vertices, int x, int y)
	{
		int i,j;
                vector<Point> vp;
                int n=sz(vertices);
                FOR(i,0,n)
                {
                    vstr v=split(vertices[i],' ');
                    Point temp(str2int(v[0]),str2int(v[1]));
                    vp.pb(temp);
                }
                string b="BOUNDARY",intr="INTERIOR",extr="EXTERIOR";
                Point inf(10000,100000);
                Point test(x,y);
                Line L(test,inf);
                
                FOR(i,0,n)
                {
                    Point p1=vp[i],p2=vp[(i+1)%n];
                    Line l1(p1,p2);
                    if (l1.calc(test)==0&&betw(min(p1.x,p2.x),x,max(p1.x,p2.x))&&betw(min(p1.y,p2.y),y,max(p1.y,p2.y)))
                    {
                        p1.print();p2.print();
                        return b;
                    }
                }
                printf("Line L: %d %d %d\n",L.a,L.b,L.c);
                int numIntersection=0;
                FOR(i,0,n)
                {
                    Point p1=vp[i],p2=vp[(i+1)%n];
                    Line l1(p1,p2);
                    pair<double,double> pd=l1.lineIntersection(L);
//                    printf("Line %d: %d %d %d\n",i,l1.a,l1.b,l1.c);
//                    printf("Intersection point: (%f,%f)\n",pd.first,pd.second);
                    if (betw((double)min(p1.x,p2.x),pd.first,(double)max(p1.x,p2.x))&&betw((double)min(p1.y,p2.y),pd.second,(double)max(p1.y,p2.y))
                            &&betw((double)x,pd.first,10000.0)&&betw((double)y,pd.second,10000.0))
                    {
//                        p1.print();
//                        printf("%f %f\n",pd.first,pd.second);
//                        p2.print();
                        numIntersection++;
                    }
                }
                p(numIntersection);
                if (numIntersection%2==1) return intr;
                else return extr;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 5; string Arg3 = "INTERIOR"; verify_case(0, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; string Arg3 = "EXTERIOR"; verify_case(1, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 10; string Arg3 = "BOUNDARY"; verify_case(2, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"-100 -90", "-100 100","100 100", "100 -100",
 "-120 -100","-120 100","-130 100","-130 -110",
 "110 -110", "110 110", "-110 110","-110 -90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "EXTERIOR"; verify_case(3, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0 0","0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 500; string Arg3 = "INTERIOR"; verify_case(4, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 322; int Arg2 = 333; string Arg3 = "EXTERIOR"; verify_case(5, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"500 0","500 100","400 100","400 200","300 200",
 "300 300","200 300","200 400","100 400","100 500",
 "0 500","0 400","-100 400","-100 300","-200 300",
  "-200 200","-300 200","-300 100","-400 100","-400 0",
  "-500 0","-500 -100","-400 -100","-400 -200","-300 -200",
  "-300 -300","-200 -300","-200 -400","-100 -400","-100 -500",
  "0 -500","0 -400","100 -400","100 -300","200 -300",
  "200 -200","300 -200","300 -100","400 -100","400 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; int Arg2 = 200; string Arg3 = "INTERIOR"; verify_case(6, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {"1 0","2 0","2 1","3 1","3 0","4 0","4 -1","5 -1","5 0",
 "6 0","6 2","0 2","0 3","-1 3","-1 4","0 4","0 6","1 6",
 "1 7","0 7","0 8","-2 8","-2 2","-8 2","-8 0","-7 0",
 "-7 -1","-6 -1","-6 0","-4 0","-4 1","-3 1","-3 0",
 "-2 0","-2 -6","0 -6","0 -5","1 -5","1 -4","0 -4",
 "0 -3","-1 -3","-1 -2","0 -2","0 -1","1 -1"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "INTERIOR"; verify_case(7, Arg3, testPoint(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	PointInPolygon ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
