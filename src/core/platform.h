/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2020-2022, Saveliy Pototskiy (SavaLione) (savalione.com)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
 /**
 * @file
 * @brief Platform specific constants
 * @author Saveliy Pototskiy (SavaLione)
 * @date 10 Now 2020
 */
#ifndef CORE_PLATFORM_H
#define CORE_PLATFORM_H

#include <stddef.h>

/* ---------------------------------------------------------
                          Platforms
------------------------------------------------------------*/
#define PLATFORM_UNKNOWN 0
#define PLATFORM_WIN32   1
#define PLATFORM_LINUX   2
#define PLATFORM_MACOS   3
#define PLATFORM_BSD     100 // Generic BSD system
#define PLATFORM_UNIX    101 // Generic UNIX system

#if defined(__linux)
	#define PLATFORM PLATFORM_LINUX
#elif defined(_WIN32)
	#define PLATFORM PLATFORM_WIN32
#elif defined(__MACH__)
	#define PLATFORM PLATFORM_MACOS
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) \
      || defined(__bsdi__) || defined(__DragonFly__)
	#define PLATFORM PLATFORM_BSD
#elif defined(__unix__) || defined(__unix) || defined(unix)
	#define PLATFORM PLATFORM_UNIX
#else
	#define PLATFORM PLATFORM_UNKNOWN
#endif

/* ---------------------------------------------------------
                          Compilers
------------------------------------------------------------*/

// This is used in many places, keep it for now
#if defined(_MSC_VER)
	#define COMPILER_MSVC 1
#else
	#define COMPILER_MSVC 0
#endif

#if COMPILER_MSVC
	#define __func__ __FUNCTION__ // MSVC doesn't know about C99 __func__
#endif

/* ---------------------------------------------------------
                           Types
------------------------------------------------------------*/

#if COMPILER_MSVC
	
	typedef signed char s8;         //  8 bits integer
	typedef unsigned char u8;       //  8 bits unsigned integer
	
	typedef signed short s16;       // 16 bits signed integer
	typedef unsigned short u16;     // 16 bits unsigned integer
	
	typedef signed long s32;        // 32 bits signed integer
	typedef unsigned long u32;      // 32 bits unsigned integer
	
	typedef signed long long s64;   // 64 bits signed integer
	typedef unsigned long long u64; // 64 bits unsigned integer
	
#else
	
	#include <stdint.h>
	
	typedef int8_t s8;    //  8 bits integer
	typedef uint8_t u8;   //  8 bits unsigned integer
	
	typedef int16_t s16;  // 16 bits signed integer
	typedef uint16_t u16; // 16 bits unsigned integer
	
	typedef int32_t s32;  // 32 bits signed integer
	typedef uint32_t u32; // 32 bits unsigned integer
	
	typedef int64_t s64;  // 64 bits signed integer
	typedef uint64_t u64; // 64 bits unsigned integer
	
#endif

typedef float f32; // 32 bits float
typedef double f64; // 64 bits double float

/* ---------------------------------------------------------
                          Break
------------------------------------------------------------*/

/*!
 * \def trap()
 * \brief Halt execution and notify any attached debugger
 */
#if COMPILER_MSVC
	#define trap() (__debugbreak(), std::abort())
#elif HAVE_BUILTIN_TRAP
	#define trap() __builtin_trap()
#else
	#define trap() std::abort()
#endif

/* ---------------------------------------------------------
                Helper macros
------------------------------------------------------------*/

/*!
 * \def DISCARD(...)
 * \brief Discard parameters from a macro
 */
#if COMPILER_MSVC
	// MS compilers support noop which discards everything inside the parens
	#define DISCARD(...) __noop
#else
	#define DISCARD(...) ((void)0)
#endif

/*!
 * \def P_FILE
 * \brief Path to the current source file
 * In release builds this will be defined to the relative path to the current
 * translation unit to avoid compiling the full source path into release executables.
 */
#if !defined(P_FILE)
	#define P_FILE __FILE__
#endif

#endif // CORE_PLATFORM_H