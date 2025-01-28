#ifndef NETWORK_H
#define NETWORK_H

typedef struct Network {
    int num;
    double averagedegree; //出力れいを参考にdouble型にする
    int maxdegree;
    int mindegree;
    int **a;
    int *freq;
} Network;


#endif // NETROWK_H