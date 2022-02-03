import java.util.*;

class FibonacciMT {
    static int i, n, a[];

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n: ");
        n = sc.nextInt();
        sc.close();
        a = new int[n];
        Fibo f = new Fibo();
        Thread t = new Thread(f);
        t.start();
        System.out.print("Thread fibo initial status: " + t.isAlive());
        while (t.isAlive())
            Thread.yield();

        System.out.print("\nFibonacci series: ");
        for (i = 0; i < n; i++)
            System.out.print(a[i] + " ");

        System.out.print("\n\nThread fibo final status: " + t.isAlive());
    }
}

class Fibo extends FibonacciMT implements Runnable {
    public void run() {
        a[0] = 0;
        a[1] = 1;
        for (i = 2; i < n; i++) {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
}
