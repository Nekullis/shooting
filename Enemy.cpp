#include "DxLib.h"
#include "Enemy.h"
#include "Utility.h"

namespace {
    constexpr auto SPEED = 3;
}

namespace shooting {

    Enemy::Enemy(int screenWidth, int screenHeight) : ObjectBase(screenWidth, screenHeight) {
        type = Type::Straight;
    }

    bool Enemy::Initialize() {
        // 基底(ObjectBase)クラス の Load 関数をつかってロードする
        int result = Load(_T("res/enemy_a00.png"));

        return result != -1;
    }

    bool Enemy::Start() {
        if (valid) {
            return false;
        }

        x = Utility::Range(0, screenWidth - sizeX);
        y = -sizeY;
        valid = true;

        return true;
    }

    void Enemy::SetType() {
        auto random = Utility::Range(0, 2);

        type = static_cast<Type>(random);
    }

    void Enemy::Process() {
        switch (type) {
        case Type::Straight:
            ProcessStraight();
            break;

        case Type::Zigzag:
            ProcessZigzag();
            break;

        case Type::CosineCurve:
            ProcessCosineCurve();
            break;

        default:
            break;
        }
    }

    void Enemy::ProcessStraight() {
        y += SPEED;

        if (y > screenHeight) {
            valid = false;
        }
    }

    void Enemy::ProcessZigzag() 
    {

    }

    void Enemy::ProcessCosineCurve() 
    {

    }
}
