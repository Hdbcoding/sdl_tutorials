project(lf_lesson05)
add_executable(lf_lesson05
    lf_lesson05.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson05 ${SDL2_LIBRARY})
install(TARGETS lf_lesson05 RUNTIME DESTINATION ${BIN_DIR})