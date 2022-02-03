import java.util.*;

class FifoPageRep {

    public static void main(String args[]) {

        int n, frame;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of Frames :");
        frame = sc.nextInt();
        int fifo[] = new int[frame];
        System.out.println("Enter the number of Requests :");
        n = sc.nextInt();
        int req[] = new int[n];
        System.out.println("Enter Request:");
        for (int i = 0; i < n; i++)
            req[i] = sc.nextInt();

        int Hit = 0;
        int miss = 0;
        int j = 0;
        boolean flag;
        for (int i = 0; i < n; i++) {
            flag = false;

            for (int k = 0; k < frame; k++)
                if (fifo[k] == req[i]) {
                    flag = true;
                    Hit++;
                }
            if (flag == false) {
                fifo[j] = req[i];
                j++;
                if (j >= frame)
                    j = 0;
                miss++;
            }

        }
        System.out.println("Hits:" + Hit + "\nMisses:" + miss);
        System.out.println("Miss/Hit = " + (float) miss / (float) Hit);
    }
}
