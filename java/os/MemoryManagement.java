import java.util.*;

class MemoryManagement {
    static void firstFit(int blockSize[], int m, int processSize[], int n) {

        int allocation[] = new int[n];

        for (int i = 0; i < n; i++)
            allocation[i] = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {

                    allocation[i] = j;

                    blockSize[j] -= processSize[i];

                    break;
                }
            }
        }

        System.out.println("\nProcess No.\tProcess Size\tBlock no.");
        for (int i = 0; i < n; i++) {
            System.out.print(" " + (i + 1) + "\t\t" +
                    processSize[i] + "\t\t");
            if (allocation[i] != -1)
                System.out.print(allocation[i] + 1);
            else
                System.out.print("Not Allocated");
            System.out.println();
        }
    }

    static void bestFit(int blockSize[], int m, int processSize[], int n) {

        int allocation[] = new int[n];

        for (int i = 0; i < n; i++)
            allocation[i] = -1;

        for (int i = 0; i < n; i++) {

            int bestIdx = -1;
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    if (bestIdx == -1)
                        bestIdx = j;
                    else if (blockSize[bestIdx] > blockSize[j])
                        bestIdx = j;
                }
            }

            if (bestIdx != -1) {
                allocation[i] = bestIdx;

                blockSize[bestIdx] -= processSize[i];
            }
        }

        System.out.println("\nProcess No.\tProcess Size\tBlock no.");
        for (int i = 0; i < n; i++) {

            System.out.print(" " + (i + 1) + "\t\t" + processSize[i] + "\t\t");
            if (allocation[i] != -1)
                System.out.print(allocation[i] + 1);
            else
                System.out.print("Not Allocated");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int blockSize[] = new int[10];
        int processSize[] = new int[10];
        System.out.print("Enter the number of blocks and number of processes: ");
        int m = sc.nextInt();
        int n = sc.nextInt();

        System.out.print("Enter the sizes of blocks: ");
        for (int i = 0; i < m; i++)
            blockSize[i] = sc.nextInt();

        System.out.print("Enter the process sizes: ");
        for (int i = 0; i < n; i++)
            processSize[i] = sc.nextInt();

        System.out.print("Enter the 1 for First fit and 2 for Best fit: ");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                firstFit(blockSize, m, processSize, n);
                break;
            case 2:
                bestFit(blockSize, m, processSize, n);
                break;
            default:
                System.out.println("Incorrect Input");
        }
        sc.close();
    }
}
