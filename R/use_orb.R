
#' @export
orb_read_and_register <- function(url1, url2){
  img1 = ocv_read(url1)
  img2 = ocv_read(url2)

  alignImages(img1, img2, 500)
}
