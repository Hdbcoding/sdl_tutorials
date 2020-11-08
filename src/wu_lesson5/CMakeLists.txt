project(wu_lesson5)
add_executable(wu_lesson5 
    wu_lesson5.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(wu_lesson5 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS wu_lesson5 RUNTIME DESTINATION ${BIN_DIR})