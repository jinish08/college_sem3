class Five extends Thread {
    public void run() {
        long startTime = System.currentTimeMillis();
        for (int i = 1; i <= 10; i++) {
            System.out.println("     " + 5 + " x " + i + " = " + 5 * i);
        }
        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        System.out.println("Five table took " + elapsedTime + " milliseconds");
    }
}

class Seven extends Thread {
    public void run() {
        long startTime = System.currentTimeMillis();
        for (int i = 1; i <= 10; i++) {
            System.out.println("     " + 7 + " x " + i + " = " + 7 * i);
        }
        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        System.out.println("Seven table took " + elapsedTime + " milliseconds");
    }
}

class Thirteen extends Thread {
    long startTime = System.currentTimeMillis();

    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println("     " + 13 + " x " + i + " = " + 13 * i);
        }
        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        System.out.println("Thirteen table took " + elapsedTime + " milliseconds");
    }
}

public class TablesMT {
    public static void main(String[] args) throws Exception {
        Five f = new Five();
        Seven s = new Seven();
        Thirteen t = new Thirteen();
        System.out.println("-----Table of 5-----    ");
        f.start();
        f.join();
        System.out.println();
        System.out.println("-----Table of 7-----    ");
        s.start();
        s.join();
        System.out.println();
        System.out.println("-----Table of 13-----   ");
        t.start();
    }
}
