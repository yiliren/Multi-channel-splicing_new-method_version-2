#!/usr/bin/sudo /bin/bash
#Setup monitor mode for receive packet
rmmod iwlwifi mac80211 cfg80211
modprobe iwlwifi debug=0x40000 connector_log=0x1
sleep 0.3
ifconfig $1 down    #turn off interface wlan0, or wlan1, 2, 3
sleep 0.3
iwconfig $1 mode monitor   #turn interface wlan0 into monitor mode
iw $1 set channel 36 HT20   #setup the channel to monitor
ifconfig $1 up  #turn on interface
echo 0x07 | tee $(find /sys -name rx_chains_msk)
iwconfig

#Setup mon0 for send packet
iw dev $1 interface add mon0 type monitor   #add mon0 interface for packet injection
iw mon0 set channel 36 HT20   #setup the channel to monitor
ifconfig mon0 up    #bring up the interface
echo 0x4101 | tee $(find /sys -name monitor_tx_rate)
iwconfig

