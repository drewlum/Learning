#include <pcap/pcap.h>
#include <iostream>

void my_packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data){
}

int main(int argc, char* argv[]) {  

  
  pcap_t*             descr;
  char                errbuf[PCAP_ERRBUF_SIZE];

  descr = pcap_open_offline(argv[1], errbuf);

  if (descr == NULL) {
      std::cerr << "pcap_open_offline() failed: " << errbuf << std::endl;
      return 1;
  }

  if (pcap_loop(descr, 0, my_packet_handler, NULL) < 0) {
      std::cerr << "pcap_loop() failed: " << pcap_geterr(descr);
      return 1;
  }
  pcap_close(descr);

  return 0;  
}
