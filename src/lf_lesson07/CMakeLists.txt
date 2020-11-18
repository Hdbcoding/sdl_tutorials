project(lf_lesson07)
add_executable(lf_lesson07
    lf_lesson07.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/imgUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson07 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS lf_lesson07 RUNTIME DESTINATION ${BIN_DIR})