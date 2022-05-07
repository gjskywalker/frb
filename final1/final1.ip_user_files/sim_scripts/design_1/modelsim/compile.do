vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xilinx_vip
vlib modelsim_lib/msim/xpm
vlib modelsim_lib/msim/axi_infrastructure_v1_1_0
vlib modelsim_lib/msim/axi_vip_v1_1_11
vlib modelsim_lib/msim/processing_system7_vip_v1_0_13
vlib modelsim_lib/msim/xil_defaultlib
vlib modelsim_lib/msim/generic_baseblocks_v2_1_0
vlib modelsim_lib/msim/axi_register_slice_v2_1_25
vlib modelsim_lib/msim/fifo_generator_v13_2_6
vlib modelsim_lib/msim/axi_data_fifo_v2_1_24
vlib modelsim_lib/msim/axi_crossbar_v2_1_26
vlib modelsim_lib/msim/axi_protocol_converter_v2_1_25
vlib modelsim_lib/msim/lib_cdc_v1_0_2
vlib modelsim_lib/msim/proc_sys_reset_v5_0_13
vlib modelsim_lib/msim/axi_clock_converter_v2_1_24
vlib modelsim_lib/msim/blk_mem_gen_v8_4_5
vlib modelsim_lib/msim/axi_dwidth_converter_v2_1_25

vmap xilinx_vip modelsim_lib/msim/xilinx_vip
vmap xpm modelsim_lib/msim/xpm
vmap axi_infrastructure_v1_1_0 modelsim_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_11 modelsim_lib/msim/axi_vip_v1_1_11
vmap processing_system7_vip_v1_0_13 modelsim_lib/msim/processing_system7_vip_v1_0_13
vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib
vmap generic_baseblocks_v2_1_0 modelsim_lib/msim/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_25 modelsim_lib/msim/axi_register_slice_v2_1_25
vmap fifo_generator_v13_2_6 modelsim_lib/msim/fifo_generator_v13_2_6
vmap axi_data_fifo_v2_1_24 modelsim_lib/msim/axi_data_fifo_v2_1_24
vmap axi_crossbar_v2_1_26 modelsim_lib/msim/axi_crossbar_v2_1_26
vmap axi_protocol_converter_v2_1_25 modelsim_lib/msim/axi_protocol_converter_v2_1_25
vmap lib_cdc_v1_0_2 modelsim_lib/msim/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 modelsim_lib/msim/proc_sys_reset_v5_0_13
vmap axi_clock_converter_v2_1_24 modelsim_lib/msim/axi_clock_converter_v2_1_24
vmap blk_mem_gen_v8_4_5 modelsim_lib/msim/blk_mem_gen_v8_4_5
vmap axi_dwidth_converter_v2_1_25 modelsim_lib/msim/axi_dwidth_converter_v2_1_25

