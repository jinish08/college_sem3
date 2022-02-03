interface member {
    void callback();
}

class store {
    member m[] = new member[100];
    int count = 0;

    void register(member m) {
        this.m[count++] = m;
    }

    void inviteSale() {
        for (int i = 0; i < count; i++) {
            m[i].callback();
        }
    }
}

class customer implements member {
    String name;

    customer(String n) {
        name = n;
    }

    public void callback() {
        System.out.println("Ok,I will visit " + name);
    }

}

public class SCinterface {

    public static void main(String[] args) {
        store s = new store();
        customer c1 = new customer("John");
        customer c2 = new customer("Smith");
        s.register(c1);
        s.register(c2);
        s.inviteSale();

    }
}