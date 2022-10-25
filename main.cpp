// Your First C++ Program

#include <iostream>

class Image {
private:
    int width;
    int height;

public:
    int getWidth() { return width; }
    int getHeight() { return height; }

    int setWidth(int width) { this->width = width; } 
    int setHeight(int height) { this->height = height; } 

    Image(int width, int height) {
        this->width = width;
        this->height = height;
    }
};

int main() {
    Image image(500, 500);
    std::cout << "Hello World!";
    return 0;
}
