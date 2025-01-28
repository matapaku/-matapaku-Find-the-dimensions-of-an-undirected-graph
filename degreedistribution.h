#ifndef DEGREEDISTRIBUTION_H
#define DEGREEDISTRIBUTION_H

#define MAXSIZE 1000

#include "network.h"
#include "option.h"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>


// 関数プロトタイプ宣言

void get_registors(void);

Option *getoption(int argc,char *argv[],Option *option);

Network *getnetworkdata(Network *network);

Network *degreeofdata(Network *network,Option *option);

void printout(int argc,char *argv[],Network *network,Option *option);

void free_registors(void);

#endif // DEGREEDISTRIBUTION_H