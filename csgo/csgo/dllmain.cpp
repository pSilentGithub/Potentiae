#include "sdk/includes.h"

unsigned long __stdcall initialize( _In_ LPVOID reserved ) {
#ifdef _LOGGING
	utilities::console::open( );
#endif

	while ( !GetAsyncKeyState( VK_END ) )
		std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );

	FreeLibraryAndExitThread( reinterpret_cast< HMODULE >( reserved ), 0 );

	return 0;
}

BOOL WINAPI DllMain( _In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved ) {

	switch ( reason ) {
	case DLL_PROCESS_ATTACH: {
		if ( const auto thread_handle = CreateThread( 0, 0, initialize, instance, 0, 0 ) )
			CloseHandle( thread_handle );
	} break;
	case DLL_PROCESS_DETACH: {
	#ifdef _LOGGING
		utilities::console::close( );
	#endif
	} break;
	}

	return TRUE;
}