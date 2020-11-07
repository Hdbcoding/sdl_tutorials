project(wu_lesson3)
add_executable(wu_lesson3 
    wu_lesson3.cxx
    "${CMAKE_SOURCE_DIR}/include/utils.cxx"
)
target_link_libraries(wu_lesson3 ${SDL2_LIBRARY})
install(TARGETS wu_lesson3 RUNTIME DESTINATION ${BIN_DIR})