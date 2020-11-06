project(wu_lesson0)
add_executable(wu_lesson0 wu_lesson0.cxx)
target_link_libraries(wu_lesson0 ${SDL2_LIBRARY})
install(TARGETS wu_lesson0 RUNTIME DESTINATION ${BIN_DIR})