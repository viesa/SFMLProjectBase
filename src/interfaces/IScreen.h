#pragma once

#include "Window.h"
#include "EventMgr.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Log.h"
#include "Draw.h"
#include "Lib.h"

#include <SFML/Graphics.hpp>

#define SCREENINDEX_NO_SCREEN -1

class IApp;

enum class ScreenState : unsigned char
{
    Running,
    ExitApp,
    ChangeNext,
    ChangePrevious,
    None,
    Count
};

class IScreen
{
public:
    friend class ScreenList;

    IScreen()
        : m_currentState(ScreenState::None),
          m_parentApp(nullptr),
          m_screenIndex(SCREENINDEX_NO_SCREEN)
    {
    }
    virtual ~IScreen()
    {
    }

    virtual int GetNextScreenIndex() const = 0;
    virtual int GetPreviousScreenIndex() const = 0;

    virtual void Build() = 0;
    virtual void Destroy() = 0;

    virtual void OnEntry() = 0;
    virtual void OnExit() = 0;

    virtual void Update() = 0;
    virtual void Draw() = 0;

    int GetScreenIndex() const { return m_screenIndex; }

    void SetRunning() { m_currentState = ScreenState::Running; }

    ScreenState GetState() const { return m_currentState; }

    void SetParentApp(IApp *app) { m_parentApp = app; }

protected:
    ScreenState m_currentState;
    IApp *m_parentApp;
    int m_screenIndex;
};