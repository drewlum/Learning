#!/bin/bash

rm -f *.so
rm -f *.out
#g++ -shared -fPIC origputs.cpp -o liborigputs.so
g++ -shared -fPIC hacked.cpp -o libhacked.so -I /opt/include -L /opt/lib -lpcap
g++ -Wall main.cpp -o main.out -I /opt/include -L /opt/lib -lpcap 
