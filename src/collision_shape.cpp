#include "collision_shape.h"

game::CollisionShape::CollisionShape(CollisionShapeType shapeType, Transform transform)
{
    this->shapeType = shapeType;
    this->transform = transform;

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "CollisionShape contructor.");
    #endif
}

game::CollisionShape::~CollisionShape(void)
{
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "CollisionShape destructor.");
    #endif
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

void game::CollisionShape::setTransform(Transform transform)
{
    this->transform = transform;
}

bool game::CollisionShape::checkCollisionCube(const Transform& transform1, const Transform& transform2) const
{
    if (!this->isEnabled) return false;

    BoundingBox box1 = {
        (Vector3){
            transform1.position.x - transform1.size.x / 2,
            transform1.position.y - transform1.size.y / 2,
            transform1.position.z - transform1.size.z / 2
        },
        (Vector3){
            transform1.position.x + transform1.size.x / 2,
            transform1.position.y + transform1.size.y / 2,
            transform1.position.z + transform1.size.z / 2
        },
    };

    BoundingBox box2 = {
        (Vector3){
            transform2.position.x - transform2.size.x / 2,
            transform2.position.y - transform2.size.y / 2,
            transform2.position.z - transform2.size.z / 2
        },
        (Vector3){
            transform2.position.x + transform2.size.x / 2,
            transform2.position.y + transform2.size.y / 2,
            transform2.position.z + transform2.size.z / 2
        },
    };

    return CheckCollisionBoxes(box1, box2);
}