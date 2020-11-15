project(lf_lesson4)
add_executable(lf_lesson4
    lf_lesson4.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson4 ${SDL2_LIBRARY})
install(TARGETS lf_lesson4 RUNTIME DESTINATION ${BIN_DIR})