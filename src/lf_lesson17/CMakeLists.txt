project(lf_lesson17)
add_executable(lf_lesson17
    lf_lesson17.cxx
    "${CMAKE_SOURCE_DIR}/include/LTexture.cxx"
    "${CMAKE_SOURCE_DIR}/include/RenderingContext.cxx"
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/imgUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
    "${CMAKE_SOURCE_DIR}/include/LButton.cxx"
)
target_link_libraries(lf_lesson17 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
install(TARGETS lf_lesson17 RUNTIME DESTINATION ${BIN_DIR})