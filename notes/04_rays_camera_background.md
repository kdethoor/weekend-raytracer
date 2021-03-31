# `ray` class

```
P(t) = A + t*b
```
where

* `P(t)` is a point along the ray, for a given `t`,
* `A` is the origin of the ray,
* `b` is the direction of the ray,
* `t` is a real number, positive or negative, a `double` in the code, that allows to move `P(t)` along the ray.

If `t > 0`, we often talk of a half-line or a ray.

# Sending rays into the scene

## Camera setup

1. Set up a viewport with an aspect ratio equal to the desired image dimensions - we assume square pixel spacing.
2. Decide on the focal length, i.e. the distance between the projection plane and the projection point.

## Rendering steps

1. Calculate the ray from the eye to the pixel.
2. Determine which objects the ray tracer intersects.
3. Compute a color for the intersection point(s).

## Development tips

* Work with a non-square to avoid making mistakes by transposing `x` and `y`.
* Get a simple camera  and a `ray_color(ray)` function that returns the color of the background up and running quickly, in order to debug mor easily.