/**
 * Blurs an image using the median filter.
 * The function smoothes an image using the median filter with the ksize×ksize aperture. Each channel of a multi-channel image is processed independently. In-place operation is supported.
 * 
 *   -   Note
 * The median filter uses BORDER_REPLICATE internally to cope with border pixels, see BorderTypes
 */