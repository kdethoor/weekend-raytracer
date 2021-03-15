cmake_minimum_required(VERSION 3.16)
project(WeekendRaytracer
    DESCRIPTION 
        "\
        Reimplementation of 'Ray Tracing in One Weekend', \
        by Peter Shirley \
        (raytracing.github.io/books/RayTracingInOneWeekend.html) \
        "
    LANGUAGES
        CXX
)

add_subdirectory(src)