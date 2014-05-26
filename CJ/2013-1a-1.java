
import java.math.BigInteger;
import java.util.Scanner;



public class JavaApplication1
{
    public static BigInteger sqrt_ceil(BigInteger b)
    {
        BigInteger lo=BigInteger.ZERO;
        BigInteger hi=b;
        BigInteger TWO=BigInteger.ONE.add(BigInteger.ONE);
        while (lo.compareTo(hi)<0)
        {
            BigInteger sum=lo.add(hi);
            BigInteger mid=sum.divide(TWO);
            BigInteger sqr=mid.multiply(mid);
            int cmp=sqr.compareTo(b);
            if (cmp==0) return mid;
            else if (cmp<0) lo=mid.add(BigInteger.ONE);
            else hi=mid;
        }
        return hi;
    }
    
    public static BigInteger sqrt_floor(BigInteger b)   //CHECK (lo,hi)=(2,3)
    {
        BigInteger lo=BigInteger.ZERO;
        BigInteger hi=b;
        BigInteger TWO=BigInteger.ONE.add(BigInteger.ONE);
        while (lo.compareTo(hi)<0)
        {
            BigInteger sum=lo.add(hi);
            BigInteger mid=sum.divide(TWO);
            BigInteger sqr=mid.multiply(mid);
            int cmp=sqr.compareTo(b);
            if (cmp==0) return mid;
            else if (cmp<0) lo=mid;
            else hi=mid.subtract(BigInteger.ONE);
        }
        return hi;
    }

    public static BigInteger calc(BigInteger r,BigInteger k)
    {
        BigInteger TWO=BigInteger.ONE.add(BigInteger.ONE);
        BigInteger r2=r.multiply(TWO);
        BigInteger k2=k.multiply(TWO);
        BigInteger res=k;
        res=res.multiply(k2.add(r2).subtract(BigInteger.ONE));
        return res;
    }
    
    public static BigInteger solve(BigInteger r,BigInteger t)
    {
        BigInteger lo=BigInteger.ZERO;
        BigInteger hi=t;
        BigInteger TWO=BigInteger.ONE.add(BigInteger.ONE);
        while (lo.compareTo(hi.subtract(BigInteger.ONE))<0)
        {
//            System.out.println(lo+" "+hi);
            BigInteger sum=lo.add(hi);
            BigInteger mid=sum.divide(TWO);
            BigInteger res=calc(r,mid);
            int cmp=res.compareTo(t);
            if (cmp==0) return mid;
            else if (cmp<0) lo=mid;
            else hi=mid.subtract(BigInteger.ONE);
        }
        BigInteger res=calc(r,hi);
        if (res.compareTo(t)<=0) return hi;
        return lo;
    }
    
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int t=0;t<T;t++)
        {
            String s1=sc.next();
            String s2=sc.next();
            BigInteger b1=new BigInteger(s1);
            BigInteger b2=new BigInteger(s2);
            System.out.println("Case #"+(t+1)+": "+solve(b1,b2));
        }
    }
}
