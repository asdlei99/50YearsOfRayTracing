/**
 * 50 Years of Ray tracing
 *
 * GitHub: https://github.com/neil3d/50YearsOfRayTracing
 *
 * Created by yanliang.fyl, 2020
 */

#pragma once
#include <algorithm>

#include "Ray.h"

namespace RTKit1 {

struct AABBox {
  glm::vec3 min;
  glm::vec3 max;

  bool intersect(const Ray& ray, float tMin, float tMax) const {
    for (int i = 0; i < 3; i++) {
      float invD = 1.0f / ray.direction[i];
      float t0 = (min[i] - ray.origin[i]) * invD;
      float t1 = (max[i] - ray.origin[i]) * invD;
      if (invD < 0.0f) std::swap(t0, t1);

      tMin = t0 > tMin ? t0 : tMin;
      tMax = t1 < tMax ? t1 : tMax;
      if (tMax <= tMin) return false;
    }  // end of for
    return true;
  }

  // this = box1+box2
  void surrounding(const AABBox& box1, const AABBox& box2) {
    min.x = std::min(box1.min.x, box2.min.x);
    min.y = std::min(box1.min.y, box2.min.y);
    min.z = std::min(box1.min.z, box2.min.z);

    max.x = std::max(box1.max.x, box2.max.x);
    max.y = std::max(box1.max.y, box2.max.y);
    max.z = std::max(box1.max.z, box2.max.z);
  }

  char maxExtent() const {
    glm::vec3 d = max - min;
    if (d.x > d.y && d.x > d.z)
      return 'x';
    else if (d.y > d.z)
      return 'y';
    else
      return 'z';
  }
};
}  // namespace RTKit1
