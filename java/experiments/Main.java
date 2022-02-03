import java.lang.*;
import java.util.*;

class Prime implements Runnable {
    long j, c;

    Prime() {
        c = 0;
    }

    public void run() {
        System.out.println("Thread Prime started.");
        long startTime = System.currentTimeMillis();
        int i = 0;
        while (c < 20) {
            i++;
            for (j = 2; j <= i; j++) {
                if (i % j == 0)
                    break;
            }
            if (j == i) {
                c++;
                System.out.println(c + "th" + " Prime no: = " + i);
            }
        }
        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        System.out.println("Prime No. Tread too " + elapsedTime + " milliseconds");
    }
}

class Fib implements Runnable {
    long a, b, c, n;

    Fib() {
        a = c = n = 0;
        b = 1;
    }

    public void run() {
        System.out.println("Thread Fib started.");
        long startTime = System.currentTimeMillis();
        while (n++ < 15) {
            System.out.println(n + "th" + " Fib no: = " + a);
            c = a + b;
            a = b;
            b = c;
        }
        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        System.out.println("Fibonacci Thread took " + elapsedTime + " milliseconds");
    }
}

class Main {

    public static void main(String[] args) {
        Prime p = new Prime();
        Fib f = new Fib();
        Thread fib = new Thread(f, "fibonacci");
        Thread prime = new Thread(p, "prime");
        fib.start();
        prime.start();
    }
}