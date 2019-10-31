#pragma once

#include <string>
#include <windows.h>
#include <iostream>

namespace colorMessage {

	class ColorMessages
	{
	public:
		static ColorMessages * instance;

		ColorMessages() {
			if (instance == nullptr) instance = this;
		}
		~ColorMessages() { instance = nullptr; }

		void RedMessage(std::string message);
	};
}
