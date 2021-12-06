import java.util.*;

class instanceV {
    float r,a;
    public static void main(String arg[]){
        instanceV c = new instanceV();
        c.circle();
        instanceV c1 = new instanceV();
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
