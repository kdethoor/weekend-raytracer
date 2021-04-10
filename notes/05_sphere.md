# Sphere-ray intersection(s)
Equation of a sphere of a radius _r_ with origin at _C = (C<sub>x</sub>, C<sub>y</sub>, C<sub>z</sub>)_:

_(x - C<sub>x</sub>) + (y - C<sub>y</sub>) + (z - C<sub>z</sub>) = r<sup>2</sup>_

Or in terms of vectors, for _P = (x, y, z)_:

_(P - C) . (P - C) = r<sup>2</sup>_

Any point _P_ satisfying the above equation is on the sphere.

If our ray _P(t) = A + tb_ intersects with the above sphere, there must some value(s) of t such that the above sphere equation is satisfied.

In other words, the ray intersects the sphere for any satisfying

_(P(t) - C) . (P(t) - C) = r<sup>2</sup>_

_(A + bt - C) . (A + bt - C) = r<sup>2</sup>_

t<sup>2</sup>b.b + 2tb . (A - C) + (A - C) . (A - C) - r<sup>2</sup> = 0

Since this is a quadratic equations there are 0, 1 or 2 solutions, as shown on the website of [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html) ([chapter 05](https://raytracing.github.io/books/RayTracingInOneWeekend.html#addingasphere)):

![Sphere-ray intersections](images/fig-1.04-ray-sphere.jpg)

Result:

![Sphere-ray interesection rendering results](images/sphere.png)

**Remark**: Solutions for _t < 0_, intersections happening **behind** the camera, work fine with the current code. This can be tested by changing the center of the sphere, e.g. from _(0, 0, -1)_ to _(0, 0, 1)_.

Note that in this case the rendering result will actually be the same in both cases, as shown here below.
Indeed, a ray with origin _A_ and direction _b_ intersects with the sphere in front of the camera at _(0, 0, -1)_, when _t > 0_, **AND** with the sphere behind the camera, when _t < 0_.

![Sphere-ray interesection rendering results, when the sphere center is behind the camera](images/sphere_behind_camera.png)

This issue will be fixed later.