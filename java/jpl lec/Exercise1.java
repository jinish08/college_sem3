import java.util.*;

interface Function {
    public String evaluate(String s);
}

class Reverse implements Function {
    public String evaluate(String s) {
        char ch[] = s.toCharArray();
        String rev = "";
        for (int i = ch.length - 1; i >= 0; i--) {
            rev += ch[i];
        }
        return rev;
    }
}

public class Exercise1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // System.in is a standard input stream.
        System.out.print("Enter a string: ");
        String str = sc.nextLine(); // reads string.

        Function func = new Reverse();

        String ans = func.evaluate(str);
        System.out.println(ans);

    }
}