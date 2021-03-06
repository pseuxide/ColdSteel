#pragma once

#include <D3D11.h>
#include <iostream>
#include <tuple>
#include <mutex>
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "../Hook.h"
#include "WndProc.h"
#include "../../GlobalFlags.h"
#include "../../Rendering/MainMenu.h"
#include "../../Rendering/MenuUtil.h"

namespace HookD3D11 {
    auto Place() -> void;
    auto InitImgui() -> void;
    extern HWND hWnd;
    extern IDXGISwapChain* pSwapChain;
    extern ID3D11Device* pDevice;
    extern ID3D11DeviceContext* pDeviceContext;
    extern ID3D11RenderTargetView*  pRenderTargetView;
}