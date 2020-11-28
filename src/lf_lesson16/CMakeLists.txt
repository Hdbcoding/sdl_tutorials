project(lf_lesson16)
add_executable(lf_lesson16
    lf_lesson16.cxx
    "${CMAKE_SOURCE_DIR}/include/LTexture.cxx"
    "${CMAKE_SOURCE_DIR}/include/RenderingContext.cxx"
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
    "${CMAKE_SOURCE_DIR}/include/imgUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/input.cxx"
    "${CMAKE_SOURCE_DIR}/include/ttfUtils.cxx"
    "${CMAKE_SOURCE_DIR}/include/LFont.cxx"
    "${CMAKE_SOURCE_DIR}/include/LTextTexture.cxx"
)
target_link_libraries(lf_lesson16 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
install(TARGETS lf_lesson16 RUNTIME DESTINATION ${BIN_DIR})