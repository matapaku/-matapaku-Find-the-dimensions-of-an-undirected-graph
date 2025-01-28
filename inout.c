#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

#include "degreedistribution.h" 
#include "network.h" 
#include "option.h" 

/* ネットワークデータ用構造体とオプション用構造体 */ 
struct Network *network; 
struct Option *option;


int main(int argc,char *argv[]) { 
    /* まず，*network と *option の領域を確保する．*/ 
    get_registors(); 

    /* オプションを読みとる．*/
    option=getoption(argc,argv,option);

    /* ネットワークデータを読み込む．*/ 
    network=getnetworkdata(network); 

    /* ネットワークデータの次数・次数分布を計算する．*/ 
    network=degreeofdata(network,option); 

    /* 結果を出力する */ 
    printout(argc,argv,network,option); 
    
    /* get_registors() で確保した領域を解放する．*/ 
    free_registors();

    return(0); 
}