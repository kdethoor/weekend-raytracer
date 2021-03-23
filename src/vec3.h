#pragma once

#include <array>
#include <iostream>

class vec3 {
    public:
        std::array<double, 3> e;

    public:
        vec3();
        vec3(double e0, double e1, double e2);

        double x() const;
        double y() const;
        double z() const;

        vec3 operator-() const;
        double operator[](int i) const;
        double& operator[](int i);
        
        vec3& operator+=(const vec3& v);
        vec3& operator*=(const vec3& v);
        vec3& operator*=(double t);
        vec3& operator/=(double t);

        double length() const;
        double length_squared() const;
};

// Type aliases
using point3 = vec3;

// Utility functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(vec3 u, const vec3& v) {
    u += v;
    return u;
}

inline vec3 operator-(vec3 u, const vec3& v) {
    u += -v;
    return u;
}

inline vec3 operator*(vec3 u, const vec3& v) {
    u *= v;
    return u;
}

inline vec3 operator*(double t, vec3 v) {
    v *= t;
    return v;
}

inline vec3 operator*(vec3 v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    v /= t;
    return v;
}

inline double dot(vec3 u, const vec3& v) {
    u *= v;
    return u[0] + u[1] + u[2];
}

inline vec3 cross(vec3 u, const vec3& v) {
    return vec3(u.e[1]*v.e[2] - u.e[2]*v.e[1]
        , u.e[2]*v.e[0] - u.e[0]*v.e[2]
        , u.e[0]*v.e[1] - u.e[1]*v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    v /= v.length();
    return v;
}
