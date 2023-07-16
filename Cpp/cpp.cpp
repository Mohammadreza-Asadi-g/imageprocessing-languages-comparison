#include <iostream>
#include <opencv2/opencv.hpp>


void imageShow(cv::Mat image, std::string window_name)
{
    cv::namedWindow("Image", cv::WINDOW_NORMAL); cv::setWindowTitle("Image", window_name);
    cv::moveWindow("Image", 0, 0); cv::resizeWindow("Image", image.size[1]/2, image.size[0]/2); 
    cv::imshow("Image", image); cv::waitKey(0);
}

cv::Mat imageCircles(cv::Mat image_orig, cv::Mat image_edges)
{
    std::vector<cv::Vec3f> circles;
    int dp, minDist, param1, param2, minRadius, maxRadius;
    cv::HoughCircles(image_edges, circles, cv::HOUGH_GRADIENT, dp=1.3, minDist=60, param1=50, param2=70, minRadius=0, maxRadius=500);
    std::vector<cv::Vec3f>::const_iterator it = circles.begin();
    while(it != circles.end()){
        cv::circle(image_orig, cv::Point((*it)[0], (*it)[1]), 10, cv::Scalar(0,255,0), -1);
        cv::rectangle(image_orig, cv::Point((*it)[0]-(*it)[2], (*it)[1]-(*it)[2]), cv::Point((*it)[0]+(*it)[2], (*it)[1]+(*it)[2]), cv::Scalar(0,255,0), 3);
    }
}


int main()
{
    std::chrono::steady_clock::time_point time_start = std::chrono::steady_clock::now();
    // Processes:
    cv::Mat image, image_gray, image_edges, image_circles;
    image = cv::imread("../test.jpg");
    cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);
    cv::Canny(image_gray, image_edges, 50, 100);
    std::chrono::steady_clock::time_point time_end = std::chrono::steady_clock::now();
    image_circles = imageCircles(image, image_edges);
    // 
    std::cout << "Processing time: " << std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count() << " ms" << std::endl;
    
    imageShow(image, "Original");
    imageShow(image_edges, "image_edges");
    return 0;
}