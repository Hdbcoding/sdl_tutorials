project(lf_lesson14)
add_executable(lf_lesson14
    lf_lesson14.cxx
    "${CMAKE_SOURCE_DIR}/include/LTexture.cxx"
    "${CMAKE_SOURCE_DIR}/include/RenderingContext.cxx"
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/imgUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
)
target_link_libraries(lf_lesson14 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS lf_lesson14 RUNTIME DESTINATION ${BIN_DIR})