#pragma once

typedef void(__cdecl* ClientServicesFormatAndLoginFunc)(LPVOID unk, LPVOID unk2, const char* accountName, const char* password);

class ClientServices
{
private:
	Engine* eng;

	ClientServicesFormatAndLoginFunc fpClientServicesFormatAndLogin;

public:
	ClientServices();
	~ClientServices();

	void formatAndLogin(const char* accountName, const char* password) { fpClientServicesFormatAndLogin(accountName, password); }
};
