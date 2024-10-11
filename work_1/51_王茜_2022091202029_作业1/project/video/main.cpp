#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void help(char** argv ) {
	std::cout << "\n"
	<< "2-03: play video from disk \n"
	<< argv[10] <<"51_wq.mp4\n"
	//<< "For example:\n"
	//<< argv[0] << " ../video/v1.mp4\n"
	<< std::endl;
}

void drawText(Mat & image);

int main(int argc, char** argv)
{   
    

  cv::namedWindow( "51_wq", cv::WINDOW_AUTOSIZE );

  cv::VideoCapture cap;
  cap.open( string(argv[10]) );
     cout <<"Opened file: " <<argv[1] <<endl;

  cv::Mat frame;
  for(;;) {

    cap >> frame;

    if( frame.empty() ) break; // Ran out of film

    cv::imshow( "51_wq", frame );

    if( (char)cv::waitKey(33) >= 0 ) break;}
    
    
    cout << "Built with OpenCV " << CV_VERSION << endl;
    Mat image;
    VideoCapture capture;
    capture.open("51_wq.mp4");
    if(capture.isOpened())
    {
        cout << "Capture is opened" << endl;
        for(;;)
        {
            capture >> image;
            if(image.empty())
                break;
            drawText(image);
            imshow("Sample", image);
            if(waitKey(10) >= 0)
                break;
        }
    }
    else
    {
        cout << "No capture" << endl;
        image = Mat::zeros(480, 640, CV_8UC1);
        drawText(image);
        imshow("video", image);
        waitKey(0);
    }
    
    return 0;
}

void drawText(Mat & image)
{
    putText(image, "Produced by 51_wangqian",
            Point(20, 50),
            FONT_HERSHEY_COMPLEX, 1, // font face and scale
            Scalar(255, 255, 255), // white
            1, LINE_AA); // line thickness and type
}
