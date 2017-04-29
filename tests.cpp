#include "tests.h"

using namespace cv;
using namespace std;

TEST(testMaximumOfTwoValues, firstGreater)
{
    double maximum = returnMaximumOfTwoValues(5.24, 3.71);
    EXPECT_TRUE(abs(maximum - 5.24) < 0.00005);
}

TEST(testMaximumOfTwoValues, secondGreater)
{
    double maximum = returnMaximumOfTwoValues(5.24, 7.63);
    EXPECT_TRUE(abs(maximum - 7.63) < 0.00005);
}

TEST(testMaximumOfTwoValues, equalNumbers)
{
    double maximum = returnMaximumOfTwoValues(3, 3);
    EXPECT_TRUE(abs(maximum - 3) < 0.00005);

}

TEST(testMaximumOfTwoValues, negativeNumbers)
{
    double maximum = returnMaximumOfTwoValues(-3.19, -0.37);
    EXPECT_TRUE(abs(maximum - -0.37) < 0.00005);
}

TEST(testMaximumOfTwoValues, oneNegativeOnePositive)
{
    double maximum = returnMaximumOfTwoValues(-19.42, 2.5);
    EXPECT_TRUE(abs(maximum - 2.5) < 0.00005);
}

TEST(testMaximumOfTwoValues, onePositiveOneNegative)
{
    double maximum = returnMaximumOfTwoValues(19.42, -2.5);
    EXPECT_TRUE(abs(maximum - 19.42) < 0.00005);
}

TEST(testUnitRemovedPoints, origoPoints_1)
{
    Point3d p = returnUnitRemovedPoints(Point3d(0, 0, 0), Point3d(0, 0, 0), 1, 1);
    EXPECT_TRUE(abs(p.x - 0) < 0.00005 && abs(p.y - 0) < 0.00005 && abs(p.z - 1) < 0.00005);
}

TEST(testUnitRemovedPoints, origoPoints_2)
{
    Point3d p = returnUnitRemovedPoints(Point3d(0, 0, 0), Point3d(0, 0, 0), 5, 5);
    EXPECT_TRUE(abs(p.x - 0) < 0.00005 && abs(p.y - 0) < 0.00005 && abs(p.z - 1) < 0.00005);
}

TEST(testUnitRemovedPoints, aroundOrigo_1)
{
    Point3d p = returnUnitRemovedPoints(Point3d(10, 10, 0), Point3d(0, 0, 0), 1, 1);
    EXPECT_TRUE(abs(p.x - 10) < 0.00005 && abs(p.y - 10) < 0.00005 && abs(p.z - 1) < 0.00005);
}

TEST(testUnitRemovedPoints, aroundOrigo_2)
{
    Point3d p = returnUnitRemovedPoints(Point3d(-10, 10, 0), Point3d(0, 0, 0), 1, 1);
    EXPECT_TRUE(abs(p.x - -10) < 0.00005 && abs(p.y - 10) < 0.00005 && abs(p.z - 1) < 0.00005);
}

TEST(testUnitRemovedPoints, aroundOrigo_3)
{
    Point3d p = returnUnitRemovedPoints(Point3d(10, 10, 0), Point3d(0, 0, 0), 5, 2);
    EXPECT_TRUE(abs(p.x - 2) < 0.00005 && abs(p.y - 5) < 0.00005 && abs(p.z - 1) < 0.00005);
}

TEST(testThreeDimensionalDistance1, origoPoint)
{
    double d = returnThreeDimensionalDistance(Point3d(0, 0, 0));
    EXPECT_TRUE(abs(d - 0) < 0.00005);
}

TEST(testThreeDimensionalDistance1, firstQuartile)
{
    double d = returnThreeDimensionalDistance(Point3d(10, 5, 3));
    EXPECT_TRUE(abs(d - sqrt(10*10+5*5+3*3)) < 0.00005);
}

TEST(testThreeDimensionalDistance1, secondQuartile)
{
    double d = returnThreeDimensionalDistance(Point3d(-4, 34, -1));
    EXPECT_TRUE(abs(d - sqrt(4*4+34*34+1*1)) < 0.00005);
}

