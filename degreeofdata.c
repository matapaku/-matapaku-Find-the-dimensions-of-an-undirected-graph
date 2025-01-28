#include <stdlib.h>
#include "option.h"
#include "network.h"

Network *degreeofdata(Network *network,Option *option){
    int *degree[network->num];
    int maxdegree = 0,mindegree = network->num+1,average_degree = 0;
    int veertex_num = 0;

    for(int i=0;i<network->num;i++){
        *degree[i] = 0;
        for(int j=0;j<network->num;j++){
            if(network->a[i][j] == 1){
                degree[i]++;
            }
        }
        average_degree += *degree[i];
    }

    //最大,最小
    for(int i=0;i<network->num;i++){
        if(maxdegree < *degree[i]){
            maxdegree = *degree[i];
        }
        if(mindegree > *degree[i]){
            mindegree = *degree[i];
        }
    }

    //平均次数
    average_degree /= network->num;

    //更新
    network->maxdegree = maxdegree;
    network->mindegree = mindegree;
    network->averagedegree = average_degree;



    //次数分布
    network->freq = malloc(sizeof(int*) * maxdegree);
    for(int i=0;i<network->num;i++){
        network->freq = 0;
    }

    for(int i=0;i<network->num;i++){
        network->freq[*degree[i]]++;
    }


    return network;
}