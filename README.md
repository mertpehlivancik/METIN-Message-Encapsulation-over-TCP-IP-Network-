# METIN (Message Encapsulation over TCP/IP Network)
## Purpose of Project
Project name is METIN (Message Encapsulation over TCP/IP Networks). This project aims to create a system that communicates over HTTP and at the mean time encapsulate a hidden TCP/IP protocol in the HTTP traffic without being detected by firewalls. Although network traffic is blocked by the firewall, the SSH connection can be established with bypassing firewall.
## Used Technology
- Socket Programming in C
- Libssh Library in C
- VirtualBox for Simulation Environment
- Cisco Packet Tracer
- Iptables Firewall
- AES256 Cryptology
## Simulation Environment
- UBUNTU 16.04.5 LTS was used by Virtual Machines in this simulation.
- Uncomment block "#net.ipv4.ip_forward=1" in sysctl.conf for acting VM2 as router. 
![](images/SimulationEnvironment.png)


