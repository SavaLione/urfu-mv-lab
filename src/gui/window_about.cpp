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
 * @brief Window about
 * @author Saveliy Pototskiy (SavaLione)
 * @date 16 Sep 2022
 */
#include "gui/window_about.h"

#include "core/compiler_version.h"
#include "core/version.h"
#include "io/logger.h"

#include <imgui.h>

window_about::window_about()
{
	_set_name("About");
}

window_about::~window_about() {}

void window_about::run()
{
	if(_show_window)
	{
		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoResize;
		window_flags |= ImGuiWindowFlags_NoCollapse;

		ImGui::Begin(get_name().c_str(), &_show_window, window_flags);

		ImGui::Text("Author: Savely Pototsky (SavaLione)");
		ImGui::Text("Group:  FOM-210510");
		ImGui::Separator();
		ImGui::Text("Application version: ");
		ImGui::SameLine();
		ImGui::Text(get_version_full().c_str());
		ImGui::Text("c++ version: ");
		ImGui::SameLine();
		std::string _cpp_version = std::to_string(__cplusplus);
		ImGui::Text(_cpp_version.c_str());
		ImGui::Text("Compiler: ");
		ImGui::SameLine();
		ImGui::Text(compiler_version().c_str());
		ImGui::Text("Compile date: ");
		ImGui::SameLine();
		std::string _date = __DATE__;
		_date += " ";
		_date += __TIME__;
		ImGui::Text(_date.c_str());
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		ImGui::End();
	}
}