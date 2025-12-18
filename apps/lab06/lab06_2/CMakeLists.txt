project("lab06_2")

include_directories(include)

file(GLOB SRC "src/*.c")

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} roots)