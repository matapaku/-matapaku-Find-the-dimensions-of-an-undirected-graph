#include <stdlib.h>
#include "option.h"
#include "network.h"

extern struct Option *option;
extern struct Network *network;


void free_registors(){

    free(network);

    free(option);
}