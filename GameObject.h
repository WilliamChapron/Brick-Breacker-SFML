#pragma once

class GameObject {
public:
    GameObject();
    GameObject(float initialX, float initialY);

    void Initialize(float initialX, float initialY);
    virtual void Update();
    virtual void Render();

    void SetPosition(float x, float y);

    float GetX() const;
    float GetY() const;



private:
    float x;
    float y;
};




