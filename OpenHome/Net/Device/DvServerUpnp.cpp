#include <OpenHome/Net/Core/DvServerUpnp.h>
#include <OpenHome/Net/Core/DvDevice.h>
#include <OpenHome/Net/Private/DviDevice.h>
#include <OpenHome/Net/Private/DviServerUpnp.h>

using namespace OpenHome;
using namespace OpenHome::Net;

DvServerUpnp::DvServerUpnp()
{
    iServer = new DviServerUpnp();
}

DvServerUpnp::~DvServerUpnp()
{
    delete iServer;
}

void DvServerUpnp::AddDevice(DvDevice& aDevice)
{
    aDevice.Device().SetCustomData("Upnp", "Server", iServer);
}
