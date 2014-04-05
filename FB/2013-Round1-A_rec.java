/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package javaapplication1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author shubham
 */



public class JavaApplication1 {

    
    static BigInteger epow(int a,int p)
    {
            if (p==0) return BigInteger.ONE;
            BigInteger t=epow(a,p/2);
            t=t.multiply(t);
            if (p%2==1) t=t.multiply(new BigInteger(Integer.toString(a)));
            return t;
    }
    
    public static void solve(String str,BigInteger N,int l,String ans)
    {
//        cout<<N<<' '<<l<<' '<<ans<<endl;
//        System.out.println(N+" "+l+" "+ans);
        int n=str.length();
        BigInteger num=epow(n,l);
//        System.out.println("num="+num+" n="+n);
        if (l==0) return;
        if (N.compareTo(num)>0) solve(str,N.subtract(num),l+1,ans);
        else
        {
            num=num.divide(new BigInteger(Integer.toString(n)));
            BigInteger bi=(N.subtract(BigInteger.ONE)).divide(num);
            int d=bi.intValue();
//            int d=(int)((N-1)/(num));
            char c=str.charAt(d);
//            System.out.println(d + " " + str.charAt(d));
            System.out.print(str.charAt(d));
            ans=ans+(str.charAt(d));
            BigInteger newn=N.subtract(num.multiply(new BigInteger(Integer.toString(d))));
            solve(str,newn,l-1,ans);
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String line=br.readLine();
        int T=Integer.parseInt(line);
        int i;
        for(i=0;i<T;i++)
        {
            String str=br.readLine();
            String[] v=str.split(" ");
            str=v[0];
            BigInteger N = new BigInteger(v[1]);
            String ans="";
            System.out.print("Case #"+(i+1)+": ");
            solve(str,N,1,ans);
            System.out.println();
        }
    }
}
