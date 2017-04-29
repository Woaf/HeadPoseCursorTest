#include <iostream>
#include <fstream>
#include <sstream>

#include "tests.h"

using namespace std;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}