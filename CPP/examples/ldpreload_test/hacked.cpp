#include <iostream>
#include <pcap/pcap.h>


pcap_t  *pcap_open_offline(const char * fd, char * errbuff){
  std::cout << "loading hacked version" << std::endl;
  return pcap_open_offline_with_tstamp_precision(fd,PCAP_TSTAMP_PRECISION_NANO,errbuff);
}
