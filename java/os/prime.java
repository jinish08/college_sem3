class prime extends Thread {
    static int n;

    public void run() {
        System.out.print("Prime numbers:\n2 ");
        for (int i = 3; i <= n; i++) {
            boolean flag = false;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                System.out.print(i + " ");
        }
    }

    public static void main(String args[]) {
        n = Integer.parseInt(args[0]);
        prime p = new prime();
        Thread t = new Thread(p);
        t.start();
    }
}
