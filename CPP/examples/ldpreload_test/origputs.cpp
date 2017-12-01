#include <iostream>
#include <pcap/pcap.h>

void my_packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data){
  std::cout << "hacked version" << std::endl;
}

