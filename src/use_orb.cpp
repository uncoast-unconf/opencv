#include "util.hpp"
#include "opencv_types.h"

#include <opencv2/opencv.hpp>
#include "opencv2/features2d.hpp"

using namespace std;
using namespace cv;


XPtrOrb cvmat_orbdetect(Mat &im1, int num_features){
// Convert images to grayscale
Mat im1Gray;
cvtColor(im1, im1Gray, CV_BGR2GRAY);

// Variables to store keypoints and descriptors
std::vector<KeyPoint> keypoints;
Mat descriptors;

// Detect ORB features and compute descriptors.
Ptr<cv::ORB> orb = ORB::create(num_features);

orb->detectAndCompute(im1Gray, Mat(), keypoints, descriptors);


Rcpp::XPtr<cv::ORB> p(orb, TRUE);

return(p);

}
