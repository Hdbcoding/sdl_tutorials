project(lesson0)
add_executable(lesson0 lesson0.cxx)
target_link_libraries(lesson0 ${SDL2_LIBRARY})
install(TARGETS lesson0 RUNTIME DESTINATION ${BIN_DIR})