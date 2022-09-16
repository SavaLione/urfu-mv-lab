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
 * @brief Working with time
 * @author Saveliy Pototskiy (SavaLione)
 * @date 10 Nov 2020
 */
#include "time/current_time.h"

current_time::current_time() {}

current_time::~current_time() {}

std::string current_time::s_year()
{
	std::string ret = "";
	ret += std::to_string(1900 + ltm->tm_year);
	return ret;
}

std::string current_time::s_month()
{
	std::string ret = "";
	if((1 + ltm->tm_mon) < 10)
	{
		ret += "0";
	}
	ret += std::to_string(1 + ltm->tm_mon);
	return ret;
}

std::string current_time::s_day()
{
	std::string ret = "";
	if(ltm->tm_mday < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_mday);
	return ret;
}

std::string current_time::s_hour()
{
	std::string ret = "";
	if(ltm->tm_hour < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_hour);
	return ret;
}

std::string current_time::s_min()
{
	std::string ret = "";
	if(ltm->tm_min < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_min);
	return ret;
}

std::string current_time::s_sec()
{
	std::string ret = "";
	if(ltm->tm_sec < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_sec);
	return ret;
}

std::string current_time::s_date()
{
	std::string ret = "";

	ret += std::to_string(1900 + ltm->tm_year);
	ret += "-";

	if((1 + ltm->tm_mon) < 10)
	{
		ret += "0";
	}
	ret += std::to_string(1 + ltm->tm_mon);
	ret += "-";

	if(ltm->tm_mday < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_mday);
	ret += " ";

	if(ltm->tm_hour < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_hour);
	ret += ":";

	if(ltm->tm_min < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_min);
	ret += ":";

	if(ltm->tm_sec < 10)
	{
		ret += "0";
	}
	ret += std::to_string(ltm->tm_sec);

	return ret;
}

int current_time::i_year()
{
	return 1900 + ltm->tm_year;
}

int current_time::i_month()
{
	return 1 + ltm->tm_mon;
}

int current_time::i_day()
{
	return ltm->tm_mday;
}

int current_time::i_hour()
{
	return ltm->tm_hour;
}

int current_time::i_min()
{
	return ltm->tm_min;
}

int current_time::i_sec()
{
	return ltm->tm_sec;
}