// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmat_add.h"

extern XMat_add_Config XMat_add_ConfigTable[];

XMat_add_Config *XMat_add_LookupConfig(u16 DeviceId) {
	XMat_add_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMAT_ADD_NUM_INSTANCES; Index++) {
		if (XMat_add_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMat_add_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMat_add_Initialize(XMat_add *InstancePtr, u16 DeviceId) {
	XMat_add_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMat_add_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMat_add_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

