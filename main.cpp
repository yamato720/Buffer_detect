#include<opencv4/opencv2/opencv.hpp>
#include<iostream>
#include<sys/time.h>
#include<vector>
using namespace std;
using namespace cv;

vector<Point> points_light;
void drawline(Point center, Mat &pic)
{
    
}
int main()
{
    Mat srcimg;
    VideoCapture cap;
    vector<Mat> channels;
    Mat R, G, B;
    struct timeval t1, t2;
    double timeuse;
    cap.open(0);
    // int wait_time = int(float(1/24) * 1000);
    Point p(370,340);
    while(1)
    {
        gettimeofday(&t1, NULL);
        cap >> srcimg;
        if(srcimg.empty()){
            cap.set(CAP_PROP_POS_FRAMES, 0);
            continue;
        }
        // split(srcimg, channels);
        // B=channels.at(0);
        // G=channels.at(1);
        // R=channels.at(2);
        circle(srcimg, p, 5, (0, 255, 255), -1);
        imshow("cap", srcimg);
        // imshow("B", B);
        // imshow("G", G);
        // imshow("R", R);
        gettimeofday(&t2, NULL);
        timeuse = (t2.tv_sec - t1.tv_sec) + (double)(t2.tv_usec - t1.tv_usec)/1000000.0;
        cout << "fps:" <<(1.0/timeuse)<<endl;
        if(waitKey(30)==27)break;


    }
    cap.release();
    return 0;
}
