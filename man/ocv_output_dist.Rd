% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/dist.R
\name{ocv_output_dist}
\alias{ocv_output_dist}
\title{Distance transformation for a 3 channel image}
\usage{
ocv_output_dist(image)
}
\arguments{
\item{image}{An external pointer to an OpenCV image.}
}
\value{
An external pointer to an image of the distance transform.
}
\description{
This is not a robust function, it is only given as an example.
This takes an OpenCV image, transforms it into a binary image, then
computes and returns the distance transform of that image.
}
