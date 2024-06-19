cmake_minimum_required(VERSION 3.13)
project(function_inference CXX)

set(CMAKE_CXX_STANDARD 17)

set(ONNXRUNTIME_ROOTDIR "./onnxruntime-linux-x64-1.18.0")

include_directories(
    "${ONNXRUNTIME_ROOTDIR}/include"
    "${ONNXRUNTIME_ROOTDIR}/include/onnxruntime"
    "${ONNXRUNTIME_ROOTDIR}/include/onnxruntime/core/session"
)

link_directories(
    "${ONNXRUNTIME_ROOTDIR}/lib"
)

find_library(ONNXRUNTIME_LIBRARY NAMES onnxruntime PATHS "${ONNXRUNTIME_ROOTDIR}/lib")

add_subdirectory(models)

add_executable(function_inference main.cc)

target_link_libraries(function_inference
    ${ONNXRUNTIME_LIBRARY}
)

add_custom_command(
    TARGET function_inference POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/model.onnx
        ${CMAKE_CURRENT_BINARY_DIR}/model.onnx
    COMMENT "Copying model.onnx to build directory"
)