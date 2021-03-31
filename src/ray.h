#pragma once

#include "vec3.h"

class ray {
    public:
        point3 orig;
        point3 dir;

    public:
        ray();
        ray(const point3& origin, const vec3& direction);
        point3 origin() const;
        vec3 direction() const;
        point3 at(double t) const;
};