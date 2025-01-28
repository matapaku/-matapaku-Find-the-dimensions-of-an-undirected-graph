#include <stdio.h>
#include <stdlib.h>
#include "option.h"
#include "network.h"

extern struct Network *network;
extern struct Option *option;


void get_registors(){
    network = (Network *)malloc(sizeof(struct Network));
    if(network == NULL){
        fprintf(stderr,"networkエラー");
        exit(1);
    }

    option = (Option *)malloc(sizeof(struct Option));
    if(option == NULL){
        fprintf(stderr,"optionエラー");
        free(network);
        exit(1);
    }

    //メモリの初期化
    network->num = 0;
    network->averagedegree = 0.0;
    network->maxdegree = 0;
    network->mindegree = 0;

    network->a = NULL;
    network->freq = NULL;
    option->day = NULL;

    return;

}