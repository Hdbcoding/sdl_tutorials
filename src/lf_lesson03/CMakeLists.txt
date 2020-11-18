project(lf_lesson03)
add_executable(lf_lesson03
    lf_lesson03.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson03 ${SDL2_LIBRARY})
install(TARGETS lf_lesson03 RUNTIME DESTINATION ${BIN_DIR})