TEST(testThreeDimensionalDistance1, thirdQuartile)
{
    double d = returnThreeDimensionalDistance(Point3d(-4, -19, 1.22));
    EXPECT_TRUE(abs(d - sqrt(4 * 4 + 19 * 19 + 1.22 * 1.22)) < 0.00005);
}

TEST(testThreeDimensionalDistance1, fourthQuartile)
{
    double d = returnThreeDimensionalDistance(Point3d(5.25, -6.11, -4.31));
    EXPECT_TRUE(abs(d - sqrt(5.25 * 5.25 + 6.11 * 6.11 + 4.31 * 4.31)) < 0.00005);
}

TEST(testThreeDimensionalDistance2, firstAndSecondQuartile)
{
    double d = returnThreeDimensionalDistance(Point3d(26, 42, 13), Point3d(-21, 19, 42/15));
    EXPECT_TRUE(abs(d - sqrt(pow(26+21, 2) + pow(42-19, 2) + pow(13 - 42/15, 2))) < 0.00005);
}

TEST(testThreeDimensionalDistance2, thirdAndFourthQuartile)
{
    double d = returnThreeDimensionalDistance(Point3d(-63, -37, -128), Point3d(89, -61, 0));
    EXPECT_TRUE(abs(d - sqrt(pow(-63 - 89, 2) + pow(-37 - -61, 2) + pow(-128 - 0, 2))) < 0.00005);
}


TEST(testCalculateCentroid, aroundOrigo1)
{
    Point3d p = returnCentroidOfThreePoints(1, Point3d(0, 1, 0), Point3d(-1 / sqrt(2), -1 / sqrt(2), 0), Point3d(1 / sqrt(2), -1 / sqrt(2), 0));
    EXPECT_EQ(0, p.y);
    EXPECT_EQ(0, p.z);
    EXPECT_TRUE(abs(p.x - 0) < 0.00005 && abs(p.y - 0) < 0.00005 && abs(p.z - 0) < 0.00005);
}

TEST(testCalculateCentroid, aroundOrigo2)
{
    Point3d p = returnCentroidOfThreePoints(2, Point3d(0, 1, 0), Point3d(-sqrt(3) / 2, -1 / 2.0, 0), Point3d(sqrt(3) / 2, -1/2.0, 0));
    EXPECT_EQ(0, p.z);
    EXPECT_TRUE(abs(p.x - 0) < 0.00005 && abs(p.y - 0) < 0.00005 && abs(p.z - 0) < 0.00005);
}

TEST(testCalculateCentroid, aroundOrigo3)
{
    Point3d p = returnCentroidOfThreePoints(3, Point3d(0, -1, 0), Point3d(sqrt(3) / 2, 1 / 2.0, 0), Point3d(-sqrt(3) / 2, 1 / 2.0, 0));
    EXPECT_TRUE(abs(p.x - 0) < 0.00005 && abs(p.y - 0) < 0.00005 && abs(p.z - 0) < 0.00005);
}

TEST(testCalculateCentroid, aroundOrigo4)
{
    Point3d p = returnCentroidOfThreePoints(3, Point3d(0, -1, 2), Point3d(sqrt(3) / 2, 1 / 2.0, 2), Point3d(-sqrt(3) / 2, 1 / 2.0, 2));
    EXPECT_TRUE(abs(p.x - 0) < 0.00005 && abs(p.y - 0) < 0.00005 && abs(p.z - 2) < 0.00005);
}

TEST(testMatrixOfTwoVectors, zeros)
{
    Mat ret;
    returnMatrixOfTwoVectors(ret, Point3d(0, 0, 0), Point3d(21.3, -4.68, 37.6));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_DOUBLE_EQ(0, ret.at<double>(i, j));
        }
    }
}

TEST(testMatrixOfTwoVectors, ones)
{
    Mat ret;
    returnMatrixOfTwoVectors(ret, Point3d(1, 1, 1), Point3d(1, 1, 1));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_DOUBLE_EQ(1, ret.at<double>(i, j));
        }
    }
}

