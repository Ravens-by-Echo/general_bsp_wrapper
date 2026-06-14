cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(HAL_WRAPPER_HEADERS
    include/private/firmware_instance.h
    include/private/fixed_signals_enum.h
    include/private/gpio_wrapper.h
    include/interface/hal_interface.h
    include/private/signals_mapping.h
    include/private/signal_handler.h
)

set(HAL_WRAPPER_SOURCES
    src/firmware_instance.cpp
    src/gpio_wrapper.cpp
    src/signal_handler.cpp
)


add_library(HAL_WRAPPER_library STATIC)
target_sources(HAL_WRAPPER_library PRIVATE
    ${HAL_WRAPPER_SOURCES}
    ${HAL_WRAPPER_HEADERS}   # optional: helps IDE show headers in target
)

target_include_directories(HAL_WRAPPER_library PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(HAL_WRAPPER_library PUBLIC
    pico_stdlib
)
