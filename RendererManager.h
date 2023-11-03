#pragma once

class RendererManager {
public:
    RendererManager();
    ~RendererManager();

    void Initialize();

private:

    void ConfigureRenderSettings();
};