
#pragma once

#include "glad/glad.h"

class Shader
{
public:
    unsigned int shaderId;
    Shader(const char* source, int shaderType) { // when constructed: load shader on GPU
        //const char* vertexShaderSource{
       
        shaderId = glCreateShader(shaderType);
        glShaderSource(shaderId, 1, &source, nullptr);
        glCompileShader(shaderId);
    }
    Shader(const Shader&) = delete; // avoid it being cloned

    ~Shader() { // when destructed: delete the shader from GPU
        glDeleteShader(shaderId);
    }
};

