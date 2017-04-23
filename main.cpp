#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

#include "tests.h"

using namespace std;

int main(int argc, char **argv)
{
    test_maximumOfTwoValues();
    test_unitRemovedPoints();
    test_threeDimensionalDistance();
    test_calculateCentroid();
    test_matrixOfTwoVectors();
    test_drawablePoints();
    test_facePose();
    test_sumOfAnglesBetweenThreePoints();
    test_anglesBetweenThreePoints();
    test_rotateTwoSetOfPointsOnEachOther();
    test_meshPointsFromFile();
    test_cameraMatrixToAFile();
    char quit = 'n';
    while (quit != 'q')
    {
        cin >> quit;
    }
    return 0;
}