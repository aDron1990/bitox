#pragma once

#define BITOX_API

#ifdef _WIN32
	#ifdef BITOX_BUILD
		#define BITOX_API __declspec(dllexport)
	#else
		#define BITOX_API __declspec(dllimport)
	#endif
#endif