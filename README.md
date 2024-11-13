# Hardware-Interrupts-AM263x-CC
This is a repository meant to give instructions for UCR FSAE Highlander Racing Club about creating hardware interrupts with the Texas Instrument TMDSCNCD263 Control Card. This control card uses an AM263x-CC processor.

## Table of Contents
* Introduction
* Needed Software and Hardware
* HwiP API Driver
* Explaining Example Code

## Introduction
This guide walks through creating an interrupt that is triggered by a GPIO voltage change. This is done through a modified example code from the Texas Instruments provided GPIO interrupt examples. This guide will run through neccessary parts for interfacing, flashing, and debugging code on the TMDSCNCD263 Control Card. Afterwards, the HwiP API driver will be explained in more detail about how to configure and create hardware interrupt service routines. Lastly, the example code folder named "InterruptTest" will be explained, and there to be available for download and testing.

## Needed Software and Hardware

### Code Composer Studio
This is an IDE that allows us to create code, compile, debug, as well use the syscfg file to adjust pinout configurations and MACROs for the board. [Link](https://www.ti.com/tool/CCSTUDIO#downloads)
### TMDSCNCD263 Control Card and Dock, Micro-USB, USB-C Power Cord
This is all the hardware you need in order to properly use the control card. The micro-USB connects the board to your computer and how you flash code. The dock the TMDSCNCN263 connects to has to be powered through a USB-C conncetion. The board must be powered with about 5V and 3A.
### AM263x SDK
This SDK contains drivers and example code related to the control card and where you can reference and read all APIs used for the TMDSCNCD263. [Link](https://www.ti.com/tool/MCU-PLUS-SDK-AM263X)
### XDS 110 Debugger Drivers
This driver is necessary for your computer and Code Composer Studio to be able to recognize the board and connect to the onboard debugger. [Link](https://software-dl.ti.com/ccs/esd/documents/xdsdebugprobes/emu_xds_software_package_download.html)
### Clang Compiler Drivers
This is the compiler is used in the example codes of the SDK and within the example in this repository. [Link](https://www.ti.com/tool/download/ARM-CGT-CLANG/4.0.0.LTS)
