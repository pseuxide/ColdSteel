#include "WndProc.h"

namespace HookD3D11 {
    WNDPROC oWndProc;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

auto WINAPI HookD3D11::hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT {
    if (uMsg == 0x100) {
        switch (wParam) {
            //If HOME key is pressed
            case 0x24:
                Flags::showMenu = !Flags::showMenu;
        }
    }

    if (Flags::showMenu) {
        //This function tells ImGui about how player manipulates cursor and keys and fire event on ImGui menu according to that data.
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        //By returning DefWindowProc, cursor and key event starts to not affect to the game.
        return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    //Pass the privilege back to the game.
    return CallWindowProc(HookD3D11::oWndProc, hWnd, uMsg, wParam, lParam);
}

auto HookD3D11::HookWndProc() -> void {
    HookD3D11::oWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(hWnd, GWLP_WNDPROC, (__int3264)(LONG_PTR)HookD3D11::hkWndProc));
}

auto HookD3D11::RestoreWndProc() -> void {
    SetWindowLongPtr(HookD3D11::hWnd, GWLP_WNDPROC, (LONG_PTR)HookD3D11::oWndProc);
}