cmake_minimum_required(VERSION 3.5)

project(ponggame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ponggame main.cpp
    ball.h ball.cpp
    bat.h bat.cpp
    aibat.h aibat.cpp
)

target_link_libraries(ponggame PUBLIC "/usr/local/lib/libraylib.a")

include(GNUInstallDirs)
install(TARGETS ponggame
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
