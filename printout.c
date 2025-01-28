#include<stdio.h>
#include "network.h"
#include "option.h"

void printout(int argc,char *argv[],Network *network,Option *option){
    printf("# Average degree: %.2f\n",network->averagedegree);
    printf("# Max degree: %d Max degree: %d\n",network->maxdegree,network->mindegree);

    if(argc > 1){//正規化する
        for(int i=0;i<network->maxdegree;i++){
            printf("%d %f\n",i,network->freq[i] / (double)network->num);
        }
    }
    else{//正規化しない
        for(int i=0;i<network->maxdegree;i++){
            printf("%d %d\n",i,network->freq[i]);
        }
    }
    
    return;
}
