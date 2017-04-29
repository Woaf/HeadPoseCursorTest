#include "tests.h"

using namespace cv;
using namespace std;

TEST(firstGreater, testMaximumOfTwoValues)
{
    double maximum = returnMaximumOfTwoValues(5.24, 3.71);
    EXPECT_EQ(5.24, maximum);
}

void test_maximumOfTwoValues()
{
    cout << returnMaximumOfTwoValues(5.321, 5.987);
}

void test_unitRemovedPoints()
{
    cout << returnUnitRemovedPoints(Point3d(0, 0, 0), Point3d(1, 1, 1), 2, 2);
}

void test_threeDimensionalDistance()
{
    cout << "TESTS FOR CALCULATING DISTANCE OF POINTS FROM THE ORIGO" << endl;
    Point3d s0(0, 0, 0);
    Point3d s1(5, 0, 0);
    Point3d s2(0, 4, 0);
    Point3d s3(0, 0, 3);
    cout << "s0 sample\t\t" << s0 << endl;
    cout << "result\t\t\t" << returnThreeDimensionalDistance(s0) << endl;
    cout << "s1 sample\t\t" << s1 << endl;
    cout << "result\t\t\t" << returnThreeDimensionalDistance(s1) << endl;
    cout << "s2 sample\t\t" << s2 << endl;
    cout << "result\t\t\t" << returnThreeDimensionalDistance(s2) << endl;
    cout << "s3 sample\t\t" << s3 << endl;
    cout << "result\t\t\t" << returnThreeDimensionalDistance(s3) << endl;

    cout << endl << "TESTS FOR CALCUALTING DISTANCES BETWEEN TWO 3D POINTS" << endl;
    Point3d d01(5, 0, 5);
    Point3d d02(5, 0, 0);
    Point3d d11(1, 0, 0);
    Point3d d12(0, 1, 0);
    cout << "d01, d02 sample\t\t" << d01 << ", " << d02 << endl;
    cout << "result\t\t\t" << returnThreeDimensionalDistance(d01, d02) << endl;
    cout << "d11, d12 sample\t\t" << d11 << ", " << d12 << endl;
    cout << "result\t\t\t" << returnThreeDimensionalDistance(d11, d12) << endl;
}

void test_calculateCentroid()
{
    Point3d a1(-3, 0, 0);
    Point3d a2(7, 0, 0);
    Point3d a3(5, 0, 0);
    //az eredmenynek (3, 0, 0)-nak kell lennie
    cout << "CENTROID_1D: " << returnCentroidOfThreePoints(1, a1, a2, a3) << endl;

    a1 = Point3d(4, 2, 0);
    a2 = Point3d(8, 7, 0);
    a3 = Point3d(-1, -2, 0);
    //az eredmenynek (3.666, 2.333, 0)-nak kell lennie
    cout << "CENTROID_2D: " << returnCentroidOfThreePoints(2, a1, a2, a3) << endl;

    a1 = Point3d(0, 2.0, 0);
    a2 = Point3d(-sqrt(3), -1, 0);
    a3 = Point3d(sqrt(3), -1, 0);
    //az eredmenynek (0, 0, 0)-nak kell lennie
    cout << "CENTROID_3D: " << returnCentroidOfThreePoints(3, a1, a2, a3) << endl;
}

void test_matrixOfTwoVectors()
{
    Point3d first = Point3d(1, 2, 3);
    Point3d second = Point3d(1, 2, 3);

    Mat ret;
    returnMatrixOfTwoVectors(ret, first, second);

    cout << ret;
}

void test_drawablePoints()
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
    win.wait_until_closed();
}

