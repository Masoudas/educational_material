/**
 * This is just a reminder that we can freely add noise to matrix using the simple plus operator. This is 
 * because the plus operator goes as far as saturating values for us.
 * 
 * However, the constraint here is that both the noise and matrix must have the same type. If one has a type
 * that's different from the other, then we need an actuall loop.
 * 
 * What they do in the literiture is to generate the noise and just directly add it, but that always feels
 * wrong to me, because adding the noise like this several times causes saturation! Although physically
 * speaking, this is correct.
 * 
 * Unfortunately, we need to allocate another memory to add noise to image for the fastest way. If we didn't
 * want to allocate memory, then we have to write a for loop to do it.
 * 
 * In particular, we use the for each function to add noise.
 */
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

void add_noise_maximum_speed(cv::Mat img){
    using namespace cv;
    
    Mat noise(img.rows, img.cols, img.type());   // Noise matrix allocated

    RNG noise_generator{};
    noise_generator.fill(noise, RNG::NORMAL, 0, 20);    

    img = img + noise;  // Unavoidable
}

void add_noise_minimum_memory(cv::Mat img){
    using namespace cv;
    using Pixel = Point3_<uint8_t>;

    RNG noise{};
    img.forEach<Pixel>([&](Pixel& p, const int* sz){ 
        p.x = noise.uniform(10, 20); 
        p.y = noise.uniform(10, 20);
        p.z = noise.uniform(10, 20);    
    });

}