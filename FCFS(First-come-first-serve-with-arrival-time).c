#include <stdio.h>

int main() {
    printf("\"FCFS with arrival time\"\n\n");
    printf("Enter the number of process , how many times you want =\n");
    int n;
    scanf("%d",&n);
    printf("Enter the  Arrival time\n");
    int AT[n];
    for(int i=0;i<n;i++){
        scanf("%d",&AT[i]);
    }
    printf("Enter the Burst time\n");
    int BT[n];
    for(int i=0;i<n;i++){
        scanf("%d",&BT[i]);
    }
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(AT[i]>AT[j]){
               temp=AT[i];
               AT[i]=AT[j];
               temp=AT[j];

               temp=BT[i];
               BT[i]=BT[j];
               temp=BT[j];

            }
        }
    }

    int CT[n],TAT[n],WT[n];

    CT[0]=AT[0]+BT[0];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        CT[j]=CT[i]+BT[j];
        break;

        }
    }
    for(int i=0;i<n;i++){
        TAT[i]=CT[i]-AT[i];

    }
    for(int i=0;i<4;i++){
         WT[i]=TAT[i]-BT[i];

    }


     for(int i=0;i<n;i++){
      printf("Process %d\tAT=%d\tBT=%d\tWT=%d\tCT=%d\tTAT=%d\n",i+1,AT[i],BT[i],WT[i],CT[i],TAT[i]) ;
    }
    printf("\n");
    float sum1=0,sum2=0,sum3=0;
    for(int i=0;i<n;i++){
        sum1=sum1+WT[i];
        sum2=sum2+CT[i];
        sum3=sum3+TAT[i];

    }
    float avg1=sum1/n;
    float avg2=sum2/n;
    float avg3=sum3/n;
    printf("Avarage Wating time=%.2fms\n",avg1);
    printf("Avarage Complition time=%.2fms\n",avg2);
    printf("Avarage Tarned around time=%.2fms\n",avg3);

    return 0;
}


