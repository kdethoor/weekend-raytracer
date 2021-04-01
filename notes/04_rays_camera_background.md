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

## Implementation
`ray_color(ray)` linearly blends white and blue according to the _linear interpolation_ (_lerp_ for short) formula:
```
blended_value = (1-t)*start_value + t * end_valie
```
In the case of `ray_color(ray)`, `t` depends on the ray's normalized `y`, which means:

- there is a vertical white-to-blue gradient,
- there is also a horizontal gradient , since `t` depends on the normalized `y`, which changes, for a same `y`, if `x` changes, since the norm depends on `x` and `y`; this gradient is more pronounced on the sides because the norm varies more per unit of `x` as one gets away from the center.


Remark: we accept the fact we aren't reaching the center of each pixel as we'll add anti-aliasing later - while I understand we should try to calculate the color at the center of a pixel to best approximate its color, I do not see yet how anti-aliasing helps...

Result:

![gradient example](images/04_gradient.png)