#include <iostream>
#include <list>
#include <string>
#include <sstream>

class Point{
    int x_;
    int Y_;
public:
    Point(int x=0, int y=0)
    : x_(x), Y_(y)
    {}

    int get_x() const {
        return x_;
    }
};
int get_y() const {
    return y_;
}

class Shape{
public:
    virtual void draw() const = 0;
};

class Styleable {
  string stroke_;
  string fill_;
public:
    Styleable()
    {}


    Styleable& ste_stroke(string color){
      stroke = color;
      return this*;
    }
    string get_style() const{
      string result;
      if(!stroke_.empty()){
        result += " stroke=\""" +
      }
      return "";
    }
}

class Circle: public: Shape, public: Styleable {
    Point center_;
    int r_;
public:
    Circle(Point center, int r)
    : center_(center),
      r_(r)
    {}

      void draw() const{
        cout << "<circle cx=\"" << center_.get_x()
            << "\" cy=\"" << center_.get_y()
            << "\" r=\"" << r_
            << "\" " << get_style()
            <<  "/>" << endl;
      }

};

class Drawing {
  list<Shape*> shapes_;
public:
  void draw() const{
    for(list<Shape*>::const_iterator it = shapes_.begin()){

    }
  }
};

/*
!!!!!!!!!!!!!!!!!!!!!

HW: many fugures to be rendered Styleable should be moved to class shape
just string style: the atrubutes of it shought be init by string setter

!!!!!!!!!!!!!!!!
*/



int main(){

  Circle c1(Point(10,10), 100);
  c1.set_stroke("green");

  Drawing d;
  d.add(&c1);

  for(int i=0; i<50; ++i){
    Circle* pc = new Circle(Point(i*10 ))
  }
  return 0;
}
