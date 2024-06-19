#include <stdio.h>
#include <stdlib.h>
#include "onnxruntime_c_api.h"

int main(int argc, char *argv[]) {
    OrtEnv *env = NULL;
    OrtSession *session = NULL;
    OrtStatus *status = NULL;

    status = OrtCreateEnv(ORT_LOGGING_LEVEL_ERROR, "my_onnx_model", &env);
    if (status != NULL) {
        const char *msg = OrtGetErrorMessage(status);
        fprintf(stderr, "Error initializing ONNX Runtime environment: %s\n", msg);
        OrtReleaseStatus(status);
        return 1;
    }

    OrtSessionOptions *session_options = NULL;
    OrtCreateSessionOptions(&session_options);

    const char *model_path = "model.onnx";
    status = OrtCreateSession(env, model_path, session_options, &session);
    if (status != NULL) {
        const char *msg = OrtGetErrorMessage(status);
        fprintf(stderr, "Error loading ONNX model: %s\n", msg);
        OrtReleaseStatus(status);
        OrtReleaseEnv(env);
        return 1;
    }

    printf("Model loaded successfully.\n");

    OrtReleaseSession(session);
    OrtReleaseEnv(env);

    return 0;
}
