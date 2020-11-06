project(wu_lesson1)
add_executable(wu_lesson1 
    wu_lesson1.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(wu_lesson1 ${SDL2_LIBRARY})
install(TARGETS wu_lesson1 RUNTIME DESTINATION ${BIN_DIR})