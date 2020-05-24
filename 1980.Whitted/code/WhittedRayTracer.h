/**
 * A Brief History of Ray tracing
 *
 * GitHub: https://github.com/neil3d/RayTracingHistory
 *
 * Created by yanliang.fyl, 2020
 */

#pragma once
#include "framework/MyRenderer.h"

namespace RayTracingHistory {

class WhittedRayTracer : public MyRenderer {
 public:
  virtual void _renderThread(MyScene::Ptr scene, MyCamera::Ptr camera) override;

 private:
  Ray _generateViewingRay(int x, int y);
  Ray _generateReflectionRay(const glm::vec3& dir, const glm::vec3& point,
                             const glm::vec3& normal);
  bool _generateRefractationRay(const glm::vec3& dir, const glm::vec3& point,
                                const glm::vec3& normal, float Kn, Ray& outRay,
                                float& outReflectivity);

  glm::vec3 _rayShading(Ray ray, MyScene* pScene, int depth);

  glm::vec3 _backgroundColor(const Ray& ray);

  // cache camera frame
  glm::vec3 mEyePos;
  glm::vec3 mFocalPlaneH, mFocalPlaneV, mFocalPlaneLeftTop;
};

}  // namespace RayTracingHistory
