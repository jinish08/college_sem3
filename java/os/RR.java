import java.util.Scanner;
class RR
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    System.out.print("Enter number of process:");
    int n = sc.nextInt();
   
    int pno[] = new int[n];   // process ids
    int at[] = new int[n];     // arrival times
    int bt[] = new int[n];     // burst or execution times
    int ct[] = new int[n];     // completion times
    int ta[] = new int[n];     // turn around times
    int wt[] = new int[n];     // waiting times
    int rem_bt[] = new int[n];     // waiting times 
    int temp,flag=0,qt,t1=0,i;
    float avgwt=0,avgta=0;
    for(i = 0; i < n; i++)
    {
    System.out.println("enter process " + (i+1) + " arrival time: ");
    at[i] = sc.nextInt();
    System.out.println("enter process " + (i+1) + " brust time: ");
    bt[i] = sc.nextInt();
    pno[i] = i+1;
     rem_bt[i] = bt[i];
    }
    System.out.print("Enter quantum time = ");
    qt = sc.nextInt();
    while(n!=flag)
    {
      for (i=0,flag=0;i<n;i++)
      {
        temp = qt;
        if(rem_bt[i] == 0)
        {
          flag++;
          continue;
        }
        if(rem_bt[i]>qt)
          rem_bt[i]= rem_bt[i] - qt;
        else
          if(rem_bt[i]>=0)
          {
            temp = rem_bt[i];
            rem_bt[i] = 0;
          }
          t1 += temp;
          ta[i] = t1;
      }
    
    }
    
    System.out.println("\npno  arrival  brust  complete TAT waiting");
    for(i=0;i<n;i++)
        {
            wt[i]=ta[i]-bt[i];
            ct[i]= ta[i]+ at[i];
            avgwt=avgwt+wt[i];
            avgta=avgta+ta[i];
            
            System.out.println(pno[i] + "  \t " + at[i] + "\t" + bt[i] + "\t" + ct[i] + "\t" + ta[i] + "\t"  + wt[i] ) ;
        }
        
        System.out.println("\nAverage waiting Time = "+avgwt/n);
        System.out.println("Average turnaround time = "+avgta/n);
  }
}
