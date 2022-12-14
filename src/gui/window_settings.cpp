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
 * @brief Window settings
 * @author Saveliy Pototskiy (SavaLione)
 * @date 16 Sep 2022
 */
#include "gui/window_settings.h"

#include "core/compiler_version.h"
#include "io/logger.h"

#include <imgui.h>
#include <tinyfiledialogs.h>

window_settings::window_settings()
{
	_set_name("Settings");
}

window_settings::~window_settings() {}

void window_settings::run()
{
	if(_show_window)
	{
		ImGui::Begin(get_name().c_str(), &_show_window);

		_select_image_file();
		_select_capture_device();
		_select_video_file();

		ImGui::End();
	}
}

void window_settings::_select_image_file()
{
	ImGui::Text("Select image");

	std::string img_path = "Image file path: ";
	if(settings_instance.image_path.is_set())
	{
		img_path += settings_instance.image_path.get();
	}
	else
	{
		img_path += "Image path is not set";
	}
	ImGui::Text(img_path.c_str());

	std::string img_path_status = "Image path status: ";
	if(settings_instance.image_path.is_set())
	{
		img_path_status += "true";
	}
	else
	{
		img_path_status += "false";
	}
	ImGui::Text(img_path_status.c_str());

	ImGui::Separator();

	if(ImGui::Button("Select image file"))
	{
		char const *the_open_file_name;
		char const *filter_patterns[3] = {"*.png", "*.jpg", "*.jpeg"};

		the_open_file_name = tinyfd_openFileDialog("Select an image", "", 2, filter_patterns, NULL, 0);

		if(!the_open_file_name)
		{
			spdlog::error("Image opening problem. Open file name is NULL.");
			settings_instance.image_path.unset();
		}
		else
		{
			settings_instance.image_path.set(the_open_file_name);
		}
	}
	ImGui::SameLine();
	if(ImGui::Button("Clear image path"))
	{
		settings_instance.image_path.unset();
	}

	ImGui::Separator();
}

void window_settings::_select_capture_device()
{
	ImGui::Text("Select webcam.");

	ImGui::Separator();
}

void window_settings::_select_video_file()
{
	ImGui::Text("Select video file.");

	std::string video_path = "Video file path: ";
	if(settings_instance.video_path.is_set())
	{
		video_path += settings_instance.video_path.get();
	}
	else
	{
		video_path += "Video path is not set";
	}
	ImGui::Text(video_path.c_str());

	std::string video_path_status = "Video path status: ";
	if(settings_instance.video_path.is_set())
	{
		video_path_status += "true";
	}
	else
	{
		video_path_status += "false";
	}
	ImGui::Text(video_path_status.c_str());

	ImGui::Separator();

	if(ImGui::Button("Select video file"))
	{
		char const *the_open_file_name;
		char const *filter_patterns[3] = {"*.mp4", "*.m4v", "*.mp4v"};

		the_open_file_name = tinyfd_openFileDialog("Select a video file", "", 2, filter_patterns, NULL, 0);

		if(!the_open_file_name)
		{
			spdlog::error("Video file opening problem. Open file name is NULL.");
			settings_instance.video_path.unset();
		}
		else
		{
			settings_instance.video_path.set(the_open_file_name);
		}
	}
	ImGui::SameLine();
	if(ImGui::Button("Clear video path"))
	{
		settings_instance.video_path.unset();
	}
}