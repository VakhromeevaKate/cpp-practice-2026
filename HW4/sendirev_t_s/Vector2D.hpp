#pragma once

#include <iostream>


class Vector2D {
public:
    
    Vector2D(double x = 0, double y = 0);

   
    double x() const;
    double y() const;

   
    double length() const;

  
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;


    Vector2D operator-() const;


    Vector2D operator*(double k) const;

  
    double operator*(const Vector2D& other) const;


    bool operator==(const Vector2D& other) const;
    bool operator!=(const Vector2D& other) const;

private:
    double x_;
    double y_;
};


std::ostream& operator<<(std::ostream& os, const Vector2D& v);
