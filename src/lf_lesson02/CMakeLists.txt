project(lf_lesson02)
add_executable(lf_lesson02
    lf_lesson02.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(lf_lesson02 ${SDL2_LIBRARY})
install(TARGETS lf_lesson02 RUNTIME DESTINATION ${BIN_DIR})