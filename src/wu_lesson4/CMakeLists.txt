project(wu_lesson4)
add_executable(wu_lesson4 
    wu_lesson4.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(wu_lesson4 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS wu_lesson4 RUNTIME DESTINATION ${BIN_DIR})