#include "models.h"
#include "onnxruntime_cxx_api.h"
#include <iostream>
#include <stdexcept>

class YOLOv8 : public Models {
public:
    YOLOv8(const std::string& model_path) : Models(model_path) {}

    void setup() override {
        Models::setup(); // Chama o método da classe base para configurar o ambiente e a sessão
    }

    void run_inference() override {
        // Implementação da inferência para YOLOv8
        Ort::AllocatorWithDefaultOptions allocator;
        // Ort::Value input_tensor(allocator, ...); // Criar o tensor de entrada
        // Ort::Value output_tensor = session_.Run(...); // Realizar a inferência
        // Processamento do resultado
        std::cout << "Running YOLOv8 inference." << std::endl;
    }
};
