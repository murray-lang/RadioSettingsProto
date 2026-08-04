#include <radio/iq/rx/BasicIqRxRadio.h>
#include <settings/model/lookup/radio/generalCoverageRadioLookup.h>


RadioLookup radioLookup(generalCoverageRadioLookup);

int main(int argc, char *argv[])
{
  BasicIqRxRadio radio(radioLookup);

  return 0;
}