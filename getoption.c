#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "option.h"

Option *getoption(int argc, char *argv[],Option *option){
    int i;
    for(i=1;i<argc;i++){
        //dのオプション
        if(strcmp(argv[i],"-d") == 0 && i+1<argc){
            break;
        }
        
        else{
            fprintf(stderr,"不明なオプションです.\n");
            exit(1);
        }
    }

    option->day = "ver.1.0.0";

    return option;
}