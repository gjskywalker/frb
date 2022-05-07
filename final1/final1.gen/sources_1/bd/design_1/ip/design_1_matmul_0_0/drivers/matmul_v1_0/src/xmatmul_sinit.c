// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmatmul.h"

extern XMatmul_Config XMatmul_ConfigTable[];

XMatmul_Config *XMatmul_LookupConfig(u16 DeviceId) {
	XMatmul_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMATMUL_NUM_INSTANCES; Index++) {
		if (XMatmul_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMatmul_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMatmul_Initialize(XMatmul *InstancePtr, u16 DeviceId) {
	XMatmul_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMatmul_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMatmul_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

