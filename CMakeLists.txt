# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

cmake_minimum_required (VERSION 3.8)

# Name of the solution
project ("physik")

# Include sub-projects.
set(EXECUTABLE_CUSTOM_NAME "verlet-physik")
add_subdirectory ("verlet-physik")
