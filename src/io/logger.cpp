/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2021-2022, Saveliy Pototskiy (SavaLione) (savalione.com)
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
 * @brief Logger wrapper
 * @author Saveliy Pototskiy (SavaLione)
 * @date 23 Jun 2021
 */
#include "io/logger.h"

#include "core/settings.h"

void logger_init()
{
	settings &settings_instance = settings::instance();

	switch(settings_instance.l_level())
	{
		case log_level::TRACE:
			spdlog::set_level(spdlog::level::trace);
			break;
		case log_level::DEBUG:
			spdlog::set_level(spdlog::level::debug);
			break;
		case log_level::INFO:
			spdlog::set_level(spdlog::level::info);
			break;
		case log_level::WARN:
			spdlog::set_level(spdlog::level::warn);
			break;
		case log_level::ERROR:
			spdlog::set_level(spdlog::level::err);
			break;
		case log_level::CRITICAL:
			spdlog::set_level(spdlog::level::critical);
			break;
		default:
			spdlog::set_level(spdlog::level::info);
			break;
	}

	// spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
}