#include <cstdlib>
#include <ctime>
#include <iostream>
#include "base.h"


int main(int argc, char *argv[])
{

    srand(time(0));

    Base ema(600,400,"emanuel",4);

    while(ema.gameLooop()){

    }

    return EXIT_SUCCESS;
}
