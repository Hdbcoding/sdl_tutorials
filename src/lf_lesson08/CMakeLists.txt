project(lf_lesson08)
add_executable(lf_lesson08
    lf_lesson08.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson08 ${SDL2_LIBRARY})
install(TARGETS lf_lesson08 RUNTIME DESTINATION ${BIN_DIR})