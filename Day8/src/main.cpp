#include "tgaimage.h"
#include<iostream>


struct Point{
    int x{0},y{0};
    TGAColor color = {{0,0,0,0}};
};


std::ostream& operator<<(std::ostream& s,const Point& p){
    s << "Point (" <<p.x << ",  " << p.y << ")" << std::endl;
    return s;
};

// constexpr TGAColor white   = {{255, 255, 255, 255}}; // attention, BGRA order
constexpr TGAColor green   = {  {0, 255,   0, 255}};
constexpr TGAColor red     = {  { 0,   0, 255, 255}};
constexpr TGAColor blue    = {{255, 128,  64, 255}};
constexpr TGAColor yellow  = {  {0, 200, 255, 255}};

void line(Point& p1, Point& p2, TGAImage& image){

    TGAColor finalCol{{0,0,0,0}};
  
    for(float i = 0.0f;i < 1.0f;i+=.001f){
        int x = static_cast<int>(p1.x + (p2.x-p1.x)*i);
        int y = static_cast<int>(p1.y + (p2.y-p1.y)*i);

        finalCol.bgra[0] = static_cast<int>(p1.color[0] + static_cast<float>(p2.color[0] - p1.color[0]) * i);
        finalCol.bgra[1] = static_cast<int>(p1.color[1] + static_cast<float>(p2.color[1] - p1.color[1]) * i);
        finalCol.bgra[2] = static_cast<int>(p1.color[2] + static_cast<float>(p2.color[2] - p1.color[2]) * i);
        

        image.set(x,y,finalCol);
    }
};

void line2(Point p1,Point p2,TGAImage& image){
    
    TGAColor finalCol{{0,0,0,0}};
    float t = .0f;
    bool steep = std::abs(p1.x-p2.x) < std::abs(p1.y - p2.y);
    
    if(steep){

        std::cout << "p1: " << p1 << std::endl;
        std::cout << "p2: " << p2 << std::endl;
        
        int tmp = p1.x;
        p1.x = p1.y;
        p1.y = tmp;
        
        tmp = p2.x;
        p2.x = p2.y;
        p2.y = tmp;
        
        std::cout << "p1: " << p1 << std::endl;
        std::cout << "p2: " << p2 << std::endl;
        
    }
    
    if(p1.x > p2.x){
        std::cout << "Diddy" << std::endl;
        Point tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    
    float slope = (p2.y-p1.y)/static_cast<float>(p2.x-p1.x);
    float y = p1.y;
    
    for(int x = p1.x;x <= p2.x;x++){
        t = (x-p1.x)/ static_cast<float>(p2.x-p1.x);
        
        finalCol.bgra[0] = static_cast<int>(p1.color[0] + static_cast<float>(p2.color[0] - p1.color[0]) * t);
        finalCol.bgra[1] = static_cast<int>(p1.color[1] + static_cast<float>(p2.color[1] - p1.color[1]) * t);
        finalCol.bgra[2] = static_cast<int>(p1.color[2] + static_cast<float>(p2.color[2] - p1.color[2]) * t);
        
        if(steep)
            image.set(y,x,finalCol);
        else
            image.set(x,y,finalCol);
        y += slope;
    }
}



int main() {
    constexpr int width  = 50;
    constexpr int height = 50;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    // int ax =  0, ay =  0;
    // int bx = 12, by = 37;
    // int cx = 62, cy = 53;

    Point p1{0,0,green};
    Point p2{30,30,{red}};
    Point p3{15,7,{blue}};

    // framebuffer.set(ax, ay, white);
    // framebuffer.set(bx, by, green);
    // framebuffer.set(cx, cy, red);

    line2(p1,p2,framebuffer);
    line2(p2,p3,framebuffer);
    line2(p3,p1,framebuffer);


    framebuffer.set(p1.x,p1.y,yellow);
    framebuffer.set(p2.x,p2.y,yellow);
    framebuffer.set(p3.x,p3.y,yellow);
    
    framebuffer.write_tga_file("framebuffer.tga");

    
    return 0;
}