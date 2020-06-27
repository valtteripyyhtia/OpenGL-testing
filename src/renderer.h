#ifndef RENDERER_H_
#define RENDERER_H_

#include <glad/glad.h>
#include <spdlog/spdlog.h>

#include <future>
#include <glm/ext/scalar_constants.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <thread>

#include "file_loader.h"
#include "glfw.h"
#include "message_callback.h"
#include "object_resource.h"

class Renderer {
   private:
    enum ATTRIBUTE_ID { vPosition = 0, vColor = 1 };
    void createVAOsAndGenerateBuffers();
    void loadAndBindObject(const ObjectResource& resource, const GLuint VAO, const GLuint BUFFER);
    void createShader(GLuint program, std::string file, GLenum shaderType);
    void createVertexShader(GLuint program);
    void createFragmentShader(GLuint program);
    glm::mat4 setupCameraPosition() const;
    glm::mat4 selectCameraLens(float fieldOfView) const;
    glm::mat4 setupModel() const;
    glm::mat4 createMVP() const;
    glm::mat4 createModel(const ObjectResource& resource) const;

    void draw();

    std::vector<ObjectResource> resources;
    std::vector<GLuint> vertex_array_objects;
    std::vector<GLuint> vertex_buffer_objects;
    GLuint program;

    int width;
    int height;
    const FileLoader fileLoader;
    GLFWwindow& window;

   public:
    Renderer(GLFWwindow* window);
    ~Renderer();
    void initialize(std::vector<ObjectResource> resources);
    void render();
    void createProgram();
};

#endif
