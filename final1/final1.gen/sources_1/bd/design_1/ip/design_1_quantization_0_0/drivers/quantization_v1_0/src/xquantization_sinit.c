// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xquantization.h"

extern XQuantization_Config XQuantization_ConfigTable[];

XQuantization_Config *XQuantization_LookupConfig(u16 DeviceId) {
	XQuantization_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XQUANTIZATION_NUM_INSTANCES; Index++) {
		if (XQuantization_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XQuantization_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XQuantization_Initialize(XQuantization *InstancePtr, u16 DeviceId) {
	XQuantization_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XQuantization_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XQuantization_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

