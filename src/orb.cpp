#include "util.hpp"
#include "opencv_types.h"

using namespace cv;
using namespace std;

// [[Rcpp::export]]
XPtrOrb cvmat_orbcreate( int 	nfeatures = 500,
                       float 	scaleFactor = 1.2,
                       int 	nlevels = 8,
                       int 	edgeThreshold = 31,
                       int 	firstLevel = 0,
                       int 	WTA_K = 2){

  Ptr<cv::ORB> obj = cv::ORB::create(nfeatures,
                             scaleFactor,
                             nlevels,
                             edgeThreshold,
                             firstLevel,
                             WTA_K,
                             cv::ORB::HARRIS_SCORE,
                             31,
                             20);

  Rcpp::XPtr<cv::ORB> p(obj, TRUE);

  return(p);
}


