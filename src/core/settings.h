/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2022, Saveliy Pototskiy (SavaLione) (savalione.com)
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
 * @brief Lanthe application settings
 * @author Saveliy Pototskiy (SavaLione)
 * @date 10 Sep 2022
 */
#ifndef CORE_SETTINGS_H
#define CORE_SETTINGS_H

#include "core/variable.h"

#include <string>


/* Log levels */
enum log_level
{
	TRACE	 = 1,
	DEBUG	 = 2,
	INFO	 = 3,
	WARN	 = 4,
	ERROR	 = 5,
	CRITICAL = 6
};

class settings
{
public:
	static settings &instance()
	{
		static settings s;
		return s;
	}

	~settings();

	/*
        Variables and parameters
    */

	/* Log level */
	log_level l_level();

	variable<std::string> image_path;

private:
	settings();
	settings(settings const &) = delete;
	settings &operator=(settings const &) = delete;

	/*
        Variables and parameters
    */

	/* Log level */
	log_level _l_level = log_level::INFO;
};

#endif // CORE_SETTINGS_H