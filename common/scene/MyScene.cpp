#include "MyScene.h"

namespace RayTracingHistory {

bool MyScene::closestHit(const Ray& ray, float tMin, float tMax,
                         HitRecord& outRec) const {
  bool hitAnything = false;
  float closestSoFar = tMax;
  HitRecord rec;

  for (auto& obj : mObjects) {
    if (obj->hit(ray, tMin, closestSoFar, rec)) {
      hitAnything = true;
      closestSoFar = rec.t;
      outRec = rec;
    }
  }  // end of for

  return hitAnything;
}

void MyScene::evaluateAnim(float t) {
  for (auto& obj : mObjects) {
    obj->evaluateAnim(t);
  }  // end of for
}

}  // namespace RayTracingHistory
