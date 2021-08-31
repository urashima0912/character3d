#include "static_mesh.h"

game::StaticMesh::StaticMesh(Transform transform, Color color)
{
    collisionShape = std::make_unique<CollisionShape>(
        CollisionShapeType::Rectangle,
        transform
    );

    this->transform = transform;
    this->color = color;   
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "StaticMesh contructor.");
    #endif
}

game::StaticMesh::~StaticMesh(void)
{
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "StaticMesh destructor.");
    #endif
}

void game::StaticMesh::update(void)
{
    //TODO.
}

void game::StaticMesh::draw(void) const
{
    DrawCube(
        transform.position,
        transform.size.x,
        transform.size.y,
        transform.size.z,
        color
    );
    DrawCubeWires(
        transform.position,
        transform.size.x,
        transform.size.y,
        transform.size.z,
        RAYWHITE
    );

    collisionShape->draw();
}

GameObjectType game::StaticMesh::type(void) const
{
    return GameObjectType::StaticMesh;
}

void game::StaticMesh::setCollisionShapeEnabled(bool value)
{
    this->collisionShape->isEnabled = value;
}

void game::StaticMesh::setCollisionShapeTrigger(bool value)
{
    this->collisionShape->isTrigger = value;
}