// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        bit 5 - enable ap_local_deadlock interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (COR/TOW)
//        bit 1 - ap_ready (COR/TOW)
//        bit 5 - ap_local_deadlock (COR/TOW)
//        others - reserved
// 0x10 : Data signal of mat_in
//        bit 31~0 - mat_in[31:0] (Read/Write)
// 0x14 : Data signal of mat_in
//        bit 31~0 - mat_in[63:32] (Read/Write)
// 0x18 : reserved
// 0x1c : Data signal of mat_out
//        bit 31~0 - mat_out[31:0] (Read/Write)
// 0x20 : Data signal of mat_out
//        bit 31~0 - mat_out[63:32] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of num
//        bit 5~0 - num[5:0] (Read/Write)
//        others  - reserved
// 0x2c : reserved
// 0x30 : Data signal of scale_n
//        bit 5~0 - scale_n[5:0] (Read/Write)
//        others  - reserved
// 0x34 : reserved
// 0x38 : Data signal of zero_point
//        bit 17~0 - zero_point[17:0] (Read/Write)
//        others   - reserved
// 0x3c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XQUANTIZATION_CONTROL_ADDR_AP_CTRL         0x00
#define XQUANTIZATION_CONTROL_ADDR_GIE             0x04
#define XQUANTIZATION_CONTROL_ADDR_IER             0x08
#define XQUANTIZATION_CONTROL_ADDR_ISR             0x0c
#define XQUANTIZATION_CONTROL_ADDR_MAT_IN_DATA     0x10
#define XQUANTIZATION_CONTROL_BITS_MAT_IN_DATA     64
#define XQUANTIZATION_CONTROL_ADDR_MAT_OUT_DATA    0x1c
#define XQUANTIZATION_CONTROL_BITS_MAT_OUT_DATA    64
#define XQUANTIZATION_CONTROL_ADDR_NUM_DATA        0x28
#define XQUANTIZATION_CONTROL_BITS_NUM_DATA        6
#define XQUANTIZATION_CONTROL_ADDR_SCALE_N_DATA    0x30
#define XQUANTIZATION_CONTROL_BITS_SCALE_N_DATA    6
#define XQUANTIZATION_CONTROL_ADDR_ZERO_POINT_DATA 0x38
#define XQUANTIZATION_CONTROL_BITS_ZERO_POINT_DATA 18

