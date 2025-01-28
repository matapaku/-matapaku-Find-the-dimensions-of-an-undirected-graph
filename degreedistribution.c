#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#include "degreedistribution.h"
#include "network.h"
#include "option.h"

//データ用構造体とオプション用構造体
struct Network *network;
struct Option *option;

int main(int argc,char *argv[]){
    //領域の確保
    get_registors();
    //オプションを読み取る
    option = getoption(argc,argv,option);
    //入力データを読みとる
    network = getnetworkdata(network);
    //次数を求める
    network = degreeofdata(network,option);
    //結果を出力する
    printout(argc,argv,network,option);
    //領域を開放
    free_registors();

    return 0;
}

