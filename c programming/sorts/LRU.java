import java.util.*;

class LRU {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of frames:");
        int n = sc.nextInt();
        System.out.println("Enter number of requests:");
        int req = sc.nextInt();
        int page[] = new int[req];
        int frame[] = new int[req];

        System.out.println("Enter requests:");
        for (int i = 0; i < req; i++)
            page[i] = sc.nextInt();

        for (int i = 0; i < n; i++)
            frame[i] = -1;

        int flag = 0, hit = 0, miss = 0;
        int age[] = new int[n];
        for (int i = 0; i < n; i++)
            age[i] = 0;

        for (int j = 0, i = 0; j < n && i < req; j = j % n, i++) {
            flag = 0;

            for (int k = 0; k < n; k++) {
                if (frame[k] == page[i]) {
                    flag = 1;
                    hit++;
                    age[k] = 0;
                }
            }
            if (flag == 0)
                if (frame[j] == -1) {

                    frame[j] = page[i];
                    miss++;
                    j++;
                } else

                {
                    int max = age[0], loc = 0;
                    miss++;

                    for (int b = 0; b < n; b++)
                        if (age[b] > max) {
                            max = age[b];
                            loc = b;
                        }
                    frame[loc] = page[i];
                    age[loc] = 0;
                    j++;
                }
            for (int a = 0; a < n; a++) {
                if (frame[a] == -1)
                    age[a] = 0;
                else
                    age[a]++;
            }

        }
        System.out.println("Hit=" + hit + " miss=" + miss);
        System.out.println("Miss/Hit = " + (float) miss / (float) hit);
    }
}
