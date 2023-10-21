#include<opencv4/opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat srcimg;
    VideoCapture cap;
    vector<Mat> channels;
    Mat R, G, B;
    cap.open("../testvideo/0.mp4");
    // int wait_time = int(float(1/24) * 1000);
    while(1)
    {
        cap >> srcimg;
        if(srcimg.empty()){
            cap.set(CAP_PROP_POS_FRAMES, 0);
            continue;
        }
        split(srcimg, channels);
        B=channels.at(0);
        G=channels.at(1);
        R=channels.at(2);
        imshow("cap", srcimg);
        // imshow("B", B);
        // imshow("G", G);
        imshow("R", R);
        if(waitKey(30)==27)break;


    }
    cap.release();
    return 0;
}
