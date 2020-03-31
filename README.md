# Multi-channel-splicing_new-method_version-2

1.	Linux 802.11n CSI Tool

1.1	 I recommend installing the new version of Linux 802.11n CSI Tool (https://dhalperi.github.io/linux-80211n-csitool/installation.html) since it is easy and faster. It can also keep the Ethernet interface (eth0).

1.2	 If you install the old version of Linux 802.11n CSI Tool, the Ethernet interface (eth0) may be removed. You have to install the driver for Ethernet interface (https://downloadcenter.intel.com/download/15817/Intel-Network-Adapter-Driver-for-PCIe-Intel-Gigabit-Ethernet-Network-Connections-Under-Linux-) (https://blog.csdn.net/zhayushui/article/details/78610490) and add the eth0 (https://askubuntu.com/questions/31023/how-to-configure-eth0-manually).

2.	Set the static IP address

2.1 You can set the static IP address (e.g., 10.0.0.5 or others) for each laptop using the same way of adding eth0 (https://askubuntu.com/questions/31023/how-to-configure-eth0-manually).

2.2 Connect all of the laptops with Ethernet cables (you can test the connection using ping).

3.	Setup description

3.1 One laptop serves as the controller (runs client) to broadcast the channel number for other laptops. Thus, these laptops can switch channels almost simultaneously.

3.2 Among these laptops (run server) who receive the channel number:
	One laptop serves as the transmitter to send CSI packets.
	Other laptops serve as receivers to receiver CSI packets.

4.	Multi-channel splicing_new method

4.1	Run ./restart on the transmitter and receivers to restart the WiFi network

4.2	Run ./setup_scanning on the transmitter and receivers to the setup the CSI tool monitor mode. Note that the channel is 36 now.

4.3	To compile: make

4.4	To remove: make clean

4.5	Assuming that the port is 1234. The group IP is 10.0.0.255.

4.6	To use: run ./server 1234 on the transmitter and receivers; run ./client 10.0.0.255 1234 on the controller

4.7	On the receiver: open a new terminal and run sudo ./log_to_file csi.dat

4.8	On the transmitter: open a new terminal and run ./random_packets 100000 1 1 1

4.9	To improve the running speed for server, you may want use the following suggestions:
	Remove all unnecessary I\O operations
	For the transmitter: only use “command1 = "sudo iw mon0 set channel " + str + " HT20";”
	For the receivers: only use “command2 = "sudo iw wlan0 set channel " + str + " HT20";”

You may want to download the source code:
