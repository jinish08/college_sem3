import java.io.*;

class Employee {
    int Emp_id;
    String Emp_name;
    int Emp_salary;

    Employee(int empid, String empname, int empsalary) {
        Emp_id = empid;
        Emp_name = empname;
        Emp_salary = empsalary;
    }

    void display() {
        System.out.println("ID: " + this.Emp_id + " Name: " + this.Emp_name + " Salary:" + this.Emp_salary);
    }

    public static void main(String args[]) throws IOException {
        Employee e[] = new Employee[10];
        for (int i = 0; i < 10; i++) {
            System.out.println("Enter the ID, Name and Salary of Employee(" + (i + 1) + ")");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int Emp_id = Integer.parseInt(br.readLine());
            String Emp_name = br.readLine();
            int Emp_salary = Integer.parseInt(br.readLine());
            e[i] = new Employee(Emp_id, Emp_name, Emp_salary);
        }
        System.out.println("Employee Details: \n	");
        for (int i = 0; i < 10; i++) {
            e[i].display();
        }

    }
}