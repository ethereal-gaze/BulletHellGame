cmake_minimum_required(VERSION 3.28)

project(game LANGUAGES CXX)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)



add_executable(game main.cpp Game.cpp ResourceManager.cpp GameObject.cpp ObjectManager.cpp Projectile.cpp ObjectManager.cpp)


target_link_libraries(game debug sfml-graphics sfml-system sfml-window)
target_compile_features(game PRIVATE cxx_std_17)

install(TARGETS game RUNTIME DESTINATION bin)
