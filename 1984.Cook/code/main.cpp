#include <iostream>

#include "BilliardScene.h"
#include "DistributedRayTracer.h"
#include "framework/MyApp.h"
#include "framework/ThinLensCamera.h"

using namespace RayTracingHistory;

const char* const APP_NAME =
    "Distributed Ray tracing -  Robert Cook et al. 1984";
const uint32_t WINDOW_WIDTH = 1280;
const uint32_t WINDOW_HEIGHT = 720;

int main(void) {
  MyApp app;
  try {
    app.init();
    app.createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, APP_NAME);
    auto renderer = app.createRenderer<DistributedRayTracer>();

    auto scene = std::make_shared<BilliardScene>();
    scene->init();

#if 1
    glm::vec3 eyePos(4, 10, 0);
    glm::vec3 lookAt(-1, 1, 1);
#else
    glm::vec3 eyePos(2, 2.5f, -8);
    glm::vec3 lookAt(0, 1, 0);
#endif
    auto camera = std::make_shared<ThinLensCamera>();
    camera->setAperture(0.1f)
        .setFocusDist(glm::distance(eyePos, lookAt))
        .setAspect((float)WINDOW_WIDTH / (float)WINDOW_HEIGHT)
        .setView(eyePos, lookAt, glm::vec3(0, 1, 0))
        .setFOV(45);
    camera->init();

    renderer->renderScene(scene, camera, glm::vec4(1, 1, 1, 1));

    app.mainLoop();

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  app.shutdown();
  return 0;
}