TEST(testMatrixOfTwoVectors, sqaured)
{
    Mat ret;
    returnMatrixOfTwoVectors(ret, Point3d(1, 2, 3), Point3d(1, 2, 3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_DOUBLE_EQ((i+1)*(j+1), ret.at<double>(i, j));
        }
    }
}

TEST(testDrawablePoints, window)
{
    dlib::image_window win;
    win.set_background_color(50, 50, 50);
    win.set_size(640, 480);
    Mat bg;
    bg = imread("images/bg.jpg");

    Point3d right(20, -20, -5);
    Point3d left(-20, -20, -5);
    Point3d middle(0, 20, 5);
    Point a1 = returnDrawablePoint(right, 1, 320, 240);
    Point a2 = returnDrawablePoint(left, 1, 320, 240);
    Point a3 = returnDrawablePoint(middle, 1, 320, 240);

    Scalar blueish = Scalar(255, 100, 100);
    Scalar greenish = Scalar(100, 255, 100);
    Scalar redish = Scalar(100, 100, 255);
    circle(bg, a1, 10, blueish, 3);
    circle(bg, a2, 10, greenish, 3);
    circle(bg, a3, 10, redish, 3);

    dlib::cv_image<dlib::bgr_pixel> info(bg);

    win.set_image(info);
    win.close_window();
    EXPECT_TRUE(win.is_closed());
}

TEST(testFacePose, first)
{

    dlib::image_window win;
    win.set_background_color(50, 50, 50);
    win.set_size(640, 480);
    Mat bg;
    bg = imread("images/bg.jpg");

    Point3d righteye(50+320, -50+240, 0);
    Point3d lefteye(-50+320, -50+240, 0);
    Point3d nose(0+320, 20+240, 0);

    righteye.x -= 320;
    righteye.y -= 240;
    righteye.z = 1;
    lefteye.x -= 320;
    lefteye.y -= 240;
    lefteye.z = 1;
    nose.x -= 320;
    nose.y -= 240;
    nose.z = 1;

    righteye /= returnThreeDimensionalDistance(righteye);
    lefteye /= returnThreeDimensionalDistance(lefteye);
    nose /= returnThreeDimensionalDistance(nose);

    double cos_ab = abs(righteye.dot(lefteye));
    double deg_ab = acos(cos_ab)*180 / dlib::pi;
    double cos_ac = abs(righteye.dot(nose));
    double deg_ac = acos(cos_ac) * 180 / dlib::pi;
    double cos_bc = abs(lefteye.dot(nose));
    double deg_bc = acos(cos_bc) * 180 / dlib::pi;

    EXPECT_TRUE(abs(180 - (deg_ab + deg_bc + deg_ac)) < 1);

    dlib::cv_image<dlib::bgr_pixel> info(bg);
    win.set_image(info);
    win.close_window();
    EXPECT_TRUE(win.is_closed());

}
/*
void test_sumOfAnglesBetweenThreePoints()
{
    Point3d p1(5, 70, -100);
    Point3d p2(9, -16, 0);
    Point3d p3(-4, -10, 5);
    cout << returnSumOfAnglesBetweenThreePoints(p1, p2, p3) << endl;
    cout << returnSumOfAnglesBetweenThreePoints(p1, p3, p2) << endl;
    cout << returnSumOfAnglesBetweenThreePoints(p2, p1, p3) << endl;
    cout << returnSumOfAnglesBetweenThreePoints(p2, p3, p1) << endl;
    cout << returnSumOfAnglesBetweenThreePoints(p3, p1, p2) << endl;
    cout << returnSumOfAnglesBetweenThreePoints(p3, p2, p1) << endl;
}

void test_anglesBetweenThreePoints()
{
    Point3d p1(5, 70, -100);
    Point3d p2(9, -16, 0);
    Point3d p3(-4, -10, 5);
    double rac[3];
    returnAnglesBetweenThreePoints(rac, p1, p2, p3);
    for (int i = 0; i < 3; i++)
    {
        cout << rac[i] << endl;
    }
}
*/