void test_facePose()
{

    dlib::image_window win;
    win.set_background_color(50, 50, 50);
    win.set_size(640, 480);
    Mat bg;
    bg = imread("images/bg.jpg");
    //

    Point3d righteye(50+320, -50+240, 0);
    Point3d lefteye(-50+320, -50+240, 0);
    Point3d nose(0+320, 20+240, 0);
    cout << "AZ EREDETI PONTOK: " << endl;
    cout << righteye << endl << lefteye << endl << nose << endl << endl;

    righteye.x -= 320;
    righteye.y -= 240;
    righteye.z = 1;
    lefteye.x -= 320;
    lefteye.y -= 240;
    lefteye.z = 1;
    nose.x -= 320;
    nose.y -= 240;
    nose.z = 1;
    cout << "A TRANSZFORMALT PONTOK: " << endl;
    cout << righteye << endl << lefteye << endl << nose << endl << endl;

    righteye /= returnThreeDimensionalDistance(righteye);
    lefteye /= returnThreeDimensionalDistance(lefteye);
    nose /= returnThreeDimensionalDistance(nose);
    cout << "EGY SUGARU GOMBRE VETITETT PONTOK: " << endl;
    cout << righteye << endl << lefteye << endl << nose << endl << endl;

    double cos_ab = abs(righteye.dot(lefteye));
    double deg_ab = acos(cos_ab)*180 / dlib::pi;
    double cos_ac = abs(righteye.dot(nose));
    double deg_ac = acos(cos_ac) * 180 / dlib::pi;
    double cos_bc = abs(lefteye.dot(nose));
    double deg_bc = acos(cos_bc) * 180 / dlib::pi;

    cout << "AB: " << cos_ab << ", " << deg_ab << endl;
    cout << "AC: " << cos_ac << ", " << deg_ac << endl;
    cout << "BC: " << cos_bc << ", " << deg_bc << endl;
    cout << "sum: " << deg_ab + deg_ac + deg_bc << endl << endl;

    //
    dlib::cv_image<dlib::bgr_pixel> info(bg);
    win.set_image(info);
    win.wait_until_closed();

}

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

void test_rotateTwoSetOfPointsOnEachOther()
{
    Point3d r1(-10, -10, 2);
    Point3d r2(10, -10, 1.91);
    Point3d r3(0, 10, -2);

    Point3d p1(-50, -10, 70);
    Point3d p2(60, -10, 70);
    Point3d p3(-30, 30, 20);

    Point3d rp = returnCentroidOfThreePoints(3, r1, r2, r3);
    Point3d cp = returnCentroidOfThreePoints(3, p1, p2, p3);

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

    cout << matrixOf_Rotation << endl << endl;

    Point d1 = returnDrawablePoint(p1, 1, 320, 240);
    Point d2 = returnDrawablePoint(p2, 1, 320, 240);
    Point d3 = returnDrawablePoint(p3, 1, 320, 240);

    Mat_<double> q1 = matrixOf_Rotation * Mat_<double>(r1);
    Mat_<double> q2 = matrixOf_Rotation * Mat_<double>(r2);
    Mat_<double> q3 = matrixOf_Rotation * Mat_<double>(r3);

    Point s1 = Point(q1.at<double>(0, 0) + 320, q1.at<double>(1, 0) + 240);
    Point s2 = Point(q2.at<double>(0, 0) + 320, q2.at<double>(1, 0) + 240);
    Point s3 = Point(q3.at<double>(0, 0) + 320, q3.at<double>(1, 0) + 240);

    dlib::image_window win;
    win.set_background_color(50, 50, 50);
    win.set_size(640, 480);
    Mat bg;
    bg = imread("images/bg.jpg");

    Scalar blueish = Scalar(255, 100, 100);
    Scalar greenish = Scalar(100, 255, 100);
    Scalar redish = Scalar(100, 100, 255);
    circle(bg, d1, 10, blueish, 3);
    circle(bg, d2, 10, greenish, 3);
    circle(bg, d3, 10, redish, 3);
    circle(bg, s1, 5, blueish, 2);
    circle(bg, s2, 5, greenish, 2);
    circle(bg, s3, 5, redish, 2);

    dlib::cv_image<dlib::bgr_pixel> info(bg);

    win.set_image(info);
    win.wait_until_closed();

}

void test_meshPointsFromFile()
{
    ifstream input("pose_mean_shape.txt");
    Point3d points[49];
    returnMeshPointsFromAFile(points);
    for (int i = 0; i < 49; i++)
    {
        cout << i+1 << ": " << points[i] << endl;
    }
    input.close();
}

void test_cameraMatrixToAFile()
{
    Mat_<double> test_matrix = Mat_<double>::ones(3,3);
    writeCameraMatrixToAFile(test_matrix);
    cout << test_matrix << endl;

    ifstream in;
    string line;
    in.open("cameraMatrixFile");
    while (getline(in, line))
    {
        cout << line << endl;
    }
    in.close();
}
/*
void test_writeErrorFile(exception &e)
{
    writeErrorFile(e);
}
*/