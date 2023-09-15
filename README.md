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
- Designed as a network driver module for the Linux kernel.
- Contains macro values and constants to define different network device registers.
- Defines control registers and memory addresses for Direct Memory Access (DMA) to optimize data transfers.
- Defines crucial network parameters like maximum packet size, MAC address registers, and control register addresses for d different network operations.
- This driver can send and receive network packets and also monitor the status and statistics of the network device.

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