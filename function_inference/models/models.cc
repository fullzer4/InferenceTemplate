#include "models.h"
#include "onnxruntime_cxx_api.h"
#include <stdexcept>

Models::Models(const std::string& model_path) : model_path_(model_path), env_(nullptr), session_(nullptr) {}

Models::~Models() {}

void Models::setup() {
    env_ = std::make_unique<Ort::Env>(OrtLoggingLevel::ORT_LOGGING_LEVEL_ERROR, "ONNX_Runtime_Env");

    Ort::SessionOptions session_options;
    Ort::Status status = session_.Create(*env_, model_path_.c_str(), session_options);
    if (!status.IsOK()) {
        throw std::runtime_error("Error creating session: " + std::string(status.ErrorMessage()));
    }
}

void Models::run_inference() {
    throw std::runtime_error("Run inference method not implemented.");
}