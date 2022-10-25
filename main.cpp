#include <iostream>
#include <fstream>


class Image {
private:
    int width;
    int height;
    std::string name;

public:
    int getWidth() { return width; }
    int getHeight() { return height; }

    int setWidth(int width) { this->width = width; } 
    int setHeight(int height) { this->height = height; } 

    Image(int width, int height, std::string name) {
        this->width = width;
        this->height = height;
        this->name = name;
    }

    void initImage() {
        std::ofstream File(name);
        File << "P3 " << width << " " << height << " 255\n";
        File.close();
    } // PPM FORMAT SPEC - magic number, width, height, color depth, raw pixel values
    
    
};

int main() {
    Image image(500, 500, "img.ppm");
    image.initImage();
    std::cout << "Hello World!";
    return 0;
}
