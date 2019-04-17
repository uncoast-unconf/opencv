#include "util.hpp"

using namespace cv;

// [[Rcpp::export]]

XPtrMat cvmat_imthresh(XPtrMat ptr){
  Mat out;
  cv::threshold(get_mat(ptr), out, 0, 255, THRESH_BINARY);
  return cvmat_xptr(out);
}

// [[Rcpp::export]]

XPtrMat cvmat_cvtColor(XPtrMat ptr){
  Mat out;
  cv::cvtColor(get_mat(ptr), out, cv::COLOR_BGR2GRAY);
  return cvmat_xptr(out);
}

// [[Rcpp::export]]
XPtrMat cvmat_distanceTransform(XPtrMat ptr){
  Mat out;
  cv::distanceTransform(get_mat(ptr), out, DIST_L2, 3, 1);
  return cvmat_xptr(out);
}
