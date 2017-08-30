import java.util.Scanner;
import java.math.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for (int i=1;i<=T;i++)
        {
            BigDecimal x1=new BigDecimal(sc.next());
            BigDecimal y1=new BigDecimal(sc.next());
            BigDecimal x2=new BigDecimal(sc.next());
            BigDecimal y2=new BigDecimal(sc.next());
            BigDecimal x3=new BigDecimal(sc.next());
            BigDecimal y3=new BigDecimal(sc.next());
            BigDecimal x=new BigDecimal(sc.next());
            BigDecimal y=new BigDecimal(sc.next());



        BigDecimal A1=x1.subtract(x2);
        BigDecimal B1=y1.subtract(y2);
        BigDecimal t1=x1.multiply(x1);
        BigDecimal t2=x2.multiply(x2);
        BigDecimal t3=y1.multiply(y1);
        BigDecimal t4=y2.multiply(y2);
        BigDecimal C1=t1.subtract(t2).add(t3).subtract(t4);
        C1=C1.divide(BigDecimal.valueOf(2.0));
        BigDecimal A2=x3.subtract(x2);
        BigDecimal B2=y3.subtract(y2);
        t1=x3.multiply(x3);
        t2=x2.multiply(x2);
        t3=y3.multiply(y3);
        t4=y2.multiply(y2);
        BigDecimal C2=t1.subtract(t2).add(t3).subtract(t4);
        C2=C2.divide(BigDecimal.valueOf(2.0));
        t1=A1.multiply(B2);
        t2=A2.multiply(B1);
        BigDecimal tmp=t1.subtract(t2);

        BigDecimal a=C1.multiply(B2).subtract(C2.multiply(B1)).divide(tmp);
        BigDecimal b=A1.multiply(C2).subtract(A2.multiply(C1)).divide(tmp);


        BigDecimal now1=x1.subtract(a);
        BigDecimal now2=y1.subtract(b);

        BigDecimal r1=now1.multiply(now1);
        BigDecimal r2=now2.multiply(now2);

        BigDecimal r=r1.add(r2);

        BigDecimal now3=x.subtract(a);
        BigDecimal now4=y.subtract(b);

        BigDecimal r3=now3.multiply(now3);
        BigDecimal r4=now4.multiply(now4);

        BigDecimal rr=r3.add(r4);

        BigDecimal tt=r.subtract(rr);
        int tete=tt.compareTo(BigDecimal.ZERO);
        if (tete==-1) System.out.println("Accepted");
        else System.out.println("Rejected");
    }
        }
    }