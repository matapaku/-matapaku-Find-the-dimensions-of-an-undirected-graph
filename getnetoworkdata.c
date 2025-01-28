#include <stdio.h>
#include <stdlib.h>
#include "network.h"
#include "degreedistribution.h"


Network *getnetworkdata(Network *network){
    int vertex_num=0,data_num=0;
    char buf[MAXSIZE];

    FILE *fp = fopen("sample.net","r");
    if(fp == NULL){
        printf("ファイルをオーペンできませんでした\n");
        exit(1);
    }
    else{
        printf("ファイルをオープンしました。\n");
    }

    while(fgets(buf,MAXSIZE,fp) != NULL){
        //コメント文
        if((buf[0] == '/' && buf[1] == '/') || buf[0] == '#') {
            printf("%s",buf);
        }
        else{
            if(vertex_num == 0){
                vertex_num = sizeof(buf) /sizeof(char);
            }

            else if(vertex_num != sizeof(buf) /sizeof(char)){
                fprintf(stderr,"データが一致しません\n");
                exit(1);
            }
            data_num++;
        }
    }

    //データの書き換え
    network = malloc(sizeof(Network));
    network->num = data_num;
    network->a = malloc(sizeof(int *)*data_num);
    for(int i=0;i<data_num;i++){
        network->a[i] = malloc(sizeof(int *)*vertex_num);
    }

    rewind(fp);
    int index = 0;

    while(fgets(buf,MAXSIZE,fp) != NULL){
        if((buf[0] == '/' && buf[1] == '/') || buf[0] == '#'){
            for(int i=0;i<vertex_num;i++){
                network->a[index][i] = (int)buf[i] - '0';
            }
            index++;
        }
    }

    //ファイルを閉じる
    fclose(fp);


    return network;
}