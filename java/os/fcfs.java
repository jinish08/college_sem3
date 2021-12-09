import java.util.*;

class fcfs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sumWt = 0, sumBt = 0, i, j, temp;
        System.out.print("Enter the no. of process:");
        int n = sc.nextInt();
        int at[] = new int[n];
        int bt[] = new int[n];
        int wt[] = new int[n];
        for (i = 0; i < n; i++) {
            System.out.println("Enter process arrival time: " + (i + 1));
            at[i] = sc.nextInt();
            System.out.println("Enter process burst time: " + (i + 1));
            bt[i] = sc.nextInt();
            sumBt += bt[i];
        }
        System.out.println("Processes with arrival time are: ");
        System.out.println("Process     Arrival Time    Burst Time");
        for (i = 0; i < n; i++) {

            System.out.println((i + 1) + "\t\t" + at[i] + "\t\t" + bt[i]);

        }
        int count;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (at[i] < at[i + 1]) {
                    temp = at[j];
                    at[j] = at[j + 1];
                    at[j + 1] = temp;

                    temp = bt[j];
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;
                }
            }
        }
        wt[0] = 0; // for fcfs
        count = at[0];
        System.out.println("The Waiting time for each process is :");
        for (i = 0; i < n; i++) {
            if (i == 0) {
                System.out.print(wt[0] + " ");
                continue;
            }
            count += bt[i - 1];
            wt[i] = count - at[i];
            sumWt += wt[i];
            System.out.print(wt[i] + " ");
        }
        System.out.println("\nThe average waiting time is :" + (sumWt / n));
        System.out.println("The Turnaround time for each process is :");
        for (i = 0; i < n; i++) {
            System.out.print(bt[i] + " ");
        }
        System.out.println("\nThe average turnaround time is :" + (sumBt / n));

    }
}