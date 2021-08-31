#include "player.h"

game::Player::Player(void) : GameObject()
{
    camera = std::make_unique<ICamera>();

    transform.size = (Vector3) {1.0f, 2.0f, 1.0f};
    transform.position = (Vector3){0.0f, transform.size.y / 2, 0.0f};
    transform.rotation = (Vector3){0};

    // CollisionShape Object Initilize
    collisionShape = std::make_unique<CollisionShape>(
        CollisionShapeType::Rectangle,
        transform
    );

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Player contructor.");
    #endif
}

game::Player::Player(Vector3 position) : GameObject()
{
    // HideCursor();
    camera = std::make_unique<ICamera>();

    transform.size = (Vector3) {1.0f, 2.0f, 1.0f};
    transform.position = position;
    transform.rotation = (Vector3){0};

    // CollisionShape Object Initilize
    collisionShape = std::make_unique<CollisionShape>(
        CollisionShapeType::Rectangle,
        transform
    );

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Player contructor.");
    #endif
}

game::Player::~Player(void)
{
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Player destructor.");
    #endif
}

void game::Player::update(void)
{
    movement();
}

void game::Player::draw(void) const
{
    camera->draw(); //TODO: Implement GUI.

    rlPushMatrix();
    rlTranslatef(
        transform.position.x,
        transform.position.y,
        transform.position.z
    );
    rlRotatef(transform.rotation.y, 0.0f, 1.0f, 0.0f);
    DrawCube(
        {0},
        transform.size.x,
        transform.size.y,
        1.0f,
        (Color){255, 0, 0, 150}
    );
    DrawCubeWires(
        {0},
        transform.size.x,
        transform.size.y,
        1.0f,
        RAYWHITE
    );

    DrawLine3D(
        {0.0f, 0.5f, 0.0f},
        {0.0f, 0.5f, 1.0f},
        RAYWHITE
    );

    rlPopMatrix();

    collisionShape->draw();
}

GameObjectType game::Player::type(void) const
{
    return GameObjectType::Player;
}

Camera3D game::Player::getCamera(void) const
{
    return camera->camera;
}

bool game::Player::checkCollision(Transform transform) const
{
    collisionShape->checkCollisionCube(this->transform, transform);
}

/****************************************************
 *  Private methods
*****************************************************/
void game::Player::movement(void)
{
    camera->update();
    
    if (IsKeyDown(KEY_A))
    {
        transform.rotation.y += angleVelocity;
        if(transform.rotation.y > 360.0f)
            transform.rotation.y = 0.0f;
    }
    else if (IsKeyDown(KEY_D))
    {
        transform.rotation.y -= angleVelocity;
        if(transform.rotation.y < 0.0f)
            transform.rotation.y = 360.0f;
    }


    if (IsKeyDown(KEY_W)) 
    {
        transform.position.z = transform.position.z + cosf(transform.rotation.y * DEG2RAD) * speed;
        transform.position.x = transform.position.x + sinf(transform.rotation.y * DEG2RAD) * speed;
        
        // camera->camera.position.z = transform.position.z - 10.5;
        // camera->camera.position.x = transform.position.x - 10.5; 
    }
    else if (IsKeyDown(KEY_S))
    {
        transform.position.z = transform.position.z - cosf(transform.rotation.y * DEG2RAD) * speed;
        transform.position.x = transform.position.x - sinf(transform.rotation.y * DEG2RAD) * speed;
        
        // camera->camera.position.z = transform.position.z + 10.5;
        // camera->camera.position.x = transform.position.x + 10.5; 
    }
    
    camera->camera.target = transform.position;
    collisionShape->setTransform(transform);
}