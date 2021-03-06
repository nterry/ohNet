#include <OpenHome/Private/TestFramework.h>
#include <OpenHome/Private/OptionParser.h>
#include <OpenHome/Net/Core/OhNet.h>
#include <OpenHome/Buffer.h>

#include <vector>

using namespace OpenHome;

extern void TestSsdpMListen(const std::vector<Brn>& aArgs);

void OpenHome::TestFramework::Runner::Main(TInt aArgc, TChar* aArgv[], Net::InitialisationParams* aInitParams)
{
    Net::UpnpLibrary::Initialise(aInitParams);
    std::vector<Brn> args = OptionParser::ConvertArgs(aArgc, aArgv);
    TestSsdpMListen(args);
    Net::UpnpLibrary::Close();
}
