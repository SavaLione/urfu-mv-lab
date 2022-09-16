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
 * @brief Graphical user interface
 * @author Saveliy Pototskiy (SavaLione)
 * @date 16 Sep 2022
 */
#include "gui/gui.h"

#include "core/compiler_version.h"
#include "core/settings.h"
#include "gui/window_about.h"
#include "gui/window_imgui_features.h"
#include "gui/window_settings.h"
#include "io/logger.h"
#include "spdlog/spdlog.h"

#include <cstddef>
#include <memory>
#include <tinyfiledialogs.h>

static void glfw_error_callback(int error, const char *description)
{
	spdlog::error("Glfw Error {}: {}", error, description);
}

gui::gui()
{
	spdlog::info("Running graphical user interface.");

	/* Adding windows to the gui */
	_windows.push_back(std::make_unique<window_imgui_features>());
	_windows.push_back(std::make_unique<window_about>());
	_windows.push_back(std::make_unique<window_settings>());
	_windows.push_back(std::make_unique<window_cv>());

	if(_setup_window())
	{
		_set_glsl_version();
		if(_create_window())
		{
			_imgui_init();
			_run();
		}
	}
}

gui::~gui()
{
	spdlog::info("Closing graphical user interface.");

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	if(_is_window_create)
	{
		glfwDestroyWindow(_window);
	}
	glfwTerminate();
}

bool gui::_setup_window()
{
	// Setup window
	glfwSetErrorCallback(glfw_error_callback);
	if(!glfwInit())
	{
		spdlog::error("Glfw init error.");
		return false;
	}
	return true;
}

void gui::_set_glsl_version()
{
	// GL 3.0 + GLSL 130
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
}

bool gui::_create_window()
{
	_window = glfwCreateWindow(1280, 720, "Machine vision OpenCV labs", NULL, NULL);
	if(_window == NULL)
	{
		spdlog::error("GLFW window create error.");
		return false;
	}
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1); // Enable vsync
	_is_window_create = true;
	return true;
}

void gui::_imgui_init()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(_window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

void gui::_run()
{
	while(show_gui_window)
	{
		show_gui_window = !glfwWindowShouldClose(_window);

		// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		for(std::size_t i = 0; i < _windows.size(); i++)
		{
			_windows[i]->run();
		}

		_render();
	}
}

void gui::_window_test()
{
	ImGui::ShowDemoWindow();
}

void gui::_render()
{
	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(_window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(_window);
}