project(wu_lesson6)
add_executable(wu_lesson6 
    wu_lesson6.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(wu_lesson6 ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
install(TARGETS wu_lesson6 RUNTIME DESTINATION ${BIN_DIR})