import java.util.*;

class Main {
    public static void Main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = 0, n, rem;
        System.out.println("Please enter a no: ");
        n = sc.nextInt();
        while (n != 0) {
            rem = n % 10;
            count++;
            n = n / 10;
        }
        System.out.println("The no of digits are: " + count);
    }
}
