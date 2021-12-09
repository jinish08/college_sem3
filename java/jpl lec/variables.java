import java.util.*;

class variables {
    float r,a;  //instance var/object variables
    // static float r,a;  static/class variables
    public static void main(String arg[]){
        variables c = new variables();
        c.circle();

        variables c1 = new variables();
        c1.circle();

        System.out.println(c.r);
        System.out.println(c1.r);
    }

    void circle(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the r: ");
        r = sc.nextFloat();
        a = 3.14f*r*r;
        System.out.println("Area is :"+a);
    }
}
