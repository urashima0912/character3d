#include "collision_shape.h"

game::CollisionShape::CollisionShape(CollisionShapeType shapeType, Transform transform)
{
    this->shapeType = shapeType;
    this->transform = transform;
}

game::CollisionShape::~CollisionShape(void)
{
    //TODO:
}

void game::CollisionShape::update(void)
{
    //TODO:
}

void game::CollisionShape::draw(void) const
{
    if (shapeType == CollisionShapeType::Rectangle)
        drawRectangleShape();
}

GameObjectType game::CollisionShape::type(void) const
{
    return GameObjectType::Collider;
}

void game::CollisionShape::drawRectangleShape(void) const
{
    rlPushMatrix();
    rlTranslatef(
        transform.position.x,
        transform.position.y,
        transform.position.z
    );
    rlRotatef(transform.rotation.y, 0.0f, 1.0f, 0.0f);
    DrawCubeWiresV(
        {0},
        transform.size,
        GREEN
    );
    rlPopMatrix();
}