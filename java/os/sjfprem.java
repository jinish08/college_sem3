import java.util.*;

class sjfprem {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter no of process:");
        int n = sc.nextInt();
        int pno[] = new int[n];
        int at[] = new int[n];
        int bt[] = new int[n];
        int ct[] = new int[n];
        int ta[] = new int[n];
        int wt[] = new int[n];
        int f[] = new int[n];
        int ogbt[] = new int[n];
        int pt = 0, tot = 0;

        for (int i = 0; i < n; i++) {
            System.out.println("enter process " + (i + 1) + " arrival time:");
            at[i] = sc.nextInt();
            System.out.println("enter process " + (i + 1) + " brust time:");
            bt[i] = sc.nextInt();
            ogbt[i] = bt[i];
            pno[i] = i + 1;
            f[i] = 0;
        }

        while (tot != n) {
            int c = n, min = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {

                if ((at[i] <= pt) && (f[i] == 0) && (bt[i] < min)) {
                    min = bt[i];
                    c = i;
                }
            }

            if (c == n)
                pt++;
            else {
                bt[c]--;
                pt++;
                if (bt[c] == 0) {
                    ct[c] = pt;
                    f[c] = 1;
                    tot++;
                }
            }
        }
        float avgwt = 0, avgta = 0;
        for (int i = 0; i < n; i++) {
            ta[i] = ct[i] - at[i];
            wt[i] = ta[i] - ogbt[i];
            avgwt += wt[i];
            avgta += ta[i];
        }
        System.out.println("\npno  arrival burst  complete waiting turnaround");
        for (int i = 0; i < n; i++) {
            System.out.println(pno[i] + "\t" + at[i] + "\t" + ogbt[i] + "\t" + ct[i] + "\t" + wt[i] + "\t" + ta[i]);
        }
        System.out.println("\naverage wt is " + (float) (avgwt / n));
        System.out.println("average tat is " + (float) (avgta / n));
        sc.close();
    }
}