import java.util.Scanner;

public class semaphores {
  public static int mutex = 1, full = 0, empty = 3, x = 0;

  public static void main(String[] args) {
    int n;
    Scanner sc = new Scanner(System.in);
    System.out.print("\n1.Producer\n2.Consumer\n3.Exit");
    while (true) {
      System.out.print("\nEnter your choice:");
      n = sc.nextInt();
      switch (n) {
        case 1:
          if (mutex == 1 && empty != 0)
            producer();
          else
            System.out.print("Buffer is full!!");
          break;
        case 2:
          if (mutex == 1 && full != 0)
            consumer();
          else
            System.out.print("Buffer is empty!!");
          break;
        case 3:
          System.exit(0);
          break;
      }
    }
  }

  public static int wait(int s) {
    return --s;
  }

  public static int signal(int s) {
    return ++s;
  }

  public static void producer() {
    mutex = wait(mutex); // mutex = 0
    full = signal(full); // full ++
    empty = wait(empty); // empty --
    x++;
    System.out.print("\nProducer produces the item " + x);
    mutex = signal(mutex); // mutex = 1
  }

  public static void consumer() {
    mutex = wait(mutex); // mutex = 0
    full = wait(full); // full--
    empty = signal(empty); // empty++
    System.out.print("\nConsumer consumes item " + x);
    x--;
    mutex = signal(mutex); // mutex = 1
  }

}
