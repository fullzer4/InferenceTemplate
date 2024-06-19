#include <iostream>
#include <stdexcept>
#include "onnxruntime_cxx_api.h"

int main(int argc, char *argv[]) {
    Ort::Env env(ORT_LOGGING_LEVEL_ERROR, "my_onnx_model");

    try {
        Ort::SessionOptions session_options;
        Ort::Session session(env, "model.onnx", session_options);

        std::cout << "Model loaded successfully." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}