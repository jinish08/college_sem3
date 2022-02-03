import java.util.*;

public class Solution {
    static char encrypt(char c, int shift) {
        if (!Character.isAlphabetic(c))
            return c;
        char base = 'A';
        if (c >= 'a')
            base = 'a';
        return (char) (((c - base + shift) % 26) + base);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string : ");
        String str = sc.nextLine();
        int shift = 0;
        try {
            System.out.print("Enter the shifts : ");
            shift = sc.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Invalid input of shifts");
        }
        sc.close();

        char sarr[] = str.toCharArray();
        for (int i = 0; i < sarr.length; i++) {
            sarr[i] = encrypt(sarr[i], shift);
        }
        System.out.println("Encrypted string : " + new String(sarr));
    }
}