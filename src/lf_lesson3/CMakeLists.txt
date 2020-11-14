project(lf_lesson3)
add_executable(lf_lesson3
    lf_lesson3.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson3 ${SDL2_LIBRARY})
install(TARGETS lf_lesson3 RUNTIME DESTINATION ${BIN_DIR})