/*
 * Point.h
 * Class to represent a 2D point with x and y coordinates
 */

 #ifndef POINT_H
 #define POINT_H
 
 #include <iostream>
 #include <cmath>
 
 namespace geom { // Put the Point class inside the geom namespace
     class Point {
     private:
         double xx, yy; // Coordinates
 
     public:
         // Constructor with x and y coordinates
         Point(double x, double y) : xx(x), yy(y) {}
 
         // Constructor that takes another Point
         Point(const Point &p) : Point(p.xx, p.yy) {}
 
         // Getter functions
         double x() const { return xx; }
         double y() const { return yy; }
 
         // Angle in radians (using atan2)
         double angle() const { return atan2(yy, xx); }
 
         // Distance from origin
         double radius() const { return hypot(xx, yy); }
 
         // Distance between two points
         double distance(const Point &p2) const {
             //subtracts the corresponding coordinates
             double dx = xx - p2.xx;
             double dy = yy - p2.yy;
             return hypot(dx, dy);
         }
 
         // Translate the point in 2D space
         void translate(double dx, double dy) {
             //add distance coordinates to x and y coordinates
             xx += dx;
             yy += dy;
         }
         
         // Rotate the point around origin by theta radians
         void rotate(double theta) {
             double new_x = xx * cos(theta) - yy * sin(theta);
             double new_y = xx * sin(theta) + yy * cos(theta);
             xx = new_x;
             yy = new_y;
         }
         
         // Rotate the point around another point p by theta radians
         void rotate(const Point& p, double theta) {
             // Translate to make p the origin
             translate(-p.xx, -p.yy);
             
             // Rotate around origin
             rotate(theta);
             
             // Translate back
             translate(p.xx, p.yy);
         }
         
         // Friend declaration for the output operator
         friend std::ostream& operator<<(std::ostream& os, const Point& p);
     }; // semicolon after class declaration
     
     // Overloaded << operator implementation
     std::ostream& operator<<(std::ostream& os, const Point& p) {
         os << "(" << p.xx << ", " << p.yy << ")";
         return os;
     }
 } // namespace geom
 
 #endif // POINT_H