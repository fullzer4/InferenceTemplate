#ifndef MODELS_H
#define MODELS_H

#include <string>
#include "onnxruntime_cxx_api.h"

class Models {
public:
    Models(const std::string& model_path);
    virtual ~Models();

    virtual void setup();
    virtual void run_inference();

protected:
    std::unique_ptr<Ort::Env> env_;
    Ort::Session session_;
    std::string model_path_;
};

#endif // MODELS_H