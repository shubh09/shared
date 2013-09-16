import java.io.*;
import java.util.*;

public class p1_HowEasy
{
	public static boolean isWord(String a)
	{
		int len=a.length();
		if (len==0) return false;
		char[] ca=new char[len];
		ca=a.toCharArray();
		int ascii;
		int i;
		for (i=0;i<len-1;i++)
		{
			ascii=ca[i];
			if (!((ascii>=65 && ascii<=90)||(ascii>=97 && ascii<=122))) return false;
		}
		ascii=ca[i];
		if (ca[i]!='.'&&  !((ascii>=65 && ascii<=90)||(ascii>=97 && ascii<=122))) return false;
		return true;
	}
	
	public static int pointVal(String a)
	{
		StringTokenizer st=new StringTokenizer(a);
		int count=0;
		int sum=0;
		while (st.hasMoreTokens())
		{
			String temp=st.nextToken();
			if (isWord(temp))
			{
				int len=temp.length();
				int add;
				if (temp.charAt(len-1)=='.') add=len-1;
				else add=len;
				sum+=add;
				count++;
			}
		}
		int val=sum/count;
		System.out.println(val);
		if (val<=3) return 250;
		else if (val<=5) return 500;
		else return 1000;
	}

	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.valueOf(br.readLine()).intValue();
		for (int i=1;i<=t;i++)
		{
			String a=br.readLine();
			System.out.println(pointVal(a));
		}
	}
		
}
