#include<stdio.h>

struct process{
    int id,at,bt,ct,tat,wt,stat;
}p[20];

void main(){
    int i=0,n;
    float tot_tat=0,tot_wt=0,awt,atat;
    int completed=0,current=0;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("Ente the details:");
    for(i=0;i<n;i++){
        printf("ID,AT,BT:");
            scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
            p[i].stat=0;
    }

    while(completed!=n){
        int index=-1,min=32765;
        for(i=0;i<n;i++){
            if(p[i].at<=current && p[i].stat==0 && p[i].at<min){
                min=p[i].at;
                index=i;
            }
        }
        if(index==-1){
            current++;
        }
        else{
            current+=p[index].bt;
            p[index].ct=current;
            completed++;
            p[index].stat=1;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;
            tot_tat+=p[index].tat;
            tot_wt+=p[index].wt;

        }
    }
    atat=tot_tat/n;
    awt=tot_wt/n;
    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        
    }
    printf("AVg TAT:%f",atat);
    printf("Avg WT:%f",awt);
}
