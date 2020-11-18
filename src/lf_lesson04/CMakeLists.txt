project(lf_lesson04)
add_executable(lf_lesson04
    lf_lesson04.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson04 ${SDL2_LIBRARY})
install(TARGETS lf_lesson04 RUNTIME DESTINATION ${BIN_DIR})