#include <iostream>
#include <fstream>

class Vec3
{
private:
    double x;
    double y;
    double z;

public:
    Vec3(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double X() {
        return this->x;
    }
    double Y() {
        return this->y;
    }
    double Z() {
        return this->z;
    }

    // Operator Overloading
    Vec3 operator+(const Vec3 &v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3 operator-(const Vec3 &v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    Vec3 operator*(const Vec3 &v) const
    {
        return Vec3(x * v.x, y * v.y, z * v.z);
    }
    Vec3 operator*(const double &T) const
    {
        return Vec3(x * T, y * T, z * T);
    }

    Vec3 operator/(const Vec3 &v) const {
        return Vec3(x / v.x, y / v.y, z / v.z);
    }

    Vec3 operator/(const double &T) const
    {
        return Vec3(x / T, y / T, z / T);
    }

};

class Renderer
{
public:
    Vec3 PerPixel(int x, int y) {
        
        x = x-250; // Centre for a 500*500 image
        y = y-250; // Centre for a 500*500 image

        if (x * x + y * y <= 10000) { // RENDER A CIRCLE WITH RADIUS 100
            return Vec3(255,0,0);
        }

        return Vec3(255,255,255);

    }
};

class Image
{
private:
    int width;
    int height;
    std::string name;

public:
    int getWidth() { return width; }
    int getHeight() { return height; }

    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }

    Image(int width, int height, std::string name)
    {
        this->width = width;
        this->height = height;
        this->name = name;

        initImage();
    }

    void initImage()
    {
        std::ofstream File(name);
        File << "P3 " << width << " " << height << " 255\n";
        File.close();
    } // PPM FORMAT SPEC - magic number, width, height, color depth, raw pixel values

    void writeImage() 
    {

        Renderer renderer;

        for(int i = 0; i < this->width; i++) {
            for (int j = 0; j < this->height; j++) {

                Vec3 pixel = renderer.PerPixel(i, j);

                std::ofstream File(name, std::ios_base::app);
                File << pixel.X() << " " << pixel.Y() << " " << pixel.Z() << "\n";
                File.close();
                
            }
        }
    }

};



int main()
{
    Image image(500, 500, "img.ppm");
    image.initImage();
    image.writeImage();
    return 0;
}
