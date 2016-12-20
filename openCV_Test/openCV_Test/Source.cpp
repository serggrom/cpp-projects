#include <opencv\cv.h>
#include <opencv\highgui.h>

using namespace cv;

int main(int argc, char** argv)
{
    IplImage* img = cvLoadImage( "D:\\repository\\cpp-projects\\openCV_Test\\x64\\Release\\opencv-logo.png" ); //change the name (image.jpg) according to your Image filename.
    cvNamedWindow( "Example1", CV_WINDOW_NORMAL );
    cvShowImage("Example1", img);
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow( "Example1" );
    return 0;
}