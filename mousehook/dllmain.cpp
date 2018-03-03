// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "mousehook.h"
#include "log.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CMouseHook::m_hModule = hModule;
		CMouseHook::UWM_DRAGEEND = ::RegisterWindowMessage(UWM_DRAGEND_MSG);
		return TRUE;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		CMouseHook::StopHook();
		break;
	}
	return TRUE;
}

