#include<stdio.h>

struct process{
    int id,at,bt,ct,tat,wt,stat;
}p[20];

void main(){
    int i,n;
    float ttat=0,twt=0,atat,awt;
    int completed=0,current=0;

    printf("ENter the limit:");
    scanf("%d",&n);
    printf("Enter the details\n");
    for(i=0;i<n;i++){
        printf("Enter ID,AT,BT");
        scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
        p[i].stat=0;
    }

    while(completed!=n){
        int index=-1,min=32765;
        for(i=0;i<n;i++){
            if(p[i].at<=current && p[i].stat==0 && p[i].bt<min){
                min=p[i].bt;
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
            ttat+=p[index].tat;
            twt+=p[index].wt;

        }
    }
    atat=ttat/n;
    awt=twt/n;

    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }
    
    printf("AVg TAT:%f",atat);
    printf("Avg WT:%f",awt);
}
