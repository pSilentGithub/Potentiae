#include "../sdk/includes.h"

void utilities::console::open( ) {
	AllocConsole( );
	freopen_s( reinterpret_cast< FILE** >( stdin ), "CONIN$", "r", stdin );
	freopen_s( reinterpret_cast< FILE** >( stdout ), "CONOUT$", "w", stdout );
}

void utilities::console::close( ) {
	fclose( reinterpret_cast< FILE* >( stdin ) );
	fclose( reinterpret_cast< FILE* >( stdout ) );
	FreeConsole( );
}

void utilities::console::log( const char* log ) {
	printf_s( "%s\n", log );
}