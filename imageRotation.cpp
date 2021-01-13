#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
    Mat src, des;

    src = imread("Resources/image.jpg", 1);
    if (src.empty())
    {
        cout << "Image not found" << endl;
        return -1;
    }
    Point2f center(src.cols / 2.0F, src.rows / 2.0f);
    double angle;
    cout << "Enter the rotating angle :" << endl;
    cin >> angle;
    Mat temp = getRotationMatrix2D(center, angle, 0.5);
    warpAffine(src, des, temp, Size(815, 580));

    imshow("Image", src);
    imshow("Rotated", des);

    waitKey(0);
    destroyAllWindows();
}