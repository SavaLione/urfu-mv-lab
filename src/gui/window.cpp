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
 * @brief Graphical user interface window template
 * @author Saveliy Pototskiy (SavaLione)
 * @date 16 Sep 2022
 */
#include "gui/window.h"

#include "io/logger.h"

#include <imgui.h>

void window::_set_name(std::string const &name)
{
	_name = name;
}

void window::_set_description(std::string const &description)
{
	_description = description;
}

std::string window::get_name()
{
	return _name;
}

std::string window::get_description()
{
	return _description;
}

void window::show_window()
{
	spdlog::info("Show window {}", _name);
	_show_window = true;
}

void window::hide_window()
{
	spdlog::info("Hide window {}", _name);
	_show_window = false;
}

void window::run()
{
	if(_show_window)
	{
		ImGui::Begin(_name.c_str(), &_show_window);

		ImGui::End();
	}
}