vlog -work xilinx_vip  -incr -mfcu -sv -L axi_vip_v1_1_11 -L processing_system7_vip_v1_0_13 -L xilinx_vip "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
"D:/vivado/Vivado/2021.2/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm  -incr -mfcu -sv -L axi_vip_v1_1_11 -L processing_system7_vip_v1_0_13 -L xilinx_vip "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"D:/vivado/Vivado/2021.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"D:/vivado/Vivado/2021.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm  -93 \
"D:/vivado/Vivado/2021.2/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_11  -incr -mfcu -sv -L axi_vip_v1_1_11 -L processing_system7_vip_v1_0_13 -L xilinx_vip "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/63b7/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_13  -incr -mfcu -sv -L axi_vip_v1_1_11 -L processing_system7_vip_v1_0_13 -L xilinx_vip "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_ama_addmuladd_6s_6s_6s_17s_17_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_control_s_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_flow_control_loop_pipe_sequential_init.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_gmem_m_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_5ns_6s_11_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_6s_6s_12_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_8ns_8ns_16_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_8s_8s_16_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_mul_mul_11s_6s_16_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_pool_Pipeline_VITIS_LOOP_44_3_VITIS_LOOP_47_4.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_sdiv_7s_8s_6_11_seq_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool_sdiv_19ns_16s_18_23_seq_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b9ab/hdl/verilog/pool.v" \
"../../../bd/design_1/ip/design_1_pool_0_0/sim/design_1_pool_0_0.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_control_s_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_flow_control_loop_pipe_sequential_init.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_gmem_m_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mac_muladd_7ns_8s_7ns_15_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mac_muladd_8s_8s_18s_18_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_matmul_Pipeline_VITIS_LOOP_16_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_matmul_Pipeline_VITIS_LOOP_20_2_VITIS_LOOP_21_3_VITIS_LOOP_22_4.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_7ns_8ns_15_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_7ns_8s_15_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_8ns_8ns_16_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul_mul_mul_8ns_16ns_24_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/75f8/hdl/verilog/matmul.v" \
"../../../bd/design_1/ip/design_1_matmul_0_0/sim/design_1_matmul_0_0.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/069d/hdl/verilog/mat_add_control_s_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/069d/hdl/verilog/mat_add_gmem_m_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/069d/hdl/verilog/mat_add.v" \
"../../../bd/design_1/ip/design_1_mat_add_0_0/sim/design_1_mat_add_0_0.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_control_s_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_flow_control_loop_pipe_sequential_init.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_gmem_m_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_im2col_mat_Pipeline_VITIS_LOOP_56_7.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mac_muladd_2ns_3ns_26ns_26_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mat_in_pad_V_RAM_AUTO_1R1W.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_3ns_3ns_6_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_3ns_32ns_35_2_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_5ns_6ns_11_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_6ns_3ns_9_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_6ns_35ns_41_2_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_6s_6s_12_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_7s_6s_11_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_9ns_3ns_12_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_9s_9s_18_1_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_18ns_41ns_59_2_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_mul_5ns_11s_11_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_mul_12s_6s_16_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_mul_mul_15ns_12ns_26_4_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat_sdiv_8s_3s_8_12_seq_1.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ed4c/hdl/verilog/im2col_mat.v" \
"../../../bd/design_1/ip/design_1_im2col_mat_0_0/sim/design_1_im2col_mat_0_0.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/4c18/hdl/verilog/relu_control_s_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/4c18/hdl/verilog/relu_gmem_m_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/4c18/hdl/verilog/relu.v" \
"../../../bd/design_1/ip/design_1_relu_0_0/sim/design_1_relu_0_0.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b8b3/hdl/verilog/quantization_control_s_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b8b3/hdl/verilog/quantization_gmem_m_axi.v" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b8b3/hdl/verilog/quantization.v" \
"../../../bd/design_1/ip/design_1_quantization_0_0/sim/design_1_quantization_0_0.v" \

vlog -work generic_baseblocks_v2_1_0  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_25  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/e1e6/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_6  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/8ae1/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_6  -93 \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/8ae1/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_6  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/8ae1/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_24  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/fa53/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_26  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ac57/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_xbar_0/sim/design_1_xbar_0.v" \

vlog -work axi_protocol_converter_v2_1_25  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/8fe4/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \

vcom -work lib_cdc_v1_0_2  -93 \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13  -93 \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib  -93 \
"../../../bd/design_1/ip/design_1_rst_ps7_0_50M_0/sim/design_1_rst_ps7_0_50M_0.vhd" \

vlog -work xil_defaultlib  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_xbar_1/sim/design_1_xbar_1.v" \

vlog -work axi_clock_converter_v2_1_24  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/23c0/hdl/axi_clock_converter_v2_1_vl_rfs.v" \

vlog -work blk_mem_gen_v8_4_5  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/25a8/simulation/blk_mem_gen_v8_4.v" \

vlog -work axi_dwidth_converter_v2_1_25  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../../final1.gen/sources_1/bd/design_1/ipshared/38b4/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -incr -mfcu "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/ec67/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ipshared/3007/hdl" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_pool_0_0/drivers/pool_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_matmul_0_0/drivers/matmul_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_mat_add_0_0/drivers/mat_add_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_im2col_mat_0_0/drivers/im2col_mat_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_relu_0_0/drivers/relu_v1_0/src" "+incdir+../../../../final1.gen/sources_1/bd/design_1/ip/design_1_quantization_0_0/drivers/quantization_v1_0/src" "+incdir+D:/vivado/Vivado/2021.2/data/xilinx_vip/include" \
"../../../bd/design_1/ip/design_1_auto_us_0/sim/design_1_auto_us_0.v" \
"../../../bd/design_1/ip/design_1_auto_us_1/sim/design_1_auto_us_1.v" \
"../../../bd/design_1/ip/design_1_auto_us_2/sim/design_1_auto_us_2.v" \
"../../../bd/design_1/ip/design_1_auto_us_3/sim/design_1_auto_us_3.v" \
"../../../bd/design_1/ip/design_1_auto_us_4/sim/design_1_auto_us_4.v" \
"../../../bd/design_1/ip/design_1_auto_us_5/sim/design_1_auto_us_5.v" \
"../../../bd/design_1/ip/design_1_auto_pc_1/sim/design_1_auto_pc_1.v" \
"../../../bd/design_1/sim/design_1.v" \

vlog -work xil_defaultlib \
"glbl.v"

