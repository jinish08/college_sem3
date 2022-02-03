import java.util.*;

interface Arr {
    int[] arr = new int[5];
    float[] val = new float[3];
}

class Average extends Thread implements Arr {
    public void run() {
        float sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        val[0] = sum / arr.length;
    }
}

class Maximum extends Thread implements Arr {
    public void run() {
        val[1] = arr[0];
        for (int i = 0; i < arr.length; i++) {
            val[1] = Math.max(val[1], arr[i]);
        }
    }
}

class Minimum extends Thread implements Arr {
    public void run() {
        val[2] = arr[0];
        for (int i = 0; i < arr.length; i++) {
            val[2] = Math.min(val[2], arr[i]);
        }
    }
}

class StatsMT implements Arr {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter value: ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        Average a = new Average();
        Maximum m = new Maximum();
        Minimum mi = new Minimum();
        a.start();
        a.join();
        m.start();
        m.join();
        mi.start();
        mi.join();
        System.out.println("Avg: " + val[0]);
        System.out.println("Max: " + val[1]);
        System.out.println("Min: " + val[2]);
        sc.close();
    }
}
