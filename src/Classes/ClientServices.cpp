#include "preCompiled.h"

ClientServices::ClientServices() : eng(Engine::getInstance())
{
	// Setup our functions
	fpClientServicesFormatAndLogin = reinterpret_cast<ClientServicesFormatAndLoginFunc>(eng->RVAToPtr(ClientServicesFormatAndLoginAddr));
}

ClientServices::~ClientServices()
{

}