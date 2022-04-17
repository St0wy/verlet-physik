#include <spdlog/spdlog.h>

#include "DemoWindow.hpp"

int main()
{
	spdlog::set_level(spdlog::level::debug);
	stw::DemoWindow demoWindow;
	demoWindow.StartMainLoop();
}
