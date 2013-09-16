import java.io.*;
import java.util.HashSet;

public class p2_SquareDigits
{
	private static int sum(int n)
	{
		int s=0;
		while (n>0)
		{
			int t=n%10;
			s+=(t*t);
			n/=10;
		}
		return s;
	}

	private static boolean check(int x,int n)		//checks whether T(x) contains n
	{
		HashSet<Integer> set=new HashSet<Integer>(); 
		int t=sum(x);
		while(true)
		{
			if (t==n) return true;
			else if (set.contains(t)) return false;
			set.add(t);
			t=sum(t);
		}
	}

	public static int smallestResult(int n)
	{
		int x=0;
		while (true)
		{
			if (check(x,n)) return x;
			else x++;
		}
	}

	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.valueOf(br.readLine()).intValue();
		for (int i=1;i<=t;i++)
		{
			int n=Integer.valueOf(br.readLine()).intValue();
			System.out.println(smallestResult(n));
		}
	}
}
