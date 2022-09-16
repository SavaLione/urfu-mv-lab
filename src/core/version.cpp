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
 * @brief Lanthe application version
 * @author Saveliy Pototskiy (SavaLione)
 * @date 10 Sep 2022
 */
#include "core/version.h"

#include <cstddef>
#include <vector>

std::string _VERSION = "0.0.1";

std::vector<std::string> split(std::string s, std::string delimiter)
{
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
	{
		token	  = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

std::string get_version_number(int const &i)
{
	std::string ret					= "";
	std::vector<std::string> _ret_v = split(_VERSION, ".");

	if(_ret_v.size() > i)
	{
		ret = _ret_v[i];
	}
	return ret;
}

std::string get_version_major()
{
	return get_version_number(0);
}

std::string get_version_minor()
{
	return get_version_number(1);
}

std::string get_version_path()
{
	return get_version_number(2);
}

std::string get_version_full()
{
	return _VERSION;
}