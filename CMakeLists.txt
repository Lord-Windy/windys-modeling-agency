cmake_minimum_required(VERSION 3.12)
project(Glamour)

set(CMAKE_CXX_STANDARD 14)

if (APPLE)
    include_directories(/usr/local/include/)
    link_directories(/usr/local/Cellar/glfw/3.2.1/lib)
ELSEIF(UNIX)
    link_directories(/usr/lib/x86_64-linux-gnu/)
ENDIF()

add_executable(Glamour src/main.cpp src/glad.c src/model.cpp src/ShaderProgram.cpp src/Helper.cpp src/json.hpp src/tiny_gltf.h)

if (APPLE)
    target_link_libraries(Glamour "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework Carbon -l glfw" )
ELSEIF(UNIX)
    target_link_libraries(Glamour glfw GL X11 pthread Xrandr Xi dl)
ENDIF()