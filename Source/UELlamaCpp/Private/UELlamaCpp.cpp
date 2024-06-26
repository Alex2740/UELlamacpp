// Copyright (c) 2023 Mika Pi, Modifications Copyright 2023-current Getnamo

#include "UELlamaCpp.h"

#define GGML_CUDA_DMMV_X 64
#define GGML_CUDA_F16
#define GGML_CUDA_MMV_Y 2
#define GGML_USE_CUBLAS
#define GGML_USE_K_QUANTS
#define K_QUANTS_PER_ITERATION 2

#include "llama.h"

#define LOCTEXT_NAMESPACE "FUELlamaCppModule"

void FUELlamaCppModule::StartupModule()
{
  llama_backend_init(true /*numa*/);
  IModuleInterface::StartupModule();
}

void FUELlamaCppModule::ShutdownModule()
{
  IModuleInterface::ShutdownModule();
  llama_backend_free();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUELlamaCppModule, UELlamaCpp)