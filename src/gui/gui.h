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
#ifndef GUI_GUI_H
#define GUI_GUI_H

#include "gui/window.h"
#include "gui/window_about.h"
#include "gui/window_imgui_features.h"
#include "gui/window_settings.h"

#include <memory>
#include <vector>

// clang-format off
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>
// clang-format on

class gui
{
public:
	gui();
	~gui();

	gui(const gui &) = delete;
	gui &operator=(const gui &) = delete;

private:
	/* Setup window */
	bool _setup_window();

	bool _is_window_create = false;

	/* Set GLSL version */
	const char *glsl_version = "#version 130";
	void _set_glsl_version();

	/* Window */
	GLFWwindow *_window = nullptr;

	/* Create window */
	bool _create_window();

	/* imgui initialization */
	void _imgui_init();

	/* Run window */
	void _run();

	/* Rednering */
	void _render();

	/*
        States
    */

	/* Show main window */
	bool show_gui_window = true;

	/* Gui main window background color */
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	/* Image path */
	std::string _path_to_the_image = "NOTSET";

	/*
        Windows
    */
	std::vector<std::unique_ptr<window>> _windows;

	/* Test window with imgui features */
	void _window_test();
};

#endif // GUI_GUI_H