# CMakeList.txt : CMake project for ray_tracer_1w, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ray_tracer_1w "main.cpp" "ray_tracer_1w.h" "vec3.h" "color.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ray_tracer_1w PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
