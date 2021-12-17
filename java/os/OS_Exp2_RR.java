import java.util.*;

public class OS_Exp2_RR {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        System.out.println("Enter the number of processes");
        int num = sc.nextInt();
        System.out.println("Enter the Time Quantum");
        int Q = sc.nextInt();
        int Bt[] = new int[num];
        int At[] = new int[num];
        int ID[] = new int[num];
        int tempBt; // to store 1 input in 2 arrays
        int immutBt[] = new int[num]; // To store value for calculation
        int Complete[] = new int[num];
        for (int i = 0; i < num; i++) {
            At[i] = 0;
            System.out.println("Enter the Burst time of process no. " + (i + 1));
            tempBt = sc.nextInt();
            Bt[i] = tempBt;
            immutBt[i] = tempBt;
            ID[i] = i + 1;
        }

        System.out.println("ID\tArrival Time\tBurstTime\tStatus");
        for (int i = 0; i < num; i++) {
            System.out.println(ID[i] + "\t\t" + At[i] + "\t\t" + Bt[i] + "\t\t" + Complete[i]);
        }

        int[] Et = new int[num];
        int totalTime = 0;
        int flag;

        while (true) {
            flag = 0;
            for (int i = 0; i < num; i++) {

                if (Bt[i] == 0) {
                    continue;
                } else if (Bt[i] > Q) {
                    Bt[i] -= Q;
                    totalTime += Q;
                    flag = 1;
                } else if (Bt[i] <= Q) {
                    totalTime += Bt[i];
                    Et[i] = totalTime;
                    Bt[i] = 0;
                    flag = 1;
                }
            }
            if (flag == 0) {
                break;
            }
        }

        int[] TAT = new int[num];
        for (int i = 0; i < num; i++) {
            TAT[i] = Et[i] - At[i];
        }
        int[] WT = new int[num];
        for (int i = 0; i < num; i++) {
            WT[i] = TAT[i] - immutBt[i];
        }
        float avgTAT = 0;
        float avgWT = 0;
        for (int i = 0; i < num; i++) {
            avgTAT += TAT[i];
        }
        avgTAT = avgTAT / num;
        for (int i = 0; i < num; i++) {
            avgWT += WT[i];
        }
        avgWT = avgWT / num;

        System.out.println("ID\tET\tAT\tBT");
        for (int i = 0; i < num; i++) {
            System.out.print(ID[i] + "\t" + Et[i] + "\t" + At[i] + "\t" + immutBt[i]);
            System.out.println();
        }

        System.out.println("ID\tTAT\tWT");
        for (int i = 0; i < num; i++) {
            System.out.print(ID[i] + "\t" + TAT[i] + "\t" + WT[i]);
            System.out.println();
        }

        System.out.println("AVG TAT : " + avgTAT);
        System.out.println("AVG WT : " + avgWT);
        sc.close();
    }
}