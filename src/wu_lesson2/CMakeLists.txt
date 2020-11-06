project(wu_lesson2)
add_executable(wu_lesson2 
    wu_lesson2.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(wu_lesson2 ${SDL2_LIBRARY})
install(TARGETS wu_lesson2 RUNTIME DESTINATION ${BIN_DIR})