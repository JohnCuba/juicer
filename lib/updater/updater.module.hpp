#pragma once

#include <ESPAsyncWebServer.h>
#include "logg.hpp"

class UpdaterModule {
	private:
	static UpdaterModule* pinstance_;
	Logg logg = Logg("UPDATER");

	void registerServerRoutes(const char* fwVersion);
	ArRequestHandlerFunction updateRequestHandler();
	ArUploadHandlerFunction updateUploadHandler(int command);

	protected:
	UpdaterModule() {};
	~UpdaterModule() {};

	public:
	static UpdaterModule *GetInstance();
	void onSetup(const char* fwVersion);
};
