## From VM3 to VM1.
	iptables -A FORWARD -i enp0s9 -o enp0s8 -p tcp -m tcp --dport 80 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s8 -o enp0s9 -p tcp -m tcp --dport 60996 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s8 -o enp0s9 -p tcp -m tcp --dport 60997 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s8 -o enp0s9 -p tcp -m tcp --dport 60998 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s8 -o enp0s9 -p tcp -m tcp --dport 60999 -m state --state NEW,ESTABLISHED -j ACCEPT

## From VM1 to VM3.
	iptables -A FORWARD -i enp0s8 -o enp0s9 -p tcp -m tcp --dport 80 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s9 -o enp0s8 -p tcp -m tcp --dport 60992 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s9 -o enp0s8 -p tcp -m tcp --dport 60993 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s9 -o enp0s8 -p tcp -m tcp --dport 60994 -m state --state NEW,ESTABLISHED -j ACCEPT
	iptables -A FORWARD -i enp0s9 -o enp0s8 -p tcp -m tcp --dport 60995 -m state --state NEW,ESTABLISHED -j ACCEPT

## All traffic between VM1 and VM3 is blocked.
	iptables -A FORWARD -i enp0s8 -o enp0s9 -j DROP
	iptables -A FORWARD -i enp0s9 -o enp0s8 -j DROP
