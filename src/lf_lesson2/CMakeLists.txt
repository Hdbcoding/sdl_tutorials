project(lf_lesson2)
add_executable(lf_lesson2
    lf_lesson2.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(lf_lesson2 ${SDL2_LIBRARY})
install(TARGETS lf_lesson2 RUNTIME DESTINATION ${BIN_DIR})