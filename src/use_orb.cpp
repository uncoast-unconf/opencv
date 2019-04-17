#include "util.hpp"
#include "opencv_types.h"

#include <opencv2/opencv.hpp>
#include "opencv2/features2d.hpp"

using namespace std;
using namespace cv;

const float GOOD_MATCH_PERCENT = 0.15f;

XPtrOrb cvmat_orbdetect(XPtrMat im, int num_features){
  Mat im1 = get_mat(im);
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

// [[Rcpp::export]]
XPtrMat alignImages(XPtrMat im1, XPtrMat im2, int features)
{
  Mat im1reg;
  Mat h;
  // Convert images to grayscale
  Mat im1Gray, im2Gray;
  cvtColor(get_mat(im1), im1Gray, CV_BGR2GRAY);
  cvtColor(get_mat(im2), im2Gray, CV_BGR2GRAY);

  // Variables to store keypoints and descriptors
  std::vector<KeyPoint> keypoints1, keypoints2;
  Mat descriptors1, descriptors2;

  // Detect ORB features and compute descriptors.
  Ptr<Feature2D> orb = ORB::create(features);
  orb->detectAndCompute(im1Gray, Mat(), keypoints1, descriptors1);
  orb->detectAndCompute(im2Gray, Mat(), keypoints2, descriptors2);

  // Match features.
  std::vector<DMatch> matches;
  Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");
  matcher->match(descriptors1, descriptors2, matches, Mat());

  // Sort matches by score
  std::sort(matches.begin(), matches.end());

  // Remove not so good matches
  const int numGoodMatches = matches.size() * GOOD_MATCH_PERCENT;
  matches.erase(matches.begin()+numGoodMatches, matches.end());


  // Draw top matches
  //Mat imMatches;
  //drawMatches(im1, keypoints1, im2, keypoints2, matches, imMatches);
  //imwrite("matches.jpg", imMatches);


  // Extract location of good matches
  std::vector<Point2f> points1, points2;

  for( size_t i = 0; i < matches.size(); i++ )
  {
    points1.push_back( keypoints1[ matches[i].queryIdx ].pt );
    points2.push_back( keypoints2[ matches[i].trainIdx ].pt );
  }

  // Find homography
  h = findHomography( points1, points2, RANSAC );

  // Use homography to warp image
  warpPerspective(get_mat(im1), im1reg, h, get_mat(im2).size());

  return cvmat_xptr(im1reg);
}


