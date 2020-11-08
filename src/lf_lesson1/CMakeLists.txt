project(lf_lesson1)
add_executable(lf_lesson1
    lf_lesson1.cxx
)
target_link_libraries(lf_lesson1 ${SDL2_LIBRARY})
install(TARGETS lf_lesson1 DESTINATION ${BIN_DIR})