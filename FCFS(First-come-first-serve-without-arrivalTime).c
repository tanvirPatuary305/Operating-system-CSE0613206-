#include<stdio.h>

int main(){
    printf("\"FCFS without arrival time\"\n\n");
    printf("Enter the number of process, how many times you want=\n");

    int n;
    scanf("%d",&n);
    printf("Enter the burst time\n");
    int BT[n];
    for(int i=0;i<n;i++){
        scanf("%d",&BT[i]);
    }
    int CT[n];
    CT[0]=BT[0];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            CT[j]=CT[i]+BT[j];
        }
    }
    int WT[n];
    for(int i=0;i<n;i++){
        WT[i]=CT[i]-BT[i];
    }

    for(int i=0;i<n;i++){
        printf("Process%d\tBT=%d\tWT=%d\tCT=%d\tTAT=%d\t\n",i+1,BT[i],WT[i],CT[i],CT[i]);

    }
    float sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        sum1=sum1+WT[i];
        sum2=sum2+CT[i];

    }
    float avg1=sum1/n;
    float avg2=sum2/n;
    printf("Average Waiting time=%.2f\n",avg1);
    printf("Average Completion time=%.2f\n",avg2);
    printf("Average Turned around time=%.2f\n",avg2);


    return 0;


}

