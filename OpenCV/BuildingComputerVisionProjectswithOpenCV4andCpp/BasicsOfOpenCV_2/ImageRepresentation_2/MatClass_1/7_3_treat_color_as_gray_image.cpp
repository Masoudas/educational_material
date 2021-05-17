/**
 * Note that the most important use of the reshape method is to be able to treat a color image as a gray
 * image. This is, for example, convert a 3 channel image to a single row image:
 * 
 * img.reshape(1, 1);
 * 
 * Or convert it in such a way that each column represents one channel
 * 
 * img.reshape(1, img.total());  
 * 
 * Note that in this latter form, because we have as many rows as total number of pixels, then each row is
 * filled with the closest values, which are the channels.
 */