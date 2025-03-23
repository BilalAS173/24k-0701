#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct point {
    float x;
    float y;
};
class shape {
protected:
string colour;
point position;
float borderthickness;
public:
shape(string c, float a, float b, float f): colour(c), borderthickness(f) {
    position.x=a;
    position.y=b;
}
virtual void draw (){
cout<<"Drawing shape..."<<endl;
}
virtual float calculatearea () {
    //placeholder
}
virtual float calculateperimeter () {
    //placeholder
}

};
struct topleftcornerposition {
float x;
float y;
};
class rectangle: public shape {
protected:
float width;
float height;
topleftcornerposition p;
public:
rectangle(string c, float a, float b, float d, float z, float g, float e, float x ):  shape(c,a,b,d), width(z), height(x) {
    p.x=g;
    p.y=e;
}
void draw () {
    cout<<"Drawing rectangle..."<<endl;
}
float calculatearea () {
float area=width*height;
return area;
}
float calculateperimeter () {
    float perimeter=2*(width+height);
    return perimeter;
    }
};
class circle: public shape {
    protected:
    float radius;
    point centreposition;
    public:
    circle(string c, float a, float b, float d, float z, float g, float e ): radius(z), shape(c,a,b,d) {
        centreposition.x=g;
        centreposition.y=e;
    }
    void draw () {
        cout<<"Drawing circle..."<<endl;
    }
    float calculatearea () {
    float area=3.142*radius*radius;
    return area;
    }
    float calculateperimeter () {
        float perimeter=2*(3.142*radius);
        return perimeter;
        }
    };
    class triangle: public shape {
        protected:
float base;
float height;
float s1;
float s2;
public:
triangle(string c, float a, float b, float d, float z, float g, float j, float k ): s1(j), s2(k), base(z), height(g), shape(c,a,b,d) {}
void draw () {
    cout<<"Drawing triangle..."<<endl;
}
float calculatearea () {
float area=0.5*base*height;
return area;
}
float calculateperimeter () {
    float perimeter=base+s1+s2;
    return perimeter;
    }
    };
    class polygon : public shape {
            protected:
                float side1, side2, side3, side4; 
            public:
                polygon(string c, float a, float b, float f, float s1, float s2, float s3, float s4)
                    : shape(c, a, b, f), side1(s1), side2(s2), side3(s3), side4(s4) {}
                void draw() override {
                    cout << "Drawing polygon..." << endl;
                }
                float calculatearea() override {
                    return side1 * side2;
                }
                float calculateperimeter() override {
                    return side1 + side2 + side3 + side4;
                }
            };
            int main() {
                rectangle rect("Green", 10, 20, 2.0, 5.0, 10.0, 10, 20);
                cout << "Rectangle:" << endl;
                rect.draw();
                cout << "Area: " << rect.calculatearea() << endl;
                cout << "Perimeter: " << rect.calculateperimeter() << endl;
                cout << "-------------------------" << endl;

                circle circ("Blue", 30, 40, 1.5, 7.0, 30, 40);
                cout << "Circle:" << endl;
                circ.draw();
                cout << "Area: " << circ.calculatearea() << endl;
                cout << "Perimeter: " << circ.calculateperimeter() << endl;
                cout << "-------------------------" << endl;
                triangle tri("Yellow", 50, 60, 1.0, 6.0, 8.0, 5.0, 7.0);
                cout << "Triangle:" << endl;
                tri.draw();
                cout << "Area: " << tri.calculatearea() << endl;
                cout << "Perimeter: " << tri.calculateperimeter() << endl;
                cout << "-------------------------" << endl;
                polygon poly("red", 70, 80, 2.0, 4.0, 3.0, 4.0, 3.0);
                cout << "Polygon:" << endl;
                poly.draw();
                cout << "Area: " << poly.calculatearea() << endl;
                cout << "Perimeter: " << poly.calculateperimeter() << endl;
                cout << "-------------------------" << endl;
            
                return 0;
            }