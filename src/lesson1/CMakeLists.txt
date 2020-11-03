project(lesson1)
add_executable(lesson1 lesson1.cxx)
target_link_libraries(lesson1 ${SDL2_LIBRARY})
install(TARGETS lesson1 RUNTIME DESTINATION ${BIN_DIR})