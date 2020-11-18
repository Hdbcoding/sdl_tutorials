project(lf_lesson01)
add_executable(lf_lesson01
    lf_lesson01.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(lf_lesson01 ${SDL2_LIBRARY})
install(TARGETS lf_lesson01 RUNTIME DESTINATION ${BIN_DIR})