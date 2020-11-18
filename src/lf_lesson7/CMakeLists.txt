project(lf_lesson7)
add_executable(lf_lesson7
    lf_lesson7.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/imgUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson7 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS lf_lesson7 RUNTIME DESTINATION ${BIN_DIR})