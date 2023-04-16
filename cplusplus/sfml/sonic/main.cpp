#include "base.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>

int main(int argc, char *argv[])
{
    std::srand(time(0));

    Base ema(600, 400, "emanuel");

    while(ema.gameLoop()){

    }

    return EXIT_SUCCESS;
}
