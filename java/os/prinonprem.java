import java.util.*;

class prinonprem {
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
    // int f[] = new int[n];
    int pri[] = new int[n];
    int temp;
    float avgwt = 0, avgta = 0;

    for (int i = 0; i < n; i++) {
      System.out.println("enter process " + (i + 1) + " arrival time:");
      at[i] = sc.nextInt();
      System.out.println("enter process " + (i + 1) + " brust time:");
      bt[i] = sc.nextInt();
      System.out.println("enter process " + (i + 1) + " priority:");
      pri[i] = sc.nextInt();
      pno[i] = i + 1;
      // f[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - (i + 1); j++) {
        if (at[j] > at[j + 1]) {
          temp = at[j];
          at[j] = at[j + 1];
          at[j + 1] = temp;
          temp = bt[j];
          bt[j] = bt[j + 1];
          bt[j + 1] = temp;
          temp = pno[j];
          pno[j] = pno[j + 1];
          pno[j + 1] = temp;
          temp = pri[j];
          pri[j] = pri[j + 1];
          pri[j + 1] = temp;
        }
        if (at[j] == at[j + 1]) {
          if (pri[j] > pri[j + 1]) {
            // swapping arrival time
            temp = at[j];
            at[j] = at[j + 1];
            at[j + 1] = temp;
            // swapping burst time
            temp = bt[j];
            bt[j] = bt[j + 1];
            bt[j + 1] = temp;

            // swapping priority
            temp = pri[j];
            pri[j] = pri[j + 1];
            pri[j + 1] = temp;

            // swapping process identity
            temp = pno[j];
            pno[j] = pno[j + 1];
            pno[j + 1] = temp;

          } else if (pri[j] == pri[j + 1]) {
            if (pno[j] > pno[j + 1]) {
              // swapping arrival time
              temp = at[j];
              at[j] = at[j + 1];
              at[j + 1] = temp;
              // swapping burst time
              temp = bt[j];
              bt[j] = bt[j + 1];
              bt[j + 1] = temp;

              // swapping priority
              temp = pri[j];
              pri[j] = pri[j + 1];
              pri[j + 1] = temp;

              // swapping process identity
              temp = pno[j];
              pno[j] = pno[j + 1];
              pno[j + 1] = temp;

            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        ct[i] = at[i] + bt[i];
      } else {
        if (at[i] > ct[i - 1]) {
          ct[i] = at[i] + bt[i];
        } else
          ct[i] = ct[i - 1] + bt[i];
      }
      ta[i] = ct[i] - at[i]; // turnaround time= completion time- arrival time
      wt[i] = ta[i] - bt[i]; // waiting time= turnaround time- burst time
      avgwt += wt[i]; // total waiting time
      avgta += ta[i]; // total turnaround time
    }
    // float avgwt=0, avgta=0;
    System.out.println("\npno  arrival burst  complete waiting turnaround Priority");
    for (int i = 0; i < n; i++) {
      System.out
          .println(pno[i] + "\t" + at[i] + "\t" + bt[i] + "\t" + ct[i] + "\t" + wt[i] + "\t" + ta[i] + "\t" + pri[i]);
    }
    System.out.println(avgwt + " " + avgta);
    System.out.println("\naverage wt is " + (float) (avgwt / n));
    System.out.println("average tat is " + (float) (avgta / n));
    sc.close();
  }
}