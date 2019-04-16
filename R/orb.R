#' @export
#' @rdname opencv
#' @param image a ocv image object
ocv_create <- function(nfeatures = 500,
                          scaleFactor = 1.2,
                          nlevels = 8,
                          edgeThreshold = 31,
                          firstLevel = 0,
                          WTA_K = 2,
                          scoreType = 1,
                          patchSize = 31,
                          fastThreshold = 20) {
  
  cvmat_create(nfeatures, scaleFactor, nlevels, edgeThreshold, firstLevel, WTA_K, scoreType, patchSize, fastThreshold)
}
