#pragma once

#include <string>
#include <cassert>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Err.hpp>

#include "WindowThrowMacros.h"
#include "VeException.h"
#include "Log.h"

class Window
{
    friend class Draw;

public:
    Window() = default;
    ~Window();
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    void Create(const std::string &title, int width, int height);

    static void Clear();
    static void Present() noexcept;

    static void PositionCenter() noexcept;

    static sf::RenderWindow *GetSFWindow() noexcept;
    static sf::Vector2i GetPosition() noexcept;
    static sf::Vector2u GetSize() noexcept;
    static int GetWidth() noexcept;
    static int GetHeight() noexcept;
    static const std::string &GetTitle() noexcept;

    static bool IsFullscreen() noexcept;
    static bool IsVSyncEnabled() noexcept;

    static void SetPosition(const sf::Vector2i &pos) noexcept;
    static void SetSize(const sf::Vector2u &size) noexcept;
    static void SetTitle(const std::string &title) noexcept;
    static void SetIcon(const std::string &icon) noexcept;
    static void SetFullscreen(bool toggle) noexcept;
    static void SetVSync(bool toggle) noexcept;
    static void SetView(const sf::View &view) noexcept;

private:
    static sf::RenderWindow *m_sfWindow;
    static std::string m_title;
    // Used after exiting fullscreen
    static sf::VideoMode m_videomode;
    // Used after exiting fullscreen
    static sf::Uint32 m_style;
    static sf::Vector2i m_nonFullscreenPosition;

    static bool m_fullscreen;

public:
    class Exception : public VeException
    {
    public:
        Exception(int line, const char *file, const char *errorString) noexcept;
        const char *what() const noexcept override;
        virtual const char *GetType() const noexcept override;
        const char *GetErrorString() const noexcept;

    private:
        std::string errorString;
    };
};