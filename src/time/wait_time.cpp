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
 * @brief Wait
 * @author Saveliy Pototskiy (SavaLione)
 * @date 10 Nov 2020
 */
#include "time/wait_time.h"

#include "core/platform.h"

#if PLATFORM == PLATFORM_WIN32
	#include <windows.h>
	#define TIME_SLEEP(x) Sleep(x)
#else
	#include <unistd.h>
	#define TIME_SLEEP(x) sleep(x)
#endif

wait_time::wait_time() {}

wait_time::~wait_time() {}

void wait_time::msec(const int &msec)
{
	_msec(msec);
}

void wait_time::sec(const int &sec)
{
	_sec(sec);
}

void wait_time::minutes(const int &minutes)
{
	_minutes(minutes);
}

void wait_time::hour(const int &hour)
{
	_hour(hour);
}

void wait_time::_msec(const int &msec)
{
	TIME_SLEEP(msec);
}

void wait_time::_sec(const int &sec)
{
	TIME_SLEEP(1000 * sec);
}

void wait_time::_minutes(const int &minutes)
{
	TIME_SLEEP(1000 * 1 * 60 * minutes);
}

void wait_time::_hour(const int &hour)
{
	TIME_SLEEP(1000 * 1 * 60 * 60 * hour);
}