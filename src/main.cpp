#include <glm/vec2.hpp>
#include <iostream>

struct AABB {
  glm::vec2 min;
  glm::vec2 max;
};

bool isIn(AABB &box1, AABB &box2) {
  if (box1.min.x >= box2.min.x && box1.min.x <= box2.max.x) {
    if (box1.min.y >= box2.min.y && box1.min.y <= box2.max.y) {
      return true;
    }
  }
  return false;
}

bool boxIntersect(AABB &box1, AABB &box2) {
  if (isIn(box1, box2)) {
    return true;
  }
  if (isIn(box2, box1)) {
    return true;
  }
  return false;
}

int main() {
  AABB box1 = AABB{glm::vec2{0, 0}, glm::vec2{1, 1}};
  AABB box2 = AABB{glm::vec2{0.5, 0.5}, glm::vec2{1.5, 1.5}};
  AABB box3 = AABB{glm::vec2{1.5, 1.5}, glm::vec2{2.5, 2.5}};
  AABB box4 = AABB{glm::vec2{-1.5, -1.5}, glm::vec2{0.5, 0.5}};
  std::cout << boxIntersect(box1, box2);
}
