#include "sdk/includes.h"

unsigned long __stdcall initialize( _In_ LPVOID reserved ) {
	return 0;
}

BOOL WINAPI DllMain( _In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved ) {

	switch ( reason ) {
	case DLL_PROCESS_ATTACH: {
		if ( const auto thread_handle = CreateThread( 0, 0, initialize, instance, 0, 0 ) )
			CloseHandle( thread_handle );
	} break;
	}

	return TRUE;
}