TEST(testRotateTwoSetOfPoints, alongYAxis)
{
    Point3d r1(0, 1, 0);
    Point3d r2(-sqrt(3)/2, -1/2.0, 0);
    Point3d r3(sqrt(3)/2, -1/2.0, 0);

    Point3d p1(0, 1, 0);
    Point3d p2(0, -1/2.0, sqrt(3)/2);
    Point3d p3(0, -1/2.0, -sqrt(3)/2);

    Point3d rp = returnCentroidOfThreePoints(3, r1, r2, r3);
    Point3d cp = returnCentroidOfThreePoints(3, p1, p2, p3);

    EXPECT_TRUE(Point3d(0, 0, 0) == rp);
    EXPECT_TRUE(Point3d(0, 0, 0) == cp);

    p1 -= cp;
    p2 -= cp;
    p3 -= cp;
    r1 -= rp;
    r2 -= rp;
    r3 -= rp;

    Mat_<double> HMatrix = Mat_<double>::ones(3, 3);
    Mat_<double> HMat2 = Mat_<double>::ones(3, 3);
    Mat_<double> HMat3 = Mat_<double>::ones(3, 3);
    returnMatrixOfTwoVectors(HMatrix, r1, p1);
    returnMatrixOfTwoVectors(HMat2, r2, p2);
    returnMatrixOfTwoVectors(HMat3, r3, p3);
    HMatrix = HMatrix + HMat2 + HMat3;

    SVD USV = SVD(HMatrix);

    Mat_<double> matrixOf_Rotation = USV.vt.t() * USV.u.t();

    EXPECT_DOUBLE_EQ(-1, matrixOf_Rotation.at<double>(2, 0));
    EXPECT_DOUBLE_EQ(1, matrixOf_Rotation.at<double>(1, 1));
    EXPECT_DOUBLE_EQ(1, matrixOf_Rotation.at<double>(0, 2));

    double rotationRadiansAroundXAxis = atan2(matrixOf_Rotation.at<double>(2, 1), matrixOf_Rotation.at<double>(2, 2));
    double rotationRadiansAroundYAxis = atan2(-matrixOf_Rotation.at<double>(2, 0), sqrt(pow(matrixOf_Rotation.at<double>(2, 1), 2) + pow(matrixOf_Rotation.at<double>(2, 2), 2)));
    double rotationRadiansAroundZAxis = atan2(matrixOf_Rotation.at<double>(1, 0), matrixOf_Rotation.at<double>(0, 0));

    EXPECT_DOUBLE_EQ(0, rotationRadiansAroundXAxis * 180 / dlib::pi);
    EXPECT_DOUBLE_EQ(90, rotationRadiansAroundYAxis * 180 / dlib::pi);
    EXPECT_DOUBLE_EQ(0, rotationRadiansAroundZAxis * 180 / dlib::pi);
}

TEST(testReadFromFile, faceMesh)
{
    ifstream input("pose_mean_shape");
    ASSERT_TRUE(input.is_open());
    Point3d points[49];
    EXPECT_DOUBLE_EQ(49 * sizeof(Point3d), sizeof(points));
    returnMeshPointsFromAFile(points);
    input.close();
    ASSERT_FALSE(input.is_open());
}

TEST(testWriteMatrixToAFile, defaultMatrix)
{
    Mat_<double> test_matrix = Mat_<double>::ones(3,3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_DOUBLE_EQ(1, test_matrix.at<double>(i, j));
        }
    }
    writeCameraMatrixToAFile(test_matrix);

    ifstream in;
    string line;
    in.open("cameraMatrixFile");
    ASSERT_TRUE(in.is_open());
    while (getline(in, line))
    {
        const char *temp = line.c_str();
        EXPECT_STREQ("1 1 1 ", temp);
    }
    in.close();
    ASSERT_FALSE(in.is_open());
}

TEST(testWriteErrorFile, errorFile)
{
    exception e = exception("This is an error message.");
    writeErrorFile(e);

    ifstream err;
    err.open("C:/Users/balin/Desktop/error_message.txt");
    ASSERT_TRUE(err.is_open());

    string firstLine;
    getline(err, firstLine);
    const char *firstCopy = firstLine.c_str();
    EXPECT_STRCASEEQ("EXCEPTION THROWN: ", firstCopy);

    err.close();
    ASSERT_FALSE(err.is_open());
}
