import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int marks;
        DataInputStream d = new DataInputStream(System.in);
        System.out.println("Enter the marks:");
        marks = Integer.parseInt(d.readLine());

        try {
            if (marks < 0 || marks > 100) {
                throw new MarksOutOfBoundsException();
            }
        } catch (Exception e) {
            marks = 0;
            System.out.println(e);
        } finally {
            System.out.println("****************");
        }
        System.out.println("Marks = " + marks);
    }
}

class MarksOutOfBoundsException extends Exception {

}
