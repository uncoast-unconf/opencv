

#' Use ORB to register one image to another
#'
#' @param url1 path to first image (image to be registered)
#' @param url2 path to second image (reference image)
#'
#' @return First image transformed to conform to second image using ORB.
#' @export
#'
#' @examples
orb_read_and_register <- function(url1, url2, numpoints){
  img1 = ocv_read(url1)
  img2 = ocv_read(url2)

  alignImages(img1, img2, numpoints)
}
