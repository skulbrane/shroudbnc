/*******************************************************************************
 * shroudBNC - an object-oriented framework for IRC                            *
 * Copyright (C) 2005 Gunnar Beutner                                           *
 *                                                                             *
 * This program is free software; you can redistribute it and/or               *
 * modify it under the terms of the GNU General Public License                 *
 * as published by the Free Software Foundation; either version 2              *
 * of the License, or (at your option) any later version.                      *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License           *
 * along with this program; if not, write to the Free Software                 *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. *
 *******************************************************************************/

// win32 specific header

#define FD_SETSIZE 4096

#ifndef RUBY
	#include <windows.h>
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#include <assert.h>
#endif

#if !defined(socklen_t)
typedef int socklen_t;
#endif

#undef GetClassName

#define strcasecmp strcmpi

#define EXPORT __declspec(dllexport)

#ifndef _MSC_VER
#undef LoadLibrary
#define LoadLibrary(lpLibFileName) (HMODULE)lt_dlopen(lpLibFileName)
#undef FreeLibrary
#define FreeLibrary(hLibModule) hLibModule ? !lt_dlclose((lt_dlhandle)hLibModule) : 0
#undef GetProcAddress
#define GetProcAddress(hModule, lpProcName) lt_dlsym((lt_dlhandle)hModule, lpProcName)
#endif
