project(lf_lesson19)
add_executable(lf_lesson19
    lf_lesson19.cxx
    "${CMAKE_SOURCE_DIR}/include/LTexture.cxx"
    "${CMAKE_SOURCE_DIR}/include/RenderingContext.cxx"
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/imgUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
    "${CMAKE_SOURCE_DIR}/include/LButton.cxx"
)
target_link_libraries(lf_lesson19 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
install(TARGETS lf_lesson19 RUNTIME DESTINATION ${BIN_DIR})