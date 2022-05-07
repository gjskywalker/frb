// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xrelu.h"

extern XRelu_Config XRelu_ConfigTable[];

XRelu_Config *XRelu_LookupConfig(u16 DeviceId) {
	XRelu_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XRELU_NUM_INSTANCES; Index++) {
		if (XRelu_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XRelu_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XRelu_Initialize(XRelu *InstancePtr, u16 DeviceId) {
	XRelu_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XRelu_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XRelu_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

