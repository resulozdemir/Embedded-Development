# Embedded-Development

This repository contains several projects I have worked on, related to network programming and kernel development. The projects are detailed below:

## **Linux Kernel Character Driver**
_Languages and Interfaces: C, Linux Kernel API_

Description:
- Designed as a character device driver module for the Linux kernel.
- Defines an input buffer with a maximum size to store data from the user.
- Defines different IOCTL commands. These commands control different functions of the device, such as retrieving the buffer size, clearing the buffer, or reversing the data.
- Uses a timer to perform operations at regular intervals. The timer triggers specific functions by making callbacks at set intervals.
- Defines a write function for the character device. This function copies data from the user's space and performs specific operations.
- This driver processes, stores, and returns the data taken from the user.


## **Linux Kernel Network Driver**
_Languages and Interfaces: C, Linux Kernel API_

Description:
- The module initializes the network device, sets up necessary configurations, and registers it with the Linux kernel. Upon module removal, it cleans up resources and unregisters the device.
- The driver can set the MAC address for the device and handle multicast addresses, configuring the device to operate in various multicast modes.
- The driver can send and receive packets using DMA buffers. It interfaces with the kernel's networking subsystem to handle packet transmission and reception.
- An interrupt service routine manages device interrupts, handling events like packet reception, packet transmission, and errors.
- The driver offers functions to change device configurations, such as MTU size, base address, and IRQ settings.
- It provides support for VLAN tag handling and retrieves network statistics from the device.

## **TCP/IP Chat Application**
_Languages and Interfaces: C, POSIX Socket API_

Description:
- The server assigns a unique ID to every connected client. This allows sending messages to a specific client.
- Clients listen to incoming messages using separate threads, handling multiple connections simultaneously.
- The server has the capability to send messages to a specific target client.
- Both server and client perform necessary cleanup operations when the connection closes.
- The application limits the maximum number of clients to optimize resource usage.

## **UDP Broadcast Server & Client**
_Languages and Interfaces: C, POSIX Socket API_

Description:
- Utilizes the UDP protocol for sending and receiving data.

Client:
- Creates a socket to send messages to a specific IP address and port.
- Sets up the socket settings to allow broadcasting messages to all devices in a specific network.

Server:
- Continuously listens to incoming data on a specific port.
- Creates a socket to receive data and binds this socket to a specific port.
- Displays the received data on the screen.


## **IPTables Firewall Application**
_Languages and Interfaces: Python, Scapy and IPTables_

Description:
-Initial Setup: Configures firewall rules to control incoming traffic, including allowances for established connections, limitations on TCP requests, and NAT configuration.
-Blocking Specific Traffic: Identifies and blocks traffic based on certain IP addresses and ports.
-Real-Time Rule Adjustment: Modifies firewall settings on-the-fly to block traffic from newly detected suspicious sources or ports.
-Traffic Monitoring and Analysis: Continuously monitors and scrutinizes network packets for source and destination information.
-Responsive Blocking: Automatically updates firewall settings to block traffic matching predefined criteria of unwanted sources or destinations.