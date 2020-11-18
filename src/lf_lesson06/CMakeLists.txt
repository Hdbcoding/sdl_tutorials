project(lf_lesson06)
add_executable(lf_lesson06
    lf_lesson06.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/imgUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson06 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS lf_lesson06 RUNTIME DESTINATION ${BIN_DIR})