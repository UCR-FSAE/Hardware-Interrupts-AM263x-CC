# Hardware-Interrupts-AM263x-CC
This is a repository meant to give instructions for UCR FSAE Highlander Racing Club about creating hardware interrupts with the Texas Instrument TMDSCNCD263 Control Card. This control card uses an AM263x-CC.

## Table of Contents
* Introduction
* Needed Software and Hardware
* HwiP API Driver
* Explaining Example Code

## Introduction
This guide walks through creating an interrupt that is triggered by a GPIO voltage change. This is done through a modified example code from the Texas Instruments provided GPIO interrupt examples. This guide will run through neccessary parts for interfacing, flashing, and debugging code on the TMDSCNCD263 Control Card. Afterwards, the HwiP API driver will be explained in more detail about how to configure and create hardware interrupt service routines. Lastly, the example code folder named "InterruptTest" will be explained, and there to be available for download and testing.
