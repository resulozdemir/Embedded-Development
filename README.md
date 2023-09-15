# Embedded-Development

This repository contains several projects I have worked on, related to network programming and kernel development. The projects are detailed below:

## **UDP Broadcast Server & Client**
_Languages and Interfaces: C, POSIX Socket API_

Description:
- A UDP broadcasting solution that consists of a server and a client.
- The server captures and displays incoming messages.
- The client persistently broadcasts messages across the network.
- Utilizes the POSIX socket API for message reception and address handling.

## **TCP/IP Chat Application**
_Languages and Interfaces: C, POSIX Socket API_

Description:
- A chat application that supports both server and client functionalities.
- Multithreading with pthread is employed to handle multiple client connections simultaneously.
- Each client is assigned a unique ID to enable targeted messaging.
- Communication is optimized using essential socket functions, ensuring real-time feedback.

## **Linux Kernel Character Device Driver**
_Languages and Interfaces: C, Linux Kernel API_

Description:
- Implements device interaction through file operations.
- Ensures safe data transfers between user space and kernel space.
- Utilizes timers to schedule data writes.
- Monitors device readiness.
- Manages resources when the module exits.

## **Linux Kernel Network Driver**
_Languages and Interfaces: C, Linux Kernel API_

Description:
- A partial implementation of a custom network driver for the Linux kernel.
- Code snippet manages device MAC address settings, VLAN configurations, packet reception/transmission using DMA, interrupt handling, and more.
- Utilizes memory-mapped IO functions (ioread32, iowrite32) to interact with hardware registers.
- Uses DMA (Direct Memory Access) to efficiently transfer data to/from network hardware.
- NAPI (New API) is used to handle packet processing in a more efficient manner during high traffic scenarios.
