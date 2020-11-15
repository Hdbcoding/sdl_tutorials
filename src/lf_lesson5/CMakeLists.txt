project(lf_lesson5)
add_executable(lf_lesson5
    lf_lesson5.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson5 ${SDL2_LIBRARY})
install(TARGETS lf_lesson5 RUNTIME DESTINATION ${BIN_DIR})